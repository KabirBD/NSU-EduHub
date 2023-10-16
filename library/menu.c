int displayMenu()
{
    // What to do if my information selected
    void userInfoMenu()
    {
       
        printf("\n User Info"); //testing
        if (getch())
            ;
    };
    // What to do if tools selected
    void toolsMenu()
    {
        // another menu will be called (will be added later)
        printf("\n tools"); //testing
        
        if (getch())
            ;
    };
    // What to do if Course Advising selected
    void courseMenu()
    {
        // another menu will be called (will be added later)
        clr();
            courseInfoQuery(); //just for testing

        if (getch())
            ;
    };
    // What to do if Class Schedule selected
    void scheduleMenu()
    {
        // class routine functionality will be added later
        clr();
        printf("\n class schedule"); //testing
        if (getch())
            ;
    };
    // What to do if Helpline selected
    void helpline()
    {
        //temoprary code for testing
        system("cls");
        printf("\nHelpline Numbers:");
        printf("\n\tZarraf Rahman");

        if (getch())
            ;
    };
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

        printf("\n Press any key to go back... ");
        if (getch())
            displayMenu();
    };
    void exit(){
        //do nothing will act like exit functionality
    };

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