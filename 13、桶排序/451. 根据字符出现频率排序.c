#define ArrayType char

typedef struct Node {
    ArrayType v;
    struct Node* next;
}Node;

Node** bucketSort(ArrayType* a, int n, int max) {
    Node** bucket = (Node**)malloc(sizeof(Node*) * (n + 1));
    int* count = (int*)malloc(sizeof(int) * max);
    memset(count, 0, sizeof(int) * max);
    for (int i = 0; i <= n; ++i) {
        bucket[i] = NULL;
    }
    for (int i = 0; i < n; ++i) {
        ++count[a[i]];
    }
    for (int i = 0; i < max; ++i) {
        int cnt = count[i];
        Node* node = (Node*)malloc(sizeof(Node));
        node->v = i;
        node->next = NULL;
        // bucket[cnt]
        if (bucket[cnt] == NULL) {
            bucket[cnt] = node;
        }
        else {
            node->next = bucket[cnt];
            bucket[cnt] = node;
        }
    }
    free(count);
    return bucket;
}

void bucketFree(Node** bucket, int n) {
    for (int i = 0; i <= n; ++i) {
        Node* curr = bucket[i];
        while (curr) {
            Node* temp = curr->next;
            free(curr);
            curr = temp;
        }
    }
    free(bucket);
}

char* frequencySort(char* s) {
    char* ret = s;
    int n = strlen(s);
    Node** bucket = bucketSort(s, n, 256);
    for (int i = n; i > 0; --i) {
        Node* curr = bucket[i];
        while (curr) {
            for (int j = 0; j < i; ++j) {
                *(ret++) = curr->v;
            }
            curr = curr->next;
        }
    }
    bucketFree(bucket, n);
    return s;
}