#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

void ispisi(int A[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

// funkcija koja traži element u polju
// vraæa 1 ako se element nalazi u polju, a 0 inaèe
int trazi(int A[], int n, int trazeni) {
	int i;
	for (i = 0; i < n; i++) {
		if (trazeni == A[i])
			return 1;
	}
	return 0;
}

// funkcija koja traži element sortiranom u polju
// vraæa 1 ako se element nalazi u polju, a 0 inaèe
int trazis(int A[], int n, int trazeni) {
	int i;

	for (i = 0; i < n; i++) {
		if (A[i] == trazeni) return 1;
		if (A[i] > trazeni)  return 0;
	}
	return 0;
}

void sortiraj(int A[], int n) {   // sortiranje polja
	int i, j, pom;

	for (i = 0; i < n - 1; i++) {	// od prvog do predzadnjeg
		for (j = i; j < n; j++) {		// provjeri iza trenutnog
			if (A[i] > A[j]) {				// i zamijeni ga s manjim
				pom = A[i]; A[i] = A[j]; A[j] = pom;
			}
		}
	}
}

int main() {
	int A[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	int b, c;

	ispisi(A, sizeof(A) / sizeof(A[0]));

	printf("Upisite trazeni broj\n");
	scanf("%d2", &b);

	c = trazi(A, sizeof(A) / sizeof(A[0]), b);
	printf("Trazeni broj %d se ", b);
	if (!c) printf("ne ");
	printf("nalazi u nesortiranom polju A\n");


	sortiraj(A, sizeof(A) / sizeof(A[0]));
	ispisi(A, sizeof(A) / sizeof(A[0]));
	c = trazis(A, sizeof(A) / sizeof(A[0]), b);
	printf("Trazeni broj %d se ", b);
	if (!c) printf("ne ");
	printf("nalazi u sortiranom polju A\n");

	return 0;
}
