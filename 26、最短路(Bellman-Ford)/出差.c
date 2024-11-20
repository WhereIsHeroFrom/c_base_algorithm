#include <stdio.h>
#include <stdlib.h>

#define maxn 1001
#define maxm 20001
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

int n, e, m;
EDGE edges[maxm];
eType dist[maxn];
int c[maxn];

int main(int argc, char* argv[])
{
    scanf("%d %d", &n, &e);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    c[n - 1] = 0;
    m = 0;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[m].u = u - 1;
        edges[m].v = v - 1;
        edges[m].w = w + c[v - 1];
        m++;
        edges[m].u = v - 1;
        edges[m].v = u - 1;
        edges[m].w = w + c[u - 1];
        m++;
    }
    bellmanford(n, m, edges, 0, dist);
    printf("%d\n", dist[n - 1]);
    return 0;
}