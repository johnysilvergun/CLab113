#include <stdio.h>

void stringcat(char src[], char dest[]) {
  int i,j = 0;
  while (dest[i]) i++;
  if (i > 0 && dest[i-1] == '\n') {
    i--; 
    dest[i] = '\0';
  }
  for (j = 0; src[j] && src[j] != '\n'; j++) {
    dest[i++] = src[j];
  }
  dest[i] = '\0';
}

int main()
{
  char in1[100],in2[100];

  printf("Input 1: ");
  fgets(in1, 100, stdin);
  printf("Input 2: ");
  fgets(in2, 100, stdin);
  stringcat(in1,in2);
  printf(" Output: ");
  printf("%s\n",in2);
  return 0;
}