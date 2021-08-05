
#include <iostream>
#include <limits>
#include <assert.h>
#include "array_func.h" //standard function to work with array... very usefull...
#include "ConsoleWork.h"    //stupid attempt to write own lib to work with console...
#include "my_hash.h"
#include "stack_fifo.h"


using namespace std;

//Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
int simple_hash() {
    cout << "HASH tasks" << endl;
    {
        const char STR[] = "test string";
        cout << "hash string "<< STR << " " << hash_simple(STR) << endl;
    }
    return 0;
}
//Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет наберет сумму 98 коп.
// Для решения задачи используйте “жадный” алгоритм.

FIFO<int>* GetCoins(int sum_coins = 98) {
    FIFO<int>* results = new FIFO<int>();
    int array[5] = {50, 10, 5, 2, 1};

    int res_sum = 0;
    while (sum_coins) {
        for (int i = 0; i < 5; i++) {
            if (sum_coins - res_sum >= array[i]) {
                results->push(array[i]);
                sum_coins -= array[i];
                break;
            }
        }

    }
    return results;
}


void greedy_algo() {
    cout << "greedy algo tasks" << endl;
    {   //test 1
        auto result = GetCoins();
        int number_coins = result->getAmountEl();
        cout << "for 98 coins = " << number_coins << " : ";
        result->ShowAllElements();
        delete result;
    }
    {   //test 2
        auto result = GetCoins(153);
        int number_coins = result->getAmountEl();
        cout << "for 153 coins = " << number_coins << " : ";
        result->ShowAllElements();
        delete result;
    }
    {   //test 3
        auto result = GetCoins(15);
        int number_coins = result->getAmountEl();
        cout << "for 153 coins = " << number_coins << " : ";
        result->ShowAllElements();
        delete result;
    }
}


int main(int argc, char** argv) {

    simple_hash();
    greedy_algo();

    std::cout << "\t\tall tests passed OK" << std::endl;

    return 0;
}
