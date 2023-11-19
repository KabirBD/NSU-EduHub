#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 100

struct Class
{
    char name[50];
    char day[50];
    char time[50];
};

struct Class classSchedule[MAX_CLASSES];
int classCount = 0;

// check input is a valid initial or not
int isValid(char initial[10])
{
    int found = 0;
    for (int i = 0; i < 54; i++)
    {

        if (strcmp(coreCourses[i].initial, initial) == 0)
        {
            found = 1;
            break;
        }
    }
    for (int trail = 1; trail <= 6; trail++)
    {
        getTrailCourses(trail);
        for (int i = 0; i < trailLnth; i++)
        {
            if (strcmp(trailCourses[i].initial, initial) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    return found;
}

// Function to add a new class
void addClass()
{
    if (classCount < MAX_CLASSES)
    {

        // Class name validation
        char initial[10];
        while (1)
        {
            printf("Enter course initial: ");
            scanf("%s", initial);
            toUpperCase(initial);
            if (!isValid(initial))
            {
                colorPrint("Enter a valid Initial", "r");
                usleep(1000000);
            }
            else
            {
                strcpy(classSchedule[classCount].name, initial);
                break;
            }
        }

        char inputDay[20];
        printf("Enter class day (ST, MW, or RA): ");
        scanf("%s", inputDay);
        toUpperCase(inputDay);
        // Day validation
        while (strcmp(inputDay, "ST") && strcmp(inputDay, "Mw") && strcmp(inputDay, "RA"))
        {
            printf("Invalid day format. Please enter ST, MW or RA: ");
            printf("Enter class day (ST, MW, or RA): ");
            scanf("%s", inputDay);
            toUpperCase(inputDay);
        }
        strcpy(classSchedule[classCount].day, inputDay);

        printf("Enter class time: ");
        scanf("%s", classSchedule[classCount].time);
        while (getchar() != '\n')
            ;

        classCount++;
        colorPrint("\nClass added successfully!\n", "g");
    }
    else
    {
        printf("Class schedule is full. Cannot add more classes.\n");
    }
}

// Function to view all classes
void viewAllClasses()
{
    if (classCount == 0)
    {
        colorPrint("No classes to display.\n", "g");
        return;
    }

    colorPrint("All Classes:\n", "g");
    for (int i = 0; i < classCount; i++)
    {
        printf("\nName: %s\nDate: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].day, classSchedule[i].time);
    }
}

// Function to search for classes by name, day, or time
void searchClasses()
{
    char searchQuery[50];
    char upperKey[50];
    char tempName[50];
    printf("Enter search query (class name, day, or time): ");
    scanf("%s", searchQuery);
    strcpy(upperKey, searchQuery);
    colorPrint("\nSearch Results:\n", "g");
    for (int i = 0; i < classCount; i++)
    {
        strcpy(tempName, classSchedule[i].name);
        toUpperCase(tempName);
        if (strstr(tempName, upperKey) || strstr(classSchedule[i].day, searchQuery) || strstr(classSchedule[i].time, searchQuery))
        {
            printf("Name: %s\nDay: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].day, classSchedule[i].time);
        }
    }
}

// Function to update class information
void updateClass()
{
    if (classCount == 0)
    {
        printf("No classes to update.\n");
        return;
    }

    printf("Select a class to update:\n");
    for (int i = 0; i < classCount; i++)
    {
        printf("%d. %s, %s, %s\n", i + 1, classSchedule[i].name, classSchedule[i].day, classSchedule[i].time);
    }

    int choice;
    printf("\nEnter the number of the class to update (Between 1-%d): ", classCount);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= classCount)
    {
        int index = choice - 1;

        printf("\nEnter updated class name: ");
        scanf("%s", classSchedule[index].name);

        while (getchar() != '\n')
            ;
        printf("Enter updated class day (ST, RA, MW): ");
        scanf("%s", classSchedule[index].day);
        while (getchar() != '\n')
            ;

        printf("Enter updated class time: ");
        scanf("%s", classSchedule[index].time);
        while (getchar() != '\n')
            ;

        colorPrint("\nClass information updated successfully!\n", "g");
    }
    else
    {
        printf("Invalid selection. Please enter a valid class number.\n");
    }
}

// Function to delete a class
void deleteClass()
{
    if (classCount == 0)
    {
        printf("No classes to delete.\n");
        return;
    }

    printf("Select a class to delete:\n");
    for (int i = 0; i < classCount; i++)
    {
        printf("%d. %s, %s, %s\n", i + 1, classSchedule[i].name, classSchedule[i].day, classSchedule[i].time);
    }

    int choice;
    printf("\nEnter the number of the class to delete (1-%d): ", classCount);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= classCount)
    {
        int index = choice - 1;

        for (int i = index; i < classCount - 1; i++)
        {
            classSchedule[i] = classSchedule[i + 1];
        }
        classCount--;

        colorPrint("\nClass deleted successfully!\n", "g");
    }
    else
    {
        printf("Invalid selection. Please enter a valid class number.\n");
    }
}

// Function to export class information to a file
void exportClasses()
{
    FILE *file = fopen("class_schedule.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file for export.\n");
        return;
    }

    for (int i = 0; i < classCount; i++)
    {
        fprintf(file, "Name: %s\nDay: %s\nTime: %s\n\n", classSchedule[i].name, classSchedule[i].day, classSchedule[i].time);
    }

    fclose(file);
    colorPrint("\nClass schedule exported to 'class_schedule.txt'.\n", "g");
}

// Function to import class information from a file
void importClasses()
{
    FILE *file = fopen("class_schedule.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for import.\n");
        return;
    }

    classCount = 0;

    while (classCount < MAX_CLASSES &&
           fscanf(file, "Name: %s\nDay: %s\nTime: %s\n",
                  classSchedule[classCount].name, classSchedule[classCount].day, classSchedule[classCount].time) == 3)
    {
        classCount++;
    }

    fclose(file);
    colorPrint("\nClass schedule imported from 'class_schedule.txt'.\n", "g");
}

void manageClassSchedule()
{

    clr();

    char *options[] = {"Add Class", "View All Classes", "Search Classes", "Update Classes", "Delete Classes", "Import Class Data", "Export Class Data", "Back to Main Menu"};

    switch (showOption("Choose an option below:", options, 8))
    {

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

    }
}
