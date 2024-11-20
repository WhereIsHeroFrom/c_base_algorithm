int singleNonDuplicate(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    for (int i = 1; i < numsSize - 1; ++i) {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }
    if (nums[0] != nums[1]) {
        return nums[0];
    }
    return nums[numsSize - 1];
}