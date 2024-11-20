#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[1000];

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    gets(a);
    int i = 0;
    int j = strlen(a) - 1;
    while (i < j) {
        char tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i += 1;
        j -= 1;
    }
    puts(a);
    return 0;
}