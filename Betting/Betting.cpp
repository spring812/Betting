#include <iostream>
#include <Windows.h>
#include "BetBase.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BetBase* bb = new BetBase();
    bb->run();
}
