#include <stdio.h>
#include <stdlib.h>

#define maxn 101
#define inf -100000000
int dp[maxn][maxn];
int a[maxn];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;

    dp[1][0] = 0;
    dp[1][1] = a[1];

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(a[i] + dp[i - 2][j - 1], dp[i - 1][j]);
        }
    }

    printf("%d\n", dp[n][n / 2]);


    return 0;
}