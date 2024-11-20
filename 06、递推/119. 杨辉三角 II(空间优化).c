/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int f[2][34];
    int now = 1, pre = 0;
    f[pre][0] = 1;

    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                f[now][j] = 1;
            }
            else {
                f[now][j] = f[pre][j] + f[pre][j - 1];
            }
        }
        now ^= 1;
        pre ^= 1;
    }
    int* ret = (int*)malloc(sizeof(int) * (rowIndex + 1));
    for (int j = 0; j <= rowIndex; ++j) {
        ret[j] = f[pre][j];
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