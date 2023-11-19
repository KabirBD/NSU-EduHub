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

    // if about selected
    void about()
    {
        // About Page design (We sill move this code into a function later)
        clr();
        logo();
        printWrap("\n\n This is an all-in-one student assistant for BSCSE students of NSU. It tracks academic progress, showcases course information, provides personalized course suggestions, and includes tools for creating class schedules and calculating CGPA. It efficiently supports multiple users, facilitating seamless tracking of academic journeys for various users.\n\n", 64);
        tab();
        row(9);
        colorPrint(" Developers ", "y");
        row(9);
        colorPrint("\n\tZarraf Rahman", "c");
        printf("\n\t\t* User Authentication");
        printf("\n\t\t* Course Advisor");
        colorPrint("\n\tMd. Kabir Hosen", "c");
        printf("\n\t\t* Dashboard");
        printf("\n\t\t* Course Manager");
        colorPrint("\n\tMd. Hasibul Hasan Sarker", "c");
        printf("\n\t\t* Class Schedule");
        printf("\n\t\t* CGPA Insight");
        colorPrint("\n\n Version: ", "c");
        printf("1.0.0\n");
    }

    void exit(){
        // do nothing will act like exit functionality
    };

    // main menu options
    void mainMenu()
    {
        clr();
        char *options[] = {"Dashboard", "Course Manager", "Course Advisor", "Class Schedule", "CGPA Insight", "About", "Exit"};

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
        case 2: // 3
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
        case 6: // 7
            exit();
            break;
        };
    };
    mainMenu();
}
