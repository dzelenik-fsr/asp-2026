#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main (void) {

  short *p;

  p = (short *) malloc (sizeof(short));
  if (p == NULL) {
    fprintf(stderr, "Pogreška rezervacije memmorije\n");
    exit(0);
  }
  
  *p = 7;

  printf("\n1. p = %d", p);

  free((void*) p);

  printf("\n2. p = %d", p);
  p = NULL;

  // ...

  if (p == NULL)
     p = malloc (1000*sizeof(short));

  printf("\n3. p = %d", p);
  *p = 8;

  p = NULL;
  printf("\n4. p = %d", p);

  return 0;
}	