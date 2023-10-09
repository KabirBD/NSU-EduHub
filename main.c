// Header Section
#include <stdio.h>
#include <conio.h>

// Function to display a list of options and return the index of the selected option.
int showOption(char title[], char *options[], int n)
{
    int optnSelected[n], index = 0;
    char key;
    void display()
    {
        system("cls");
        for (int i = 0; i < n; i++)
            optnSelected[i] = 0;
        optnSelected[index] = 1;
        if (title[0] != '\0') // Check if title is not an empty string
            printf("%s\n", title);

        for (int i = 0; i < n; i++)
            printf("\t%c %s\n", (optnSelected[i] ? '>' : ' '), options[i]);
    }
    display();
    while ((key = getch()) != 13 && key != 32)
    {
        switch (getch())
        {
        case 72: // Up arrow
            if (index != 0)
                index--;
            else
                index = n - 1;
            display();
            break;
        case 80: // Down arrow
            if (index != (n - 1))
                index++;
            else
                index = 0;
            display();
            break;
        }
    };
    return index;
}

int main()
{
    do
    {
        // main manu options
        char *options[] = {"My information", "Tools", "Coure Advising", "Class Schedule", "Helpline", "About", "Exit"};
        int selected = showOption("Choose an option below:", options, 7);

        // check wich option selected
        if (selected == 0)
        {
            // What to do if my niformation selected
            char *infoList[] = {"My department", "Completed Corses", "Currentl Enrolling Courses"};
            selected = showOption("View or Edit your information:", infoList, 3);
            system("cls");
            printf("You choose: %s", infoList[selected]);
        }
        else if (selected == 1)
        {
            // What to do if tools selected
            char *toolsList[] = {"CGPA calculator", "Converters", "Problem Solvers"};
            selected = showOption("View or Edit your information:", toolsList, 3);
            system("cls");
            printf("You choose: %s", toolsList[selected]);
        }
        else if (selected == 2)
        {
            // What to do if Course Advising selected
            system("cls");
            printf("You choose: %s", options[selected]);
            printf("\nYou can see which courses are available to you to take in the next semester");
        }
        else if (selected == 3)
        {
            // What to do if Class Schedule selected
            system("cls");
            printf("You choose: %s", options[selected]);
        }
        else if (selected == 4)
        {
            // What to do if Helpline selected
            system("cls");
            printf("\nHelpline Numbers:");
            printf("\n\tZarraf Rahman");
            printf("\n\tZarraf Rahman");
            printf("\n\tZarraf Rahman");
            printf("\n\tZarraf Rahman");
            printf("\n\tZarraf Rahman");
            printf("\n\tZarraf Rahman");
            printf("\n\tZarraf Rahman");
        }
        else if (selected == 5)
        {
            // if about selected
            system("cls");
            printf("\n\n\nVersion: 1.0.0");
            printf("\nDeveloper: ");
            printf("\n\tMd. Kabir Hosen");
            printf("\n\tZarraf Rahman");
            printf("\n\tMd. Hasibul Hasan Sarker");
            printf("\nWebsite: https://nsueduhub.com\n\n\n");
        }
        else if (selected == 6)
        {
            // What to do if exit selected
            return 0;
        }

    } while (getch() != 27);
    return 0;
}
