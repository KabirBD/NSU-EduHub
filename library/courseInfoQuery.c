void courseInfoQuery()
{
    char *trails[] = {"Not Selected", "Algorithms and Computation", "Software Engineering", "Networks", "Computer Architecture and VLSI", "Artificial Intelligence", "Bioinformatics"};

    colorPrint("\n Enter course initial (Format: cse115): ", "g");
    int courseFound = 0;
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
            colorPrint("\n\nCourse Type: ", "g");
            printf("Core Course");
            colorPrint("\nCourse Name: ", "g");
            printf("%s", coreCourses[i].name);
            colorPrint("\nCredit: ", "g");
            printf("%.*f", needDeci(coreCourses[i].credit), coreCourses[i].credit);
            colorPrint("\nPre-requisites: ", "g");
            printf("%s\n\n", analyseReq(coreCourses[i].require));
            colorPrint("Description:\n", "g");
            printWrap(coreCourses[i].description, 80);
            n();
            row(80);
            colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
            courseFound = 1;
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
                colorPrint("\n\nCourse Type: ", "g");
                printf(trails[trail]);
                colorPrint("\nCourse Name: ", "g");
                printf("%s", trailCourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", trailCourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", trailCourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(trailCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                return;
            }
        }
    }

    colorPrint(" Couldn't find this initial.", "r");
    usleep(1000000);
    clr();
    courseInfoQuery();
}