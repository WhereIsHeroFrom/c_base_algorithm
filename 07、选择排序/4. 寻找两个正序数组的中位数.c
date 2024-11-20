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

int a[2000];

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = 0;
    for (int i = 0; i < nums1Size; ++i) a[n++] = nums1[i];
    for (int i = 0; i < nums2Size; ++i) a[n++] = nums2[i];
    selectionSort(a, n);
    if (n % 2) {
        return a[n / 2];
    }
    return (a[n / 2 - 1] + a[n / 2]) / 2.0;
}