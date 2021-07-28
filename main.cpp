
#include <iostream>
#include <limits>
#include <assert.h>
#include <cstring>
#include <string>
#include <iterator>
#include <algorithm>
#include <regex>
#include "array_func.h" //standard function to work with array... very usefull...
#include "ConsoleWork.h"    //stupid attempt to write own lib to work with console...

#include "binary_tree.h"
#include "test_bin_tree.h"

using namespace std;


//1. Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
//      1.1.    создаст [50] деревьев по [10000] узлов и заполнит узлы случайными целочисленными значениями;
//      1.2.    рассчитает, какой процент из созданных деревьев является сбалансированными.
//#define SHOW_OK
#ifndef SHOW_OK
const int AMOUNT_ELEMENT = 10000;
const int RANGE_ELEMENT = AMOUNT_ELEMENT * 100;
const int AMOUNT_TREE = 50;
#else
//вот с этими параметрами можно найти сбалансированные деревья!!!
    const int AMOUNT_ELEMENT = 10;
    const int RANGE_ELEMENT = AMOUNT_ELEMENT * 10;
    const int AMOUNT_TREE = 100;
#endif

void CreateTree(BIN_SEARCH_TREE** new_tree) {
    static int temp_seed = 0;
    srand(time(NULL) + temp_seed++);
    *new_tree = new BIN_SEARCH_TREE();
    for (int i = 0; i < AMOUNT_ELEMENT; i++) {
        (*new_tree)->insert_key(rand() % RANGE_ELEMENT);
    }
}
float GetStatBalancedTree() {
    BIN_SEARCH_TREE *tree;
    int count_balanced_tree = 0;
    for (int i = 0; i < AMOUNT_TREE; i++) {
        CreateTree(&tree);

        if(tree->isBalancedTree()) {
#ifdef SHOW_OK
            tree->ShowTree(SHOW_TREE);
            cout << "balanced OK" << endl;
#endif
            count_balanced_tree++;
        }
        delete tree;
    }

    float percentage = (float)count_balanced_tree * 100.0 / (float)AMOUNT_TREE;
    return percentage;
}


int main(int argc, char** argv) {

// here check balanced tree one part of task 1
// here also test binary search, the task is number 2   //2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
    test_binary_tree();

    std::cout << "\t\tall tests passed OK" << std::endl;
    float perc = GetStatBalancedTree();
    std::cout << "percentages of balanced tree = " << perc << std::endl;

    return 0;
}
