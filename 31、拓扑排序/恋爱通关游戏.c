#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 200005
#define maxm 200005

typedef struct {
    int v;
    int w;
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

void addEdge(int u, int v, int w) {
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
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


int dp[maxn];
int ans[maxn];

int main(int argc, char* argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    initEdges(n);
    while (m--) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        --A, --B;
        addEdge(A, B, C);
    }

    topoSort(n, ans);
    int ret = 0;

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = -1000000000;
    }
    for (int i = 0; i < n; ++i) {
        int u = ans[i];
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;
            int w = edges[e].w;
            if (dp[u] + w > dp[v]) {
                dp[v] = dp[u] + w;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (head[i] == -1 && dp[i] >= 100) ++ret;
    }

    printf("%d\n", ret);
    return 0;
}