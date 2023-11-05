void courseAdvisor()
{

    char thisUserFile[25];
    strcpy(thisUserFile, userName);
    strcat(thisUserFile, ".dat");


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
        int flag; //if flag is set to 1, course is unavailable.
    }courseDetails;

    typedef struct coreCoursesdiv
    {
        courseDetails schoolCore[15];
        courseDetails cseCore[28];
        courseDetails uniCore[15];
    }coreCoursesdiv;

    coreCoursesdiv core;

    courseDetails recommendedCourses[55];

    int perSemCourse[30];

    float totalCredits = 0;
    
    int totalSemester;

    int cseCourse, uniCourse, schoolCourse;

    void loadUserData(const char *filename)
    {
        FILE *file = fopen(filename, "rb");
        if (file == NULL) // if no file found named username.dat,
        {
            perror("Error opening file");
            return;
        }

        // Read user data from the file
        fread(&courseList, sizeof(courseList),1, file);

        fclose(file);
    }


    void courseCopier(courseDetails *course, int copiedTo, int source)
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
        course[copiedTo].flag = 1; // by default course is unavailable
    }

    int getValidInput(int min, int max, const char* prompt)
    {
        int input;
        do {
            printf("%s", prompt);
            scanf("%d", &input);
            if (input < min || input > max) 
            {
                printf("Please enter a number between %d and %d.\n", min, max);
            }
        } while (input < min || input > max);

        return input;
    }

    void courseDivider()
    {   
        int cse_count = 0, school_count = 0, uni_count = 0;

        for (int i = 0; i < (sizeof(coreCourses)/sizeof(coreCourses[0])); i++) // this whole part is a function
        {
            if(strncmp("CSE",coreCourses[i].initial, 3) == 0 || (strncmp("EEE",coreCourses[i].initial, 3) == 0) )
            {
                if(strncmp("EEE452",coreCourses[i].initial, 6) == 0 || strncmp("EEE154",coreCourses[i].initial, 6) == 0) 
                {
                    courseCopier(core.schoolCore,school_count,i);
                    school_count++;
                }
                else
                {
                    courseCopier(core.cseCore,cse_count,i);
                    cse_count++;
                } 

            }
            else if(strncmp("MAT",coreCourses[i].initial, 3) == 0 || (strncmp("PHY",coreCourses[i].initial, 3) == 0)|| (strncmp("CHE",coreCourses[i].initial, 3) == 0) )
            {
                    courseCopier(core.schoolCore,school_count,i);
                    school_count++;
            }
            else
            {
                courseCopier(core.uniCore,uni_count,i);
                uni_count++;
            }
            
        }
    }


    int coursePicker(courseDetails *courseCore, int limitCourses, courseDetails *recommendedCourses,int startIdx)
    {
        int numCourses = 0;

        for(int i = 0; numCourses<limitCourses; i++)
        {   

            if(courseCore[i].flag == 0)
            {
                
                recommendedCourses[numCourses+startIdx] = courseCore[i];

                if(strncmp(courseCore[i].courseInitials,courseCore[i+1].courseInitials,6) == 0) //checks if the next course is a lab course
                {
                    recommendedCourses[numCourses+startIdx + 1] = courseCore[i+1]; // if yes then adds it to recommended courses
                    numCourses += 2; //increase numCourse by 2 because of extra lab course
                    limitCourses++; //limit increased because of lab course
                    i++;// i incremented to skip next course, which is the lab course
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
        clr();

        totalSemester = getValidInput(1,8,"Enter the number of semesters(e.g. 1 if you want to be advised for your next semester): ");

        cseCourse = getValidInput(1,4,"Enter the number of CSE core courses you want per semester: ");

        uniCourse = getValidInput(1,4,"Enter the number of University core courses(GED) you want per semester: ");

        schoolCourse = getValidInput(1,4,"Enter the number of School core courses you want per semester: ");

        clr();
    }

    int adder(int recCount, int recIndx)
    {
        int j = recIndx;

        int z = atoi(courseList[0]);

        for(int i = z+1 ;i< z+1+recCount;i++)
        {
            
            strcpy(courseList[i], recommendedCourses[j].courseInitials);
            j++;
        }

        int newCount = z+recCount; 

        char newC[3];
        
        sprintf(newC, "%d",newCount);

        strcpy(courseList[0], newC);
    }

    int courseAvailabilityChecker(courseDetails *courseCore, int n,int courseCount, int k) 
    {
        for(int m = 0; m < n; m++) 
        {
            courseDetails *s_ptr = courseCore + m; // Pointer to the course in the core CSE courses.
            if((strcmp(courseList[k],courseCore[m].courseInitials)) != 0 && courseCore[m].flag == 1)  // checks if done course matches, the name of course in list. also checks if course is available(flag is set to 1 or 0)
            {
                if((courseCore[m].preReq1[0] == '\0' && courseCore[m].preReq2[0] == '\0'))//if both preReqs are null, meaning that there are no preReqs. so course is available.
                {
                    s_ptr->flag = 0;
                }
                else //enters if preReq are not null. now checks if preReq courses are completed or not.
                {
                    int preReq1_temp; 
                    int preReq2_temp; 
                    for(int g = 1 ;g<=courseCount;g++)
                    {
                            if(strcmp(courseCore[m].preReq1, courseList[g]) == 0)
                            {
                                preReq1_temp = 0;
                                break; //preRequisite course exists in the done course courseListay. so preReq is set to 0; 
                            }
                            else if(courseCore[m].preReq1[0] == '\0')
                            {
                                preReq1_temp = 0; //no preReq course. so loop breaks.
                                break;
                            }
                            else
                            {
                                preReq1_temp = 1; //preReq not completed so set to 1.
                            }
                        }
                    for(int g = 1; g<=courseCount;g++)
                    {
                            if(strcmp(courseCore[m].preReq2, courseList[g]) == 0)
                            {
                                preReq2_temp = 0;
                                break; // preRequisite course exists in the done course courseListay. so preReq is set to 0;
                            }
                            else if(courseCore[m].preReq2[0] == '\0')
                            {
                                preReq2_temp = 0; //no preReq course. so loop breaks.
                                break;
                            }
                            else
                            {
                                preReq2_temp = 1; //preReq not completed so set to 1.
                            }
                        }
                    s_ptr->flag = preReq2_temp || preReq1_temp; //changes the flag to 1 or 0. if both preReqs are done then sets it to 0, meaning course is available.
                }
            }
            else if((strcmp(courseList[k],courseCore[m].courseInitials)) == 0) //the course has already been completed. so flag is set to 2
            {
                s_ptr->flag = 2;
            }
        }
    }

    int courseCheck(int courseCount, int initCount)
    {
        int i;

        for(i = initCount; i <= courseCount; i++) 
        {
            if(strncmp("CSE",courseList[i], 3) == 0 || (strncmp("EEE",courseList[i], 3) == 0) )
            {
                if(strncmp("EEE452",courseList[i], 6) == 0 || strncmp("EEE154",courseList[i], 6) == 0) 
                {
                    courseAvailabilityChecker(core.schoolCore,15,courseCount,i);
                }
                else
                {
                    courseAvailabilityChecker(core.cseCore,28,courseCount,i);
                }    
            }
            else if(strncmp("MAT",courseList[i], 3) == 0 || (strncmp("PHY",courseList[i], 3) == 0)|| (strncmp("CHE",courseList[i], 3) == 0) )
            {
                    courseAvailabilityChecker(core.schoolCore,15,courseCount,i);
            }
            else
            {
                courseAvailabilityChecker(core.uniCore,15,courseCount,i);
            }
        }
        return i;
    }

    int printData(int totalSemester)
    {
        int index = 0;
        int limit = 0;

        for(int i = 0; i<totalSemester;i++)
        {            
            printf("\n\n");
            printf("Semester: %d ============\n\n", (i) + 1);

            index += perSemCourse[i];

            limit += perSemCourse[i+1];
            
            for(int j = index; j< limit; j++)
            {
                printf("Initials: %s\n", recommendedCourses[j].courseInitials);
                printf("Name: %s\n", recommendedCourses[j].name);
                printf("Credits: %f\n", recommendedCourses[j].courseCredits);
                printf("\n");
                totalCredits += (float)recommendedCourses[j].courseCredits;
            }

            printf("Total credits for Semester no. %d: %.2f\n", i+1, totalCredits);

        }

        printf("Total Credits: %.2f\n", totalCredits);
    }

        loadUserData(thisUserFile);

        int courseCount = atoi(courseList[0]);

        getInput();

        int totalCount = cseCourse + uniCourse +schoolCourse;
        
        courseDivider();

        int recommendedCourseCount = 0;
        int prevCount = 1;

        int diffBef, diffAft;

        perSemCourse[0] = 0;

        for(int i = 0; i<totalSemester; i++)
        {   
            prevCount = courseCheck(courseCount, prevCount);

            diffBef = recommendedCourseCount;

            recommendedCourseCount += coursePicker(core.cseCore,cseCourse,recommendedCourses,recommendedCourseCount);
            recommendedCourseCount += coursePicker(core.uniCore,uniCourse,recommendedCourses,recommendedCourseCount);
            recommendedCourseCount += coursePicker(core.schoolCore,schoolCourse,recommendedCourses,recommendedCourseCount);

            diffAft = recommendedCourseCount;

            perSemCourse[i+1] = diffAft - diffBef;

            int recIndx = perSemCourse[i-1] + perSemCourse[i];

            if(i == 0)
            {
                adder(perSemCourse[i+1],0);
            }
            else    
                adder(perSemCourse[i+1],recIndx);

            courseCount = atoi(courseList[0]);
        }

        printData(totalSemester);

        closeDialog();
}




