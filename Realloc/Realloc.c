#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define MAXBUF 512

void fatal (char *poruka) {
  fputs (poruka, stderr); fputs ("\n", stderr);
  exit (1);
}

int main () {
	FILE *du, *di;
	long *polje;
	char buf [MAXBUF+1];
	char* res;
	int i, n;

  if ((du = fopen ("stara.txt", "r")) == NULL)
		fatal ("Ne moze se otvoriti ulazna datoteka");

  n = 0; polje = NULL;
  do {
	  polje = (long *) realloc (polje, (n+1)*sizeof (long));
	  if (polje == NULL)  fatal ("Nedovoljno memorije");
	  polje[n] = ftell (du);
	  res = fgets(buf, MAXBUF, du);
	  printf("%d %ld %s", n, polje[n], res);
	  n++;
  } while (res != NULL);

  printf("\nn=%d\n", n);

  if ((di = fopen ("nova.txt", "w")) == NULL)
		fatal ("Ne moze se stvoriti izlazna datoteka");

  printf("\nUpisujem:\n");
  for (i = n-2; i >= 0; i--) {
		fseek (du, (long) polje[i], SEEK_SET);
		fgets (buf, MAXBUF, du);
		fputs (buf, di);
		printf("%s", buf);
	}
	free (polje);  fclose (du); fclose (di);
	return 0;
}

