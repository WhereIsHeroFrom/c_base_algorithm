#include <stdio.h>
#include <stdlib.h>


int n, a[100001];

int cmp(const void* pa, const void* pb) {
    int a = *(int*)pa;
    int b = *(int*)pb;
    return a < b ? -1 : 1;
}

int main(int argc, char* argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int l = 1;
    for (int r = 1; r < n; ++r) {
        if (a[r] != a[l - 1]) {
            a[l++] = a[r];
        }
    }
    int ret = 0;
    for (int i = 0; i + 2 < l; ++i) {
        int x = a[i];
        if (a[i + 1] == x + 1 && a[i + 2] == x + 2) {
            ++ret;
        }
    }
    printf("%d\n", ret);

    return 0;
}