
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const char* p[3] = { "Ana", "Marko", "Ivo" };

    printf("%s\n", p[0]);
    printf("%c\n", *p[1]);
    printf("%c\n", *p[2]);

    return 0;
}
