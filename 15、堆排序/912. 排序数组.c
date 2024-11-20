/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define eleType int
#define idType int
#define maxn 50000

idType lson(idType idx) {
    return 2 * idx + 1;
}
idType rson(idType idx) {
    return 2 * idx + 2;
}
idType parent(idType idx) {
    return (idx - 1) / 2;
}

bool better(eleType a, eleType b) {
    return a > b;
}

void swap(eleType* a, eleType* b) {
    eleType tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heapify(eleType* heap, int hSize, eleType curr) {
    idType lsonId = lson(curr);
    idType rsonId = rson(curr);
    idType optId = curr;
    if (lsonId < hSize && better(heap[lsonId], heap[optId]))
        optId = lsonId;
    if (rsonId < hSize && better(heap[rsonId], heap[optId]))
        optId = rsonId;
    if (optId != curr) {
        swap(&heap[curr], &heap[optId]);
        Heapify(heap, hSize, optId);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    for (int i = numsSize / 2; i >= 0; --i) {
        Heapify(nums, numsSize, i);
    }
    for (int i = numsSize - 1; i >= 0; --i) {
        swap(&nums[0], &nums[i]);
        Heapify(nums, i, 0);
    }
    *returnSize = numsSize;
    return nums;
}