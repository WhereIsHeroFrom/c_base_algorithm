/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* swapNumbers(int* a, int numbersSize, int* returnSize) {
    *returnSize = 2;
    a[0] = a[0] ^ a[1];  // Xa0 = a0 ^ a1
    a[1] = a[0] ^ a[1];  // Xa1 = Xa0 ^ a1 = a0 ^ a1 ^ a1 = a0 ^ 0 = a0
    a[0] = a[0] ^ a[1];  // XXa0 = Xa0 ^ Xa1 = a0 ^ a1 ^ a0 = a0 ^ a0 ^ a1 = 0 ^ a1 = a1
    return a;
}