//
// Created by Tr on 29.07.2021.
//

#ifndef CPP_PROJ_STACK_FIFO_H
#define CPP_PROJ_STACK_FIFO_H

#include <iostream>

template<typename T>
class FIFO {
private:
    T *fifo_data;
    int size;
    int last_el_index;
public:
    FIFO() : size(32), last_el_index(-1) {
        fifo_data = new T [size];
        memset(fifo_data, 0x00, size * sizeof(T));
    }
    FIFO(int size_) : size(size_), last_el_index(-1) {
        fifo_data = new T [size_];
        memset(fifo_data, 0x00, size_ * sizeof(T));
    }
    ~FIFO() {
        delete [] fifo_data;
    }

    int push(const T& el);
    int pop(T& el);

    int ShowAllElements() {
        for (int i = 0; i < last_el_index+1; i++) {
            std::cout << fifo_data[i] << " ";
        }
        std::cout << std::endl;
        return last_el_index;
    }
    int getAmountEl() const {
        return last_el_index + 1;
    }
};

template<typename T>
int FIFO<T>::push(const T& el) {
    if (last_el_index == size) {
        return 0;
    }
    fifo_data[++last_el_index] = el;
    return 1;
}
template<typename T>
int FIFO<T>::pop(T &el) {
    if (last_el_index < 0) {
        return 0;
    }

    el = fifo_data[0];

    for (int i = 1; i < last_el_index+1; i++) {
        fifo_data[i-1] = fifo_data[i];
    }
    --last_el_index;

    return 1;
}



#endif //CPP_PROJ_STACK_FIFO_H
