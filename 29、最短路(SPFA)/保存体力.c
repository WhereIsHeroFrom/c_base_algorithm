#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define maxn 10001
#define maxm 200001
#define eType double
#define inf -1000000000
#define longOrShortPath >

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


int main(int argc, char* argv[])
{
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    initEdges();
    for (int i = 0; i < m; ++i) {
        int u, v;
        eType w;
        scanf("%d %d %lf", &u, &v, &w);
        w = log10(w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    SPFA(n, 1);
    if (dist[n] <= inf) {
        printf("-1\n");
    }
    else {
        double ans = t * pow(10, dist[n]);
        printf("%.8lf\n", ans);
    }

    return 0;
}