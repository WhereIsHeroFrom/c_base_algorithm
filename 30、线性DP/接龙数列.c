#include <stdio.h>
#include <stdlib.h>

int dp[10];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char* argv[])
{
    int n;
    int m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int A;
        scanf("%d", &A);
        int r = A % 10;
        int l = r;
        while (A) {
            l = A % 10;
            A = A / 10;
        }
        dp[r] = max(dp[l] + 1, dp[r]);
        m = max(m, dp[r]);
    }
    printf("%d\n", n - m);
    return 0;
}