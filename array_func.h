//
// Created by Tr on 14.07.2021.
//

#ifndef CPP_PROJ_ARRAY_FUNC_H
#define CPP_PROJ_ARRAY_FUNC_H

#include <time.h>
#include <random>

//#define REAL_UNIQUE

template<class T>
void Create2DArray(T** &ar, int col, int row, bool fill_rand = true) {
    ar = new T *[row];

    T *temp_ar;
    if (fill_rand == true) {
        temp_ar = new T [col*row];
        memset(temp_ar, 0x00, col*row * sizeof(T));
    }

    for (int i = 0; i < row; i++) {
        ar[i] = new T [col];
        if (fill_rand == true) {
            srand(time(NULL));
            for (int j = 0; j < col; j++) {
                T uniq = rand() % 200;
                //fill unique number
                int i_u = 0;
                for (; i_u < i*row + j; i_u++) {
                    while (temp_ar[i_u] == uniq) {
                        uniq = rand() % 200;
#ifdef  REAL_UNIQUE
                        i_u = 0;    //for real unique number
#endif
                    }
                }
                temp_ar[i_u] = uniq;
                ar[i][j] = uniq;
            }
        }
    }

    if (fill_rand == true) {
        delete [] temp_ar;
    }
}

template<class T>
void Release2DArray(T** ar, int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] ar[i];
    }
    delete [] ar;
}

template<class T>
void Copy2DArray(T** ar_dest, T* ar_cp, int col, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ar_dest[i][j] = ar_cp[j + row*i];
        }
    }
}

template<class T>
void FillRandom1DArray(T* arr, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

#endif //CPP_PROJ_ARRAY_FUNC_H
