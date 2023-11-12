void courseAdvisor()
{
    char courseListTemp[90][10];

    char thisUserFile[25];
    strcpy(thisUserFile, userName);
    strcat(thisUserFile, ".dat");

    char thisUserCourseMap[25];
    strcpy(thisUserCourseMap, userName);
    strcat(thisUserCourseMap, "map.txt");

    struct courseObj
    {
        char initial[10];
        char name[100];
        float credit;
        char require[25];
        char description[2000];
    };

    typedef struct courseDetails
    {
        char courseInitials[10];
        char name[100];
        float courseCredits;
        char preReq1[10];
        char preReq2[10];
        char preReq3[10];
        int flag; // if flag is set to 1, course is unavailable.
    } courseDetails;

    typedef struct coreCoursesdiv
    {
        courseDetails schoolCore[15];
        courseDetails cseCore[28];
        courseDetails uniCore[15];
    } coreCoursesdiv;

    coreCoursesdiv core;

    courseDetails recommendedCourses[55];

    int perSemCourse[30];

    float totalCredits = 0;
    float totalCreditsCalc = copy.doneCredit;

    int totalSemester;

    int cseCourse, uniCourse, schoolCourse;

    void loadUserData(const char *filename)
    {
        FILE *file = fopen(filename, "rb");
        if (file == NULL) // if no file found named username.dat,
        {
            // perror("Error opening file");
            return;
        }

        // Read user data from the file
        fread(&courseList, sizeof(courseList), 1, file);

        for (int i = 0; i < 90; i++)
        {
            strcpy(courseListTemp[i], courseList[i]);
        }

        fclose(file);
    }

    int gedCheck(courseDetails * courseCore, const char *comp, int i)
    {
        courseDetails *changePtr = courseCore + i;

        if (strncmp(courseCore[i].courseInitials, comp, 3) == 0)
        {
            changePtr->flag = 2;
        }
    }

    void courseCopier(courseDetails * course, int copiedTo, int source)
    {
        strcpy(course[copiedTo].courseInitials, coreCourses[source].initial);
        strcpy(course[copiedTo].name, coreCourses[source].name);
        course[copiedTo].courseCredits = coreCourses[source].credit;
        course[copiedTo].preReq1[0] = '\0';
        course[copiedTo].preReq2[0] = '\0';
        course[copiedTo].preReq3[0] = '\0';
        // Split prerequisites
        char *token, *rest = coreCourses[source].require;
        int prereqCount = 0;
        while ((token = strtok_r(rest, ",", &rest)))
        {
            if (prereqCount == 0)
                strcpy(course[copiedTo].preReq1, token);
            else if (prereqCount == 1)
                strcpy(course[copiedTo].preReq2, token);
            else if (prereqCount == 2)
                strcpy(course[copiedTo].preReq3, token);
            prereqCount++;
        }
        if ((course[copiedTo].preReq1[0] == '\0' && course[copiedTo].preReq2[0] == '\0'))
        {
            course[copiedTo].flag = 0;

            if (course == core.uniCore)
            {
                if (strcmp(course[copiedTo].courseInitials, "POL104") == 0)
                {
                    gedCheck(course, "POL", copiedTo);
                }
                else if ((strcmp(course[copiedTo].courseInitials, "ENV203") == 0) || (strcmp(course[copiedTo].courseInitials, "ANT101") == 0))
                {
                    gedCheck(course, "ENV", copiedTo);
                    gedCheck(course, "ANT", copiedTo);
                }
                else if (strcmp(course[copiedTo].courseInitials, "ECO104") == 0)
                {
                    gedCheck(course, "ECO", copiedTo);
                }
            }
        }
        else
        {
            course[copiedTo].flag = 1;
        }
    }

    int getValidInput(int min, int max, const char *prompt)
    {
        int input;
        int validInput = 0; // Variable to track if the input is valid

        do
        {
            printf("%s", prompt);
            if (scanf("%d", &input) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
            }
            else if (input < min || input > max)
            {
                printf("Please enter a number between %d and %d.\n", min, max);
            }
            else
            {
                validInput = 1;
            }
        } while (!validInput);

        return input;
    }

    void courseDivider()
    {
        int cse_count = 0, school_count = 0, uni_count = 0;

        for (int i = 0; i < (sizeof(coreCourses) / sizeof(coreCourses[0])); i++) // this whole part is a function
        {
            if (strncmp("CSE", coreCourses[i].initial, 3) == 0 || (strncmp("EEE", coreCourses[i].initial, 3) == 0))
            {
                if (strncmp("EEE452", coreCourses[i].initial, 6) == 0 || strncmp("EEE154", coreCourses[i].initial, 6) == 0)
                {
                    courseCopier(core.schoolCore, school_count, i);
                    school_count++;
                }
                else
                {
                    courseCopier(core.cseCore, cse_count, i);
                    cse_count++;
                }
            }
            else if (strncmp("MAT", coreCourses[i].initial, 3) == 0 || (strncmp("PHY", coreCourses[i].initial, 3) == 0) || (strncmp("CHE", coreCourses[i].initial, 3) == 0))
            {
                courseCopier(core.schoolCore, school_count, i);
                school_count++;
            }
            else
            {
                courseCopier(core.uniCore, uni_count, i);
                uni_count++;
            }
        }
    }

    int coursePicker(courseDetails * courseCore, int limitCourses, courseDetails *recommendedCourses, int startIdx)
    {
        int numCourses = 0;

        for (int i = 0; numCourses < limitCourses; i++)
        {
            if (courseCore[i].flag == 0)
            {
                recommendedCourses[numCourses + startIdx] = courseCore[i];
                totalCreditsCalc += recommendedCourses[numCourses + startIdx].courseCredits;

                if (strncmp(courseCore[i].courseInitials, courseCore[i + 1].courseInitials, 6) == 0) // checks if the next course is a lab course
                {
                    recommendedCourses[numCourses + startIdx + 1] = courseCore[i + 1]; // if yes then adds it to recommended courses
                    totalCreditsCalc += recommendedCourses[numCourses + startIdx + 1].courseCredits;
                    numCourses += 2; // increase numCourse by 2 because of extra lab course
                    limitCourses++;  // limit increased because of lab course
                    i++;             // i incremented to skip next course, which is the lab course
                }
                else
                {
                    numCourses++;
                }
            }
        }

        return numCourses;
    }

    int getInput()
    {
        totalSemester = getValidInput(1, 8, "Enter the number of semesters(e.g. 1 if you want to be advised for your next semester): ");

        cseCourse = getValidInput(1, 4, "Enter the number of CSE core courses you want per semester: ");

        uniCourse = getValidInput(1, 4, "Enter the number of University core courses(GED) you want per semester: ");

        schoolCourse = getValidInput(1, 4, "Enter the number of School core courses you want per semester: ");
    }

    int preReqChecker(int courseCount, courseDetails *courseCore, int m)
    {
        int preReq1_temp;
        int preReq2_temp;
        int result;
        for (int g = 1; g <= courseCount; g++)
        {
            if (strcmp(courseCore[m].preReq1, courseListTemp[g]) == 0)
            {
                preReq1_temp = 0;
                break; // preRequisite course exists in the done courselist. so preReq is set to 0;
            }
            else if (courseCore[m].preReq1[0] == '\0')
            {
                preReq1_temp = 0; // no preReq course. so loop breaks.
                break;
            }
            else
            {
                preReq1_temp = 1; // preReq not completed so set to 1.
            }
        }
        for (int g = 1; g <= courseCount; g++)
        {
            if (strcmp(courseCore[m].preReq2, courseListTemp[g]) == 0)
            {
                preReq2_temp = 0;
                break; // preRequisite course exists in the done courselist. so preReq is set to 0;
            }
            else if (courseCore[m].preReq2[0] == '\0')
            {
                preReq2_temp = 0; // no preReq course. so loop breaks.
                break;
            }
            else
            {
                preReq2_temp = 1; // preReq not completed so set to 1.
            }
        }

        result = preReq2_temp || preReq1_temp;

        return result;
    }

    int adder(int recCount, int recIndx)
    {
        int j = recIndx;

        int z = atoi(courseListTemp[0]);

        for (int i = z + 1; i < z + 1 + recCount; i++)
        {
            strcpy(courseListTemp[i], recommendedCourses[j].courseInitials);
            j++;
        }

        int newCount = z + recCount;

        char newC[3];

        sprintf(newC, "%d", newCount);

        strcpy(courseListTemp[0], newC);
    }

    void clearData()
    {
        memset(&courseListTemp, 0, sizeof(courseListTemp));
        loadUserData(thisUserFile);
    }

    int courseAvailabilityChecker(courseDetails * courseCore, int n, int courseCount, int k)
    {
        for (int m = 0; m < n; m++)
            for (int m = 0; m < n; m++)
            {
                courseDetails *s_ptr = courseCore + m; // Pointer to the course in the core CSE courses.

                if (strcmp(courseListTemp[k], courseCore[m].courseInitials) != 0 && courseCore[m].flag == 1) // checks if done course matches, the name of course in list. also checks if course is available(flag is set to 1 or 0)
                {
                    if (strncmp("c-", courseCore[m].preReq1, 2) == 0)
                    {
                        char req[15];
                        strcpy(req, courseCore[m].preReq1);

                        char *hyphen = strchr(req, '-');
                        int creditLimit = atoi(hyphen + 1);

                        if (totalCreditsCalc >= creditLimit)
                        {

                            s_ptr->flag = 0;
                        }
                        else
                        {

                            s_ptr->flag = 1;
                        }
                    }
                    else // enters if preReq are not null. now checks if preReq courses are completed or not.
                    {
                        s_ptr->flag = preReqChecker(courseCount, courseCore, m); // changes the flag to 1 or 0. if both preReqs are done then sets it to 0, meaning course is available.
                    }
                }
                else if (strcmp(courseListTemp[k], courseCore[m].courseInitials) == 0) // the course has already been completed. so flag is set to 2
                {
                    s_ptr->flag = 2;

                    if (courseCore == core.uniCore)
                    {
                        if (strncmp(courseListTemp[k], "POL", 3) == 0) // if course is POL
                        {
                            for (int i = 0; i < n; i++)
                            {
                                gedCheck(courseCore, "POL", i);
                            }
                        }
                        else if ((strncmp(courseListTemp[k], "ENV", 3) == 0) || (strncmp(courseListTemp[k], "ANT", 3) == 0) || (strncmp(courseListTemp[k], "SOC", 3) == 0))
                        {
                            for (int i = 0; i < n; i++)
                            {
                                gedCheck(courseCore, "ENV", i);
                                gedCheck(courseCore, "ANT", i);
                                gedCheck(courseCore, "SOC", i);
                            }
                        }
                        else if ((strncmp(courseListTemp[k], "EC0", 3) == 0))
                        {
                            for (int i = 0; i < n; i++)
                            {
                                gedCheck(courseCore, "ECO", i);
                            }
                        }
                    }
                }
            }
    }

    int courseCheck(int courseCount, int initCount)
    {
        int i;

        for (i = initCount; i <= courseCount; i++)
        {
            if (strncmp("CSE", courseListTemp[i], 3) == 0 || (strncmp("EEE", courseListTemp[i], 3) == 0))
            {
                if (strncmp("EEE452", courseListTemp[i], 6) == 0 || strncmp("EEE154", courseListTemp[i], 6) == 0)
                {
                    courseAvailabilityChecker(core.schoolCore, 15, courseCount, i);
                }
                else
                {
                    courseAvailabilityChecker(core.cseCore, 28, courseCount, i);
                }
            }
            else if (strncmp("MAT", courseListTemp[i], 3) == 0 || (strncmp("PHY", courseListTemp[i], 3) == 0) || (strncmp("CHE", courseListTemp[i], 3) == 0))
            {
                courseAvailabilityChecker(core.schoolCore, 15, courseCount, i);
            }
            else
            {
                courseAvailabilityChecker(core.uniCore, 15, courseCount, i);
            }
        }
        return i;
    }

    int printData(int totalSemester)
    {
        int index = 0;
        int limit = 0;
        float semesterCredit;
        totalCredits = 0;

        colorPrint("The advisor system considers your currently enrolled courses as completed in order to function.", "b");
        colorPrint("\n\n\tList of Advised Courses:\n\t", "y");
        row(83);
        n();
        n();
        n();

        for (int i = 0; i < totalSemester; i++)
        {
            printf("\t\t  ");
            colorRow(2, "b", 25);
            printf(" Semester:");
            printf(" %d ", (i) + 1 + copy.userSemester);
            colorRow(2, "b", 25);

            index += perSemCourse[i];

            limit += perSemCourse[i + 1];

            semesterCredit = 0;

            n();
            colorPrint("\n\tInitial        Course Name                                                 Credit\n\t", "c");
            row(83);
            n();
            for (int j = index; j < limit; j++)
            {
                printf("\t%-15s%-60s%-10.1f\n", recommendedCourses[j].courseInitials, recommendedCourses[j].name, recommendedCourses[j].courseCredits);
                colorPrint("\t-----------------------------------------------------------------------------------", "y");
                n();

                totalCredits += (float)recommendedCourses[j].courseCredits;

                semesterCredit += (float)recommendedCourses[j].courseCredits;
            }

            if (totalSemester > 1)
            {
                colorPrint("\tTotal credits for this semester: ", "g");
                printf("%.2f\n", semesterCredit);
            }
            printf("\n");
            n();
        }

        printf("\tTotal credits: %.2f\n", totalCredits);
        printf("\tTotal credits with your completed credits: %.2f\n", totalCreditsCalc);
        printf("\tTotal credits without: %.2f\n\n", copy.doneCredit);

        colorPrint("For certain GED courses with alternative options, the system automatically suggests:\n", "g");
        colorPrint("\t1. SOC101 (SOC101/ANT101/ENV203)\n\t2. ECO101 (ECO101/ECO104)\n\t3. POL101 (POL101/POL104)\n", "y");
        colorPrint("This is done for the sake of simplicity.", "g");
    }

    void writeDataToFile(int totalSemester, const char *fileName)
    {
        int index = 0;
        int limit = 0;
        float semesterCredit = 0;

        FILE *file = fopen(fileName, "w"); // Open the file for writing

        if (file == NULL)
        {
            // printf("Error opening the file.\n");
            return;
        }

        for (int i = 0; i < totalSemester; i++)
        {
            fprintf(file, "\n\n");
            fprintf(file, "Semester: %d ============\n\n", (i) + 1);

            index += perSemCourse[i];

            limit += perSemCourse[i + 1];

            for (int j = index; j < limit; j++)
            {
                fprintf(file, "Initials: %s\n", recommendedCourses[j].courseInitials);
                fprintf(file, "Name: %s\n", recommendedCourses[j].name);
                fprintf(file, "Credits: %f\n", recommendedCourses[j].courseCredits);
                fprintf(file, "\n");
                totalCredits += (float)recommendedCourses[j].courseCredits;
            }
        }

        fprintf(file, "Total Credits: %.2f\n", totalCredits);

        fclose(file); // Close the file when done
    }

    void mainSystem()
    {
        int courseCount = atoi(courseListTemp[0]);
        getInput();

        int totalCount = cseCourse + uniCourse + schoolCourse;

        courseDivider();

        int recommendedCourseCount = 0;
        int prevCount = 1;
        int recIndx = 0;

        int diffBef, diffAft;

        perSemCourse[0] = 0;

        for (int i = 0; i < totalSemester; i++)
        {
            prevCount = courseCheck(courseCount, prevCount);
            diffBef = recommendedCourseCount;

            recommendedCourseCount += coursePicker(core.cseCore, cseCourse, recommendedCourses, recommendedCourseCount);
            recommendedCourseCount += coursePicker(core.uniCore, uniCourse, recommendedCourses, recommendedCourseCount);
            recommendedCourseCount += coursePicker(core.schoolCore, schoolCourse, recommendedCourses, recommendedCourseCount);

            diffAft = recommendedCourseCount;

            perSemCourse[i + 1] = diffAft - diffBef;

            if (i == 0)
            {
                adder(perSemCourse[i + 1], 0);
            }
            else
                adder(perSemCourse[i + 1], diffBef);

            courseCount = atoi(courseListTemp[0]);
        }

        printData(totalSemester);

        closeDialog();
    }
    void showAdvisorMenu()
    {
        ////clr()
        char *options1[] = {"Export Course Map", "Change Parameters", "Go back"};
        // char *options2[] = {"Start","Go back"};
        switch (showOption("Select an option:", options1, 3))
        {
        case 0:
            writeDataToFile(totalSemester, thisUserCourseMap);
            showAdvisorMenu();
            break;
        case 1:
            clearData();
            mainSystem();
            showAdvisorMenu();
        case 2:
            return;
            break;
        }
    }

    void showAdvisorMenu2()
    {
        // clr()
        char *options1[] = {"Start", "Go back"};
        // char *options2[] = {"Start","Go back"};
        switch (showOption("Select an option:", options1, 2))
        {
        case 0:
            mainSystem();
            showAdvisorMenu();
            break;
        case 1:
            return;
            break;
        }
    }

    loadUserData(thisUserFile);

    int courseCount = atoi(courseListTemp[0]);

    if (courseCount == 0)
    {
        colorPrint("You haven't entered your data yet. Please enter your data in the Dashboard option.", "r");
        closeDialog();
        return;
    }

    showAdvisorMenu2();
}
