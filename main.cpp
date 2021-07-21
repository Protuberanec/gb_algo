
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

// 1. Описать очередь с приоритетным исключением
/*
 * Очередь с приоритетами — это очередь в которой включение либо исключение, элементов производится в соответствии с их приоритетами.
 * Очередь с приоритетным включением — такая очередь, в которой последовательность элементов все время поддерживается упорядоченной по убыванию приоритета. (положить элемент за log(N) извлечь за..???
 *Очередь с приоритетным исключением — очередь, в которой включение элементов осуществляется в конец, а при исключении производится поиск элемента с максимальным приоритетом. (положить элемент за O(1), извлечь за log(N)?
 */


// 2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.


using namespace std;

int main(int argc, char** argv) {

    DATA* temp_data = new DATA();

    QUEUE *my_queue = new QUEUE();

    cout << "data" << endl;
    temp_data->fillRandom(5);
    temp_data->ShowData();
    cout << "end" << endl;

    my_queue->push(temp_data, 1);

    temp_data->fillRandom(5);
    cout << "data" << endl;
    temp_data->ShowData();
    cout << "end" << endl;
    my_queue->push(temp_data, 2);

    temp_data->fillRandom(11);
    cout << "data" << endl;
    temp_data->ShowData();
    cout << "end" << endl;
    my_queue->push(temp_data, 2);

    temp_data->fillRandom(22);
    cout << "data" << endl;
    temp_data->ShowData();
    cout << "end" << endl;
    my_queue->push(temp_data, 2);

    temp_data->fillRandom(1);
    cout << "data" << endl;
    temp_data->ShowData();
    cout << "end" << endl;
    my_queue->push(temp_data, 2);

    cout << "show queue elements" << endl;
    my_queue->ShowAllElements_non_rec();

    return 0;
}
