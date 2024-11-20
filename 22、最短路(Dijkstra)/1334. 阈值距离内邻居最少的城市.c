#define maxn 101
#define edgeType int
#define inf INT_MAX

void initEdges(edgeType graph[maxn][maxn], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = inf;
        }
    }
}

void addEdge(edgeType graph[maxn][maxn], int u, int v, edgeType w) {
    if (graph[u][v] == inf || w < graph[u][v]) {
        graph[u][v] = w;
    }
}

void dijkstra(edgeType graph[maxn][maxn], int n, int s, edgeType dist[maxn]) {
    bool visited[maxn];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        dist[i] = inf;
    }
    // dist[i]   s -> i
    dist[s] = 0;

    while (1) {
        edgeType minDist = inf;
        int minIndex;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            if (minDist == inf || dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        if (minDist == inf) {
            break;
        }
        visited[minIndex] = true;
        //   s ->  minIndex   +  graph[minIndex][i]

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            int dis = graph[minIndex][i];
            if (dis == inf) {
                continue;
            }
            if (dist[i] == inf || dist[minIndex] + dis < dist[i]) {
                dist[i] = dist[minIndex] + dis;
            }
        }
    }
}

edgeType graph[maxn][maxn];

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    initEdges(graph, n);
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        edgeType w = edges[i][2];
        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w);
    }
    int retIdx = -1;
    int retCnt = 100000;
    for (int i = n - 1; i >= 0; --i) {
        int dist[maxn];
        int cnt = 0;
        dijkstra(graph, n, i, dist);
        for (int j = 0; j < n; ++j) {
            if (dist[j] == inf) {
                continue;
            }
            if (dist[j] > distanceThreshold) {
                continue;
            }
            ++cnt;
        }
        if (cnt < retCnt) {
            retCnt = cnt;
            retIdx = i;
        }

    }

    return retIdx;
}