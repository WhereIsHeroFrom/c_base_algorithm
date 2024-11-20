int dp[1000][1000];

int dfs(char* s, int l, int r) {
    if (l > r) {
        return 1;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = 1;
    if (s[l] != s[r]) {
        dp[l][r] = 0;
    }
    else {
        dp[l][r] = dfs(s, l + 1, r - 1);
    }
    return dp[l][r];
}

int countSubstrings(char* s) {
    int n = strlen(s);
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        ++ans;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dp[i][j] == -1) {
                dp[i][j] = dfs(s, i, j);
            }
            if (dp[i][j] == 1) {
                ++ans;
            }
        }
    }
    return ans;
}