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

int minimumDifference(int* nums, int numsSize, int k) {
    countingSort(nums, numsSize, 100000);
    int ret = 100000000;
    for (int i = 0; i + k - 1 < numsSize; ++i) {
        int l = i;
        int r = i + k - 1;
        if (nums[r] - nums[l] < ret) {
            ret = nums[r] - nums[l];
        }
    }
    return ret;
}