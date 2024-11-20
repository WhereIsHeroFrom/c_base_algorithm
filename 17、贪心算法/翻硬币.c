#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1001], t[1001];
int main(int argc, char* argv[])
{
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            s[i] = (s[i] == 'o' ? '*' : 'o');
            s[i + 1] = (s[i + 1] == 'o' ? '*' : 'o');
            ++ret;
        }
    }
    printf("%d\n", ret);
    return 0;
}