//
// Created by Tr on 05.08.2021.
//

#include "my_hash.h"

int hash_simple(const char* string) {
    int size = strlen(string);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += string[i];
    }

    return sum;
}