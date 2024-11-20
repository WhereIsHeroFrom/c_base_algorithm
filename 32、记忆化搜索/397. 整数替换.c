#define maxn 1000000
int f[maxn];

int min(int a, int b) {
    return a < b ? a : b;
}

int integerReplacement(int n) {
    if (n == 1) {
        return 0;
    }
    if (n < maxn) {
        if (f[n]) {
            return f[n];
        }
    }
    int ans;
    if (n % 2 == 0) {
        ans = integerReplacement(n / 2) + 1;
    }
    else {
        ans = min(integerReplacement(n / 2 + 1) + 1, integerReplacement(n - 1)) + 1;
    }
    if (n < maxn) {
        f[n] = ans;
    }
    return ans;
}