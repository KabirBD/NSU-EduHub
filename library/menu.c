int displayMenu()
{

    // What to do if Course Advising selected
    void courseMenu()
    {
        // another menu of course navigation will be called (will be added later)
        char *options[] = {"Courses List", "Search Course", "Courses You Can Enroll", "Go back"};
        switch (showOption("Select an option", options, 4))
        {
        case 0:
            clr();
            courseTable();
            closeDialog();
            courseMenu();
            break;
        case 1:
            clr();
            courseInfoQuery();
            courseMenu();
            break;
        case 2:
            clr();
            availableCourses();
            closeDialog();
            courseMenu();
            break;
        case 3:
            break;
        }
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

    // main menu options
    void mainMenu()
    {
        clr();
        char *options[] = {"Dashboard", "Course Manager","Course Advisor", "Class Schedule", "CGPA Insight", "About", "Exit"};

        switch (showOption("Choose an option below:", options, 7))
        {
        case 0: // 1
            dashboard();
            mainMenu();
            break;
        case 1: // 2
            courseMenu();
            mainMenu();
            break;
        case 2: //3
            courseAdvisor();
            mainMenu();
            break;
        case 3: // 4
            manageClassSchedule();
            mainMenu();
            break;
        case 4: // 5
            cgpaInsight();
            closeDialog();
            mainMenu();
            break;
        case 5: // 6
            about();
            closeDialog();
            mainMenu();
            break;
        case 6: //7
            exit();
            break;
        };
    };
    mainMenu();
}
