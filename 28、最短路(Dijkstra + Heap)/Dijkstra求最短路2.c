#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************************/
/*****************************Dijkstra + Heap***************************/

#define ValueType int

typedef struct {
    int v;
    ValueType w;
    int next;
}Dist;

#define inf 2000000001
#define maxn 600001
#define eleType Dist
#define idType int

typedef struct {
    eleType data[maxn];
    idType size;
}Heap;


idType lson(idType idx) {
    return 2 * idx + 1;
}

idType rson(idType idx) {
    return 2 * idx + 2;
}

idType parent(idType idx) {
    return (idx - 1) / 2;
}

int better(eleType a, eleType b) {
    return a.w < b.w;
}

void swap(eleType* a, eleType* b) {
    eleType tmp = *a;
    *a = *b;
    *b = tmp;
}

void shiftUp(Heap* h, idType curr) {
    if (curr == 0) {
        return;
    }
    idType par = parent(curr);
    if (better(h->data[curr], h->data[par])) {
        swap(&h->data[curr], &h->data[par]);
        shiftUp(h, par);
    }
}

void shiftDown(Heap* h, idType curr) {
    idType lsonId = lson(curr);
    idType rsonId = rson(curr);
    idType optId = curr;
    if (lsonId < h->size && better(h->data[lsonId], h->data[optId])) {
        optId = lsonId;
    }
    if (rsonId < h->size && better(h->data[rsonId], h->data[optId])) {
        optId = rsonId;
    }
    if (curr != optId) {
        swap(&h->data[curr], &h->data[optId]);
        shiftDown(h, optId);
    }
}

void HeapInit(Heap* h) {
    h->size = 0;
}

void HeapPush(Heap* h, eleType value) {
    h->data[h->size++] = value;
    shiftUp(h, h->size - 1);
}

eleType HeapPop(Heap* h) {
    eleType ret = h->data[0];
    swap(&h->data[0], &h->data[h->size - 1]);
    --h->size;
    shiftDown(h, 0);
    return ret;
}

eleType HeapTop(Heap* h) {
    return h->data[0];
}

int HeapEmpty(Heap* h) {
    return h->size == 0;
}

#define maxm 400001

int head[maxn];
int edgeCount;
Dist edges[maxm];

void initEdges() {
    memset(head, -1, sizeof(head));
    edgeCount = 0;
}

void addEdge(int u, int v, ValueType w) {
    Dist* d = &edges[edgeCount];
    d->v = v;
    d->w = w;
    d->next = head[u];
    head[u] = edgeCount;
    edgeCount++;
}

void dijkstraInit(int n, int st, Heap* heap, int* visited, ValueType* d) {
    for (int i = 0; i < n; ++i) {
        d[i] = inf;
        visited[i] = 0;
    }
    d[st] = 0;
    HeapInit(heap);
    Dist dis = { st, d[st], -1 };
    HeapPush(heap, dis);

}

int dijkstraFindMin(Heap* heap) {
    Dist s = HeapTop(heap);
    HeapPop(heap);
    return s.v;
}

void dijkstraUpdate(int u, Heap* heap, int* visited, ValueType* d) {
    if (visited[u]) {
        return;
    }
    visited[u] = 1;
    for (int e = head[u]; e != -1; e = edges[e].next) {
        int v = edges[e].v;
        ValueType w = edges[e].w;
        if (d[u] + w < d[v]) {
            d[v] = d[u] + w;
            Dist dis = { v, d[v], -1 };
            HeapPush(heap, dis);
        }
    }
}

void DijkstraHeap(int n, int st, ValueType* d) {
    Heap heap;
    int visited[maxn] = { 0 };
    dijkstraInit(n, st, &heap, visited, d);
    while (!HeapEmpty(&heap)) {
        int u = dijkstraFindMin(&heap);
        dijkstraUpdate(u, &heap, visited, d);
    }
}

/***********************************************************************/

ValueType d[maxn];

int main(int argc, char* argv[]) {
    int n, m;
    initEdges();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u, --v;
        addEdge(u, v, w);
    }
    DijkstraHeap(n, 0, d);
    if (d[n - 1] == inf) {
        printf("-1\n");
    }
    else {
        printf("%d\n", d[n - 1]);
    }
    return 0;
}