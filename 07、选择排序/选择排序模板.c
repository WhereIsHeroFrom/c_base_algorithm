#include <stdio.h>

void selectionSort(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}
int main() {
    int a[] = { 7,6,5,4,3,1 };
    int size = sizeof(a) / sizeof(int);
    selectionSort(a, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
