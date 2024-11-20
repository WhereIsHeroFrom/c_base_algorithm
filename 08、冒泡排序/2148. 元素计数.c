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
int countElements(int* nums, int numsSize) {
    bubbleSort(nums, numsSize);
    int cnt = 0;
    for (int i = 1; i < numsSize - 1; ++i) {
        if (nums[i] != nums[0] && nums[i] != nums[numsSize - 1]) {
            ++cnt;
        }
    }
    return cnt;
}