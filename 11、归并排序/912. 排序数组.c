/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int* a, int l, int m, int r) {
    int n1 = m - l + 1;  // a[l, m]
    int n2 = r - m;      // a[m+1, r]
    int temp[n1 + n2];
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

int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}