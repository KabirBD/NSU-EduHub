void courseInfoQuery()
{
    // clr();
    printf("Enter course initial (Format: cse115): ");
    int courseFound = 0;
    char initial[10];
    scanf("%s", initial);

    for (int i = 0; initial[i]; i++)
    {
        initial[i] = toupper((unsigned char)initial[i]);
    }
    int courseLenth = sizeof(coreCourses) / sizeof(coreCourses[0]);
    for (int i = 0; i < courseLenth; i++)
    {
        if (strcmp(coreCourses[i].initial, initial) == 0)
        {
            printf("\nName: %s", coreCourses[i].name);
            printf("\nCredit: %.1f", coreCourses[i].credit);
            printf("\nPre-requisites: %s\n\n", coreCourses[i].require);
            printWrap(coreCourses[i].description, 60);
            printf("Source: http://ece.northsouth.edu/\n");
            courseFound = 1;
            break;
        }
    }
    if (!courseFound)
    {
        printf("ERROR: Couldn't find this initial.\n\n");
        courseInfoQuery();
    }
}