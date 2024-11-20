#include <stdio.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int x = a[i];
        int j;
        for (j = i - 1; j >= 0; --j) {
            if (x < a[j]) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
        }
        a[j + 1] = x;
    }
}
int main() {
    int a[] = { 7,6,5,4,3,1 };
    int size = sizeof(a) / sizeof(int);
    insertionSort(a, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
