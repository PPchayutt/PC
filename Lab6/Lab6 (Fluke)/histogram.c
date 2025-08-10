#include <stdio.h>
#include <ctype.h>

int main(){
    int num;
    char allc[26] = {0};
    int countc[26] = {0};
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        char c;
        scanf(" %c", &c);
        if(isupper(c)) c = tolower(c);
        for(int i = 0; i < 26; i++){
            if(allc[i] == c){
                countc[i] += 1;
                break;
            }
            if(allc[i] == 0){
                allc[i] = c;
                countc[i] += 1;
                break;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(allc[i] == 0){
            break;
        }
        printf("%c: %d\n", allc[i], countc[i]);
    }
    return 0;
}