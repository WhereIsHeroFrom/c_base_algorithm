void insertionSort(int* a, int n) {
    for (int i = 1; i < n; ++i) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0) {
            if (x < a[j]) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
            j--;
        }
        a[j + 1] = x;
    }
}

int minimumDifference(int* nums, int numsSize, int k) {
    insertionSort(nums, numsSize);
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