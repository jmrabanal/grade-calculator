#include <stdio.h>
#include <string.h>

int main(){

    char subject[30] = "";
    float w_score, w_total, p_score, p_total, e_score, e_total;
    float worth1, worth2, worth3, average ;

    printf("What subject are you calculating your grade for?: ");
    fgets(subject, sizeof(subject), stdin);

    printf("How much percentage is the written work for the subject?\n (ex. 25%% = 0.25): ");
    scanf("%f", &worth1);

    printf("How much percentage is the performance task for the subject?\n (ex. 25%% = 0.25): ");
    scanf("%f", &worth2);

    printf("How much percentage is the exam for the subject?\n (ex. 25%% = 0.25): ");
    scanf("%f", &worth3);

    printf("Written: Enter [Your Score] [Total Possible]: ");
    scanf("%f %f", &w_score, &w_total);
    
    printf("Performance: Enter [Your Score] [Total Possible]: ");
    scanf("%f %f", &p_score, &p_total);
    
    printf("Exam: Enter [Your Score] [Total Possible]: ");
    scanf("%f %f", &e_score, &e_total);

    average = ((w_score / w_total) * 100 * worth1) + 
              ((p_score / p_total) * 100 * worth2) + 
              ((e_score / e_total) * 100 * worth3);
    printf("\nYour Average for %s is: %.2f\n", subject, average);

    if (average >= 90) {
        printf("Your Grade is enough to be a DEAN LISTER, Congrats!\n");
    } else if (average >= 80) {
        printf("Your Grade is enough to pass.\n");
    } else {
        printf("Your Grade is failing, study more.\n");
    }
    
    return 0;
}
