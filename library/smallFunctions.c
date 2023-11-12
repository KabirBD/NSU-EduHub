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

// return 1 if input is a decimal number
int needDeci(float n)
{
    return (n) ? (n != (int)n) : 0;
}

// show a slider with range and return selected integer
int slider(int min, int max)
{
    int x, y; // to store cursor position

    // Function to move the cursor to a specific position in the terminal
    void setCursorPosition(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    // Function to get current cursor position
    void getCursorPosition(int *x, int *y)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        {
            *x = csbi.dwCursorPosition.X;
            *y = csbi.dwCursorPosition.Y;
        }
    }

    // printing format on the terminal
    void showNum(int n)
    {
        colorPrint("  [<<]", "y");
        printf("... %d", n - 1);
        colorPrint(" [", "g"); 
        setColor("b");
        printf(" %d ", n);
        resetColor();
        colorPrint("] ", "g"); 
        printf("%d ...", n + 1);
        colorPrint("[>>]   ", "y");
    }

    int count = min;
    char key;
    getCursorPosition(&x, &y);
    colorPrint(" [<<] ", "y");
    colorPrint("Use Arrow Keys", "c");
    colorPrint("  [>>]", "y");
    usleep(1000000);
    setCursorPosition(x, y);
    showNum(count);

    while ((key = getch()) != 13)
    {
        switch (key)
        {
        case 75:
        case 80:
            setCursorPosition(x, y);
            if (count > min)
                count--;
            else
            {
                colorPrint("  Reached to Lower limit       ", "r");
                usleep(500000);
                setCursorPosition(x, y);
            }
            showNum(count);
            break;
        case 77:
        case 72:
            setCursorPosition(x, y);
            if (count < max)
                count++;
            else
            {
                colorPrint("  Reached to Upper limit      ", "r");
                usleep(500000);
                setCursorPosition(x, y);
            }
            showNum(count);
            break;
        default:
            if (key >= min + '0' && key <= max + '0')
            {
                setCursorPosition(x, y);
                count = key - '0';
                showNum(count);
            }
        }
    }
    printf("\n");
    return count;
}