/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isGreen(int* a, int index, int t) {
    return a[index] >= t;
}

// r r r r r g g g g g 
int bSearch(int* a, int n, int t) {
    int l = -1;
    int r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (isGreen(a, mid, t)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int idx = bSearch(nums, numsSize, target);
    if (idx == numsSize || nums[idx] != target) {
        ret[0] = ret[1] = -1;
        return ret;
    }
    ret[0] = idx;
    ret[1] = bSearch(nums, numsSize, target + 1) - 1;
    return ret;
}