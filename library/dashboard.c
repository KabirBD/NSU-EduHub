void dashboard()
{
    // setting username.dat as this user file name
    char thisUserFile[25];
    strcpy(thisUserFile, userName);
    strcat(thisUserFile, ".dat");

    // structure used to store couse informations
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
    } thisUser; // logged in user info will be stored in thisUser object

    // global variable for this function
    char courseInit[5];
    char courseName[100];
    float courseCredit;
    char courseRequire[25];

    char *trails[] = {"Not Selected", "Algorithms and Computation", "Software Engineering", "Networks", "Computer Architecture and VLSI", "Artificial Intelligence", "Bioinformatics"};
    char *yesno[] = {"Yes", "No"};
    char grades[13][5] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F", "I", "W"};
    float point[13] = {4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.3, 1.0, 0, 0, 0};
    int foundAt;

    // check input is a valid & available initial or not
    int isValid(char initial[10], int trail)
    {
        int found = 0;
        for (int i = 0; i < 54; i++)
        {

            if (strcmp(coreCourses[i].initial, initial) == 0)
            {
                strcpy(courseInit, coreCourses[i].initial);
                strcpy(courseName, coreCourses[i].name);
                strcpy(courseRequire, coreCourses[i].require);
                courseCredit = coreCourses[i].credit;
                found = 1;
                break;
            }
        }
        if (trail)
        {
            getTrailCourses(trail);
            for (int i = 0; i < trailLnth; i++)
            {
                if (strcmp(trailCourses[i].initial, initial) == 0)
                {
                    strcpy(courseInit, trailCourses[i].initial);
                    strcpy(courseName, trailCourses[i].name);
                    strcpy(courseRequire, trailCourses[i].require);
                    courseCredit = trailCourses[i].credit;
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
        if (file == NULL) // if no file found named username.dat,
        {
            perror("Error opening file");
            thisUser.semester = 0; // to promt user to enter information
            return;
        }

        // Read user data from the file
        fread(&thisUser, sizeof(struct userInfo), 1, file);
        // if there is no completed course and enrolling course
        if (thisUser.numOfEnrollingCourses == 0 && thisUser.numOfEnrolledCourses == 0)
            thisUser.semester = 0; // to promt user to enter information

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

    // display user information from file
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
            colorPrint("\n\tInitial        Course Name                                                 Credit    Grade  Point\n", "b");
            for (int i = 0; i < thisUser.numOfEnrolledCourses; i++)
            {
                printf("\t%-15s%-60s%-10.1f%-7s%-3.1f\n", thisUser.enrolledCourses[i].initial, thisUser.enrolledCourses[i].name, thisUser.enrolledCourses[i].credit, thisUser.enrolledCourses[i].grade, gradeToPoint(thisUser.enrolledCourses[i].grade));
                pointSum += thisUser.enrolledCourses[i].credit * gradeToPoint(thisUser.enrolledCourses[i].grade);
            }
            colorPrint("\t-------------------------------------------------------------------------------------------------", "y");
            colorPrint("\n\t                                                                              Current CGPA: ", "g");
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
            n();
            row(118);
            n();
            colorPrint("\n This Semester tuition and other fees\n", "y");
            printf("\t%-40s%7.0lf TK\n", "Tuition fees", thisUser.completingCredit * 6500);
            printf("\t%-40s%7d TK\n", "Student Activity Fee", 4500);
            printf("\t%-40s%7d TK\n", "Computer Lab Fee", 3750);
            printf("\t%-40s%7d TK\n", "Library Fee", 2250);
            printf("\t%-40s%7d TK\n", "Science Lab Fee", 3750);
            colorPrint("\t--------------------------------------------------\n", "y");
            colorPrint("\tTotal fees:", "c");
            printf("%29s%7.0lf TK\n", " ", (thisUser.completingCredit * 6500 + 4500 + 3750 + 2250 + 3750));
        }
        n();
        row(118);
        n();
        closeDialog();
    }

    // check if entered grade is valid or not
    int isValidGrade(char grade[5])
    {

        int validity = 0;
        for (int i = 0; i < 11; i++)
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

    // check if the course is in completed courses list
    int foundInCompletedCurses(char givenInitial[10], int lnth)
    {
        int flag = 0;
        for (int i = 0; i < lnth; i++)
        {
            if (strcmp(thisUser.enrolledCourses[i].initial, givenInitial) == 0)
            {
                foundAt = i;
                flag = 1;
                break; // Exit the loop when the match is found
            }
        }
        return flag;
    }

    // check if the course is in enrolling courses list
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

    // analyse requirement of the course
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

    // check if other courses require this course
    int isRequiredBy(char index)
    {
        int flag = 0;
        char require[25];
        for (int i = 0; i < thisUser.numOfEnrolledCourses; i++)
        {
            isValid(thisUser.enrolledCourses[i].initial, thisUser.trail); // to get pre-requisites of that course
            strcpy(require, courseRequire);
            if (strlen(require))
            {
                if (require[1] == '-')
                {
                    char *hyphen = strchr(require, '-');
                    int credit = atoi(hyphen + 1);
                    if (thisUser.completedCredit - thisUser.enrolledCourses[index].credit <= credit)
                        return 1;
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
                            if (strcmp(requires[i], thisUser.enrolledCourses[index].initial) == 0)
                                return 1;
                        }
                    }
                    else
                    {
                        if (strcmp(require, thisUser.enrolledCourses[index].initial) == 0)
                            return 1;
                    }
                }
            }
        }
        for (int i = 0; i < thisUser.numOfEnrollingCourses; i++)
        {
            isValid(thisUser.enrollingCourses[i].initial, thisUser.trail); // to get pre-requisites of that course
            strcpy(require, courseRequire);
            if (strlen(require))
            {
                if (require[1] == '-')
                {
                    char *hyphen = strchr(require, '-');
                    int credit = atoi(hyphen + 1);
                    if (thisUser.completedCredit - thisUser.enrolledCourses[index].credit <= credit)
                        return 1;
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
                            if (strcmp(requires[i], thisUser.enrolledCourses[index].initial) == 0)
                                return 1;
                        }
                    }
                    else
                    {
                        if (strcmp(require, thisUser.enrolledCourses[index].initial) == 0)
                            return 1;
                    }
                }
            }
        }
        return 0;
    }

    // get semester info from user
    void getSemeterInfo()
    {
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
    }

    // get trail info from user
    void getTrailInfo()
    {
        thisUser.trail = showOption("Select your trail", trails, 7);
    }

    // get completed courses from user
    void getCompletedCourses()
    {
        while (1)
        {
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
                if (!foundInCompletedCurses(initial, i))
                {
                    if (checkRequire(courseRequire))
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
                        colorPrint(" Required courses are not completed for this course\n", "r");
                        i--;
                    }
                }
                else
                {
                    colorPrint(" You have already added this initial\n", "r");
                    i--;
                }
            }
            else
            {
                colorPrint(" No course matches with this initial!\n", "r");
                i--;
            }
        }
    }

    // get courses for this semester from user
    void getEnrollingCourses()
    {
        while (1)
        {
            colorPrint("How many courses have you taken this semester? : ", "b");
            scanf("%d", &thisUser.numOfEnrollingCourses);
            if (thisUser.numOfEnrollingCourses < 1 || thisUser.numOfEnrollingCourses > 100)
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
                if (!foundInEnrollingCurses(initial, i))
                {
                    if (foundInCompletedCurses(initial, thisUser.numOfEnrolledCourses) && gradeToPoint(thisUser.enrolledCourses[foundAt].grade) == 4)
                    {
                        colorPrint(" No need to retake this course. Already got highest grade.\n", "y");
                        i--;
                    }
                    else
                    {
                        if (checkRequire(courseRequire))
                        {
                            strcpy(thisUser.enrollingCourses[i].initial, courseInit);
                            strcpy(thisUser.enrollingCourses[i].name, courseName);
                            thisUser.enrollingCourses[i].credit = courseCredit;
                            thisUser.completingCredit += courseCredit;
                        }
                        else
                        {
                            colorPrint(" Required courses are not completed or not added to enrolling courses list\n", "r");
                            i--;
                        }
                    }
                }
                else
                {
                    colorPrint(" You have already added this initial\n", "r");
                    i--;
                }
            }
            else
            {
                colorPrint(" No course matches with this initial!\n", "r");
                i--;
            }
        }
    }

    // get all info from user
    void getUserInfo()
    {
        // Clear the thisUser struct (for demonstration purposes)
        memset(&thisUser, 0, sizeof(struct userInfo));
        getSemeterInfo();

        if (thisUser.semester > 1)
        {
            getTrailInfo();
            clr();
            getCompletedCourses();
        }
        clr();
        getEnrollingCourses();
        // Save user data to a file
        saveUserData(thisUserFile);

        // Clear the thisUser struct (for demonstration purposes)
        memset(&thisUser, 0, sizeof(struct userInfo));
        colorPrint("\n\n\t...Complete...", "g");
        usleep(500000);
        clr();
        showUserData();
    }

    // add a course in completed courses list
    void addCompletedCourse()
    {
        char initial[10];
        while (1)
        {
            colorPrint("Course initial: ", "b");
            scanf("%s", initial);
            toUpperCase(initial);
            if (isValid(initial, thisUser.trail))
            {
                int index = thisUser.numOfEnrolledCourses;

                if (!foundInCompletedCurses(initial, index))
                {
                    if (checkRequire(courseRequire))
                    {
                        strcpy(thisUser.enrolledCourses[index].initial, courseInit);
                        strcpy(thisUser.enrolledCourses[index].name, courseName);
                        char grade[5];
                        do
                        {
                            colorPrint("Enter grade: ", "b");
                            scanf("%s", grade);
                            toUpperCase(grade);
                        } while (!isValidGrade(grade));

                        if (foundInEnrollingCurses(initial, thisUser.numOfEnrollingCourses) && gradeToPoint(grade) == 4)
                        {
                            colorPrint(" Deleted this course from enrolling courses list. No need to retake.\n", "r");
                            usleep(1000000);
                            thisUser.numOfEnrollingCourses--;
                            thisUser.completingCredit -= thisUser.enrollingCourses[foundAt].credit;
                            for (int i = foundAt; i < thisUser.numOfEnrollingCourses; i++)
                            {
                                strcpy(thisUser.enrollingCourses[i].initial, thisUser.enrollingCourses[i + 1].initial);
                                strcpy(thisUser.enrollingCourses[i].name, thisUser.enrollingCourses[i + 1].name);
                                thisUser.enrollingCourses[i].credit = thisUser.enrollingCourses[i + 1].credit;
                            }
                        }
                        strcpy(thisUser.enrolledCourses[index].grade, grade);
                        thisUser.enrolledCourses[index].credit = courseCredit;
                        thisUser.completedCredit += courseCredit;
                        thisUser.numOfEnrolledCourses++;
                        saveUserData(thisUserFile);
                        break;
                    }
                    else
                    {
                        colorPrint(" Required courses are not completed or not added to enrolling courses list\n", "r");
                    }
                }
                else
                {
                    colorPrint(" You have already added this initial\n", "r");
                }
            }
            else
            {
                colorPrint(" No course matches with this initial!\n", "r");
            }
        }
    }

    // delete a course from completed courses list
    void deleteCompletedCourse()
    {
        char *initials[thisUser.numOfEnrolledCourses];

        for (int i = 0; i < thisUser.numOfEnrolledCourses; i++)
        {
            initials[i] = malloc(strlen(thisUser.enrolledCourses[i].initial) + 1);
            strcpy(initials[i], thisUser.enrolledCourses[i].initial);
        }

        int index = showOption("Select which course you want to delete", initials, thisUser.numOfEnrolledCourses);
        for (int i = 0; i < thisUser.numOfEnrolledCourses; i++)
            free(initials[i]);
        if (isRequiredBy(index))
        {
            clr();
            colorPrint(" Can't delete. Some courses require this course.", "r");
            usleep(1000000);
        }
        else
        {
            thisUser.numOfEnrolledCourses--;
            thisUser.completedCredit -= thisUser.enrolledCourses[index].credit;
            for (int i = index; i < thisUser.numOfEnrolledCourses; i++)
            {
                strcpy(thisUser.enrolledCourses[i].initial, thisUser.enrolledCourses[i + 1].initial);
                strcpy(thisUser.enrolledCourses[i].name, thisUser.enrolledCourses[i + 1].name);
                strcpy(thisUser.enrolledCourses[i].grade, thisUser.enrolledCourses[i + 1].grade);
                thisUser.enrolledCourses[i].credit = thisUser.enrolledCourses[i + 1].credit;
            }
            saveUserData(thisUserFile);
        }
    }

    // add a course in enrolling courses list
    void addEnrollingCourse()
    {
        char initial[10];
        while (1)
        {
            colorPrint("Course initial: ", "b");
            scanf("%s", initial);
            toUpperCase(initial);
            if (isValid(initial, thisUser.trail))
            {
                int index = thisUser.numOfEnrollingCourses;
                if (!foundInEnrollingCurses(initial, index))
                {
                    if (foundInCompletedCurses(initial, thisUser.numOfEnrolledCourses) && gradeToPoint(thisUser.enrolledCourses[foundAt].grade) == 4)
                    {
                        colorPrint(" No need to retake this course. Already get highest grade.\n", "y");
                    }
                    else
                    {
                        if (checkRequire(courseRequire))
                        {
                            strcpy(thisUser.enrollingCourses[index].initial, courseInit);
                            strcpy(thisUser.enrollingCourses[index].name, courseName);
                            thisUser.enrollingCourses[index].credit = courseCredit;
                            thisUser.completingCredit += courseCredit;
                            thisUser.numOfEnrollingCourses++;
                            saveUserData(thisUserFile);
                            break;
                        }
                        else
                        {
                            colorPrint(" Required courses are not completed or not added to enrolling courses list\n", "r");
                        }
                    }
                }
                else
                {
                    colorPrint(" You have already added this initial\n", "r");
                }
            }
            else
            {
                colorPrint(" No course matches with this initial!\n", "r");
            }
        }
    }

    // delete a course from enrolling courses list
    void deleteEnrollingCourse()
    {
        char *initials[thisUser.numOfEnrollingCourses];

        for (int i = 0; i < thisUser.numOfEnrollingCourses; i++)
        {
            initials[i] = malloc(strlen(thisUser.enrollingCourses[i].initial) + 1);
            strcpy(initials[i], thisUser.enrollingCourses[i].initial);
        }

        int index = showOption("Select which course you want to delete", initials, thisUser.numOfEnrollingCourses);
        for (int i = 0; i < thisUser.numOfEnrollingCourses; i++)
            free(initials[i]);
        thisUser.numOfEnrollingCourses--;
        thisUser.completingCredit -= thisUser.enrollingCourses[index].credit;
        for (int i = index; i < thisUser.numOfEnrollingCourses; i++)
        {
            strcpy(thisUser.enrollingCourses[i].initial, thisUser.enrollingCourses[i + 1].initial);
            strcpy(thisUser.enrollingCourses[i].name, thisUser.enrollingCourses[i + 1].name);
            thisUser.enrollingCourses[i].credit = thisUser.enrollingCourses[i + 1].credit;
        }
        saveUserData(thisUserFile);
    }
    int gradeImproved(char oldGrade[5], char newGrade[5])
    {
        int old, new;
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(grades[i], oldGrade) == 0)
            {
                old = i;
            }
            if (strcmp(grades[i], newGrade) == 0)
            {
                new = i;
            }
        }
        return (old > new);
    }

    // move all enrolling courses to completed courses list to start next semester
    void completeThisSemester()
    {
        clr();
        loadUserData(thisUserFile);
        int index = thisUser.numOfEnrolledCourses;
        char grade[5];
        for (int i = 0; i < thisUser.numOfEnrollingCourses; i++, index++)
        {
            colorPrint("Enter grade for ", "b");
            printf("%s\n", thisUser.enrollingCourses[i].initial);
            do
            {
                colorPrint("Grade: ", "b");
                scanf("%s", grade);
                toUpperCase(grade);
            } while (!isValidGrade(grade));

            if (foundInCompletedCurses(thisUser.enrollingCourses[i].initial, thisUser.numOfEnrolledCourses))
            {
                if (gradeImproved(thisUser.enrolledCourses[foundAt].grade, grade))
                {
                    thisUser.numOfEnrolledCourses--;
                    index--;
                    thisUser.completedCredit -= thisUser.enrolledCourses[foundAt].credit;
                    for (int j = foundAt; j < thisUser.numOfEnrolledCourses; j++)
                    {
                        strcpy(thisUser.enrolledCourses[j].initial, thisUser.enrolledCourses[j + 1].initial);
                        strcpy(thisUser.enrolledCourses[j].name, thisUser.enrolledCourses[j + 1].name);
                        strcpy(thisUser.enrolledCourses[j].grade, thisUser.enrolledCourses[j + 1].grade);
                        thisUser.enrolledCourses[j].credit = thisUser.enrolledCourses[j + 1].credit;
                    }
                }
                else
                {
                    index--;
                    continue;
                }
            }
            strcpy(thisUser.enrolledCourses[index].initial, thisUser.enrollingCourses[i].initial);
            strcpy(thisUser.enrolledCourses[index].name, thisUser.enrollingCourses[i].name);
            strcpy(thisUser.enrolledCourses[index].grade, grade);
            thisUser.enrolledCourses[index].credit = thisUser.enrollingCourses[i].credit;
            thisUser.completedCredit += thisUser.enrollingCourses[i].credit;
            thisUser.numOfEnrolledCourses++;
        }
        thisUser.semester++;
        thisUser.completingCredit = 0;
        thisUser.numOfEnrollingCourses = 0;

        switch (showOption("Do you want to add new courses for this semester now?", yesno, 2))
        {
        case 0:
            clr();
            getEnrollingCourses();
        }
        saveUserData(thisUserFile);
    }

    // delete all coursers of this trail from completed and enrolling courses
    void deleteTrailCourses(int trail)
    {
        getTrailCourses(trail);
        for (int i = 0; i < trailLnth; i++)
        {
            for (int j = 0; j < thisUser.numOfEnrolledCourses; j++)
            {
                if (strcmp(trailCourses[i].initial, thisUser.enrolledCourses[j].initial) == 0)
                {
                    thisUser.numOfEnrolledCourses--;
                    thisUser.completedCredit -= thisUser.enrolledCourses[j].credit;
                    for (int k = j; j < thisUser.numOfEnrolledCourses; j++)
                    {
                        strcpy(thisUser.enrolledCourses[k].initial, thisUser.enrolledCourses[k + 1].initial);
                        strcpy(thisUser.enrolledCourses[k].name, thisUser.enrolledCourses[k + 1].name);
                        strcpy(thisUser.enrolledCourses[k].grade, thisUser.enrolledCourses[k + 1].grade);
                        thisUser.enrolledCourses[k].credit = thisUser.enrolledCourses[k + 1].credit;
                    }
                }
            }
            for (int j = 0; j < thisUser.numOfEnrollingCourses; j++)
            {
                if (strcmp(trailCourses[i].initial, thisUser.enrollingCourses[j].initial) == 0)
                {
                    thisUser.numOfEnrollingCourses--;
                    thisUser.completingCredit -= thisUser.enrollingCourses[j].credit;
                    for (int k = j; j < thisUser.numOfEnrollingCourses; j++)
                    {
                        strcpy(thisUser.enrollingCourses[k].initial, thisUser.enrollingCourses[k + 1].initial);
                        strcpy(thisUser.enrollingCourses[k].name, thisUser.enrollingCourses[k + 1].name);
                        strcpy(thisUser.enrollingCourses[k].grade, thisUser.enrollingCourses[k + 1].grade);
                        thisUser.enrollingCourses[k].credit = thisUser.enrollingCourses[k + 1].credit;
                    }
                }
            }
        }
    }

    // user info edit functionalities
    void editMenu()
    {
        clr();
        char *options[] = {"Change Semester", "Change Trail", "Add a Course in Completed Courses List", "Delete a Course from Completed Courses List", "Add a Course in Currently Enrolling Courses List", "Delete a Course from Currently Enrolling Courses List", "Go Back"};

        switch (showOption("Select an option:", options, 7))
        {
        case 0:
            clr();
            loadUserData(thisUserFile);
            getSemeterInfo();
            saveUserData(thisUserFile);
            showUserData();
            editMenu();
            break;
        case 1:
            clr();
            loadUserData(thisUserFile);
            if (thisUser.semester > 1)
            {
                if (thisUser.trail != 0)
                {
                    switch (showOption("If you change the trail, courses of your previous trail will be removed from completed and currently enrolling courses lists.\nDo you want to continue?", yesno, 2))
                    {
                    case 0:
                        deleteTrailCourses(thisUser.trail);
                        getTrailInfo();
                        saveUserData(thisUserFile);
                        showUserData();
                        break;
                    }
                }
                else
                {
                    getTrailInfo();
                    saveUserData(thisUserFile);
                    showUserData();
                }
            }
            else
            {
                colorPrint("You Can not choose trail in 1st Semester.", "r");
                usleep(2000000);
            }
            editMenu();
            break;
        case 2:
            clr();
            loadUserData(thisUserFile);
            if (thisUser.semester > 1)
            {
                addCompletedCourse();
                showUserData();
            }
            else
            {
                colorPrint("You Can Not Have a Completed Course in 1st Semester.", "r");
                usleep(5000000);
            }
            editMenu();
            break;
        case 3:
            clr();
            loadUserData(thisUserFile);
            if (thisUser.numOfEnrolledCourses > 0)
            {
                deleteCompletedCourse();
                showUserData();
            }
            else
            {
                colorPrint("You don't have any completed course.", "r");
                usleep(2000000);
            }
            editMenu();
            break;
        case 4:
            clr();
            loadUserData(thisUserFile);
            addEnrollingCourse();
            showUserData();
            editMenu();
            break;
        case 5:
            clr();
            loadUserData(thisUserFile);
            if (thisUser.numOfEnrollingCourses > 0)
            {
                deleteEnrollingCourse();
                showUserData();
            }
            else
            {
                colorPrint("You don't have any Enrolling course.", "r");
                usleep(2000000);
            }
            editMenu();
            break;
        }
    }

    // to show dashboard menu
    void showDashboardMenu()
    {
        clr();
        char *options[] = {"See Your Information", "Completed this Semester", "Edit Information", "Reset Information", "Go back"};
        switch (showOption("Select an option:", options, 5))
        {
        case 0:
            showUserData();
            showDashboardMenu();
            break;
        case 1:
            if (thisUser.numOfEnrollingCourses)
            {
                switch (showOption("\n All your currently enrolling courses will be moved to completed courses list with their grades.\n Do you want to continue?", yesno, 2))
                {
                case 0:
                    completeThisSemester();
                    showUserData();
                case 1:
                    showDashboardMenu();
                }
            }
            else
            {
                clr();
                colorPrint("No course in the enrolling courses list", "r");
                usleep(2000000);
                showDashboardMenu();
            }
            break;
        case 2:
            editMenu();
            showDashboardMenu();
            break;
        case 3:
            clr();
            switch (showOption("Do you really want to reset all your informations?", yesno, 2))
            {
            case 0:
                clr();
                getUserInfo();
            case 1:
                showDashboardMenu();
            }
        }
    }

    // Load user data from the file
    loadUserData(thisUserFile);

    if (thisUser.semester) // if user data found
    {
        showDashboardMenu(); // display user menu
    }
    else
    {
        // if this user data not found then get user information
        clr();
        colorPrint("\n\n You haven't enterd your information yet.\n\n", "r");
        usleep(2000000);
        clr();
        getUserInfo();
        showDashboardMenu();
    }
}
