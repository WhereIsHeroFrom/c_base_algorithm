void bubbleSort(int* a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int lastStoneWeight(int* a, int n) {
    while (n > 1) {
        // 1. paixu
        bubbleSort(a, n);
        // 2. fensui
        int v = a[n - 1] - a[n - 2];
        n -= 2;
        // 3. fanghuiqu
        if (v != 0 || n == 0) {
            a[n] = v;
            n++;
        }
    }
    return a[0];
}