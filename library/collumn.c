
void colPrint(int colN, int colLnth, char *arr[])
{
    int space;
    for (int i = 0; i < colN; i++)
    {

        printf("| ");
        space = colLnth - 3;
        space -= printf("%s", arr[i]);
        for (int j = 0; j <= space; j++)
            printf(" ");
    }
    printf("|");
    printf("\n");
    for (int j = 0; j <= colLnth * colN; j++)
        printf("-");
    printf("\n");
}
