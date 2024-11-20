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


int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    edgeType dist[maxn];
    initEdges(graph, n);
    for (int i = 0; i < timesSize; ++i) {
        int u = times[i][0] - 1;
        int v = times[i][1] - 1;
        edgeType w = times[i][2];
        addEdge(graph, u, v, w);
    }
    dijkstra(graph, n, k - 1, dist);
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == inf) {
            return -1;
        }
        if (dist[i] > max) {
            max = dist[i];
        }
    }
    return max;
}


