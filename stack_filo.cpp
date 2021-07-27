//
// Created by Tr on 25.07.2021.
//

#include "stack_filo.h"

FILO::FILO(int size_) : size(size_), last_el_index(-1) {
    ar = new char [size_];
    memset(ar, 0x00, size_ * sizeof(char));
}

FILO::FILO() : size(32), last_el_index(-1) {
    ar = new char [size];
    memset(ar, 0x00, size * sizeof(char));
}

FILO::~FILO() {
    delete [] ar;
}

int FILO::push(char el) {
    if (last_el_index == size) {
        return 0;
    }
    ar[++last_el_index] = el;
    return 1;
}

int FILO::pop(char &el) {
    if (last_el_index < 0) {
        return 0;
    }
    el = ar[last_el_index--];

    return 1;
}
