
#include <iostream>
#include <limits>
#include <assert.h>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <windows.h>
#include <sysinfoapi.h>

#include "array_func.h"
#include "ConsoleWork.h"
#include "queue.h"
#include "test_queue.h"

/*
 * Очередь с приоритетами — это очередь в которой включение либо исключение, элементов производится в соответствии с их приоритетами.
 * Очередь с приоритетным включением — такая очередь, в которой последовательность элементов все время поддерживается упорядоченной по убыванию приоритета. (положить элемент за log(N) извлечь за..???
 * Очередь с приоритетным исключением — очередь, в которой включение элементов осуществляется в конец, а при исключении производится поиск элемента с максимальным приоритетом. (положить элемент за O(1), извлечь за log(N)?
 */

using namespace std;

struct STACK {
    int *array;
    int size;
    int pEnd;

    STACK()  {
        pEnd = -1;
        array = new int [32];
        size = 32;
        memset(array, 0x00, 32*sizeof(int));
    }
    STACK(int size_) {
        pEnd = -1;
        array = new int [size_];
        size = size_;
        memset(array, 0x00, size_*sizeof(int));
    }
    ~STACK() {
        delete [] array;
    }

    int push(int element) {
        if (pEnd >= size) {
            return -1;  //stack is full
        }

        array[++pEnd] = element;
        return pEnd;
    }

    int pop(int& element) {
        if (pEnd < 0) {
            return -1;  //no elements in stack
        }
        element = array[pEnd--];
        return 1;
    }
};

STACK* convert_dec_to_bin(int dec) {
    STACK *bin_num = new STACK(32); //assume that number will not exceed 32 binary number....

    while(dec != 0) {
        bin_num->push(dec % 2);
        dec = dec / 2;
    }

    return bin_num;
}

char* getBinNum(int dec) {
    STACK *bin_num = convert_dec_to_bin(dec);
    char *temp_str = new char [bin_num->pEnd + 1];
    memset(temp_str, 0x00, bin_num->pEnd * (sizeof(char)) + 1);

    int element;
    int i = 0;
    while(bin_num->pop(element) > 0) {
        temp_str[i++] = element + 0x30; //as ASCII codes
    }

    return temp_str;
}

void test_getBinNun() {
    {
        char *bin_num0 = getBinNum(43);
        assert(strcmp(bin_num0, "101011\0") == 0);
        delete[] bin_num0;
    }
    {
        char *bin_num0 = getBinNum(99);
        assert(strcmp(bin_num0, "1100011\0") == 0);
        delete[] bin_num0;
    }
    {
        char *bin_num0 = getBinNum(368);
        assert(strcmp(bin_num0, "101110000\0") == 0);
        delete[] bin_num0;
    }
    {
        //don't test negative number
        //negative number can'be present in 3 mode
            //прямой, дополнительный, обратный
    }
    std::cout << "test convert bin num passed OK" << std::endl;
}


int main(int argc, char** argv) {
// 1. Описать очередь с приоритетным исключением
//described in file queue.*
//test queue in test_queue
    test_queue();

// 2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
    test_getBinNun();

    return 0;
}
