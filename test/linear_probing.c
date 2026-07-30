/*
 * Linear Probing implementation in C
 * ------------------------------------
 * Open-addressing hash table: on a collision, keep scanning forward
 * (wrapping around) through the array until an empty slot is found.
 * No linked lists — all entries live directly in one fixed-size array.
 */

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY   -1
#define DELETED -2

typedef struct {
    int key;
    int value;
    int status; /* EMPTY, DELETED, or OCCUPIED (any other value used as marker) */
} Slot;

typedef struct {
    Slot slots[TABLE_SIZE];
    int num_entries;
} HashTable;

/* ---------- Setup ---------- */

void ht_init(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->slots[i].status = EMPTY;
    }
    ht->num_entries = 0;
}

static int hash_fn(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

/* ---------- Insert ---------- */

int ht_insert(HashTable *ht, int key, int value) {
    if (ht->num_entries >= TABLE_SIZE) {
        printf("Table full, cannot insert key %d\n", key);
        return 0;
    }

    int idx = hash_fn(key);
    int start = idx;
    int first_deleted = -1;

    do {
        if (ht->slots[idx].status == EMPTY) {
            int target = (first_deleted != -1) ? first_deleted : idx;
            ht->slots[target].key = key;
            ht->slots[target].value = value;
            ht->slots[target].status = 1; /* OCCUPIED */
            ht->num_entries++;
            return 1;
        }
        if (ht->slots[idx].status == DELETED) {
            if (first_deleted == -1) first_deleted = idx; /* reuse tombstone */
        } else if (ht->slots[idx].key == key) {
            ht->slots[idx].value = value; /* update existing key */
            return 1;
        }
        idx = (idx + 1) % TABLE_SIZE; /* linear probe: step forward, wrap around */
    } while (idx != start);

    /* Looped all the way around without an empty slot, but a tombstone existed */
    if (first_deleted != -1) {
        ht->slots[first_deleted].key = key;
        ht->slots[first_deleted].value = value;
        ht->slots[first_deleted].status = 1;
        ht->num_entries++;
        return 1;
    }

    printf("Table full, cannot insert key %d\n", key);
    return 0;
}

/* ---------- Search ---------- */

int ht_search(HashTable *ht, int key, int *value_out) {
    int idx = hash_fn(key);
    int start = idx;

    do {
        if (ht->slots[idx].status == EMPTY) {
            return 0; /* empty slot means key can't be further along the probe chain */
        }
        if (ht->slots[idx].status != DELETED && ht->slots[idx].key == key) {
            if (value_out) *value_out = ht->slots[idx].value;
            return 1;
        }
        idx = (idx + 1) % TABLE_SIZE;
    } while (idx != start);

    return 0;
}

/* ---------- Delete ---------- */

int ht_delete(HashTable *ht, int key) {
    int idx = hash_fn(key);
    int start = idx;

    do {
        if (ht->slots[idx].status == EMPTY) {
            return 0;
        }
        if (ht->slots[idx].status != DELETED && ht->slots[idx].key == key) {
            ht->slots[idx].status = DELETED; /* tombstone, not EMPTY, to preserve probe chains */
            ht->num_entries--;
            return 1;
        }
        idx = (idx + 1) % TABLE_SIZE;
    } while (idx != start);

    return 0;
}

/* ---------- Debug / inspection ---------- */

void ht_print(HashTable *ht) {
    printf("HashTable (linear probing), num_entries=%d\n", ht->num_entries);
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->slots[i].status == EMPTY) {
            printf("  slot[%d]: empty\n", i);
        } else if (ht->slots[i].status == DELETED) {
            printf("  slot[%d]: <deleted>\n", i);
        } else {
            printf("  slot[%d]: (%d, %d)\n", i, ht->slots[i].key, ht->slots[i].value);
        }
    }
}

/* ---------- Demo ---------- */

int main(void) {
    HashTable ht;
    ht_init(&ht);

    int keys[] = {5, 15, 25, 7, 35, 6};
    for (int i = 0; i < 6; i++) {
        ht_insert(&ht, keys[i], keys[i] * 10);
    }
    ht_print(&ht);

    int v;
    if (ht_search(&ht, 25, &v))
        printf("Found key 25 -> value %d\n", v);

    ht_delete(&ht, 15);
    if (!ht_search(&ht, 15, &v))
        printf("Key 15 successfully deleted\n");

    /* Insert after delete should be able to reuse the tombstone slot */
    ht_insert(&ht, 45, 450);
    ht_print(&ht);

    return 0;
}
