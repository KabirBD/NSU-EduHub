
/// Internal Libraries
#include <stdio.h>
#include <string.h>
#include <conio.h>

/// Import our own library functions
#include "./library/logo.c"
#include "./library/smallFunctions.c"
#include "./library/menu.c"
#include "./library/wrap.c"
#include "./library/collumn.c"
#include "./library/CSEcourses.c"
#include "./library/courseInfoQuery.c"
#include "./library/complex.c"

/// Initialize our functions
// small functions
// clear console
void clr();
// print new line
void n();
// print a horizontal line of n number of characters(-)
void row(int n);
// print array as a row of multiple collumn
// colPrint(number collumn, collumn width, array of cell data)
void colPrint(int colN, int colLnth, char *arr[]);
//print logo
void logo();

// showOption( title, options, number of options)
int showOption(char title[], char *options[], int n);
// calculate complex number
void complex();
// wrap text function
void printWrap(const char *text, int lineWidth);
// CSE courses query and display
struct courseObj courses[];
void courseInfoQuery();