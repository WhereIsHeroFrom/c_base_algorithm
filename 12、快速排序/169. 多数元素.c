void Swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// l             r
// 2 1 3 7 5 9 8 5
//    i=j     
// x = 3
int Partition(int* a, int l, int r) {
    int idx = l + rand() % (r - l + 1);
    Swap(&a[l], &a[idx]);
    int i = l;
    int j = r;
    int x = a[i];
    while (i < j) {
        while (i < j && a[j] > x)
            j--;
        if (i < j)
            Swap(&a[i], &a[j]), i++;

        while (i < j && a[i] < x)
            i++;
        if (i < j)
            Swap(&a[i], &a[j]), --j;

    }
    //a[i] = x;
    return i;
}


// a[l:r]
void QuickSort(int* a, int l, int r) {
    if (l >= r) {
        return;
    }
    int pivox = Partition(a, l, r);
    QuickSort(a, l, pivox - 1);
    QuickSort(a, pivox + 1, r);
}

int majorityElement(int* nums, int numsSize) {
    QuickSort(nums, 0, numsSize - 1);
    return nums[numsSize / 2];
}