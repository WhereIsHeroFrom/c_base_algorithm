#include <stdio.h>
#include <stdlib.h>

#define maxn 1001
#define maxm 100001
#define eType int
#define inf 1000000000

typedef struct {
    int u, v;
    eType w;
}EDGE;

int doRelax(int m, EDGE* edges, eType* dist) {
    int isRelax = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        eType w = edges[i].w;
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            isRelax = 1;
        }
    }
    return isRelax;
}

int bellmanford(int n, int m, EDGE* edges, int s, eType* dist) {
    for (int i = 0; i < n; ++i) {
        dist[i] = (i == s ? 0 : inf);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (!doRelax(m, edges, dist)) {
            return 0;
        }
    }
    return doRelax(m, edges, dist);
}

int n, m;
EDGE edges[maxm];
eType dist1[maxn], dist2[maxn];
int u[maxm], v[maxm], w[maxm];

int main(int argc, char* argv[])
{
    int x;
    scanf("%d %d %d", &n, &m, &x);
    --x;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        --u[i];
        --v[i];
    }
    for (int i = 0; i < m; ++i) {
        edges[i].u = u[i];
        edges[i].v = v[i];
        edges[i].w = w[i];
    }
    bellmanford(n, m, edges, x, dist1);

    for (int i = 0; i < m; ++i) {
        edges[i].u = v[i];
        edges[i].v = u[i];
        edges[i].w = w[i];
    }
    bellmanford(n, m, edges, x, dist2);

    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (dist1[i] + dist2[i] > max) {
            max = dist1[i] + dist2[i];
        }
    }
    printf("%d\n", max);

    return 0;
}