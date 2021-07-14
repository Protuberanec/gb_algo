
#include <iostream>
#include <limits>
#include <assert.h>
#include <assert.h>
#include <cstring>
#include <map>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "array_func.h"

using namespace std;
/*
 * 1. Реализовать пузырьковую сортировку двумерного массива например, массив 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9 (main.c)
 * 2. Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута     (algo)
 *      2.1. - запросить у пользователя 11 чисел и записать их в последовательность П
 *      2.2. - инвертировать последовательность П
 *      2.3. - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) и если результат вычислений превышает 400 - проинформировать пользователя.
 * 3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С (main.c)
 */

/*
 * 1. Реализовать пузырьковую сортировку двумерного массива например, массив 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9 (main.c)
 */
void Swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
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
bool is2DArraySorted(T **arr, int row_size, int col_size, bool ascending = true) {
    if (ascending == true) {
        for (int i = 0; i < row_size; i++) {
            if (is2DArraySorted(&arr[i][0], col_size, 1) == false) {
                return false;
            }
            if (i >= row_size-1) {
                return true;
            }
            if (arr[i][col_size-1] > arr[i+1][0]) {
                return false;
            }

        }
    }
    else if (ascending == false) {}

    return true;
}

template<class T>
void SortBubble(T* arr, unsigned int col_size, unsigned int row_size) {
    int total_size = col_size * row_size;
    for (int i = 0; i < total_size; i++) {
        for (int j = 0; j < total_size - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
 *  сортировка реального двумерного динамического массива
 *  изврат ещё тот...
 */
template<class T>
void SortBubble(T** arr, unsigned int row_size, unsigned int col_size) {
    int count_swap = row_size - 1;
    while(count_swap) {
        count_swap = row_size - 1;
        for (int i1 = 0; i1 < row_size; i1++) {
            SortBubble(&arr[i1][0], col_size, 1);
            if (i1 >= row_size-1)
                break;
            if (arr[i1][col_size-1] > arr[i1+1][0]) {
                Swap(arr[i1][col_size-1], arr[i1+1][0]);
            }
            else {
                count_swap--;   //считаем кол-во перестановок из массива в массив
            }

        }
    }
    return;
}

void test_task1_SortBubble() {
    {//test1 static array
        int arr[3][3] = {{13,2,7},{8,6,9},{1,-1,3}};
        SortBubble(&arr[0][0], 3, 3);
        assert(is2DArraySorted(&arr[0][0], 3, 3) == true);
    }
    {   //test2 static array, random filled
        int arr[5][5];
        FillRandom1DArray(&arr[0][0], 25);
        SortBubble(&arr[0][0], 3, 3);
        assert(is2DArraySorted(&arr[0][0], 3, 3) == true);
    }
//dynamic arrays
    {   //test2 dynamic array
        int temp_arr[3][3] = {{3,2,7},{8,6,3},{1,-1,3}};
        int **arr;
        Create2DArray(arr, 3,3, false);
        Copy2DArray(arr, &temp_arr[0][0], 3,3);

        SortBubble(arr, 3, 3);
        assert(is2DArraySorted(arr, 3, 3) == true);

        Release2DArray(arr, 3);
    }
    {   //test2 dynamic array
        int temp_arr[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
        int **arr;
        Create2DArray(arr, 3,3, false);
        Copy2DArray(arr, &temp_arr[0][0], 3,3);

        SortBubble(arr, 3, 3);
        assert(is2DArraySorted(arr, 3, 3) == true);

        Release2DArray(arr, 3);
    }

    {   //test2 dynamic array
        const int row = 3, col = 5;
        int temp_arr[row][col] = {{9,8,7,-1,-2},{6,5,4,0,19},{3,2,1,99,90}};
        int **arr;
        Create2DArray(arr, col,row, false);
        Copy2DArray(arr, &temp_arr[0][0], col,row);

        SortBubble(arr, row, col);
        assert(is2DArraySorted(arr, row, col) == true);

        Release2DArray(arr, row);
    }

    {   //test2 dynamic array, random filled
        const int row = 10, col = 10;
        int **arr;
        Create2DArray(arr, col, row, true);

        SortBubble(arr, row, col);
        assert(is2DArraySorted(arr, row, col) == true);
        Release2DArray(arr, row);
    }

    cout << "Test bubble sort " << __func__ << " passed ok" << endl;
}


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

/* 2. Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута     (algo)
*      2.1. - запросить у пользователя 11 чисел и записать их в последовательность П
*      2.2. - инвертировать последовательность П
*      2.3. - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) и если результат вычислений превышает 400 - проинформировать пользователя.
* 3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С (main.c)
*/
#define VICE_VERSA //показывать числа ряда в обратном порядке
void algo_TPK(int n = 11) {
    if (n <= 0) {
        return;
    }
    unsigned int enter_number = GetNumber();

#ifdef VICE_VERSA
    --n;
    algo_TPK(n);
#endif
    float res_calc = sqrt(fabs(enter_number))+ 5 * pow(enter_number,3);
    cout    << "number = " << enter_number
            << " inv = " << ~enter_number << "\t" << (int)(~enter_number)
            << " sqrt(fabs(X) + 5 * pow(X,3) = " << res_calc << (res_calc > 400 ? "\tmore than 400" : "\tOK")
            << endl;
#ifndef VICE_VERSA
    n--;
    algo_TPK(n);    //show vice vers data
#endif
}



int main(int argc, char** argv) {


    test_task1_SortBubble();        //task1

    cout << "enter 11 numbers : " << endl;
    algo_TPK();



    return 0;
}
