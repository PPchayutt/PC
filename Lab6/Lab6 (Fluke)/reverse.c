#include <stdio.h>

int main()
{
    char text[101] = {0};
    int endindex = 101;
    scanf("%[^\n]s", text);
    for(int i = 0; i < 101; i++){
        if(text[i] == '\0'){
            endindex = i;
            break;
        }
    }
    for(int i = endindex - 1; i >= 0; i--){
        printf("%c", text[i]);
    }
    return 0;
}
