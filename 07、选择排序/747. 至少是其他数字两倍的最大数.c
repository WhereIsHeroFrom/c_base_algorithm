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

int dominantIndex(int* nums, int numsSize) {
    int max = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }
    selectionSort(nums, numsSize);
    if (nums[numsSize - 1] >= 2 * nums[numsSize - 2]) {
        return max;
    }
    return -1;
}