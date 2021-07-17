//
// Created by Tr on 15.07.2021.
//

#ifndef CPP_PROJ_CONSOLEWORK_H
#define CPP_PROJ_CONSOLEWORK_H

#include <iostream>
#include <stdlib.h>
using namespace std;

int GetNumber() {
    int number;
    cin >> number;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> number;
    }
    return number;
}

#endif //CPP_PROJ_CONSOLEWORK_H
