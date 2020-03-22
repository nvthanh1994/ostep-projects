#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Cannot open the file\n");
        exit(1);
    }else{
        char c;
        while(1){
            c = fgetc(fp);
            if(c != EOF){
                printf("%c", c);
            }else{
                break;
            }
        }
    }

    fclose(fp);
    return 0;
}