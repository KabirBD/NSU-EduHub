void courseInfoQuery()
{
    // clr();
    colorPrint("Enter course initial (Format: cse115): ", "g");
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
            printf("%.1f", coreCourses[i].credit);
            colorPrint("\nPre-requisites: ", "g");
            printf("%s\n\n", coreCourses[i].require);
            colorPrint("Description:\n", "g");
            printWrap(coreCourses[i].description, 80);
            n();
            row(80);
            colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
            courseFound = 1;
            break;
        }
    }
    if (!courseFound)
    {
        courseLenth = sizeof(algorithCourses) / sizeof(algorithCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(algorithCourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\nCourse Type: ", "g");
                printf("Algorithms and Computation");
                colorPrint("\nCourse Name: ", "g");
                printf("%s", algorithCourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", algorithCourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", algorithCourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(algorithCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                break;
            }
        }
    }
    if (!courseFound)
    {
        courseLenth = sizeof(softwareCourses) / sizeof(softwareCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(softwareCourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\nCourse Type: ", "g");
                printf("Software Engineering");
                colorPrint("\nCourse Name: ", "g");
                printf("%s", softwareCourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", softwareCourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", softwareCourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(softwareCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                break;
            }
        }
    }
    if (!courseFound)
    {
        courseLenth = sizeof(networkCourses) / sizeof(networkCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(networkCourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\nCourse Type: ", "g");
                printf("Networks");
                colorPrint("\nCourse Name: ", "g");
                printf("%s", networkCourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", networkCourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", networkCourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(networkCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                break;
            }
        }
    }
    if (!courseFound)
    {
        courseLenth = sizeof(architectureCourses) / sizeof(architectureCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(architectureCourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\nCourse Type: ", "g");
                printf("Computer Architecture and VLSI");
                colorPrint("\nCourse Name: ", "g");
                printf("%s", architectureCourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", architectureCourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", architectureCourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(architectureCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                break;
            }
        }
    }
    if (!courseFound)
    {
        courseLenth = sizeof(AICourses) / sizeof(AICourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(AICourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\nCourse Type: ", "g");
                printf("Artificial Intelligence");
                colorPrint("\nCourse Name: ", "g");
                printf("%s", AICourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", AICourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", AICourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(AICourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                break;
            }
        }
    }
    if (!courseFound)
    {
        courseLenth = sizeof(bioinformaticsCourses) / sizeof(bioinformaticsCourses[0]);
        for (int i = 0; i < courseLenth; i++)
        {
            if (strcmp(bioinformaticsCourses[i].initial, initial) == 0)
            {
                n();
                row(80);
                colorPrint("\n\nCourse Type: ", "g");
                printf("Bioinformatics");
                colorPrint("\nCourse Name: ", "g");
                printf("%s", bioinformaticsCourses[i].name);
                colorPrint("\nCredit: ", "g");
                printf("%.1f", bioinformaticsCourses[i].credit);
                colorPrint("\nPre-requisites: ", "g");
                printf("%s\n\n", bioinformaticsCourses[i].require);
                colorPrint("Description:\n", "g");
                printWrap(bioinformaticsCourses[i].description, 80);
                n();
                row(80);
                colorPrint("\nSource: http://ece.northsouth.edu/\n", "b");
                courseFound = 1;
                break;
            }
        }
    }
    if (!courseFound)
    {
        colorPrint(" Couldn't find this initial.", "r");
        usleep(1000000);
        clr();
        courseInfoQuery();
    }
}