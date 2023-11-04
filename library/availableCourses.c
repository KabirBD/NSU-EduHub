void availableCourses()
{
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
        int courseLenth;
        courseLenth = sizeof(coreCourses) / sizeof(coreCourses[0]);
        colorPrint("Core Courses\n", "g");
        setColor("b");
        row(107);
        printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
        row(107);
        resetColor();
        for (int i = 0; i < courseLenth; i++)
        {
            if (!foundInCompletedCurses(coreCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(coreCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(coreCourses[i].require))
            {
                printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", coreCourses[i].initial, coreCourses[i].name, coreCourses[i].credit, coreCourses[i].require);
                row(107);
            }
        }
        switch (thisUser.trail)
        {
        case 1:
            courseLenth = sizeof(algorithCourses) / sizeof(algorithCourses[0]);
            colorPrint("\nAlgorithms and Computation Courses\n", "g");
            row(107);
            for (int i = 0; i < courseLenth; i++)
            {
                if (!foundInCompletedCurses(algorithCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(algorithCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(algorithCourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", algorithCourses[i].initial, algorithCourses[i].name, algorithCourses[i].credit, algorithCourses[i].require);
                    row(107);
                }
            }
            break;
        case 2:
            courseLenth = sizeof(softwareCourses) / sizeof(softwareCourses[0]);
            colorPrint("\nSoftware Engineering Courses\n", "g");
            row(107);
            for (int i = 0; i < courseLenth; i++)
            {

                if (!foundInCompletedCurses(softwareCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(softwareCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(softwareCourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", softwareCourses[i].initial, softwareCourses[i].name, softwareCourses[i].credit, softwareCourses[i].require);
                    row(107);
                }
            }
            break;
        case 3:
            courseLenth = sizeof(networkCourses) / sizeof(networkCourses[0]);
            colorPrint("\nNetworks Courses\n", "g");
            row(107);
            for (int i = 0; i < courseLenth; i++)
            {
                if (!foundInCompletedCurses(networkCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(networkCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(networkCourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", networkCourses[i].initial, networkCourses[i].name, networkCourses[i].credit, networkCourses[i].require);
                    row(107);
                }
            }
            break;
        case 4:
            courseLenth = sizeof(architectureCourses) / sizeof(architectureCourses[0]);
            colorPrint("\nComputer Architecture and VLSI Courses\n", "g");
            row(107);
            for (int i = 0; i < courseLenth; i++)
            {
                if (!foundInCompletedCurses(architectureCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(architectureCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(architectureCourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", architectureCourses[i].initial, architectureCourses[i].name, architectureCourses[i].credit, architectureCourses[i].require);
                    row(107);
                }
            }
            break;
        case 5:
            courseLenth = sizeof(AICourses) / sizeof(AICourses[0]);
            colorPrint("\nArtificial Intelligence Courses\n", "g");
            row(107);
            for (int i = 0; i < courseLenth; i++)
            {
                if (!foundInCompletedCurses(AICourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(AICourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(AICourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", AICourses[i].initial, AICourses[i].name, AICourses[i].credit, AICourses[i].require);
                    row(107);
                }
            }
            break;
        case 6:
            courseLenth = sizeof(bioinformaticsCourses) / sizeof(bioinformaticsCourses[0]);
            colorPrint("\nBioinformatics Courses\n", "g");
            row(107);
            for (int i = 0; i < courseLenth; i++)
            {
                if (!foundInCompletedCurses(bioinformaticsCourses[i].initial, thisUser.numOfEnrolledCourses) && !foundInEnrollingCurses(bioinformaticsCourses[i].initial, thisUser.numOfEnrollingCourses) && checkRequire(bioinformaticsCourses[i].require))
                {
                    printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", bioinformaticsCourses[i].initial, bioinformaticsCourses[i].name, bioinformaticsCourses[i].credit, bioinformaticsCourses[i].require);
                    row(107);
                }
            }
            break;
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
        colorPrint("\n\n You haven't enterd your information yet.\n\n", "r");
        usleep(2000000);
        clr();
    }
}