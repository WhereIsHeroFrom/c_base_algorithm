int findMiddleIndex(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        int middleIndex = i;
        int a = 0, b = 0;
        for (int j = 0; j < middleIndex; ++j) {
            a += arr[j];
        }
        for (int j = middleIndex + 1; j < n; ++j) {
            b += arr[j];
        }
        if (a == b) {
            return middleIndex;
        }
    }
    return -1;
}