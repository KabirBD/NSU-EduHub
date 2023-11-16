void courseTable()
{
    colorPrint("\n\t\t\t\tList of All Courses for CSE Degree \n", "g");
    row(107);
    printf("\n\n");
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
        printf("\n| %-10s| %-60s| %-8.*f| %-20s|\n", coreCourses[i].initial, coreCourses[i].name, needDeci(coreCourses[i].credit), coreCourses[i].credit, analyseReq(coreCourses[i].require));
        row(107);
    }

    char *trails[] = {"Not Selected", "Algorithms and Computation", "Software Engineering", "Networks", "Computer Architecture and VLSI", "Artificial Intelligence", "Bioinformatics"};
    for (int trail = 1; trail <= 6; trail++)
    {
        getTrailCourses(trail);
        printf("\n\n");
        colorPrint(trails[trail], "g");
        n();
        setColor("b");
        row(107);
        printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
        row(107);
        resetColor();
        for (int i = 0; i < trailLnth; i++)
        {
            printf("\n| %-10s| %-60s| %-8.*f| %-20s|\n", trailCourses[i].initial, trailCourses[i].name, needDeci(trailCourses[i].credit), trailCourses[i].credit, analyseReq(trailCourses[i].require));
            row(107);
        }
    }
    n();
    n();
}