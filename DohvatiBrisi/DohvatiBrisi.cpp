#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct zapis {
	int mbr;
	char ime[40 + 1];
	char spol[1 + 1];
};

struct zapis dohvati_brisi(FILE* direktna, int mbr) {  // funkcija vraæa dohvaæeni zapis
	struct zapis z, z1; // z je varijabla tipa 'struct zapis'
	z.mbr = 0;

	// TODO: nadopisi
	return z;
}

void kontrola(FILE* direktna) {
	struct zapis z;
	fseek(direktna, 0, SEEK_SET);
	while (fread(&z, sizeof(z), 1, direktna) == 1) {
		if (z.mbr > 0)
			printf("%3d %s %s\n", z.mbr, z.ime, z.spol);
	}
}

int main() {
	struct zapis z;
	int mbr, i;
	FILE* slijedna, * direktna;

	if (!(slijedna = fopen("studenti.txt", "r"))) {
		printf("\nNema ulazne dateke studenti.txt\n");
		return 1;
	}
	// Stvaranje direktne neformatirane datoteke iz slijedne formatirane 
	if (!(direktna = fopen("studenti.dat", "w+b"))) {
		printf("\nNe mogu otvoriti direktnu datoteku studenti.dat\n");
		fclose(slijedna);
		return 1;
	}

	// Pražnjenje direktne datoteke
	z.mbr = 0;
	for (i = 0; i <= 999; i++) fwrite(&z, sizeof(z), 1, direktna);

	// Prijepis iz slijedne formatirane u direktnu neformatiranu
	while (fscanf(slijedna, "%3d%s%s", &z.mbr, z.ime, z.spol) != EOF) {
		printf("Procitan zapis %d %s %s\n", z.mbr, z.ime, z.spol);
		fseek(direktna, (z.mbr - 1) * sizeof(struct zapis), SEEK_SET);
		fwrite(&z, sizeof(z), 1, direktna);
	}

	// Dohvat i brisanje
	while (1) {
		kontrola(direktna);
		printf("\nUpisite mbr >");
		scanf("%d", &mbr);
		if (mbr == 0)
			break;
		z = dohvati_brisi(direktna, mbr);
		if (z.mbr) {
			printf("Izbrisan zapis: %d %s %s\n", z.mbr, z.ime, z.spol);
		}
		else {
			printf("\nNema zapisa s mbr = %d\n", mbr);
		}
	}
	return 0;
}
