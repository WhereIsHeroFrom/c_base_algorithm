// 0 1 2 3 4 5 6  7
// 1 2 3 4 6 7 8  5
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

double average(int* salary, int salarySize) {
    insertionSort(salary, salarySize);
    double sum = 0;
    for (int i = 1; i < salarySize - 1; ++i) {
        sum += salary[i];
    }
    return sum / (salarySize - 2);
}