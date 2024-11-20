#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 10
int visited[maxn];
int stack[maxn];

char str[maxn + 1];
char sorted[maxn];

int ans, count;
void dfs(int depth, int maxDepth) {
    if (depth == maxDepth) {
        // stack 存储了 [0, maxDepth-1] 数组的全排列
        int i;
        for (i = 0; i < maxDepth; ++i) {
            int idx = stack[i];
            char c = sorted[idx];
            if (c != str[i]) {
                break;
            }
        }
        if (i == maxDepth) {
            ans = count;
        }
        ++count;
        return;
    }
    for (int i = 0; i < maxDepth; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            stack[depth] = i;
            dfs(depth + 1, maxDepth);
            visited[i] = 0;
        }
    }
}

int main(int argc, char* argv[])
{
    scanf("%s", str);
    int len = strlen(str);
    int hash[256];
    int idx = 0;
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < len; ++i) {
        hash[str[i]] = 1;
    }
    for (int i = 0; i < 256; ++i) {
        if (hash[i] == 1) {
            sorted[idx++] = (char)i;
        }
    }
    memset(visited, 0, sizeof(visited));
    dfs(0, len);
    printf("%d\n", ans);

    return 0;
}