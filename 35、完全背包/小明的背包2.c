#include <stdio.h>
#include <stdlib.h>

#define maxn 1001
#define maxv 1001
#define inf -1
#define init 0
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return a > b ? a : b;
}

void KnapsackComplete(int n, int V, int w[maxn], vType v[maxn], vType dp[maxn][maxv]) {
    for (int i = 1; i <= V; ++i) {
        dp[0][i] = inf;
    }
    dp[0][0] = init;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = inf;
            for (int k = 0; k <= j / w[i]; ++k) {
                dp[i][j] = opt(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
}

int n, V;
int w[maxn];
vType v[maxn];
vType dp[maxn][maxv];

int main(int argc, char* argv[])
{
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }
    KnapsackComplete(n, V, w, v, dp);
    int ans = inf;
    for (int i = 0; i <= V; ++i) {
        ans = opt(ans, dp[n][i]);
    }
    printf("%d\n", ans);

    return 0;
}