

// Function to display a list of options and return the index of the selected option.
int showOption(char title[], char *options[], int n)
{
    int optnSelected[n], index = 0;
    char key;
    void display()
    {
        system("cls");
        for (int i = 0; i < n; i++)
            optnSelected[i] = 0;
        optnSelected[index] = 1;
        if (title[0] != '\0') // Check if title is not an empty string
            printf("%s\n", title);

        for (int i = 0; i < n; i++)
            printf("\t%c %s\n", (optnSelected[i] ? '>' : ' '), options[i]);
    }
    display();
    while ((key = getch()) != 13 && key != 32)
    {
        switch (getch())
        {
        case 72: // Up arrow
            if (index != 0)
                index--;
            else
                index = n - 1;
            display();
            break;
        case 80: // Down arrow
            if (index != (n - 1))
                index++;
            else
                index = 0;
            display();
            break;
        }
    };
    return index;
}
