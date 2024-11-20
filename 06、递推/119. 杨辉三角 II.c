/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int f[34][34];
    for (int i = 0; i <= rowIndex; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                f[i][j] = 1;
            }
            else {
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            }
        }
    }
    int* ret = (int*)malloc(sizeof(int) * (rowIndex + 1));
    for (int j = 0; j <= rowIndex; ++j) {
        ret[j] = f[rowIndex][j];
    }
    *returnSize = rowIndex + 1;
    return ret;
}

/*
1 0 0 0 0
1 1 0 0 0
1 2 1 0 0
1 3 3 1 0
1 4 6 4 1
*/