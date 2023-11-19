void availableCourses()
{
    char courseList[90][10];
    char thisUserFile[25];
    strcpy(thisUserFile, userName);
    strcat(thisUserFile, ".dat");

    struct courseInfo
    {
        char initial[10];
        char name[100];
        char grade[5];
        float credit;
    };
    struct userInfo
    {
        int semester;
        int trail;
        float completedCredit;
        float completingCredit;
        int numOfEnrolledCourses;
        struct courseInfo enrolledCourses[70];
        int numOfEnrollingCourses;
        struct courseInfo enrollingCourses[20];
    } thisUser;

    char *trails[] = {"Not Selected", "Algorithms and Computation", "Software Engineering", "Networks", "Computer Architecture and VLSI", "Artificial Intelligence", "Bioinformatics"};

    // Function to load user data from a file
    void loadUserData(const char *filename)
    {
        FILE *file = fopen(filename, "rb");
        if (file == NULL)
        {
            perror("Error opening file");
            thisUser.semester = 0;
            return;
        }

        // Read user data from the file
        fread(&courseList, sizeof(courseList), 1, file);
        fread(&thisUser, sizeof(struct userInfo), 1, file);

        fclose(file);
    }

    int foundInCompletedCurses(char givenInitial[10], int lnth)
    {
        int flag = 0;
        for (int i = 0; i < lnth; i++)
        {
            if (strcmp(thisUser.enrolledCourses[i].initial, givenInitial) == 0)
            {
                flag = 1;
                break; // Exit the loop when the match is found
            }
        }
        return flag;
    }

    // if given initial is found in enrolling courses list
    int foundInEnrollingCurses(char givenInitial[10], int lnth)
    {
        int flag = 0;
        for (int i = 0; i < lnth; i++)
        {
            if (strcmp(thisUser.enrollingCourses[i].initial, givenInitial) == 0)
            {
                flag = 1;
                break; // Exit the loop when the match is found
            }
        }
        return flag;
    }

    // check if requirement is fulfilled or not
    int checkRequire(char require[25])
    {
        if (strlen(require))
        {
            if (require[1] == '-')
            {
                char *hyphen = strchr(require, '-');
                int credit = atoi(hyphen + 1);
                if (thisUser.completedCredit >= credit)
                    return 1;
                else
                    return 0;
            }
            else
            {
                char *comma = strchr(require, ',');
                if (comma != NULL)
                {
                    char *
                        requires[4];
                    int n = 0;
                    char *c = strtok(require, ",");
                    while (c != NULL)
                    {
                        requires[n] = c;
                        n++;
                        c = strtok(NULL, ",");
                    }
                    for (int i = 0; i < n; i++)
                    {
                        if (!foundInCompletedCurses(requires[i], thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(requires[i], thisUser.numOfEnrollingCourses))
                            return 0;
                    }
                    return 1;
                }
                else
                {
                    if (foundInCompletedCurses(require, thisUser.numOfEnrolledCourses) || foundInEnrollingCurses(require, thisUser.numOfEnrolledCourses))
                        return 1;
                    else
                        return 0;
                }
            }
        }
        else
        {
            return 1;
        }
    }

    void showList()
    {
        colorPrint("\n This table contains all that courses which pre-requisites are fulfilled according to your selected trail,\n completed courses and enrolling courses. You can take any of these courses.\n\n", "y");
        int courseLenth;
        courseLenth = sizeof(coreCourses) / sizeof(coreCourses[0]);
        colorPrint("University, School & CSE Core Courses\n", "g");
        setColor("b");
        row(107);
        printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
        row(107);
        resetColor();
        for (int i = 0; i < courseLenth; i++)
        {
            if (!foundInCompletedCurses(coreCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(coreCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(coreCourses[i].require))
            {
                printf("\n| %-10s| %-60s| %-8.*f| %-20s|\n", coreCourses[i].initial, coreCourses[i].name, needDeci(coreCourses[i].credit), coreCourses[i].credit, analyseReq(coreCourses[i].require));
                row(107);
            }
        }
        if (thisUser.trail)
        {
            n();
            colorPrint(trails[thisUser.trail], "g");
            n();
            getTrailCourses(thisUser.trail);
            row(107);
            for (int i = 0; i < trailLnth; i++)
            {
                if (!foundInCompletedCurses(trailCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(trailCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(trailCourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.*f| %-20s|\n", trailCourses[i].initial, trailCourses[i].name, needDeci(trailCourses[i].credit), trailCourses[i].credit, analyseReq(trailCourses[i].require));
                    row(107);
                }
            }
        }
    }

    loadUserData(thisUserFile);
    if (thisUser.semester)
    {
        showList();
        n();
        n();
    }
    else
    {
        // if no this user data not found then get user information
        clr();
        colorPrint("\n\n You haven't entered your information yet.\n\n", "r");
    }
}