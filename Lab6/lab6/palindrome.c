#include <stdio.h>

int main(){
    char text[101];
    int endindex;
    for(int i = 0; i < 101; i++){
        text[i] = -1;
    }
    scanf("%[^\n]s", text);
    for(int i = 0; i < 101; i++){
        if(text[i] == '\0'){
            endindex = i;
        }
    }
    for(int i = 0; i < endindex; i++){
        if(text[i] != text[endindex - i - 1]){
            printf("It is not Palindrome.");
            return 0;
        }
    }
    printf("It is Palindrome.");
    return 0;
}