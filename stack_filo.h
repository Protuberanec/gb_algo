//
// Created by Tr on 25.07.2021.
//

#ifndef CPP_PROJ_STACK_FILO_H
#define CPP_PROJ_STACK_FILO_H

#include <stdio.h>
#include <iostream>
#include <cstring>

template<typename T>
class FILO {
private:
    T *filo_data;
    int size;
    int last_el_index;
public:
    FILO() : size(32), last_el_index(-1) {
        filo_data = new T [size];
        memset(filo_data, 0x00, size * sizeof(T));
    }
    FILO(int size_) : size(size_), last_el_index(-1) {
        filo_data = new T [size_];
        memset(filo_data, 0x00, size_ * sizeof(T));
    }
    ~FILO() {
        delete [] filo_data;
    }

    int push(const T& el);
    int pop(T& el);

};

template<typename T>
int FILO<T>::push(const T& el) {
    if (last_el_index == size) {
        return 0;
    }
    filo_data[++last_el_index] = el;
    return 1;
}
template<typename T>
int FILO<T>::pop(T &el) {
    if (last_el_index < 0) {
        return 0;
    }
    el = filo_data[last_el_index--];

    return 1;
}



#endif //CPP_PROJ_STACK_FILO_H
