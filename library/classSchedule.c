#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 100

// Define the struct to store class information
struct Class {
    char name[50];
    char date[50];
    char time[50];
};

// Declare an array of structs to store classes
struct Class classSchedule[MAX_CLASSES];
int classCount = 0;

// Function to add a new class
void addClass() {
    if (classCount < MAX_CLASSES) {
        printf("\nEnter class name: ");
        scanf("%s", classSchedule[classCount].name);
        while (getchar() != '\n');

        printf("Enter class date (DD/MM/YYYY): ");
        scanf("%s", classSchedule[classCount].date);

        // Date validation
        while (strlen(classSchedule[classCount].date) != 10 || 
               classSchedule[classCount].date[2] != '/' ||
               classSchedule[classCount].date[5] != '/') {
            printf("Invalid date format. Please enter in DD/MM/YYYY format: ");
            scanf("%s", classSchedule[classCount].date);
            while (getchar() != '\n');
        }

        printf("Enter class time: ");
        scanf("%s", classSchedule[classCount].time);
        while (getchar() != '\n');

        classCount++;
        
        printf("\n\033[32mClass added successfully!\033[0m\n");
    } else {
        printf("Class schedule is full. Cannot add more classes.\n");
    }
}




// Function to view all classes sorted by date
void viewAllClasses() {
    if (classCount == 0) {
        printf("\n\033[34mNo classes to display.\033[0m\n");
        return;
    }

    // Sort classes by date
    for (int i = 0; i < classCount - 1; i++) {
        for (int j = 0; j < classCount - i - 1; j++) {
            // Compare the dates of adjacent classes
            if (strcmp(classSchedule[j].date, classSchedule[j + 1].date) > 0) {
                // Swap the classes if they are out of order
                struct Class temp = classSchedule[j];
                classSchedule[j] = classSchedule[j + 1];
                classSchedule[j + 1] = temp;
            }
        }
    }

    // Display all classes
    printf("\n\033[34mAll Classes:\033[0m\n");
    for (int i = 0; i < classCount; i++) {
        printf("\nName: %s\nDate: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].date, classSchedule[i].time);
    }
}





// Function to search for classes by name, date, or time
void searchClasses() {
    char searchQuery[50];
    printf("Enter search query (name, date, or time): ");
    scanf("%s", searchQuery);

    printf("\n\033[34mSearch Results:\033[0m\n");
    for (int i = 0; i < classCount; i++) {
        if (strstr(classSchedule[i].name, searchQuery) != NULL || strstr(classSchedule[i].date, searchQuery) != NULL || strstr(classSchedule[i].time, searchQuery) != NULL) {
            printf("Name: %s\nDate: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].date, classSchedule[i].time);
        }
    }
}

// Function to update class information
void updateClass() {
    if (classCount == 0) {
        printf("No classes to update.\n");
        return;
    }

    printf("Select a class to update:\n");
    for (int i = 0; i < classCount; i++) {
        printf("%d. %s, %s, %s\n", i + 1, classSchedule[i].name, classSchedule[i].date, classSchedule[i].time);
    }

    int choice;
    printf("\nEnter the number of the class to update (1-%d): ", classCount);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= classCount) {
        // Adjust the index for the array
        int index = choice - 1;

        printf("\nEnter updated class name: ");
        scanf("%s", classSchedule[index].name);

        while (getchar() != '\n'); // Clear the input buffer
        printf("Enter updated class date (DD/MM/YYYY): ");
        fgets(classSchedule[index].date, sizeof(classSchedule[index].date), stdin);
        classSchedule[index].date[strcspn(classSchedule[index].date, "\n")] = '\0';

        printf("Enter updated class time: ");
        fgets(classSchedule[index].time, sizeof(classSchedule[index].time), stdin);
        classSchedule[index].time[strcspn(classSchedule[index].time, "\n")] = '\0';

        printf("\n\033[34mClass information updated successfully!\033[0m\n");
    } else {
        printf("Invalid selection. Please enter a valid class number.\n");
    }
}


// Function to delete a class
void deleteClass() {
    if (classCount == 0) {
        printf("No classes to delete.\n");
        return;
    }

    printf("Select a class to delete:\n");
    for (int i = 0; i < classCount; i++) {
        printf("%d. %s, %s, %s\n", i + 1, classSchedule[i].name, classSchedule[i].date, classSchedule[i].time);
    }

    int choice;
    printf("\nEnter the number of the class to delete (1-%d): ", classCount);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= classCount) {
        // Adjust the index for the array
        int index = choice - 1;

        for (int i = index; i < classCount - 1; i++) {
            classSchedule[i] = classSchedule[i + 1];
        }
        classCount--;

        printf("\n\033[31mClass deleted successfully!\033[0m\n");
    } else {
        printf("Invalid selection. Please enter a valid class number.\n");
    }
}




// Function to export class information to a file
void exportClasses() {
    FILE *file = fopen("class_schedule.txt", "w");
    if (file == NULL) {
        printf("Error opening file for export.\n");
        return;
    }

    for (int i = 0; i < classCount; i++) {
        fprintf(file, "Name: %s\nDate: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].date, classSchedule[i].time);
    }

    fclose(file);
    printf("\n\033[34mClass schedule exported to 'class_schedule.txt'.\033[0m\n");
}




//Function to import class information from a file
void importClasses() {
    FILE *file = fopen("class_schedule.txt", "r");
    if (file == NULL) {
        printf("Error opening file for import.\n");
        return;
    }

    classCount = 0;

    // Use a loop to read multiple class entries
    while (classCount < MAX_CLASSES &&
           fscanf(file, "Name: %s\nDate: %s\nTime: %s\n", 
           classSchedule[classCount].name, classSchedule[classCount].date, classSchedule[classCount].time) == 3) {
        classCount++;
    }

    fclose(file);
    printf("\n\033[32mClass schedule imported from 'class_schedule.txt'.\033[0m\n");
}






// void manageClassSchedule() {
//     int choice;

//     clr();

//     while (1) {
//         printf("\n\033[32mClass Schedule Menu:\033[0m\n\n");
//         printf("1. Add Class\n");
//         printf("2. View All Classes\n");
//         printf("3. Search Classes\n");
//         printf("4. Update Class\n");
//         printf("5. Delete Class\n");
//         printf("6. Import Classes\n");
//         printf("7. Export Classes\n");
//         printf("8. Back to Main Menu\n\n");

//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 clr();
//                 addClass();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 2:
//                 clr();
//                 viewAllClasses();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 3:
//                 clr();
//                 searchClasses();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 4:
//                 clr();
//                 updateClass();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 5:
//                 clr();
//                 deleteClass();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 6:
//                 clr();
//                 importClasses();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 7:
//                 clr();
//                 exportClasses();
//                 closeDialog();
//                 manageClassSchedule();
//                 break;
//             case 8:
//                 displayMenu();

//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }
// }




void manageClassSchedule() {

    clr();

    char *options[] = {"Add Class", "View All Classes", "Search Classes", "Update Classes", "Delete Classes", "Import Classes", "Export Classes", "Back to Main Menu"};

    switch (showOption("Choose an option below:", options, 8)) {
        
        case 0:
            clr();
            addClass();
            closeDialog();
            manageClassSchedule();
            break;

        case 1:
            clr();
            viewAllClasses();
            closeDialog();
            manageClassSchedule();
            break;

        case 2:
            clr();
            searchClasses();
            closeDialog();
            manageClassSchedule();
            break; 

        case 3:
            clr();
            updateClass();
            closeDialog();
            manageClassSchedule();
            break;   

        case 4:
            clr();
            deleteClass();
            closeDialog();
            manageClassSchedule();
            break;

        case 5:
            clr();
            importClasses();
            closeDialog();
            manageClassSchedule();
            break;

        case 6:
            clr();
            exportClasses();
            closeDialog();
            manageClassSchedule();
            break;  

        case 7:
            clr();
            displayMenu();
    }
}





