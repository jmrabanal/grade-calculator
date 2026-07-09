#include <stdio.h>
#include <string.h>

int main(){

    printf("---GRADE CALCULATOR---");

    char subject[40];
    printf("What subject are you calculating your grade?: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0'; 

    int type;

    printf("Select subject type (1 for Laboratory, 2 for Lecture): ");
    scanf("%d", &type);

     float class_standing, exam, activities, quizzes, final_grade;

    if(type == 1){
        printf("");
    }
    else{
        printf("");
    }

    printf("Your GWA for %s is: %0.2f", subject, class_standing);

    return 0;
}