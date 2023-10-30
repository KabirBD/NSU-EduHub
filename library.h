//Internal libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

/// Import our own library functions
#include "./library/colorPrint.c"
#include "./library/logo.c"
#include "./library/smallFunctions.c"
#include "./library/authInterface.c"
#include "./library/option.c"
#include "./library/wrap.c"
#include "./library/collumn.c"
#include "./library/courses.c"
#include "./library/courseInfoQuery.c"
#include "./library/menu.c"
#include "./library/dashboard.c"
#include "./library/complex.c"
#include "./library/classSchedule.c"
#include "./library/cgpa.c"

/// Initialize our functions
// print colorful text
void setColor(char color[]);
void resetColor();
int colorPrint(char output[], char color[]);
// small functions
// clear console
void clr();
// print new line
void n();
// print a horizontal line of n number of characters(-)
void row(int n);
// print spaces of n number
void sp(int n);
//string upper case
void toUpperCase(char *str);
// return suffix of a number
const char *getSuffix(int n);
// wait for a chaacter input to complete the function
void closeDialog();
// print array as a row of multiple collumn
// colPrint(number collumn, collumn width, array of cell data)
void colPrint(int colN, int colLnth, char *arr[]);
// print logo
void logo();
// authentifacion interface
char userName[20];
int authInterface();
// showOption( title, options, number of options)
int showOption(char title[], char *options[], int n);
// display menu
int displayMenu();
//dashboard functionalities
void dashboard();
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
void courseInfoQuery();

// cgpa calculation
// double getGradePoint(int score);
// void cgpaCalculator();
// void multiCgpaCalculator();


void manageClassSchedule();

void cgpaInsight();


void toolsmenu();
