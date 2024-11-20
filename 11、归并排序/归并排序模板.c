#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int l, int m, int r) {
    int n1 = m - l + 1;  // a[l, m]
    int n2 = r - m;      // a[m+1, r]
    int* temp = (int*)malloc((n1 + n2) * sizeof(int));
    for (int i = 0; i < n1; ++i) {
        temp[i] = a[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        temp[n1 + j] = a[m + 1 + j];
    }
    int i = 0, j = n1, k = l;
    while (i < n1 && j < n1 + n2) {
        if (temp[i] <= temp[j]) {
            a[k++] = temp[i++];
        }
        else {
            a[k++] = temp[j++];
        }
    }
    while (i < n1) {
        a[k++] = temp[i++];
    }
    while (j < n1 + n2) {
        a[k++] = temp[j++];
    }
    free(temp);
}

void mergeSort(int* a, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int a[] = { 7,6,5,4,3,1 };
    int size = sizeof(a) / sizeof(int);
    mergeSort(a, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
