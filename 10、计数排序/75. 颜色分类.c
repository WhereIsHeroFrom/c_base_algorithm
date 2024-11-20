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

void sortColors(int* nums, int numsSize) {
    countingSort(nums, numsSize, 2);
}