#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001];

int main(int argc, char* argv[])
{

    scanf("%s", s);
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            break;
        }
        i += 1;
        j -= 1;
    }
    if (i >= j) {
        printf("Y\n");
    }
    else {
        printf("N\n");
    }
    return 0;
}