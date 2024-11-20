#include <stdio.h>

void bubbleSort(int* a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
int main() {
    int a[] = { 7,6,5,4,3,1 };
    int size = sizeof(a) / sizeof(int);
    bubbleSort(a, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
