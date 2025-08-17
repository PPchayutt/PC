#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int size = 10;
    scanf("%d", &size);
    char names[size][60];
    for(int i = 0; i < size; i++){
        scanf(" %[^\n]", names[i]);
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 60; j++){
            if(names[i][j] == '\0'){
                break;
            }
            if(j == 0 || names[i][j - 1] == ' '){
                names[i][j] = toupper(names[i][j]);
            }
            else{
                names[i][j] = tolower(names[i][j]);
            }
        }
    }

    int del = 0;
    int minindex;

    while(del < size){
        minindex = 0;
        for(int i = 1; i < size; i++){
            if(names[i][0] == 0){
                continue;
            }
            if(names[minindex][0] == 0 || strcmp(names[i], names[minindex]) < 0){
                minindex = i;
            }
        }
        printf("%s\n", names[minindex]);
        names[minindex][0] = 0;
        del++;
    }

    return 0;
}