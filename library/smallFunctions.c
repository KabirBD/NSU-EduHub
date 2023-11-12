// small independent functions
void clr()
{
    system("cls"); // Clear the screen for Windows users, and clear terminal for Linux / Mac OS X Users
}
void n()
{
    printf("\n"); // line break
}
void row(int n) // print a horizontal line of n number of characters(-)
{
    for (int i = 1; i <= n; ++i)
        printf("-");
}
void sp(int n) // print spaces of n number
{
    for (int i = 1; i <= n; ++i)
        printf(" ");
}

void toUpperCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper((unsigned char)str[i]);
    }
}

const char *getSuffix(int n)
{
    // Handle the special cases first (11, 12, and 13)
    if (n >= 11 && n <= 13)
    {
        return "th";
    }

    // For other numbers, determine the suffix based on the last digit
    int lastDigit = n % 10;
    switch (lastDigit)
    {
    case 1:
        return "st";
    case 2:
        return "nd";
    case 3:
        return "rd";
    default:
        return "th";
    }
}

void closeDialog()
{
    colorPrint("\n Press any key to go back..\n", "g");
    if (getch())
        ;
}

void colorRow(int symbol, char color[], int n) // print a horizontal line of n number of characters(-)
{
    if (symbol == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            colorPrint("-", color);
        }
    }

    else
    {
        for (int i = 1; i <= n; ++i)
        {
            colorPrint("=", color);
        }
    }
}