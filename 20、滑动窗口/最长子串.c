#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slideWindow(int n, int k, char* a) {
    int i = 0;
    int j = -1;
    int count[256] = { 0 };
    int max = 0;
    while (j < n - 1) {
        ++j;
        count[a[j]]++;
        while (count[a[j]] > k) {
            count[a[i]]--;
            i++;
        }
        // [i, j]
        int x = j - i + 1;
        if (x > max) {
            max = x;
        }
    }
    return max;
}

char s[100001];

int main(int argc, char* argv[])
{
    scanf("%s", s);
    int n = strlen(s);
    int k;
    scanf("%d", &k);
    int ans = slideWindow(n, k, s);
    printf("%d\n", ans);
    return 0;
}