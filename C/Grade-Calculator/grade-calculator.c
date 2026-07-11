#include <stdio.h>
#include <string.h>

int main(){

    printf("---GRADE CALCULATOR---\n");

    char subject[40];
    printf("What subject are you calculating your grade?: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0'; 

    int type;

    printf("Select subject type (1 for Laboratory, 2 for Lecture): ");
    scanf("%d", &type);

     float class_standing, exam, activities, quizzes, final_grade;

    if(type == 1){
        printf("\n--- Laboratory Grading ---\n");
        printf("Enter Activities score (0-100): ");
        scanf("%f", &activities);
        printf("Enter Exam score (0-100): ");
        scanf("%f", &exam);

        final_grade = (activities * 0.60) + (exam * 0.40);
        printf("\nFinal Grade for %s (Lab): %.2f\n", subject, final_grade);
    }
    else if(type == 2){
        printf("\n--- Lecture Grading ---\n");
        printf("Enter Quizzes score (0-100): ");
        scanf("%f", &quizzes);
        printf("Enter Class Standing (0-100): ");
        scanf("%f", &class_standing);
        printf("Enter Exam score (0-100): ");
        scanf("%f", &exam);
        
        final_grade = (quizzes * 0.30) + (class_standing * 0.30) + (exam * 0.40);
        printf("\nFinal Grade for %s (Lecture): %.2f\n", subject, final_grade);
    }
    else{
        printf("Error, please only input 1 or 2.\n");
    }


    return 0;
}
