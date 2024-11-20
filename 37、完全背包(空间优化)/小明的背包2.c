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

void KnapsackComplete(int n, int V, int w[maxn], vType v[maxn], vType dp[maxv]) {
    dp[0] = init;
    for (int i = 1; i <= V; ++i) {
        dp[i] = inf;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = w[i]; j <= V; ++j) {
            dp[j] = opt(dp[j], dp[j - w[i]] + v[i]);
        }
    }
}

int w[maxn];
vType v[maxn];
vType dp[maxv];

int main(int argc, char* argv[]) {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }
    KnapsackComplete(n, V, w, v, dp);
    int ans = inf;
    for (int i = 0; i <= V; ++i) {
        ans = opt(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}