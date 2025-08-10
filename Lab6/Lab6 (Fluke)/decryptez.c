#include <stdio.h>
#include <ctype.h>

int main(){
    char text[201] = {0};
    int key[] = {
        0, 1, 
        9, 11, 
        10, 20, 
        23, 17,
        25, 14,
        12, 13,
        7, 8,
        15, 4,
        5, 6,
        16, 18,
        19, 21,
        24, 2,
        3, 22
    };
    char wheel[] = {
        'a', 'b', 
        'x', 'y', 
        'p', 'q', 
        'r', 'm', 
        'n', 'c', 
        'e', 'd', 
        'k', 'l', 
        'j', 'o', 
        's', 'h', 
        't', 'u', 
        'f', 'v', 
        'z', 'g', 
        'w', 'i'
    };

    scanf("%[^\n]s", text);

    for(int i = 0; i < 201; i++){
        if(text[i] == '\0'){
            break;
        }
        if(text[i] != ' '){
            int wheelindex = key[tolower(text[i]) - 97] + 5;
            if(wheelindex > 25){
                wheelindex -= 26;
            }
            
            printf("%c", isupper(text[i]) ? toupper(wheel[wheelindex]) : wheel[wheelindex]);
        }
        else{
            printf("%c", text[i]);
        }
    }

    return 0;
}