#include <stdio.h>
#include <stdlib.h>

int slideWindow(int n, int k, int* a) {
    int i = 0, j = -1;
    int sum = 0;
    int ans = 0;
    while (j++ < n - 1) {
        sum += a[j];
        while (sum >= k) {
            ans += n - j;
            sum -= a[i];
            i++;
        }
    }
    return ans;
}

int main(int argc, char* argv[])
{
    int n, m, k;
    int a[2010];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] = (a[i] >= m ? 1 : 0);
    }
    int ans = slideWindow(n, k, a);
    printf("%d\n", ans);
    return 0;
}