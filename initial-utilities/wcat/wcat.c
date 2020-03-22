#include <stdio.h>
#include <stdlib.h>

// The readFile func read file from provided path char by char
// and print to stdout it's content
// finally close the file

#define BUFFER_SIZE 256
char buffer[BUFFER_SIZE];

void readFile(char *path)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("my-cat: cannot open file\n");
        return;
    }
    else
    {
        while (1)
        {
            char* c = fgets(buffer, BUFFER_SIZE, fp);
            if (c != NULL)
            {
                printf("%s", c);
            }
            else
            {
                break;
            }
        }
    }

    fclose(fp);
    return;
}

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        readFile(argv[i]);
    }

    return 0;
}