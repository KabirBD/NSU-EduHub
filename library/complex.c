
void complex()
{
    struct complex
    {
        int r;
        int i;
    } c1, c2;

    printf("Enter Real part of 1st complex number: ");
    scanf("%d", &c1.r);

    printf("Enter Imaginary part of 1st complex number: ");
    scanf("%d", &c1.i);

    printf("Enter Real part of 2nd complex number: ");
    scanf("%d", &c2.r);

    printf("Enter Imaginary part of 2nd complex number: ");
    scanf("%d", &c2.i);

    int sumR = c1.r + c2.r;
    int sumI = c1.i + c2.i;
    if (sumI < 0)
        printf("\nSum= %d%di", sumR, sumI);
    else
        printf("\nSum= %d+%di", sumR, sumI);

    int difR = c1.r - c2.r;
    int difI = c1.i - c2.i;
    if (difI < 0)
        printf("\nDifference= %d%di", difR, difI);
    else
        printf("\nDifference= %d+%di", difR, difI);

    int prdR = c1.r * c2.r - c1.i * c2.i;
    int prdI = c1.r * c2.i + c2.r * c1.i;
    if (prdI < 0)
        printf("\nProduct= %d%di", prdR, prdI);
    else
        printf("\nProduct= %d+%di", prdR, prdI);
}
