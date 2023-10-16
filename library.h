
/// Internal Libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

/// Import our own library functions
#include "./library/logo.c"
#include "./library/smallFunctions.c"
#include "./library/authInterface.c"
#include "./library/option.c"
#include "./library/wrap.c"
#include "./library/collumn.c"
#include "./library/courses.c"
#include "./library/courseInfoQuery.c"
#include "./library/menu.c"
#include "./library/complex.c" 
#include "./library/gradePoint.c" 
#include "./library/cgpaCalculator.c" 


/// Initialize our functions
// small functions
// clear console
void clr();
void courseInfoQuery();
// print new line
void n();
// print a horizontal line of n number of characters(-)
void row(int n);
// print array as a row of multiple collumn
// colPrint(number collumn, collumn width, array of cell data)
void colPrint(int colN, int colLnth, char *arr[]);
// print logo
void logo();
// authentifacion interface
int authInterface();
// showOption( title, options, number of options)
int showOption(char title[], char *options[], int n);
// display menu
int displayMenu();
// calculate complex number
void complex();
// wrap text function
void printWrap(const char *text, int lineWidth);
// CSE courses query and display
struct courseObj coreCourses[];
struct courseObj algorithCourses[];
struct courseObj softwareCourses[];
struct courseObj networkCourses[];
struct courseObj AICourses[];
struct courseObj bioinformaticsCourses[];

int user_num = 0;
typedef struct acc //declares a struct of accounts.
{
    char name[50];
    char pass[50];
}account;

account acc_num[100]; //declares an array of user structs

const char* SCAN_FORMAT = "(%[^,], %[^)])\n"; 
const char* PRINT_FORMAT = "(%s, %s)\n"; 
const char* FILENAME = "userCredentials.txt"; 
const char* USERNUM = "userNUM.txt"; 

account *current_user = NULL;

account temp;

//cgpa calculation
double getGradePoint(int score);
void cgpaCalculator();