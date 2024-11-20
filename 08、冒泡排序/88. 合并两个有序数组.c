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

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for (int i = 0; i < n; ++i) {
        nums1[m + i] = nums2[i];
    }
    bubbleSort(nums1, m + n);
}