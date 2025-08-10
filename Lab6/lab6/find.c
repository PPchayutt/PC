#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[301] = {0};
    char find;
    scanf("%[^\n]s", text);
    scanf(" %c", &find);

    int count = 0;
    int indices[301] = {0};
    int endindex = 0;

    for(int i = 0; i < 301; i++){
        if(text[i] == '\0'){
            break;
        }
        if(tolower(text[i]) == tolower(find)){
            count++;
            indices[i] = i + 1;
            endindex = i;
        }
    }
    if(count > 0){
        printf("There is/are %d \"%c\" in the above sentences.\n", count, find);
        printf("Position: ");
        for(int i = 0; i < 301; i++){
            if(indices[i] != 0){
                if(i != endindex) {
                    printf("%d, ", indices[i]);
                }
                else {
                    printf("%d", indices[i]);
                    break;
                }
            }
        }
    }
    else{
        printf("Not found.");
    }

    return 0;
}
