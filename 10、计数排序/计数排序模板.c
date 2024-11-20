#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int* a, int n, int m) {
    int* count = (int*)malloc(sizeof(int) * (m + 1));
    memset(count, 0, sizeof(int) * (m + 1));
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }
    int s = 0;
    for (int v = 0; v <= m; ++v) {
        while (count[v]) {
            a[s++] = v;
            --count[v];
        }
    }
    free(count);
}

int main() {
    int a[] = { 7,6,5,4,3,1 };
    int size = sizeof(a) / sizeof(int);
    countingSort(a, size, 100);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
