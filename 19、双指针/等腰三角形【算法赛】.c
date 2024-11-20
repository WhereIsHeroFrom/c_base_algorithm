#include <stdio.h>
#include <stdlib.h>

#define maxn 200001
int n;
int A[maxn], B[maxn], C[maxn];

int cmp(const void* pa, const void* pb) {
    int a = *(int*)pa;
    int b = *(int*)pb;
    return a < b ? -1 : 1;
}

int main(int argc, char* argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        C[i] = 2 * A[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
    }
    qsort(C, n, sizeof(int), cmp);
    qsort(B, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < n) {
        if (C[i] > B[j]) {
            j += 1;
            ans += 1;
        }
        i += 1;
    }
    printf("%d\n", ans);

    return 0;
}