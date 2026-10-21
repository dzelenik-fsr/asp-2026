#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
typedef int tip;
#define MAX 100

// binarno pretrazivanje polja a[] od n elemenata
// vraca indeks nadjenog elementa ili -1 ako trazeni ne postoji
int BinTraz(tip a[], tip x, int n, int* brojpokusaja) {
	int donji, srednji, gornji;	// granice podpolja koje se pretrazuje
	// inicijalizacija
	donji = 0; gornji = n - 1; *brojpokusaja = 0;

	while (donji <= gornji) {
		(*brojpokusaja)++;
		srednji = (donji + gornji) / 2;				// "prepolovi" (pod)polje
		printf("Trazim u a[%2d:%2d], a[%2d]=%2d\n",
			donji, gornji, srednji, a[srednji]);

		// TODO: nadopisi

	}
	return -1;										// nije nadjen
}

int main(void) {
	tip a[MAX], x;
	int i, n, brojpokusaja;
	FILE* fi;

	// citanje ulaznih podataka
	fi = fopen("UlazZaBinarnoPretrazivanje.txt", "r");

	for (n = 0; n < MAX && fscanf(fi, "%d", &a[n]) == 1; n++);
	printf("Broj clanova polja: %d\nClanovi:\n", n);

	for (i = 0; i < n; i++)
		printf("%d->%d ", i, a[i]);
	printf("\n");

	fclose(fi);

	// binarno trazenje
	while (1) {
		printf("Upisite trazenu vrijednost, -1 za kraj >");
		scanf("%d", &x);
		if (x == -1) return 0;
		i = BinTraz(a, x, n, &brojpokusaja);
		if (i < 0) {
			printf("Vrijednost %d nije pronadjena!\n"
				"Broj pokusaja:%d\n",
				x, brojpokusaja);
		}
		else {
			printf("Vrijednost %d pronadjena je na poziciji %d.\n"
				"Broj pokusaja:%d\n",
				x, i, brojpokusaja);
		}
	}
	return 0;
}
