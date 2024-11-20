#include <stdio.h>
#include <stdlib.h>

char S[1000010];

int main(int argc, char* argv[])
{
    int hash[256] = { 0 };
    scanf("%s", S);
    for (int i = 0; S[i]; ++i) {
        hash[S[i]]++;
    }
    int maxc = 0;
    char ret[256];
    int retSize = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (hash[c] > maxc) {
            maxc = hash[c];
            retSize = 0;
            ret[retSize++] = c;
        }
        else if (hash[c] == maxc) {
            ret[retSize++] = c;
        }
    }
    ret[retSize] = '\0';
    printf("%s\n", ret);

    return 0;
}