#include <stdio.h>
#include <ctype.h>

int main(){
    char name1[102];
    char name2[102];
    scanf(" %[^\n]", name1);
    scanf(" %[^\n]", name2);
    int length1 = 0;
    int length2 = 0;
    int isSame = 1;
    for(int i = 0; i < 102; i++){
        if(name1[i] == '\0'){ length1 = i; break;}
        if(isupper(name1[i])) {
            name1[i] = tolower(name1[i]);
        }
        else {
            name1[i] = toupper(name1[i]);
        }
    }
    for(int i = 0; i < 102; i++){
        if(name2[i] == '\0') { length2 = i; break;}
        if(isupper(name2[i])) {
            name2[i] = tolower(name2[i]);
        }
        else {
            name2[i] = toupper(name2[i]);
        }
    }
    if(length1 == length2){
        for(int i = 0; i < 102; i++){
            if(name1[i] != '\0'){
                if(tolower(name1[i]) != tolower(name2[i])){
                    isSame = 0;
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    else{
        isSame = 0;
    }
    printf("*** Results ***\n");
    printf("%s\n", name1);
    printf("%s\n", name2);
    printf("***************\n");
    if(isSame) printf("Both strings are the same.");
    else printf("Both strings are not the same.");
    
    return 0;
}