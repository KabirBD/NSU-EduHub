void courseInfoQuery()
{
    char *trails[] = {"Not Selected", "Algorithms and Computation", "Software Engineering", "Networks", "Computer Architecture and VLSI", "Artificial Intelligence", "Bioinformatics"};

    void searchByInitial()
    {
        clr();
        colorPrint("\n Enter Course Initial (Format: cse115): ", "g");
        char initial[10];
        scanf("%s", initial);
        toUpperCase(initial);
        int courseLenth = sizeof(coreCourses) / sizeof(coreCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(coreCourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\n Course Name: ", "g");
                printf("%s", coreCourses[i].name);
                colorPrint("\n Course Type: ", "g");
                printf("Core Course");
                colorPrint("\n Credit: ", "g");
                printf("%.*f", needDeci(coreCourses[i].credit), coreCourses[i].credit);
                colorPrint("\n Pre-requisites: ", "g");
                printf("%s\n\n", analyseReq(coreCourses[i].require));
                colorPrint(" Description:\n", "g");
                printWrap(coreCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\n Source: http://ece.northsouth.edu/\n", "b");
                return;
            }
        }
        for (int trail = 1; trail <= 6; trail++)
        {
            getTrailCourses(trail);
            for (int i = 0; i < trailLnth; i++)
            {
                if (strcmp(trailCourses[i].initial, initial) == 0)
                {
                    n();
                    row(80);
                    colorPrint("\n\n Course Name: ", "g");
                    printf("%s", trailCourses[i].name);
                    colorPrint("\n Course Type: ", "g");
                    printf(trails[trail]);
                    colorPrint("\n Credit: ", "g");
                    printf("%.1f", trailCourses[i].credit);
                    colorPrint("\n Pre-requisites: ", "g");
                    printf("%s\n\n", trailCourses[i].require);
                    colorPrint(" Description:\n", "g");
                    printWrap(trailCourses[i].description, 80);
                    n();
                    row(80);
                    colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                    return;
                }
            }
        }
        colorPrint(" Couldn't find this initial.\n", "r");
        usleep(1000000);
        searchByInitial();
    }

    void searchByMatch()
    {
        clr();
        colorPrint("\n Enter Course Name Or Initial", "g");
        colorPrint(" (Support Partial Match): ", "c");
        int courseFound = 0;
        char input[100];
        char tempName[100];
        scanf("%s", input);
        toUpperCase(input);

        int courseLenth = sizeof(coreCourses) / sizeof(coreCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            strcpy(tempName, coreCourses[i].name);
            toUpperCase(tempName);
            if (strstr(tempName, input) || strstr(coreCourses[i].initial, input))
            {
                n();
                row(100);
                colorPrint("\n\n Course Name: ", "g");
                printf("%s", coreCourses[i].name);
                colorPrint("\n Initial: ", "g");
                printf("%s", coreCourses[i].initial);
                colorPrint("\n Course Type: ", "g");
                printf("Core Course");
                colorPrint("\n Credit: ", "g");
                printf("%.*f", needDeci(coreCourses[i].credit), coreCourses[i].credit);
                colorPrint("\n Pre-requisites: ", "g");
                printf("%s\n\n", analyseReq(coreCourses[i].require));
                colorPrint(" Description:\n", "g");
                printWrap(coreCourses[i].description, 100);
                n();
                courseFound++;
            }
        }
        for (int trail = 1; trail <= 6; trail++)
        {
            getTrailCourses(trail);
            for (int i = 0; i < trailLnth; i++)
            {
                strcpy(tempName, trailCourses[i].name);
                toUpperCase(tempName);
                if (strstr(tempName, input) || strstr(trailCourses[i].initial, input))
                {
                    n();
                    row(100);
                    colorPrint("\n\n Course Name: ", "g");
                    printf("%s", trailCourses[i].name);
                    colorPrint("\n Initial: ", "g");
                    printf("%s", trailCourses[i].initial);
                    colorPrint("\n Course Type: ", "g");
                    printf(trails[trail]);
                    colorPrint("\n Credit: ", "g");
                    printf("%.1f", trailCourses[i].credit);
                    colorPrint("\n Pre-requisites: ", "g");
                    printf("%s\n\n", trailCourses[i].require);
                    colorPrint(" Description:\n", "g");
                    printWrap(trailCourses[i].description, 100);
                    n();
                    courseFound++;
                }
            }
        }
        if (courseFound)
        {
            row(100);
            colorPrint("\n Results Found: ", "b");
            printf("%d\n\n\n", courseFound);
        }
        else
        {
            colorPrint(" No course matches\n\n\n", "r");
        }
    }

    char *option[] = {"Seach By Initial", "Deep Search", "Go Back"};
    switch (showOption("Select an option", option, 3))
    {
    case 0:
        searchByInitial();
        closeDialog();
        courseInfoQuery();
        break;
    case 1:
        searchByMatch();
        closeDialog();
        courseInfoQuery();
        break;
    }
}