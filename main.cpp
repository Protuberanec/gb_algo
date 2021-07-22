
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

void convert_dec_to_bin()


int main(int argc, char** argv) {
// 1. Описать очередь с приоритетным исключением
//described in file queue.*
//test queue in test_queue
    test_queue();

// 2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

    return 0;
}
