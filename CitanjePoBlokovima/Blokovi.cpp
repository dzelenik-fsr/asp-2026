#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOK 60
#define MJESTATXT "mjesta.txt"
#define MJESTADAT "mjesta.dat"

typedef struct {
	int pbr;
	char naziv[30];
	char opcina[30];
} zapmjesto;


int nadjiMjesto(char* naziv, zapmjesto* z) {
	FILE* f;
	zapmjesto zm;
	int podatak_nadjen = 0;
	int i;
	int brojacBlokova = 0, brojacuBloku = 0;

	if ((f = fopen(MJESTADAT, "rb")) == NULL) {
		printf("Greska: otvaranje datoteke!\n");
		exit(1);
	}

	//trazenje bloka	
	while (fread(&zm, sizeof(zm), 1, f)) {
		brojacBlokova++;
		//debug ispis
		printf("Blok: %d; vodeci zapis: %s, %d %s\n", brojacBlokova, zm.naziv, zm.pbr, zm.opcina);

		if (_stricmp(naziv, zm.naziv) < 0) {					// traŽeni je manji od vodećeg => mora biti u prethodnom bloku
			break;
		}
		else if (_stricmp(naziv, zm.naziv) == 0) { // traženi je jednak vodećem 
			podatak_nadjen = 1;
			break;
		}
		else // dohvati vodeći sljedećeg bloka 
			i = fseek(f, 1L * brojacBlokova * BLOK * sizeof(zm), SEEK_SET);
	}

	if (!podatak_nadjen) {

		if (!feof(f)) brojacBlokova -= 1; // pronaðen je zapravo u prethodnom bloku, osim ako smo na kraju
		//trazenje podatka u bloku
		printf("Podatak se mora nalaziti u bloku %d\n", brojacBlokova);

		fseek(f, 1L * (brojacBlokova - 1) * BLOK * sizeof(zm), SEEK_SET); //idemo na poèetak tog prethodnog
		i = 0;
		do {
			fread(&zm, sizeof(zm), 1, f);

			//debug ispis
			printf("Blok %d, zapis %d: %s, %d %s\n", brojacBlokova, i, zm.naziv, zm.pbr, zm.opcina);

			if (_stricmp(naziv, zm.naziv) == 0) {
				podatak_nadjen = 1;
			}
			i++;
		} while (i < BLOK && !podatak_nadjen && !feof(f));
	}

	fclose(f);

	*z = zm;
	return (podatak_nadjen);
}

void pripremi() {
	FILE* fi, * fo;
	zapmjesto zm;
	char pom[32];

	fi = fopen("mjesta.txt", "rt");
	fo = fopen(MJESTADAT, "w+b");
	if (!fi || !fo) exit(1);

	while (fscanf(fi, "%[^,],%[^,],%[^\n]", zm.naziv, pom, zm.opcina) == 3) {
		fgetc(fi);
		zm.pbr = atoi(pom);
		printf("%s %d %s\n", zm.naziv, zm.pbr, zm.opcina);
		if (fwrite(&zm, sizeof(zm), 1, fo) != 1)
			exit(0);
	}

	fclose(fi);
	fclose(fo);
}

int main() {
	zapmjesto zm;
	char trazi[30];

	pripremi();

	do {
		printf("Upisi naziv mjesta (k - kraj): ");
		gets_s(trazi, sizeof(trazi));
		if ((strcmp(trazi, "k") != 0))
			if (nadjiMjesto(trazi, &zm)) {
				printf("Trazeno mjesto:\n%d; %s; %s\n", zm.pbr, zm.naziv, zm.opcina);
			}
			else
				printf("Trazeno mjesto ne postoji!!\n");
	} while (strcmp(trazi, "k") != 0);

	return 0;
}
