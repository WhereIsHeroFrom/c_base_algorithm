#include <stdio.h>
#include <stdlib.h>

#define maxn 1001
#define maxv 1001
#define inf 0
#define init 1
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return a || b;
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
    scanf("%d", &V);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        v[i] = 0;
    }
    Knapsack01(n, V, w, v, dp);
    int ans = 0;
    for (int i = V; i >= 0; --i) {
        if (dp[n][i] == init) {
            ans = V - i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}