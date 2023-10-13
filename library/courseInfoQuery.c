void courseInfoQuery()
{
    clr();
    printf("Enter course initial (cse115): ");
    char initial[10];
    scanf("%s", initial);
    int courseLenth = sizeof(courses) / sizeof(courses[0]);
    for (int i = 0; i < courseLenth; i++)
    {
        if (strcmp(courses[i].initial, initial) == 0)
        {
            printf("\nTitle: %s\n\n", courses[i].title);
            printWrap(courses[i].description, 60);
        }
    }
}