int pivotIndex(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        int middleIndex = i;
        int a = 0, b = 0;
        if (middleIndex)
            a = arr[middleIndex - 1];
        b = arr[n - 1] - arr[middleIndex];
        if (a == b) {
            return middleIndex;
        }
    }
    return -1;
}