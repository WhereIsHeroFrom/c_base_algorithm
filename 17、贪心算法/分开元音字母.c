#include <stdio.h>
#include <stdlib.h>

char s[100001];
char ret[300001];

int isYuanYin(char c) {
    return c == 'a' ||
        c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(int argc, char* argv[])
{
    scanf("%s", s);
    int size = 0;
    int cnt = 0;
    int flag = 0;
    ret[size++] = '(';
    for (int i = 0; s[i]; ++i) {
        if (isYuanYin(s[i])) {
            flag = 1;
            cnt++;
            if (cnt == 2) {
                ret[size++] = ')';
                ret[size++] = '(';
                cnt = 1;
            }
        }
        ret[size++] = s[i];
    }
    ret[size++] = ')';
    ret[size] = '\0';
    if (flag == 0)
        printf("%s\n", s);
    else
        printf("%s", ret);
    return 0;
}