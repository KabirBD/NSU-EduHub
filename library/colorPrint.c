
int colorPrint(char output[], char color[])
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (color == "r" || color == "red")
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED);
    else if (color == "g" || color == "green")
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    else if (color == "b" || color == "blue")
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    else if (color == "y" || color == "yellow")
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    else if (color == "c" || color == "cyan")
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
    else if (color == "m" || color == "magenta")
        SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);

    int size = printf("%s", output);

    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return size;
}