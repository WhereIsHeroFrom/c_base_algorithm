#define maxn 200010
#define maxm 400010

typedef struct {
    int v;
    int next;
}Edge;

Edge edges[maxm];
int edgeCount;
int head[maxn];

void initEdges() {
    edgeCount = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v) {
    edges[edgeCount].v = v;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount;
    edgeCount++;
}

void bfs(int n, int s, bool visited[maxn]) {
    int q[maxn];
    int front = 0;
    int rear = 0;
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    visited[s] = true;
    q[rear++] = s;

    while (front < rear) {
        int u = q[front++];
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;
            if (!visited[v]) {
                visited[v] = true;
                q[rear++] = v;
            }
        }
    }
}


bool validPath(int n, int** es, int edgesSize, int* edgesColSize, int source, int destination) {
    initEdges(n);
    for (int i = 0; i < edgesSize; ++i) {
        int u = es[i][0];
        int v = es[i][1];
        addEdge(u, v);
        addEdge(v, u);
    }
    bool v[maxn];
    bfs(n, source, v);
    return v[destination];
}