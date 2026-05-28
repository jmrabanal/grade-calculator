#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//checks to see if the user is trying to send a stupid character instead of a number lol
float get_valid_float(const char* prompt) {
    char buffer[50];
    char *endptr;
    float value;
    while (true) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            value = strtof(buffer, &endptr);
            // Check if input was empty or not a number
            if (endptr != buffer && *endptr == '\n') {
                return value;
            }
        }
        printf("That's not a number, genius. Try again.\n");
    }
}

int main(){

    char subject[30];

    printf("What subject are you calculating your grade for?: ");
    fgets(subject, sizeof(subject), stdin);

    //lets the user input the percentages the different subcategories are worth for different subjects
    float worth1 = get_valid_float("Written work percentage\n (ex. 25% = 0.25): ");
    float worth2 = get_valid_float("Performance task percentage (ex. 50% = 0.50): ");
    float worth3 = get_valid_float("Exam percentage (ex. 25% = 0.25): ");

    //the different subcategories for getting grade
    float w_score = get_valid_float("Written Score: ");
    float w_total = get_valid_float("Written Total: ");

    float p_score = get_valid_float("Performance Task Score: ");
    float p_total = get_valid_float("Performance Task Total: ");

    float e_score = get_valid_float("Exam Score: ");
    float e_total = get_valid_float("Exam Total: ");

    //calculating the average
    float average = ((w_score / w_total) * 100 * worth1) + 
              ((p_score / p_total) * 100 * worth2) + 
              ((e_score / e_total) * 100 * worth3);
    printf("\nYour Average for %s is: %.2f%\n", subject, average);

    if (average >= 90) {
        printf("Your Grade is enough to be a DEAN LISTER, Congrats!\n");
    } else if (average >= 80) {
        printf("Your Grade is enough to pass.\n");
    } else {
        printf("Your Grade is failing, study more.\n");
    }
    
    return 0;
}
