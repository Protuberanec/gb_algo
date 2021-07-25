//
// Created by Tr on 14.07.2021.
//

#ifndef CPP_PROJ_ARRAY_FUNC_H
#define CPP_PROJ_ARRAY_FUNC_H

#include <time.h>
#include <random>
#include <stdio.h>
#include <cstring>
#include <iostream>

//#define REAL_UNIQUE


bool in_array(const char* in_str, char element);

template<class T>
void Create1DArray(T* &ar, int size, bool fill_rand = true, bool unique = true) {
    ar = new T [size];
    memset(ar, 0x00, size * sizeof(T));

    if (fill_rand != true) {
        return;
    }

    T *array_unique_number;
    if (unique == true) {
        array_unique_number = new T[size];
        memset(array_unique_number, 0x00, size * sizeof(T));
    }

    srand(time(NULL));

    for (int j = 0; j < size; j++) {
        T uniq_number = rand() % 999 + 1;   //exclude zero
        //fill unique number
        if (unique == false) {
            ar[j] = uniq_number;
            continue;
        }

        int i_u = 0;
        for (; i_u < j; i_u++) {
            while (array_unique_number[i_u] == uniq_number) {
                uniq_number = rand() % (size*2);
#ifdef  REAL_UNIQUE //else will appear duplicate
                i_u = 0;    //for real unique number
#endif
            }
        }
        array_unique_number[i_u] = uniq_number;
        ar[j] = uniq_number;
    }
    if (unique == true) {
        delete[] array_unique_number;
    }
}
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
void array1D_Copy(T* ar_dest, T* ar_cp, int size) {
    for (int i = 0; i < size; i++) {
        ar_dest[i] = ar_cp[i];
    }
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
bool is2DArraySorted(T *arr, int row_size, int col_size, bool ascending = true) {
    int total_size = row_size*col_size - 1; //for optimize, that not multiply every cycle
    if (ascending == true) {
        for (int i = 0; i < total_size; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    }
    else if (ascending == false) {}

    return true;
}
template<class T>
bool array1D_isSorted(T *arr, int size, bool ascending = true) {
    if (ascending == true) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    }
    else if (ascending == false) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    }

    return true;
}
template<class T>
void array1D_Print(T* arr, int size, const char* info = nullptr) {
    if (info != nullptr) {
        std::cout << info << " : ";
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
template<class T>
void array1D_FillRandom(T *ar, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        ar[i] = rand() % 100;
    }
}
template<class T>
bool array1D_compareAllNumbers(T* array0, T* array1, int size) {
    for (int i = 0; i < size; i++) {
        if (array0[i] != array1[i]) {
            return false;
        }
    }
    return true;
}
template<class T>
bool array1D_compareODDNumber(T* source, T* array, int size) {
    for (int i = 0; i < size; i++) {
        if (source[i] % 2) {
            if (source[i] != array[i]) {
                return false;
            }
        }
    }
    return true;
}
template<class T>
bool array1D_compareSortEvenNumber(T* source, int size, bool ascending = true) {
    int index_prev = -1;
    for (int i = 0; i < size; i++) {
        if (source[i] % 2) {
            continue;
        }
        if (index_prev == -1) {
            index_prev = i;
            continue;
        }
        if (source[index_prev] > source[i]) {
            return false;
        }
        index_prev = i;
    }
    return true;
}
template<class T>
int array1D_GetIndexMax(T* ar, int size) {
    int ind_max = 0;
    for (int i = 1; i < size; i++) {
        if (ar[ind_max] < ar[i]) {
            ind_max = i;
        }
    }
    return ind_max;
}

template<class T>
int array1D_GetIndexMin(T* ar, int size) {
    int ind_min = 0;
    for (int i = 1; i < size; i++) {
        if (ar[ind_min] > ar[i]) {
            ind_min= i;
        }
    }
    return ind_min;
}
template<class T>
void Swap(T& a, T& b) {
//    a ^= b;
//    b ^= a;
//    a ^= b;
    int temp = a;
    a = b;
    b = temp;
}

template<class T>
void array1D_InsertionSort(T* ar, int size) {
    int ind_max = 0;
    for (int i = 0; i < size; i++) {
        ind_max = array1D_GetIndexMin(&ar[i], size - i) + i;
        Swap(ar[i], ar[ind_max]);
    }
}


#endif //CPP_PROJ_ARRAY_FUNC_H
