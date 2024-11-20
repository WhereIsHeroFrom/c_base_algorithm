#define maxn 100010
#define maxm 200010

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

int reachableNodes(int n, int** e, int edgesSize, int* edgesColSize, int* restricted, int restrictedSize) {
    initEdges(n);
    int hash[maxn];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < restrictedSize; ++i) {
        hash[restricted[i]] = 1;
    }
    for (int i = 0; i < edgesSize; ++i) {
        int u = e[i][0];
        int v = e[i][1];
        if (hash[u] + hash[v] == 0) {
            addEdge(u, v);
            addEdge(v, u);
        }
    }
    bool v[maxm];
    bfs(n, 0, v);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i]) {
            ++ans;
        }
    }
    return ans;
}