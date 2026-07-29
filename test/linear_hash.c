/*
 * Linear Hashing implementation in C
 * ------------------------------------
 * Supports insert, search, delete, and automatic incremental growth
 * via bucket splitting (no full-table rehash).
 *
 * Each bucket is a singly linked list of (key, value) pairs.
 * The table grows one bucket at a time when the load factor exceeds
 * a threshold, keeping insert cost amortized low and avoiding the
 * "stop the world" rehash of standard dynamic hash tables.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;      /* array of bucket head pointers */
    int initial_size;     /* N: number of buckets at level 0 */
    int level;             /* current doubling level */
    int next_to_split;     /* index of next bucket to split */
    int num_buckets;       /* current total number of buckets (allocated slots) */
    int num_entries;       /* total number of key/value pairs stored */
    double split_threshold; /* load factor that triggers a split, e.g. 0.75 */
} LinearHashTable;

/* ---------- Hash functions ---------- */

/* h_level(key) = key % (N * 2^level) */
static int hash_level(int key, int initial_size, int level) {
    int range = initial_size << level; /* N * 2^level */
    int h = key % range;
    if (h < 0) h += range; /* handle negative keys */
    return h;
}

/* Determine which bucket a key currently belongs to, given level/next_to_split */
static int lh_bucket_index(LinearHashTable *ht, int key) {
    int idx = hash_level(key, ht->initial_size, ht->level);
    /* If idx is a bucket that hasn't been split yet this round, use it as-is.
       If idx < next_to_split, it means this bucket has already been split
       at the current level, so we must use the next level's hash function. */
    if (idx < ht->next_to_split) {
        idx = hash_level(key, ht->initial_size, ht->level + 1);
    }
    return idx;
}

/* ---------- Table lifecycle ---------- */

LinearHashTable *lh_create(int initial_size, double split_threshold) {
    LinearHashTable *ht = malloc(sizeof(LinearHashTable));
    ht->initial_size = initial_size;
    ht->level = 0;
    ht->next_to_split = 0;
    ht->num_buckets = initial_size;
    ht->num_entries = 0;
    ht->split_threshold = split_threshold;

    /* Allocate generously up front to avoid realloc complexity;
       in production you'd grow this array as num_buckets grows. */
    ht->buckets = calloc(initial_size * 64, sizeof(Entry *));
    return ht;
}

void lh_destroy(LinearHashTable *ht) {
    for (int i = 0; i < ht->num_buckets; i++) {
        Entry *e = ht->buckets[i];
        while (e) {
            Entry *tmp = e;
            e = e->next;
            free(tmp);
        }
    }
    free(ht->buckets);
    free(ht);
}

/* ---------- Split logic ---------- */

static void lh_split(LinearHashTable *ht) {
    int old_idx = ht->next_to_split;
    int new_idx = ht->num_buckets; /* new bucket appended at the end */

    Entry *old_head = ht->buckets[old_idx];
    Entry *keep_head = NULL, *move_head = NULL;
    Entry *keep_tail = NULL, *move_tail = NULL;

    /* Redistribute entries between old_idx and new_idx using level+1 hash */
    while (old_head) {
        Entry *e = old_head;
        old_head = old_head->next;
        e->next = NULL;

        int target = hash_level(e->key, ht->initial_size, ht->level + 1);
        if (target == old_idx) {
            if (!keep_head) keep_head = keep_tail = e;
            else { keep_tail->next = e; keep_tail = e; }
        } else {
            if (!move_head) move_head = move_tail = e;
            else { move_tail->next = e; move_tail = e; }
        }
    }

    ht->buckets[old_idx] = keep_head;
    ht->buckets[new_idx] = move_head;
    ht->num_buckets++;
    ht->next_to_split++;

    /* Finished a full pass over the current level -> advance level */
    if (ht->next_to_split == (ht->initial_size << ht->level)) {
        ht->next_to_split = 0;
        ht->level++;
    }
}

/* ---------- Public operations ---------- */

void lh_insert(LinearHashTable *ht, int key, int value) {
    int idx = lh_bucket_index(ht, key);

    /* Update if key already exists */
    for (Entry *e = ht->buckets[idx]; e; e = e->next) {
        if (e->key == key) {
            e->value = value;
            return;
        }
    }

    Entry *e = malloc(sizeof(Entry));
    e->key = key;
    e->value = value;
    e->next = ht->buckets[idx];
    ht->buckets[idx] = e;
    ht->num_entries++;

    /* Trigger a split if load factor exceeds threshold */
    double load_factor = (double)ht->num_entries / ht->num_buckets;
    if (load_factor > ht->split_threshold) {
        lh_split(ht);
    }
}

int lh_search(LinearHashTable *ht, int key, int *value_out) {
    int idx = lh_bucket_index(ht, key);
    for (Entry *e = ht->buckets[idx]; e; e = e->next) {
        if (e->key == key) {
            if (value_out) *value_out = e->value;
            return 1;
        }
    }
    return 0;
}

int lh_delete(LinearHashTable *ht, int key) {
    int idx = lh_bucket_index(ht, key);
    Entry *prev = NULL, *e = ht->buckets[idx];
    while (e) {
        if (e->key == key) {
            if (prev) prev->next = e->next;
            else ht->buckets[idx] = e->next;
            free(e);
            ht->num_entries--;
            return 1;
        }
        prev = e;
        e = e->next;
    }
    return 0;
}

/* ---------- Debug / inspection ---------- */

void lh_print(LinearHashTable *ht) {
    printf("LinearHashTable: level=%d next_to_split=%d num_buckets=%d num_entries=%d\n",
           ht->level, ht->next_to_split, ht->num_buckets, ht->num_entries);
    for (int i = 0; i < ht->num_buckets; i++) {
        printf("  bucket[%d]: ", i);
        for (Entry *e = ht->buckets[i]; e; e = e->next) {
            printf("(%d,%d) ", e->key, e->value);
        }
        printf("\n");
    }
}

/* ---------- Demo ---------- */

int main(void) {
    LinearHashTable *ht = lh_create(4, 0.75);

    for (int i = 0; i < 20; i++) {
        lh_insert(ht, i, i * i);
    }

    lh_print(ht);

    int v;
    if (lh_search(ht, 13, &v))
        printf("Found key 13 -> value %d\n", v);

    lh_delete(ht, 13);
    if (!lh_search(ht, 13, &v))
        printf("Key 13 successfully deleted\n");

    lh_destroy(ht);
    return 0;
}
