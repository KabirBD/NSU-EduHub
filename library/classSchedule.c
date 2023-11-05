#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 100

struct Class {
    char name[50];
    char date[50];
    char time[50];
};

struct Class classSchedule[MAX_CLASSES];
int classCount = 0;


// Function to add a new class
void addClass() {
    if (classCount < MAX_CLASSES) {

        // Class name validation
        char inputClassName[10];
        int isValidClassName = 0;
        
        while (!isValidClassName) {
            printf("\nEnter class name: ");
            scanf("%s", inputClassName);
            while (getchar() != '\n');


            for (int i = 0; i < sizeof(coreCourses) / sizeof(coreCourses[0]); i++) {
                if (strcmp(inputClassName, coreCourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName); 
                    break;
                }
            }

            for (int i = 0; i < sizeof(algorithCourses) / sizeof(algorithCourses[0]); i++) {
                if (strcmp(inputClassName, algorithCourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName); 
                    break;
                }
            }

            for (int i = 0; i < sizeof(softwareCourses) / sizeof(softwareCourses[0]); i++) {
                if (strcmp(inputClassName, softwareCourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName); 
                    break;
                }
            }

            for (int i = 0; i < sizeof(networkCourses) / sizeof(networkCourses[0]); i++) {
                if (strcmp(inputClassName, networkCourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName); 
                    break;
                }
            }

            for (int i = 0; i < sizeof(architectureCourses) / sizeof(architectureCourses[0]); i++) {
                if (strcmp(inputClassName, architectureCourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName);
                    break;
                }
            }

            for (int i = 0; i < sizeof(AICourses) / sizeof(AICourses[0]); i++) {
                if (strcmp(inputClassName, AICourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName);
                    break;
                }
            }

            for (int i = 0; i < sizeof(bioinformaticsCourses) / sizeof(bioinformaticsCourses[0]); i++) {
                if (strcmp(inputClassName, bioinformaticsCourses[i].initial) == 0) {
                    isValidClassName = 1;
                    strcpy(classSchedule[classCount].name, inputClassName);
                    break;
                }
            }

            if (!isValidClassName) {
                printf("Invalid class name. Please enter a valid class name (e.g. CSE115, ENG102, etc.) ");
            }
        }



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




// Function to view all classes
void viewAllClasses() {
    if (classCount == 0) {
        printf("\n\033[34mNo classes to display.\033[0m\n");
        return;
    }

    printf("\n\033[34mAll Classes:\033[0m\n");
    for (int i = 0; i < classCount; i++) {
        printf("\nName: %s\nDate: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].date, classSchedule[i].time);
    }
}





// Function to search for classes by name, date, or time
void searchClasses() {
    char searchQuery[50];
    printf("Enter search query (class name, date, or time): ");
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
        int index = choice - 1;

        printf("\nEnter updated class name: ");
        scanf("%s", classSchedule[index].name);

        while (getchar() != '\n');
        printf("Enter updated class date (DD/MM/YYYY): ");
        scanf("%s", classSchedule[index].date);
        while (getchar() != '\n');

        printf("Enter updated class time: ");
        scanf("%s", classSchedule[index].time);
        while (getchar() != '\n');

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

    while (classCount < MAX_CLASSES &&
           fscanf(file, "Name: %s\nDate: %s\nTime: %s\n", 
           classSchedule[classCount].name, classSchedule[classCount].date, classSchedule[classCount].time) == 3) {
        classCount++;
    }

    fclose(file);
    printf("\n\033[32mClass schedule imported from 'class_schedule.txt'.\033[0m\n");
}





void manageClassSchedule() {

    clr();

    char *options[] = {"Add Class", "View All Classes", "Search Classes", "Update Classes", "Delete Classes", "Import Class Data", "Export Class Data", "Back to Main Menu"};

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





