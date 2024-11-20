#include <stdio.h>
#include <stdlib.h>

#define maxn 10001
#define mod 1000000007
int dp[maxn];
int a[maxn];

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        int max = 0;
        int min = 10000000;
        for (int j = i; j >= 1; --j) {
            if (a[j] > max) max = a[j];
            if (a[j] < min) min = a[j];
            if (max - min == i - j) {
                dp[i] += dp[j - 1];
                dp[i] %= mod;
            }
        }
    }
    printf("%d\n", dp[n]);


    return 0;
}