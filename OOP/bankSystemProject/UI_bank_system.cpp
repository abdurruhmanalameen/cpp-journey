#include <iostream>
#include "clsLoginScreen.h"
using namespace std;

int main()
{
    // clsMainScreen::showMainMenu();
    while (true)
    {
        if (!clsLoginScreen::showLoginScreen())
        {
            break;
        }
    }

    return 0;
}