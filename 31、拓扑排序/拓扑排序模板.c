#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000005
#define maxm 1000005

typedef struct {
    int v;
    int next;
}EDGE;

int head[maxn];
EDGE edges[maxm];
int edgeCount;

void initEdges(int n) {
    for (int i = 0; i < n; ++i) {
        head[i] = -1;
    }
    edgeCount = 0;
}

void addEdge(int u, int v) {
    edges[edgeCount].v = v;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount;
    edgeCount++;
}

int deg[maxn];
int q[maxn], front, rear;
int topoSort(int n, int* ans) {
    int ansSize = 0;
    front = rear = 0;
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < n; ++i) {
        int u = i;
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;
            ++deg[v];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q[rear++] = i;
        }
    }
    while (front < rear) {
        int u = q[front++];
        ans[ansSize++] = u;
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;
            --deg[v];
            if (!deg[v]) {
                q[rear++] = v;
            }
        }
    }
    return ansSize == n;
}

int main(int argc, char* argv[])
{
    return 0;
}