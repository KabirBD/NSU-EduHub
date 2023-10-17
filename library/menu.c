int displayMenu()
{

    // What to do if my information selected
    void userInfoMenu()
    {
        clr();
        printf("\n User Info"); // testing
    }


    // What to do if tools selected
    void toolsMenu()
    {
        // another menu of tools will be called (will be added later)
        clr();
        cgpaCalculator();
    }


    // What to do if Course Advising selected
    void courseMenu()
    {
        // another menu of course navigation will be called (will be added later)
        clr();
        courseInfoQuery(); // just for testing
    }


    // What to do if Class Schedule selected
    void scheduleMenu()
    {
        // class routine functionality will be added later
        clr();
        printf("\n Class schedule"); // testing
    }


    // What to do if Helpline selected
    void helpline()
    {
        // helpline page
        clr();
        printf("\nHelpline Numbers:");
        printf("\n\tZarraf Rahman");
    }

    // if about selected
    void about()
    {
        // About Page design (We sill move this code into a function later)
        clr();
        logo();
        printf("\n\n Version: 1.0.0");
        printf("\n Developer: ");
        printf("\n\tZarraf Rahman");
        printf("\n\tMd. Kabir Hosen");
        printf("\n\tMd. Hasibul Hasan Sarker");
        printf("\n Website: https://nsueduhub.com\n\n\n");
    }


    void exit(){
        // do nothing will act like exit functionality
    };


    void closeDialog()
    {
        printf("\nPress any key to go back ");
        if (getch())
            ;
    }


    // main menu options
    void mainMenu()
    {
        clr();
        char *options[] = {"My information", "Tools", "Course Advising", "Class Schedule", "Helpline", "About", "Exit"};

        switch (showOption("Choose an option below:", options, 7))
        {
        case 0:
            userInfoMenu();
            closeDialog();
            mainMenu();
            break;
        case 1:
            toolsMenu();
            closeDialog();
            mainMenu();
            break;
        case 2:
            courseMenu();
            closeDialog();
            mainMenu();
            break;
        case 3:
            scheduleMenu();
            closeDialog();
            mainMenu();
            break;
        case 4:
            helpline();
            closeDialog();
            mainMenu();
            break;
        case 5:
            about();
            closeDialog();
            mainMenu();
            break;
        case 6:
            exit();
            break;
        };
    };
    mainMenu();
}