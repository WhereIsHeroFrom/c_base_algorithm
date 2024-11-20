#define maxn 1010
#define maxm 30010

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

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int n = roomsSize;
    initEdges();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < roomsColSize[i]; ++j) {
            addEdge(i, rooms[i][j]);
        }
    }
    bool v[maxn];
    bfs(n, 0, v);
    for (int i = 0; i < n; ++i) {
        if (v[i] == false) {
            return false;
        }
    }
    return true;
}