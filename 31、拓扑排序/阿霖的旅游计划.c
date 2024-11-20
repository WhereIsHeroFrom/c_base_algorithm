#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100005
#define maxm 2000005

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

int a[maxn];
int ans[maxn];
long long dp[maxn];

int main(int argc, char* argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    initEdges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        if (a[u] < a[v])
            addEdge(u, v);
        else if (a[v] < a[u])
            addEdge(v, u);
    }
    topoSort(n, ans);
    long long ret = 0;
    for (int i = n - 1; i >= 0; --i) {
        int u = ans[i];
        long long max = 0;
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;
            if (dp[v] > max) {
                max = dp[v];
            }
        }
        dp[u] = a[u] + max;
        if (dp[u] > ret) {
            ret = dp[u];
        }
    }
    printf("%lld\n", ret);

    return 0;
}