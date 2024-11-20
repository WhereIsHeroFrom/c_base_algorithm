#include <stdio.h>

int isGreen(int* a, int index, int t) {
    return a[index] >= t;
}

// r r r r r g g g g g 
int bSearch(int* a, int n, int t) {
    int l = -1;
    int r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (isGreen(a, mid, t)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}

int main()
{
    int v[] = { 1,2,3,4,6,7,8,9,9,11 };
    int size = sizeof(v) / sizeof(int);
    printf("≥ -1的最小值的下标是：%d\n", bSearch(v, size, -1));
    printf("≥ 5的最小值的下标是：%d\n", bSearch(v, size, 5));
    printf("≥ 9的最小值的下标是：%d\n", bSearch(v, size, 9));
    printf("≥ 12的最小值的下标是：%d\n", bSearch(v, size, 12));
    return 0;
}