#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char *name;
    unsigned int id;
    float gpa;
};

void updated_gpa(struct Student *s, float new_gpa);

int main() {
    char input[100];
    float input_gpa;

    scanf("%[^\n]", input);
    scanf(" %f", &input_gpa);

    struct Student *opto = (struct Student*) malloc(sizeof(struct Student));

    opto->name = 


}
