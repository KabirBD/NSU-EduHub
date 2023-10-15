

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
            if (n > 0 && n <= 9)
                printf("\t%c %d. %s\n", (optnSelected[i] ? '>' : ' '), (i + 1), options[i]);
            else
                printf("\t%c %s\n", (optnSelected[i] ? '>' : ' '), options[i]);
    }
    display();
    while ((key = getch()) != 13 && key != 32)
    {
        switch (key)
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
        if (n <= 9 && key >= '1' && key <= (n + '0'))
        {
            index = key - '1';
            break;
        }
    };
    return index;
}
