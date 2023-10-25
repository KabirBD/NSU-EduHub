void dashboard()
{
    char thisUserFile[23];
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

    char courseInit[5];
    char courseName[100];
    float courseCredit;

    char *trails[] = {"Not Selected", "Algorithms and Computation", "Software Engineering", "Networks", "Computer Architecture and VLSI", "Artificial Intelligence", "Bioinformatics"};

    char grades[13][5] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F", "I", "W"};
    float point[13] = {4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.3, 1.0, 0, 0, 0};

    int isValid(char initial[10], int trail)
    {
        int found = 0;

        for (int i = 0; i < 54; i++)
        {
            if (strcmp(coreCourses[i].initial, initial) == 0)
            {
                strcpy(courseInit, coreCourses[i].initial);
                strcpy(courseName, coreCourses[i].name);
                courseCredit = coreCourses[i].credit;
                found = 1;
                break;
            }
        }

        if (trail == 1)
        {
            for (int i = 0; i < 6; i++)
            {
                if (strcmp(algorithCourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, algorithCourses[i].initial);
                    strcpy(courseName, algorithCourses[i].name);
                    courseCredit = algorithCourses[i].credit;
                    found = 1;
                    break;
                }
            }
        }
        else if (trail == 2)
        {
            for (int i = 0; i < 6; i++)
            {
                if (strcmp(softwareCourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, softwareCourses[i].initial);
                    strcpy(courseName, softwareCourses[i].name);
                    courseCredit = softwareCourses[i].credit;
                    found = 1;
                    break;
                }
            }
        }
        else if (trail == 3)
        {
            for (int i = 0; i < 6; i++)
            {
                if (strcmp(networkCourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, networkCourses[i].initial);
                    strcpy(courseName, networkCourses[i].name);
                    courseCredit = networkCourses[i].credit;
                    found = 1;
                    break;
                }
            }
        }
        else if (trail == 4)
        {
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(architectureCourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, architectureCourses[i].initial);
                    strcpy(courseName, architectureCourses[i].name);
                    courseCredit = architectureCourses[i].credit;
                    found = 1;
                    break;
                }
            }
        }
        else if (trail == 5)
        {
            for (int i = 0; i < 7; i++)
            {
                if (strcmp(AICourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, AICourses[i].initial);
                    strcpy(courseName, AICourses[i].name);
                    courseCredit = AICourses[i].credit;
                    found = 1;
                    break;
                }
            }
        }
        else if (trail == 6)
        {
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(bioinformaticsCourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, bioinformaticsCourses[i].initial);
                    strcpy(courseName, bioinformaticsCourses[i].name);
                    courseCredit = bioinformaticsCourses[i].credit;
                    found = 1;
                    break;
                }
            }
        }
        return found;
    }

    // Function to save user data to a file
    void saveUserData(const char *filename)
    {
        FILE *file = fopen(filename, "wb");
        if (file == NULL)
        {
            perror("Error opening file");
            return;
        }

        // Write user data to the file
        fwrite(&thisUser, sizeof(struct userInfo), 1, file);

        fclose(file);
    }

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
    // return point of grade
    float gradeToPoint(char grade[5])
    {
        int index;
        for (int i = 0; i < 13; i++)
        {
            if (strcmp(grades[i], grade) == 0)
            {
                index = i;
                break;
            }
        }
        return point[index];
    }
    void showUserData()
    {
        float pointSum = 0;
        clr();
        loadUserData(thisUserFile);
        n();
        row(50);
        colorPrint(" User Information ", "c");
        row(50);

        colorPrint("\n\n User : ", "g");
        printf("%s\n", userName);
        colorPrint(" Current Semester : ", "g");
        printf("%d\n", thisUser.semester);
        colorPrint(" Trail : ", "g");
        printf("%s", trails[thisUser.trail]);
        colorPrint("\n Number of Completed Courses : ", "g");
        printf("%d", thisUser.numOfEnrolledCourses);
        colorPrint("\n Total Credits of Completed Courses: ", "g");
        printf("%.1f", thisUser.completedCredit);
        colorPrint("\n Number of Currently Enrolling Courses: ", "g");
        printf("%d", thisUser.numOfEnrollingCourses);
        colorPrint("\n Total Credits of Currently Enrolling Courses: ", "g");
        printf("%.1f\n\n", thisUser.completingCredit);
        // if user has completed any course
        if (thisUser.numOfEnrolledCourses)
        {
            row(118);
            colorPrint("\n\n List of Completed Courses:", "y");
            colorPrint("\n\tInitial        Course Name                                                 Credit    Grade\n", "b");
            for (int i = 0; i < thisUser.numOfEnrolledCourses; i++)
            {
                printf("\t%-15s%-60s%-10.1f%-10s\n", thisUser.enrolledCourses[i].initial, thisUser.enrolledCourses[i].name, thisUser.enrolledCourses[i].credit, thisUser.enrolledCourses[i].grade);
                pointSum += thisUser.enrolledCourses[i].credit * gradeToPoint(thisUser.enrolledCourses[i].grade);
            }
            colorPrint("\t-------------------------------------------------------------------------------------------", "y");
            colorPrint("\n\t                                                                       Current CGPA: ", "g");
            printf("%.2f\n", pointSum / thisUser.completedCredit);
            n();
        }
        if (thisUser.numOfEnrollingCourses)
        {
            row(118);
            colorPrint("\n\n List of Currently Enrolling Courses:", "y");
            colorPrint("\n\tInitial        Course Name                                                 Credit\n", "b");
            for (int i = 0; i < thisUser.numOfEnrollingCourses; i++)
                printf("\t%-15s%-60s%-10.1f\n", thisUser.enrollingCourses[i].initial, thisUser.enrollingCourses[i].name, thisUser.enrollingCourses[i].credit);
        }
        n();
        row(118);
        n();
        n();
        closeDialog();
    }

    int isValidGrade(char grade[5])
    {

        int validity = 0;
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(grades[i], grade) == 0)
            {
                validity = 1;
                break;
            }
        }
        if (!validity)
        {
            colorPrint("Invalid grade.", "r");
            colorPrint(" Example: 'a' or 'A', 'b+' or 'B+'\n", "c");
        }
        return validity;
    }

    void getUserInfo()
    {
        // Clear the thisUser struct (for demonstration purposes)
        memset(&thisUser, 0, sizeof(struct userInfo));
        while (1)
        {
            colorPrint("Which semester are you studying? ", "b");
            scanf("%d", &thisUser.semester);
            if (thisUser.semester < 1 || thisUser.semester > 20)
            {
                colorPrint("Invalid Semester!", "r");
                usleep(500000);
                clr();
            }
            else
                break;
        }

        if (thisUser.semester > 1)
        {
            thisUser.trail = showOption("Select your trail", trails, 7);
            clr();
            while(1){
            colorPrint("How many courses have you completed? ", "b");
            scanf("%d", &thisUser.numOfEnrolledCourses);
            if (thisUser.numOfEnrolledCourses < 1 || thisUser.numOfEnrolledCourses > 100)
            {
                colorPrint("Invalid Number!", "r");
                usleep(500000);
                clr();
            }
            else
                break;
            }

            thisUser.completedCredit = 0;
            for (int i = 0; i < thisUser.numOfEnrolledCourses; i++)
            {
                n();
                row(20);
                printf(" %d%s ", i + 1, getSuffix(i + 1));
                row(20);
                n();
                colorPrint("Course initial: ", "b");
                char initial[10];
                scanf("%s", initial);
                toUpperCase(initial);
                if (isValid(initial, thisUser.trail))
                {
                    strcpy(thisUser.enrolledCourses[i].initial, courseInit);
                    strcpy(thisUser.enrolledCourses[i].name, courseName);
                    char grade[5];
                    do
                    {
                        colorPrint("Enter grade: ", "b");
                        scanf("%s", grade);
                        toUpperCase(grade);
                    } while (!isValidGrade(grade));
                    strcpy(thisUser.enrolledCourses[i].grade, grade);
                    thisUser.enrolledCourses[i].credit = courseCredit;
                    thisUser.completedCredit += courseCredit;
                }
                else
                {
                    colorPrint(" No course matches with this initial!\n", "r");
                    i--;
                }
            }
        }
        clr();

        while (1)
        {
            colorPrint("How many courses have you taken this semester? : ", "b");
            scanf("%d", &thisUser.numOfEnrollingCourses);
            if (thisUser.numOfEnrollingCourses < 1 || thisUser.numOfEnrollingCourses >100)
            {
                colorPrint("Invalid Number!", "r");
                usleep(500000);
                clr();
            }
            else
                break;
        }

        thisUser.completingCredit = 0;
        for (int i = 0; i < thisUser.numOfEnrollingCourses; i++)
        {
            n();
            row(20);
            printf(" %d%s ", i + 1, getSuffix(i + 1));
            row(20);
            n();
            colorPrint("Enter course initial: ", "b");
            char initial[10];
            scanf("%s", initial);
            toUpperCase(initial);
            if (isValid(initial, thisUser.trail))
            {
                strcpy(thisUser.enrollingCourses[i].initial, courseInit);
                strcpy(thisUser.enrollingCourses[i].name, courseName);
                thisUser.enrollingCourses[i].credit = courseCredit;
                thisUser.completingCredit += courseCredit;
            }
            else
            {
                colorPrint(" No course matches with this initial!\n", "r");
                i--;
            }
        }

        // Save user data to a file
        saveUserData(thisUserFile);

        // Clear the thisUser struct (for demonstration purposes)
        memset(&thisUser, 0, sizeof(struct userInfo));
        colorPrint("\n\n\t...Complete...", "g");
        usleep(500000);
        clr();
        showUserData();
    }

    void showDashboardMenu()
    {
        clr();
        char *options[] = {"Dashboard", "Complete this semester", "Reset my information", "Go back"};
        switch (showOption("Select an option:", options, 4))
        {
        case 0:
            showUserData();
            showDashboardMenu();
            break;
        case 2:
            clr();
            getUserInfo();
            break;
        }
    }
    // Load user data from the file
    loadUserData(thisUserFile);
    if (thisUser.semester)
    {
        showDashboardMenu();
    }
    else
    {
        clr();
        colorPrint("\n\n You haven't enterd your information yet.\n\n", "r");
        usleep(2000000);
        clr();
        getUserInfo();
    }
}
