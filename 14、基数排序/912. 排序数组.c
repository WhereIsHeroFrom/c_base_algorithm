/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

const int MAXN = 50005;
const int MAXT = 7;
const int BASE = 10;

void RadixSort(int* a, int n) {
    int PowOfBase[MAXT];
    PowOfBase[0] = 1;
    for (int i = 1; i < MAXT; ++i) {
        PowOfBase[i] = PowOfBase[i - 1] * BASE;
    }
    int RadixBucket[BASE][MAXN];
    int RadixBucketTop[BASE];

    for (int i = 0; i < n; ++i) {
        a[i] += PowOfBase[MAXT - 1];
    }

    int pos = 0;
    while (pos < MAXT) {
        memset(RadixBucketTop, 0, sizeof(RadixBucketTop));
        for (int i = 0; i < n; ++i) {
            int rdx = a[i] / PowOfBase[pos] % BASE;
            RadixBucket[rdx][RadixBucketTop[rdx]++] = a[i];
        }
        int top = 0;
        for (int i = 0; i < BASE; ++i) {
            for (int j = 0; j < RadixBucketTop[i]; ++j) {
                a[top++] = RadixBucket[i][j];
            }
        }
        pos++;
    }
    for (int i = 0; i < n; ++i) {
        a[i] -= PowOfBase[MAXT - 1];
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    RadixSort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}