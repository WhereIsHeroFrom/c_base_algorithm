#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SB 1000000001
#define ll long long
#define maxn 100010
#define maxn2 (maxn*2)
int n;
int A[maxn];
int B[maxn];

ll hash[maxn2];
int cnt[maxn2];

void hashInsert(ll x) {
    int y = x % maxn2;
    while (1) {
        if (hash[y] == -1) {
            hash[y] = x;
            cnt[y] = 1;
            return;
        }
        else if (hash[y] == x) {
            cnt[y]++;
            return;
        }
        y++;
        if (y >= maxn2) {
            y = 0;
        }
    }
}

int hashGet(ll x) {
    int y = x % maxn2;
    while (1) {
        if (hash[y] == -1) {
            return 0;
        }
        else if (hash[y] == x) {
            return cnt[y];
        }
        y++;
        if (y >= maxn2) {
            y = 0;
        }
    }
    return -1;
}


int main(int argc, char* argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
    }
    // A[i] = B[j]
    // B[i] = A[j]
    // A[i]*SB + B[i] == B[j]*SB + A[j]
    memset(hash, -1, sizeof(hash));
    memset(cnt, 0, sizeof(cnt));

    ll ret = 0;
    for (int j = 0; j < n; ++j) {
        ll y = (ll)B[j] * SB + A[j];
        ret += hashGet(y);
        ll x = (ll)A[j] * SB + B[j];
        hashInsert(x);
    }
    printf("%lld\n", ret);
    return 0;
}