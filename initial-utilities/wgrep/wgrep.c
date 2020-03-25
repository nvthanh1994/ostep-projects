#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>



int get_length(char* term){
    int i = 0;
    while(term[i] != '\0'){
        ++i;
    }
    return i;
}


int find(char* line, char* term){
    int length = get_length(term);
    int len = get_length(line);
    
    //printf("%s %d %d %s", line, (int) len, length,  term);
    for(int i=0; i + length < len; i++){
        int found = 1;
        for(int j=0; j< length; j++ ){
            if(term[j] != line[i+j]){
                found = 0;
                break;
            }
        }
        if(found){
            return 1;
        }
    }
    return 0 ;
}

void grepFile(char* path, char* term)
{
    FILE *fp;
    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("%s", "wgrep: cannot open file\n");
        exit(1);
    }
    else
    {
        char *line = NULL;
        
        ssize_t read;
        size_t len;

        while ((read = getline(&line, &len, fp)) != -1)
        {
            //printf("%s", line);
            if(find(line, term)){
                printf("%s", line);
            }
        }

        free(line);
    }
}

int main(int argc, char *argv[])
{

    if(argc <=1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if (argc == 2)
    {
        char *term = argv[1];
        // Read from stdin 
        grepFile(stdin, term);
        exit(0);
    }

    // File 
    char *term = argv[1];
    for (int i = 2; i < argc; i++)
    {
        grepFile(argv[i], term);
    }

    return 0;
}