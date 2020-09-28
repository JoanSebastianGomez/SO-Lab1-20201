#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    char *linea = argv[1];
    if (argc == 2)
    {
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        while ((read = getline(&line, &len, stdin)) != -1)
            {
                if (strstr(line, linea) != NULL)
                {
                    printf("%s", line);
                }
            }
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            while ((read = getline(&line, &len, fp)) != -1)
            {
                if (strstr(line, linea) != NULL)
                {
                    printf("%s", line);
                }
            }
            fclose(fp);
        }
    }

    return 0;
}