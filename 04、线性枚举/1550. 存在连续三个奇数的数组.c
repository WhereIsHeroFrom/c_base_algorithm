bool threeConsecutiveOdds(int* arr, int arrSize) {
    for (int i = 0; i + 2 < arrSize; ++i) {
        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[i + 2];
        if (a % 2 && b % 2 && c % 2) {
            return true;
        }
    }
    return false;
}