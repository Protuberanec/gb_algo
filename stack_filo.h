//
// Created by Tr on 25.07.2021.
//

#ifndef CPP_PROJ_STACK_FILO_H
#define CPP_PROJ_STACK_FILO_H

#include <stdio.h>
#include <iostream>
#include <cstring>

class FILO {
private:
    char *ar;
    int size;
    int last_el_index;
public:
    FILO();
    FILO(int size_);

    ~FILO();

    int push(char el);
    int pop(char& el);

};

#endif //CPP_PROJ_STACK_FILO_H
