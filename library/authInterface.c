int authInterface()
{
    clr();
    n();
    printf(" Welcome To\n");
    logo();
    printf(" [ 1. Sign-in ]      [ 2. Sign-up ]       [ 3. Exit ]\n\n\n");

    int checkSelected()
    {
        switch (getch())
        {
        case '1':
        // Do what if user select sign in option
            signin();
            return 1;
            break;
        case '2':
        // Do what if user select sign up option
            signup();
            return 2;
            break;
        case '3':
        // If user select exit option
            printf("Exit selected");
            return 3;
            break;
        default:
            checkSelected();
        };
        return 0;
    };

    if (checkSelected() == 3)
    {
        //return 1 if user select exit
        return 1;
    };

    return 0;
};
