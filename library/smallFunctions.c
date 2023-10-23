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
    printf("\n");
}

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}