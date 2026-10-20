#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_RED 10
#define MAX_STU 8

int main(void) {
    FILE* fi;
    int i, j, m, n, a[MAX_RED][MAX_STU];
    int* p;

    p = &a[0][0];
    fi = fopen("UlazZaDvodimenzionalnoPolje.txt", "r");
    if (!fi) {
        printf("Nema ulazne datoteke");
        return 1;
    }

    fscanf(fi, "%d %d\n", &m, &n);
    printf("Dimenzije: m=%d, n=%d\n", m, n);

    printf("Dvodimenzionalno Jednodimenzionalno\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fi, "%d", &a[i][j]);
            printf("a[%d][%d]=%3d \t a[%2d]\n", i, j, a[i][j], i * MAX_STU + j);
        }
    }
    fclose(fi);


    return 0;
}


