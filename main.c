// Header Section
#include "library.h"

// main function
int main()
{

    int result = authInterface();
    if (result == 1) 
        displayMenu();

    return 0;
}
