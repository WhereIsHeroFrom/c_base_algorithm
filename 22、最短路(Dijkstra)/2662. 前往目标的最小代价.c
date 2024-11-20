long long point[402];
int pointSize;
#define base 100001

int findPoint(int x, int y) {
    long long p = (long long)x * base + y;
    for (int i = 0; i < pointSize; ++i) {
        if (p == point[i]) {
            return i;
        }
    }
    point[pointSize++] = p;
    return pointSize - 1;
}

#define maxn 402
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


int minimumCost(int* start, int startSize, int* target, int targetSize, int** specialRoads, int specialRoadsSize, int* specialRoadsColSize) {
    pointSize = 0;
    initEdges(graph, maxn);
    int s = findPoint(start[0], start[1]);
    int t = findPoint(target[0], target[1]);
    for (int i = 0; i < specialRoadsSize; ++i) {
        int u = findPoint(specialRoads[i][0], specialRoads[i][1]);
        int v = findPoint(specialRoads[i][2], specialRoads[i][3]);
        edgeType w = specialRoads[i][4];
        addEdge(graph, u, v, w);
    }
    for (int i = 0; i < pointSize; ++i) {
        int x1 = point[i] / base;
        int y1 = point[i] % base;
        for (int j = 0; j < pointSize; ++j) {
            int x2 = point[j] / base;
            int y2 = point[j] % base;
            addEdge(graph, i, j, abs(x1 - x2) + abs(y1 - y2));
        }
    }
    edgeType dist[maxn];
    dijkstra(graph, pointSize, s, dist);
    return dist[t];
}