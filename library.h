// Internal libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

/// Import our own library functions files
#include "./library/colorPrint.c"
#include "./library/logo.c"
#include "./library/smallFunctions.c"
#include "./library/authInterface.c"
#include "./library/option.c"
#include "./library/wrap.c"
#include "./library/courses.c"
#include "./library/courseInfoQuery.c"
#include "./library/courseTable.c"
#include "./library/availableCourses.c"
#include "./library/menu.c"
#include "./library/dashboard.c"
#include "./library/classSchedule.c"
#include "./library/cgpa.c"
#include "./library/courseAdvisor.c"

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
// print tab
void tab();
// string upper case
void toUpperCase(char *str);
// return suffix of a number
const char *getSuffix(int n);
// wait for a chaacter input to complete the function
void closeDialog();
// print a horizontal line of n number of characters(-)
void colorRow(int symbol, char color[], int n);
// return 1 if float need decimal else return 0 if float is an integer num
int needDeci(float n);
// show a slider with range and return selected integer
int slider(int min, int max);

// print logo
void logo();

// authentifacion interface
char userName[20];
int authInterface();

// showOption( title, options, number of options)
int showOption(char title[], char *options[], int n);

// wrap text function
void printWrap(const char *text, int lineWidth);

// CSE courses objects
struct courseObj coreCourses[];
struct courseObj algorithCourses[];
struct courseObj softwareCourses[];
struct courseObj networkCourses[];
struct courseObj AICourses[];
struct courseObj bioinformaticsCourses[];
struct courseObj *trailCourses;
int trailLnth;
// get a particular trail courses in trailCourses object with traillnth from the index of trail
void getTrailCourses(int trail);
char *analyseReq(const char require[20]);

// course manager
void courseInfoQuery();
void courseTable();
void availableCourses();

// display main menu
int displayMenu();

// dashboard functionalities
void dashboard();

// class schedle management
void manageClassSchedule();

// cgpa calculations
void cgpaInsight();

void courseAdvisor();
