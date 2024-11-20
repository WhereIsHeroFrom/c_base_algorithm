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

int max(int a, int b) {
    return a > b ? a : b;
}

int ans[maxn], dp[maxn];

int main(int argc, char* argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    initEdges(n);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        addEdge(u, v);
    }
    topoSort(n, ans);
    int ret = 0;
    for (int i = n - 1; i >= 0; --i) {
        int u = ans[i];
        dp[u] = 0;
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;
            dp[u] = max(dp[u], dp[v] + 1);
        }
        ret = max(ret, dp[u]);
    }
    printf("%d\n", ret);

    return 0;
}