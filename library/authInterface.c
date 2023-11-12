char userName[20];
int authInterface()
{
    int user_num = 0;
    typedef struct acc // declares a struct of accounts.
    {
        char name[50];
        char pass[50];
    } account;

    account acc_num[50]; // declares an array of user structs

    account *current_user = 0;

    void getInput(char *input)
    {
        fflush(stdin); // Clears input buffer

        fgets(input, 50, stdin); // Read the input, ensuring it doesn't exceed the buffer size

        input[strcspn(input, "\n")] = '\0'; // Remove any character.
    };

    void saveData(const char *filename)
    {
        FILE *file = fopen(filename, "wb");
        if (file == NULL)
        {
            perror("Error opening file");
            return;
        }

        // Write user data to the file
        fwrite(&user_num, sizeof(int), 1, file);
        fwrite(&acc_num, sizeof(acc_num), 1, file);

        fclose(file);
    }

    void loadData(const char *filename)
    {
        FILE *file = fopen(filename, "rb");
        if (file == NULL) // if no file found named username.dat,
        {
            perror("Error opening file");
            saveData("usercred");
        }

        // Read user data from the file
        fread(&user_num, sizeof(user_num), 1, file);
        fread(&acc_num, sizeof(acc_num), 1, file);

        fclose(file);
    }

    int namepassCheck(const char *name, const char *pass) // verifies name and pass
    {
        for (int i = 0; i < user_num; i++)
        {
            int check_name = strcmp(acc_num[i].name, name);
            if (check_name == 0)
            {
                if (strcmp(acc_num[i].pass, pass) == 0)
                {
                    current_user = &acc_num[i]; // sets i to current user. to keep track of which user is logged in.
                    return 1;                   // successful check
                }

                colorPrint("Incorrect password.", "r");
                printf("\n");
                return -1;
            }
        }

        colorPrint("Incorrect username.", "r");
        printf("\n");
        return -1;
    };

    int signUp()
    {
        loadData("usercred");

        if (user_num >= 30)
        {
            printf("Sorry max user number reached.\n");
            return 0;
        }

        int n = user_num;

        colorPrint("Enter your account name: ", "c");

        do
        {
            getInput(acc_num[user_num].name);
            if (strlen(acc_num[user_num].name) <= 4)
            {
                printf("The username is too short.\n");
            }
        } while (strlen(acc_num[user_num].name) <= 4);

        colorPrint("Enter your password: ", "c");
        do
        {
            getInput(acc_num[user_num].pass);
            if (strlen(acc_num[user_num].pass) <= 5)
            {
                printf("The password is too short.\n");
            }
        } while (strlen(acc_num[user_num].pass) <= 5);

        for (int i = 0; i < user_num; i++)
        {
            if (strcmp(acc_num[i].name, acc_num[user_num].name) == 0)
            {
                printf("User name already exists. Please try again.\n");
                return 0;
            }
        }

        user_num++;

        saveData("usercred");
        loadData("usercred");

        namepassCheck(acc_num[n].name, acc_num[n].pass);

        strcpy(userName, acc_num[n].name); // I need current username for saving user info (Kabir)

        printf("Sign up successful.\n");

        return 1;
    };

    int signIn()
    {
        loadData("usercred");

        account temp;

        colorPrint("Enter your account name:", "c");
        fgets(temp.name, 50, stdin);
        temp.name[strcspn(temp.name, "\n")] = 0;

        colorPrint("Enter your password:", "c");
        int i = 0;
        char ch;
        char password[20];

        while (1)
        {
            ch = getch();

            if (ch == 13)
            { // Enter key
                password[i] = '\0';
                break;
            }
            else if (ch == 8)
            { // Backspace key
                if (i > 0)
                {
                    printf("\b \b"); // Move cursor back and overwrite with a space
                    i--;
                }
            }
            else
            {
                password[i] = ch;
                i++;
                printf("*"); // Print asterisks for password characters
            }
        }
        printf("\nPassword entered: %s\n", password);

        password[strcspn(password, "\n")] = 0;

        if (namepassCheck(temp.name, password) == 1)
        {
            printf("Sign in successful.\n");
            strcpy(userName, temp.name); // I need current username for saving user info (Kabir)
            return 1;
        }
        else
        {
            return 0;
        }
    };

    int checkSelected()
    {
        int choice;

        while (1)
        {
            choice = getch();

            switch (choice)
            {
            case '1':
                printf("Sign in selected.\n");
                usleep(200000); // program pauses for half a second.
                clr();
                if (signIn())
                    return 1;
                else
                {
                    printf("\t [ 1. Sign-in ]    [ 2. Sign-up ]    [ 3. Exit ]\n\n\n");
                    break; // Return indicating sign in was unsuccessful
                }
            case '2':
                printf("Sign up selected\n");
                usleep(200000); // program pauses for half a second.
                clr();
                if (signUp())
                    return 1;
                else
                    printf("\t [ 1. Sign-in ]    [ 2. Sign-up ]    [ 3. Exit ]\n\n\n");
                break;
            case '3':
                // If user selects exit option
                printf("Exit selected");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            };
        }
    }

    clr();
    n();
    printf("\t      ============= Welcome To =============\n");
    logo();
    printf("\t [ 1. Sign-in ]    [ 2. Sign-up ]    [ 3. Exit ]\n\n\n");

    return checkSelected();
}

