#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main (void) {
  int polje[40] = {1,2,3,4};
  int *p;
  int i, n;
    
  printf("Velicina pokazivaca: %d\n", sizeof(p));
  printf("Velicina polja: %d\n", sizeof(polje));
  n = sizeof(polje) / sizeof(polje[0]);

  p = polje; 

  if (p == &polje[0]) 
    printf("Dokaz da je polje pokazivac:"); 

  for (i = 0; i < n; ++i) {
    printf ("\n%d = %d\ %d = %d", polje[i], *(p+i), &polje[i], p+i);
  }
  
  return 0;
}

