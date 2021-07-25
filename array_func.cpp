//
// Created by Tr on 14.07.2021.
//

#include "array_func.h"

bool in_array(const char* in_str, char element) {
    size_t size_str = strlen(in_str);
    for (int i = 0; i < size_str; i++) {
        if (in_str[i] == element)
            return true;
    }
    return false;
}