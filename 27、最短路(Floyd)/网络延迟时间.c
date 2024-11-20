#define maxn 100
#define edgeType int
#define inf INT_MAX

void initEdges(edgeType f[maxn][maxn], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                f[i][j] = 0;
            }
            else {
                f[i][j] = inf;
            }
        }
    }
}

void addEdge(edgeType f[maxn][maxn], int u, int v, edgeType w) {
    if (w < f[u][v]) {
        f[u][v] = w;
    }
}

void FloyedWarshall(edgeType f[maxn][maxn], int n) {
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
                }
            }
        }
    }
}

edgeType f[maxn][maxn];

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    initEdges(f, n);
    for (int i = 0; i < timesSize; ++i) {
        int u = times[i][0] - 1;
        int v = times[i][1] - 1;
        edgeType w = times[i][2];
        addEdge(f, u, v, w);
    }
    FloyedWarshall(f, n);
    int max = 0;
    k = k - 1;
    for (int i = 0; i < n; ++i) {
        if (f[k][i] > max) {
            max = f[k][i];
        }
    }
    if (max == inf) max = -1;
    return max;
}