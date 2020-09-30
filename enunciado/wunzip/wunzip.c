#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        char caracter;
        char valores[4];
        int contador = 1;
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        caracter = fgetc(fp);
        while (caracter != EOF)
        {
            if (contador == 5)
            {
                int x = (valores[3] << 24) | (valores[2] << 16) | (valores[1] << 8) | valores[0];
                for (int a = 0; a < x; a++)
                {
                    printf("%c", caracter);
                }
                contador=0;
            }
            else
            {
                valores[contador - 1] = caracter;
            }
            caracter = fgetc(fp);
            contador = contador + 1;
        }

        fclose(fp);
    }

    return 0;
}