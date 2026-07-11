#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
    char website[50];
    char username[50];
    char password[50];
};

void add_password();
void view_password();

int main(){

    int choice;

    while (1) {
        printf("----PASSWORD MANAGER----\n");
        printf("1. Add Password\n");
        printf("2. View All Passwords (Error will be given if you've never entered a password)\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You chose to add a password.\n"); 
            add_password();
        } 
        else if (choice == 2) {
            printf("You chose to view passwords.\n");
            view_password();
        } 
        else if (choice == 3) {
            printf("Exiting program. Goodbye!\n");
            break; 
        } 
        else {
            printf("Invalid choice! Please type 1, 2, or 3.\n");
        }
    }

    return 0;
}

void add_password() {
    getchar(); 

    struct Entry p;
    printf("What website/app is the password for?: ");

    fgets(p.website, sizeof(p.website), stdin);

    printf("Write your username: ");    
    fgets(p.username, sizeof(p.username), stdin);

    printf("Write your password: "); 
    fgets(p.password, sizeof(p.password), stdin);

    p.website[strcspn(p.website, "\n")] = '\0';
    p.username[strcspn(p.username, "\n")] = '\0';
    p.password[strcspn(p.password, "\n")] = '\0';

    FILE *file = fopen("passwords.txt", "a");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return; 
    }
    fprintf(file, "%s,%s,%s\n", p.website, p.username, p.password);

    fclose(file);
    
    printf("Successfully saved to passwords.txt!\n");
}

void view_password(){

    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- YOUR SAVED PASSWORDS ---\n");
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("----------------------------\n");

    fclose(file);

    printf("\nPress Enter to go back to the menu...");
    getchar();
    getchar();
}
