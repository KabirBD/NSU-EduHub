#include <stdio.h>
#include <conio.h>

int main() {
    char password[20];
    int i = 0;
    char ch;

    printf("Enter password: ");

    while (1) {
        ch = getch();

        if (ch == 13) { // Enter key
            password[i] = '\0';
            break;
        } else if (ch == 8) { // Backspace key
            if (i > 0) {
                printf("\b \b"); // Move cursor back and overwrite with a space
                i--;
            }
        } else {
            password[i] = ch;
            i++;
            printf("*"); // Print asterisks for password characters
        }
    }
    printf("\nPassword entered: %s\n", password);

    return 0;
}
