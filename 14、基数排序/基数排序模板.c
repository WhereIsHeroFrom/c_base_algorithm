#include <stdio.h>
#include <string.h>
#define MAXN 5005
#define MAXT 7
#define BASE 10

void RadixSort(int* a, int n) {
    int PowOfBase[MAXT];
    PowOfBase[0] = 1;
    for (int i = 1; i < MAXT; ++i) {
        PowOfBase[i] = PowOfBase[i - 1] * BASE;
    }
    int RadixBucket[BASE][MAXN];
    int RadixBucketTop[BASE];

    for (int i = 0; i < n; ++i) {
        a[i] += PowOfBase[MAXT - 1];
    }

    int pos = 0;
    while (pos < MAXT) {
        memset(RadixBucketTop, 0, sizeof(RadixBucketTop));
        for (int i = 0; i < n; ++i) {
            int rdx = a[i] / PowOfBase[pos] % BASE;
            RadixBucket[rdx][RadixBucketTop[rdx]++] = a[i];
        }
        int top = 0;
        for (int i = 0; i < BASE; ++i) {
            for (int j = 0; j < RadixBucketTop[i]; ++j) {
                a[top++] = RadixBucket[i][j];
            }
        }
        pos++;
    }
    for (int i = 0; i < n; ++i) {
        a[i] -= PowOfBase[MAXT - 1];
    }
}

int main() {
    int a[] = { 7,6,5,4,3,101,178,56,332,69,40,41,28 };
    int size = sizeof(a) / sizeof(int);
    RadixSort(a, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
