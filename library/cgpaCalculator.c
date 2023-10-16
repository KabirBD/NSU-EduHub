
void cgpaCalculator() {
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
        printf("Your cgpa: %.2lf \n", cgpa);
        // return cgpa;
    }
}
