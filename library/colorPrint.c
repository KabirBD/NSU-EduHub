void setColor(char color[])
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color[0])
    {
    case 'r':
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED);
        break;
    case 'g':
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        break;
    case 'b':
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        break;
    case 'y':
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        break;
    case 'c':
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
        break;
    case 'm':
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
        break;
    }
}
void resetColor()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
int colorPrint(char output[], char color[])
{
    setColor(color);
    int size = printf("%s", output);
    resetColor();
    return size;
}