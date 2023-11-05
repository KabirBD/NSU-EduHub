// Header Section
#include "library.h"

// main function2
int main()
{

    int status = authInterface();
    if (status == 1) 
        displayMenu();

    return 0;
}
