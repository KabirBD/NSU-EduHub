int displayMenu()
{
    // What to do if my information selected
    void userInfoMenu()
    {
        printf("\n User Info");
        // char *infoList[] = {"My department", "Completed Corses", "Currentl Enrolling Courses"};
        // selected = showOption("View or Edit your information:", infoList, 3);
        // system("cls");
        // printf("You choose: %s", infoList[selected]);
        if (getch())
            ;
    };
    // What to do if tools selected
    void toolsMenu()
    {
        printf("\n tools");
        // char *toolsList[] = {"CGPA calculator", "Converters", "Problem Solvers"};
        // selected = showOption("View or Edit your information:", toolsList, 3);
        // system("cls");
        // if (selected == 2)
        //     complex();
        // printf("You choose: %s", toolsList[selected]);
        if (getch())
            ;
    };
    // What to do if Course Advising selected
    void courseMenu()
    {
        // printf("\n course");
        // char *options[] = {"View All Courses Details", "Courses You Can Take in the Next Semester", "Courses You Can't Take"};
        // selected = showOption("Select any option:", options, 3);
        // switch (selected)
        // {
        // case 0:
        // {
        //     clr();
        //     courseInfoQuery();
        //     break;
        // }
        // default:
        // {
        //     printf("\n\t Invalid Option \n ");
        // }
        // }
        clr();
            courseInfoQuery();

        if (getch())
            ;
    };
    // What to do if Class Schedule selected
    void scheduleMenu()
    {
        system("cls");
        // printf("You choose: %s", options[selected]);
        if (getch())
            ;
    };
    // What to do if Helpline selected
    void helpline()
    {
        system("cls");
        printf("\nHelpline Numbers:");
        printf("\n\tZarraf Rahman");
        if (getch())
            ;
    };
    // if about selected
    void about()
    {
        // About Page design
        clr();
        logo();
        printf("\n\n Version: 1.0.0");
        printf("\n Developer: ");
        printf("\n\tZarraf Rahman");
        printf("\n\tMd. Kabir Hosen");
        printf("\n\tMd. Hasibul Hasan Sarker");
        printf("\n Website: https://nsueduhub.com\n\n\n");

        printf("\n Press any key to go back... ");
        if (getch())
            displayMenu();
    };
    void exit(){};

        // main menu options
    void mainMenu()
    {
        clr();
        char *options[] = {"My information", "Tools", "Course Advising", "Class Schedule", "Helpline", "About", "Exit"};

        switch (showOption("Choose an option below:", options, 7))
        {
        case 0:
            userInfoMenu();
            break;
        case 1:
            toolsMenu();
            break;
        case 2:
            courseMenu();
            break;
        case 3:
            scheduleMenu();
            break;
        case 4:
            helpline();
            break;
        case 5:
            about();
            break;
        case 6:
            exit();
            break;
        };
    };
    mainMenu();
}