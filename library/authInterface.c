int authInterface()
{
    clr();
    n();
    printf(" Welcome To\n");
    logo();
    printf(" [ 1. Sign-in ]      [ 2. Sign-up ]       [ 3. Exit ]\n\n\n");
    int user_num = 0;
    typedef struct acc //declares a struct of accounts.
    {
        char name[50];
        char pass[50];
    }account;

    account acc_num[100]; //declares an array of user structs

    const char* SCAN_FORMAT = "(%[^,], %[^)])\n"; 
    const char* PRINT_FORMAT = "(%s, %s)\n"; 
    const char* FILENAME = "u1serCredentials.txt"; 
    const char* USERNUM = "u1serNUM.txt"; 

    account *current_user = 0;

FILE *fileHandler(const char* mode)
{     
    FILE *file_ptr;
    
    if (access(FILENAME, F_OK) != -1)
    {
        file_ptr = fopen(FILENAME, mode);
    }
    else
    {
        file_ptr = fopen(FILENAME, "w+");
    }


    if (file_ptr == NULL)
    {
        printf("Error in opbening file.");
    }

    return file_ptr;
};

void getInput(char *input) 
{
    fflush(stdin); // Clears input buffer
    
    fgets(input, 50, stdin); // Read the input, ensuring it doesn't exceed the buffer size

    input[strcspn(input, "\n")] = '\0'; // Remove any character.
}


void saveUsernum() 
{
    FILE *file = fopen(USERNUM, "w+");
    if (file == NULL) 
        {
            printf("Error opening user num file");
            return;
        }

    fseek(file, 0, SEEK_SET);  //put file pointer at the start of the file.
    fprintf(file, "%d", user_num);

    fclose(file);

};

void readUsernum() 
{
    FILE *file_num;

    if (access(USERNUM, F_OK) != -1)
    {
        file_num = fopen(USERNUM, "r+");
    }
    else
    {
        file_num = fopen(USERNUM, "w+");
    }
    if (file_num == NULL) 
        {
            printf("Error opening user num file");
            return;
        }

    fseek(file_num, 0, SEEK_SET);

    if(fscanf(file_num, "%d", &user_num)!= 0)
    {
        printf("Error while reading user num. No data in file.Signing up will fix this error.");
        user_num = 0;
    }

};

void writeUserdata(FILE *file_ptr, int k)
{
    fprintf_s(file_ptr,PRINT_FORMAT,acc_num[k].name,acc_num[k].pass);
};

void readUserdata()
{
    int i = 0;
    char buff[150];
    FILE *file_ptr = fileHandler("r+");
    if (file_ptr == NULL)
    {
        printf("Error in opening file.");
        exit(1);
    }
    
    //fgets(buff, 150, file_ptr);

    while (fgets(buff, sizeof(buff), file_ptr) != NULL)
    {
        account *s_ptr = acc_num + i;
        sscanf(buff, SCAN_FORMAT, s_ptr->name, s_ptr->pass);
        i++;
    }

    user_num = i;
} ;

int namepassCheck(const char* name, const char* pass) //verifies name and pass
{   
    for(int i = 0; i<user_num; i++)
    {
        int check_name = strcmp(acc_num[i].name,name); 
        if(check_name == 0)
        {
            if(strcmp(acc_num[i].pass,pass) == 0)

                current_user = &acc_num[i]; //sets i to current user. to keep track of which user is logged in.
                return 1;// successful check
        }

    }
    return -1;
};

int signUp()
{
    if(user_num >= 10)
    {
        printf("Sorry max user number reached.");
        return 0;
    }

    int n=user_num;

    printf("Enter your account name: ");
    getInput(acc_num[user_num].name);

    printf("Enter your password: ");
    getInput(acc_num[user_num].pass);

    for(int i = 0; i<user_num;i++)
    {
        if(strcmp(acc_num[i].name,acc_num[user_num].name ) == 0)
        {
            printf("User name already exists. Please try again.");
            return 0;
        }
    }
    writeUserdata(fileHandler("a"), user_num);
    readUserdata();
    
    namepassCheck(acc_num[n].name,acc_num[n].pass);

    user_num++;

    saveUsernum();

    printf("Sign up successful.");


    return 1;
};

int signIn()
{
    account temp;

    printf("Enter your account name:");
     fgets(acc_num[user_num].name, 50, stdin);
    acc_num[user_num].name[strcspn(acc_num[user_num].name,"\n")] = 0;

    printf("Enter your password:");
    fgets(acc_num[user_num].pass, 50, stdin);
    acc_num[user_num].pass[strcspn(acc_num[user_num].pass,"\n")] = 0;


        if (namepassCheck(temp.name, temp.pass) == 1) //checks through every existing account
        {   
            printf("Login successful.\n");
            return 1;

        }
        
        printf("Login unsuccessful.\n");
        return 0;
};

    int checkSelected()
    {
        switch (getch())
        {
        case '1':
            printf("Sign in selected");
            usleep(500000); // program pauses for half a second.
            clr();
            readUserdata();
            saveUsernum();
            signIn();
            saveUsernum();
            return 1;
            break;
        case '2':
            printf("Sign up selected");
            usleep(500000); // program pauses for half a second.
            clr();
            readUserdata();
            saveUsernum();
            signUp();
            saveUsernum();
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

    if(checkSelected() == 3)
    {
        return 0;
    };

    checkSelected();

}
