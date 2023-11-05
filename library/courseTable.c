void courseTable()
{
    colorPrint("\n\t\t\t\tList of All Courses for CSE Degree \n\n", "g");

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
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", coreCourses[i].initial, coreCourses[i].name, coreCourses[i].credit, coreCourses[i].require);
        row(107);
    }
    courseLenth = sizeof(algorithCourses) / sizeof(algorithCourses[0]);
    colorPrint("\n\nAlgorithms and Computation Courses\n", "g");
    setColor("b");
    row(107);
    printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
    row(107);
    resetColor();
    for (int i = 0; i < courseLenth; i++)
    {
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", algorithCourses[i].initial, algorithCourses[i].name, algorithCourses[i].credit, algorithCourses[i].require);
        row(107);
    }
    courseLenth = sizeof(softwareCourses) / sizeof(softwareCourses[0]);
    colorPrint("\n\nSoftware Engineering Courses\n", "g");
    setColor("b");
    row(107);
    printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
    row(107);
    resetColor();
    for (int i = 0; i < courseLenth; i++)
    {
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", softwareCourses[i].initial, softwareCourses[i].name, softwareCourses[i].credit, softwareCourses[i].require);
        row(107);
    }
    courseLenth = sizeof(networkCourses) / sizeof(networkCourses[0]);
    colorPrint("\n\nNetworks Courses\n", "g");
    setColor("b");
    row(107);
    printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
    row(107);
    resetColor();
    for (int i = 0; i < courseLenth; i++)
    {
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", networkCourses[i].initial, networkCourses[i].name, networkCourses[i].credit, networkCourses[i].require);
        row(107);
    }
    courseLenth = sizeof(architectureCourses) / sizeof(architectureCourses[0]);
    colorPrint("\n\nComputer Architecture and VLSI Courses\n", "g");
    setColor("b");
    row(107);
    printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
    row(107);
    resetColor();
    for (int i = 0; i < courseLenth; i++)
    {
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", architectureCourses[i].initial, architectureCourses[i].name, architectureCourses[i].credit, architectureCourses[i].require);
        row(107);
    }
    courseLenth = sizeof(AICourses) / sizeof(AICourses[0]);
    colorPrint("\n\nArtificial Intelligence Courses\n", "g");
    setColor("b");
    row(107);
    printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
    row(107);
    resetColor();
    for (int i = 0; i < courseLenth; i++)
    {
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", AICourses[i].initial, AICourses[i].name, AICourses[i].credit, AICourses[i].require);
        row(107);
    }
    courseLenth = sizeof(bioinformaticsCourses) / sizeof(bioinformaticsCourses[0]);
    colorPrint("\n\nBioinformatics Courses\n", "g");
    setColor("b");
    row(107);
    printf("\n| %-10s| %-60s| %-8s| %-20s|\n", "Initial", "Name", "Credit", "Pre-requisites");
    row(107);
    resetColor();
    for (int i = 0; i < courseLenth; i++)
    {
        printf("\n| %-10s| %-60s| %-8.1f| %-20s|\n", bioinformaticsCourses[i].initial, bioinformaticsCourses[i].name, bioinformaticsCourses[i].credit, bioinformaticsCourses[i].require);
        row(107);
    }
    colorPrint("\n\n # In pre-requisites, c-[n] means that the course requires [n] credits completed \n", "y");
    n();
    n();
}