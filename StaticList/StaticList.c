//
// Created by sdarshan on 7/14/26.
//
#include <stdio.h>
#include "StaticList.h"
#define SIZE 100

int list[SIZE];
int n = 0;
void insert(const int pos, const int value) {
    if (pos < 0 || pos > n || n == SIZE) {
        printf("Invalid position or overflow.\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = value;
    n++;
}
void delete(const int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        list[i] = list[i + 1];
    }
    n--;
}
void display() {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
