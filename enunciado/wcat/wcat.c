#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

for(int i=1; i<argc;i++){

  char c; 

  FILE *fp = fopen(argv[i], "r");
  if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
  }

  c = fgetc(fp); 
  while (c != EOF) 
  { 
      printf ("%c", c); 
      c = fgetc(fp); 
      } 
  fclose(fp);

} 

return 0; 
}