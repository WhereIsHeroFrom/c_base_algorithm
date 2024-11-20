#include <stdio.h>
#include <stdlib.h>

/* È«ÅÅÁÐÄ£°å
#define maxn 10
int visited[maxn];
int stack[maxn];

void dfs(int depth, int maxDepth) {
    if(depth == maxDepth) {
        return ;
    }
    for(int i = 0; i < maxDepth; ++i) {
        if(!visited[i]) {
            visited[i] = 1;
            stack[depth] = i;
            dfs(depth+1, maxDepth);
            visited[i] = 0;
        }
    }
}
*/

#define maxn 10
int visited[maxn];
int stack[maxn];

long long max = 0;
long long min = (long long)9876543210;

void dfs(int depth, int maxDepth, long long ans) {
    if (depth == maxDepth) {
        if (ans % 11 == 0) {
            if (ans > max) max = ans;
            if (ans < min) min = ans;
        }
        return;
    }
    if (depth == 1) {
        if (ans == 0) {
            return;
        }
    }
    for (int i = 0; i < maxDepth; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            stack[depth] = i;
            dfs(depth + 1, maxDepth, ans * 10 + i);
            visited[i] = 0;
        }
    }
}


int main(int argc, char* argv[])
{
    dfs(0, 10, 0);
    printf("%lld\n", max - min);
    return 0;
}