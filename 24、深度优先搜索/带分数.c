#include <stdio.h>
#include <stdlib.h>

#define maxn 10
int visited[maxn];
int N;
int ans;
int pow10[maxn] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
};


// 100 = 82 + 3546 / 197
//  N     x       y
//            z = 3546197
//                      
int count(int sum) {
    int ans = 0;
    for (int i = 8; i >= 0; --i) {
        int x = sum / pow10[i];
        if (N <= x) {
            break;
        }
        int y = N - x;
        int z = sum % pow10[i];
        for (int j = 1; ; ++j) {
            int fm = z % pow10[j];
            int fz = z / pow10[j];
            if (fz < fm) {
                break;
            }
            if (fz % fm == 0 && fz / fm == y) {
                ++ans;
            }
        }
    }
    return ans;
}

void dfs(int depth, int maxDepth, int sum) {
    if (depth == maxDepth) {
        ans += count(sum);
        return;
    }
    for (int i = 0; i < maxDepth; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(depth + 1, maxDepth, sum * 10 + (i + 1));
            visited[i] = 0;
        }
    }
}

int main(int argc, char* argv[])
{
    scanf("%d", &N);
    dfs(0, 9, 0);
    printf("%d\n", ans);
    return 0;
}