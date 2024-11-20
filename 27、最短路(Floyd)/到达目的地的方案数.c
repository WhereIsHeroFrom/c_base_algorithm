#define maxn 200
#define edgeType long long
#define inf ((edgeType)1000000000 * 1000)
#define mod (1000000007)

void initEdges(edgeType f[maxn][maxn], edgeType c[maxn][maxn], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                f[i][j] = 0;
                c[i][j] = 1;
            }
            else {
                f[i][j] = inf;
                c[i][j] = 0;
            }
        }
    }
}

void addEdge(edgeType f[maxn][maxn], edgeType c[maxn][maxn], int u, int v, edgeType w) {
    if (w < f[u][v]) {
        f[u][v] = w;
        c[u][v] = 1;
    }
}

void FloyedWarshall(edgeType f[maxn][maxn], edgeType c[maxn][maxn], int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (f[i][k] == inf || f[k][j] == inf) {
                    continue;
                }
                if (k == i || k == j) {
                    continue;
                }
                if (f[i][k] + f[k][j] < f[i][j]) {
                    f[i][j] = f[i][k] + f[k][j];
                    c[i][j] = c[i][k] * c[k][j] % mod;
                }
                else if (f[i][k] + f[k][j] == f[i][j]) {
                    c[i][j] += c[i][k] * c[k][j] % mod;
                    if (c[i][j] >= mod) {
                        c[i][j] %= mod;
                    }
                }
            }
        }
    }
}

edgeType f[maxn][maxn];
edgeType c[maxn][maxn];

int countPaths(int n, int** roads, int roadsSize, int* roadsColSize) {
    initEdges(f, c, n);
    for (int i = 0; i < roadsSize; ++i) {
        int u = roads[i][0];
        int v = roads[i][1];
        edgeType w = roads[i][2];
        addEdge(f, c, u, v, w);
        addEdge(f, c, v, u, w);
    }
    FloyedWarshall(f, c, n);
    return c[0][n - 1];
}
