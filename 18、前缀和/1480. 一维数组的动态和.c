
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    ret[0] = nums[0];
    *returnSize = numsSize;
    for (int i = 1; i < numsSize; ++i) {
        ret[i] = ret[i - 1] + nums[i];
    }
    return ret;
}

// runningSum[i] = sum(nums[0]¡­nums[i])
//               =   sum(nums[0]¡­nums[i-1]) + nums[i]
//               = runningSum[i-1] + nums[i]
// runningSum[i-1] = sum(nums[0]¡­nums[i-1])



// ret[i] = ret[i-1] + nums[i]