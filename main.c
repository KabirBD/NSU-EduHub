// Header Section
#include "library.h"

// main function
int main()
{
    clr();
    logo();

/*

    do
    {
        system("cls");
        // main manu options
        char *options[] = {"My information", "Tools", "Coure Advising", "Class Schedule", "Helpline", "About", "Exit"};
        int selected = showOption("Choose an option below:", options, 7);

        // check wich option selected
        if (selected == 0)
        {
            // What to do if my information selected
            char *infoList[] = {"My department", "Completed Corses", "Currentl Enrolling Courses"};
            selected = showOption("View or Edit your information:", infoList, 3);
            system("cls");
            printf("You choose: %s", infoList[selected]);
            if (getch())
                ;
        }
        else if (selected == 1)
        {
            // What to do if tools selected
            char *toolsList[] = {"CGPA calculator", "Converters", "Problem Solvers"};
            selected = showOption("View or Edit your information:", toolsList, 3);
            system("cls");
            if (selected == 2)
                complex();
            printf("You choose: %s", toolsList[selected]);
            if (getch())
                ;
        }
        else if (selected == 2)
        {
            // What to do if Course Advising selected
            char *options[] = {"View All Courses Details", "Courses You Can Take in the Next Semester", "Courses You Can't Take"};
            selected = showOption("Select any option:", options, 3);
            switch (selected)
            {
            case 0:
            {
                courseInfoQuery();
                break;
            }
            default:
            {
                printf("\n\t Invalid Option \n ");
            }
            }
            if (getch())
                ;
        }
        else if (selected == 3)
        {
            // What to do if Class Schedule selected
            system("cls");
            printf("You choose: %s", options[selected]);
            if (getch())
                ;
        }
        else if (selected == 4)
        {
            // What to do if Helpline selected
            system("cls");
            printf("\nHelpline Numbers:");
            printf("\n\tZarraf Rahman");
            if (getch())
                ;
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
            if (getch())
                ;
        }
        else if (selected == 6)
        {
            // What to do if exit selected
            break;
        }

    } while (0);
    */
    return 0;
}
