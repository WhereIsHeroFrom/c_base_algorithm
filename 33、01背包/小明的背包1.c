#include <stdio.h>
#include <stdlib.h>

// dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i])

#define maxn 101
#define maxv 1001
#define inf -1
#define init 0
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return a > b ? a : b;
}

void Knapsack01(int n, int V, int w[maxn], vType v[maxn], vType dp[maxn][maxv]) {
    // 1. ��ʼ��
    for (int i = 1; i <= maxv; ++i) {
        dp[0][i] = inf;
    }
    dp[0][0] = init;

    // 2. ״̬ת��
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= V; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = opt(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
}

int w[maxn];
vType v[maxn];
vType dp[maxn][maxv];


int main(int argc, char* argv[])
{
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }
    Knapsack01(n, V, w, v, dp);
    vType ret = 0;
    for (int i = 0; i <= V; ++i) {
        ret = opt(ret, dp[n][i]);
    }
    printf("%d\n", ret);

    return 0;
}