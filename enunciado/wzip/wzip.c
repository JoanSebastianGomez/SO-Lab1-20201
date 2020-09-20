#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char c;
    char cAnterior;
    char primera = 1;
    int contador = 1;

    for (int i = 1; i < argc; i++)
    {

        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        c = fgetc(fp);

        while (c != EOF)
        {

            if (c == cAnterior)
            {

                contador = contador + 1;
            }
            else
            {
                if (primera != 1)
                {

                    fwrite(&contador, 1, sizeof(contador), stdout);
                    printf("%c", cAnterior);
                }

                contador = 1;
            }

            cAnterior = c;
            c = fgetc(fp);
            primera = 2;
        }

        fclose(fp);
    }
    fwrite(&contador, 1, sizeof(contador), stdout);
    printf("%c", cAnterior);
    return 0;
}