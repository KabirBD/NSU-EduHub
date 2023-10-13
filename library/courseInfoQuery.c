void courseInfoQuery()
{
    clr();
    printf("Enter course initial (Format: CSE115): ");
    char initial[10];
    scanf("%s", initial);
    int courseLenth = sizeof(coreCourses) / sizeof(coreCourses[0]);
    for (int i = 0; i < courseLenth; i++)
    {
        if (strcmp(coreCourses[i].initial, initial) == 0)
        {
            printf("\nName: %s", coreCourses[i].name);
            printf("\nCredit: %d", coreCourses[i].credit);
            printf("\nPre-requisites: %s\n\n", coreCourses[i].require);
            printWrap(coreCourses[i].description, 60);
        }
    }
}