//
// Created by Tr on 18.07.2021.
//

#ifndef CPP_PROJ_TEST_SORTS_H
#define CPP_PROJ_TEST_SORTS_H

#include <iostream>
#include <assert.h>
#include <string>
#include <map>
#include <windows.h>
#include "sorts.h"
#include "array_func.h"

using namespace std;

void testSorts(void (*TypeSort)(int*, int), const string& name_sort, bool test_speed);

void test_mergeSort();
void test_BucketSort_forTASK2();

#endif //CPP_PROJ_TEST_SORTS_H
