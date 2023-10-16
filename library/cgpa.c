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

double calculateCGPA() {
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
        return -1.0; // Indicate an error
    } else {
        double cgpa = totalGradePoints / totalCreditHours;
        return cgpa;
    }
}
