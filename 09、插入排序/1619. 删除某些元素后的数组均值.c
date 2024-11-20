void insertionSort(int* a, int n) {
    for (int i = 1; i < n; ++i) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0) {
            if (x < a[j]) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
            j--;
        }
        a[j + 1] = x;
    }
}

double trimMean(int* arr, int n) {
    insertionSort(arr, n);
    double sum = 0;
    int cnt = 0;
    for (int i = n / 20; i < n - n / 20; ++i) {
        sum += arr[i];
        cnt++;
    }
    return sum / cnt;
}