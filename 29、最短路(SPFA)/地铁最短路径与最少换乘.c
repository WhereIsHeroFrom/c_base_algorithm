#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100001
#define maxm 400001
#define eType int
#define inf 1000000000
#define longOrShortPath <

typedef struct {
    int v;
    eType w;
    int next;
}EDGE;

int head[maxn];   // head[i] 代表第i个顶点链接的边链表的头节点编号
EDGE edges[maxm]; // edges[i] 代表第 i 条边
int edgeCount;

int q[6000000], front, rear;
int inqueue[maxn];   // inqueue[i] 代表当前元素 i 是否在队列中
eType dist[maxn];    // dist[i] 代表从起点到i这个点的最短路径估计值

void initEdges() {
    memset(head, -1, sizeof(head));
    edgeCount = 0;
}

void addEdge(int u, int v, eType w) {
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount;
    edgeCount++;
}

void SPFAInit(int n, int s) {
    for (int i = 0; i <= n; ++i) {
        dist[i] = (i == s ? 0 : inf);
        inqueue[i] = 0;
    }
    front = rear = 0;
    q[rear++] = s;
    inqueue[s] = 1;
}

void SPFAUpdate(int u) {
    for (int e = head[u]; ~e; e = edges[e].next) {
        int v = edges[e].v;
        eType w = edges[e].w;
        if (dist[u] + w longOrShortPath dist[v]) {
            dist[v] = dist[u] + w;
            if (!inqueue[v]) {
                q[rear++] = v;
                inqueue[v] = 1;
            }
        }
    }
}

void SPFA(int n, int s) {
    SPFAInit(n, s);
    while (front < rear) {
        int u = q[front++];
        inqueue[u] = 0;
        SPFAUpdate(u);
    }
}

int u[maxm], v[maxm], w[maxm];


int main(int argc, char* argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    int s, d;
    scanf("%d %d", &s, &d);

    initEdges();
    for (int i = 0; i < m; ++i) {
        addEdge(u[i], v[i], w[i]);
        addEdge(v[i], u[i], w[i]);
    }
    SPFA(n, s);
    if (dist[d] == inf) {
        dist[d] = -1;
    }
    printf("%d\n", dist[d]);

    initEdges();
    for (int i = 0; i < m; ++i) {
        addEdge(u[i], v[i], 1);
        addEdge(v[i], u[i], 1);
    }
    SPFA(n, s);
    if (dist[d] == inf) {
        dist[d] = -1;
    }
    printf("%d\n", dist[d]);

    return 0;
}