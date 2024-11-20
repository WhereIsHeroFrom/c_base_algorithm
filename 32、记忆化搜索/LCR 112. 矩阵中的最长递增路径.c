int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
int dp[200][200];


int dfs(int** matrix, int m, int n, int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    int len = 1;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx < 0 || ty < 0 || tx >= m || ty >= n) {
            continue;
        }
        if (matrix[tx][ty] <= matrix[x][y]) {
            continue;
        }
        if (dfs(matrix, m, n, tx, ty) + 1 > len) {
            len = dfs(matrix, m, n, tx, ty) + 1;
        }
    }
    dp[x][y] = len;
    return len;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    memset(dp, -1, sizeof(dp));
    int m = matrixSize;
    int n = matrixColSize[0];
    int len = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int v = dfs(matrix, m, n, i, j);
            if (v > len) {
                len = v;
            }
        }
    }
    return len;
}