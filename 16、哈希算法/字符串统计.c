#include <stdio.h>
#include <stdlib.h>

#define B 256
#define P 2011201401

int stringHash(char* s) {
    long long sum = 0;
    for (int i = 0; s[i]; ++i) {
        sum = (sum * B + s[i]) % P;
    }
    return sum;
}

char s[2000010];

#define maxn 10001
int hash[maxn];

void hashInsert(int x) {
    int y = x % maxn;
    while (1) {
        if (hash[y] == -1) {
            hash[y] = x;
            return;
        }
        else if (hash[y] == x) {
            return;
        }
        y += 1;
        if (y >= maxn) {
            y = 0;
        }
    }
}

int main(int argc, char* argv[])
{
    int n;
    memset(hash, -1, sizeof(hash));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int x = stringHash(s);
        hashInsert(x);
    }
    int cnt = 0;
    for (int i = 0; i < maxn; ++i) {
        if (hash[i] != -1) {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}