#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slideWindow(int n, int* a) {
    int i = 0, j = -1;
    int count[1001] = { 0 };
    int need = 0, tot = 0;
    int min = n;
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
        if (count[a[i]] == 1) {
            need++;
        }
    }
    memset(count, 0, sizeof(count));
    while (j++ < n - 1) {
        count[a[j]]++;
        if (count[a[j]] == 1) {
            tot++;
        }
        while (tot == need) {
            // [i, j]
            if (j - i + 1 < min) {
                min = j - i + 1;
            }
            count[a[i]]--;
            if (count[a[i]] == 0) {
                tot--;
            }
            i += 1;
        }
    }
    return min;
}

int a[100001];

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = slideWindow(n, a);
    printf("%d\n", ans);
    return 0;
}