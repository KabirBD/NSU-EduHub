#include <stdio.h>

double getGradePoint(int score) {
    if (score >= 93) {
        return 4.0;
    } else if (score >= 90) {
        return 3.7;
    } else if (score >= 87) {
        return 3.3;
    } else if (score >= 83) {
        return 3.0;
    } else if (score >= 80) {
        return 2.7;
    } else if (score >= 77) {
        return 2.3;
    } else if (score >= 73) {
        return 2.0;
    } else if (score >= 70) {
        return 1.7;
    } else if (score >= 67) {
        return 1.3;
    } else if (score >= 60) {
        return 1.0;
    } else {
        return 0.0;
    }
}





void singleCgpaCalculator() {
    int numCourses;
    double totalGradePoints = 0;
    int totalCreditHours = 0;

    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);

    for (int i = 1; i <= numCourses; i++) {
        int score;
        int creditHours;

        printf("Enter the numerical score for Course %d: ", i);
        scanf("%d", &score);

        printf("Enter the credit hours for Course %d: ", i);
        scanf("%d", &creditHours);

        double gradePoint = getGradePoint(score);
        totalGradePoints += gradePoint * creditHours;
        totalCreditHours += creditHours;
    }

    if (totalCreditHours == 0) {
        printf("Error: Total credit hours cannot be zero.\n");
        // return -1.0; // Indicate an error
    } else {
        double cgpa = totalGradePoints / totalCreditHours;
        printf("\n\033[32mYour CGPA: %.2lf \033[0m\n", cgpa);
        // return cgpa;
    }
}





void multiCgpaCalculator() {
    int numSemesters;
    double totalGradePoints = 0;
    int totalCreditHours = 0;

    printf("Enter the number of semesters: ");
    scanf("%d", &numSemesters);

    for (int semester = 1; semester <= numSemesters; semester++) {
        int numCourses;
        double semesterGradePoints = 0;
        int semesterCreditHours = 0;

        printf("Semester %d:\n", semester);
        printf("Enter the number of courses for this semester: ");
        scanf("%d", &numCourses);

        for (int i = 1; i <= numCourses; i++) {
            int score;
            int creditHours;

            printf("Enter total score for Course %d: ", i);
            scanf("%d", &score);

            printf("Enter the credit hours for Course %d: ", i);
            scanf("%d", &creditHours);

            double gradePoint = getGradePoint(score);
            semesterGradePoints += gradePoint * creditHours;
            semesterCreditHours += creditHours;
        }

        if (semesterCreditHours == 0) {
            printf("Error: Total credit hours cannot be zero for Semester %d.\n", semester);
        } else {
            double semesterCGPA = semesterGradePoints / semesterCreditHours;
            totalGradePoints += semesterGradePoints;
            totalCreditHours += semesterCreditHours;
            printf("\n\033[32mCGPA for Semester %d: %.2lf\033[0m\n\n", semester, semesterCGPA);
        }
    }

    if (totalCreditHours == 0) {
        printf("Error: Total credit hours cannot be zero.\n");
    } else {
        double overallCGPA = totalGradePoints / totalCreditHours;
        printf("\n\033[32mOverall CGPA for all semesters: %.2lf\033[0m\n", overallCGPA);
    }

}


// Start --- What If CGPA Analysis
struct Course {
    int score;
    int creditHours;
};

void calculateCGPA(struct Course courses[], int numCourses, double *cgpa) {
    double totalGradePoints = 0;
    int totalCreditHours = 0;

    for (int i = 0; i < numCourses; i++) {
        double gradePoint = getGradePoint(courses[i].score);
        totalGradePoints += gradePoint * courses[i].creditHours;
        totalCreditHours += courses[i].creditHours;
    }

    if (totalCreditHours == 0) {
        printf("Error: Total credit hours cannot be zero.\n");
    } else {
        *cgpa = totalGradePoints / totalCreditHours;
        printf("\n\033[32mYour CGPA: %.2lf\033[0m\n", *cgpa);
    }
}

void whatIfCgpa() {
    int numCourses;
    
    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);
    
    struct Course courses[numCourses];

    // Input course information
    for (int i = 0; i < numCourses; i++) {
        printf("Enter the numerical score for Course %d: ", i + 1);
        scanf("%d", &courses[i].score);

        printf("Enter the credit hours for Course %d: ", i + 1);
        scanf("%d", &courses[i].creditHours);
    }

    double cgpa;
    calculateCGPA(courses, numCourses, &cgpa);

    // Edit a course result
    int courseToEdit;
    printf("\nEnter the course number you want to edit: ");
    scanf("%d", &courseToEdit);

    if (courseToEdit > 0 && courseToEdit <= numCourses) {
        int newScore;
        printf("Enter the new numerical score for Course %d: ", courseToEdit);
        scanf("%d", &newScore);

        courses[courseToEdit - 1].score = newScore;

        // Recalculate CGPA
        calculateCGPA(courses, numCourses, &cgpa);
    } else {
        printf("Invalid course number to edit.\n");
    }

}

// End --- What If CGPA Analysis


// void cgpaInsight() {
//     int choice;

//     clr();

//     while (1) {
//         printf("\n\033[32mCGPA Insight:\033[0m\n\n");
//         printf("1. Calculate Single Semester CGPA\n");
//         printf("2. Calculate Multiple Semester CGPA\n");
//         printf("3. What If CGPA Analysis\n");
//         printf("4. Back to Main Menu\n\n");

//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 clr();
//                 singleCgpaCalculator();
//                 closeDialog();
//                 cgpaInsight();
//                 break;
//             case 2:
//                 clr();
//                 multiCgpaCalculator();
//                 closeDialog();
//                 cgpaInsight();
//                 break;
//             case 3:
//                 clr();
//                 whatIfCgpa();
//                 closeDialog();
//                 cgpaInsight();
//                 break;
//             case 4:
//                 displayMenu();
//                 //printf("Goodbye!\n");
//                 //return; // Return instead of exiting
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }
// }



void cgpaInsight() {

    clr();

    char *options[] = {"Calculate Single Semester CGPA", "Calculate Multiple Semester CGPA", "What If CGPA Analysis", "Back to Main Menu"};

    switch (showOption("Choose an option below:", options, 4)) {
        
        case 0:
            clr();
            singleCgpaCalculator();
            closeDialog();
            cgpaInsight();
            break;

        case 1:
            clr();
            multiCgpaCalculator();
            closeDialog();
            cgpaInsight();
            break;

        case 2:
            clr();
            whatIfCgpa();
            closeDialog();
            cgpaInsight();
            break;   

        case 3:
            clr();
            displayMenu();
    }
}

