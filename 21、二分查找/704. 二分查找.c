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

int search(int* nums, int numsSize, int target) {
    int idx = bSearch(nums, numsSize, target);
    if (idx == numsSize) {
        return -1;
    }
    if (nums[idx] != target) {
        return -1;
    }
    return idx;
}