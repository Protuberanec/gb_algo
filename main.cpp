
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
#include "test_sorts.h"
#include "ConsoleWork.h"

using namespace std;

int main(int argc, char** argv) {
    cout << " test quick sort" << endl;
    testSorts(QuickSort, "quick sort", true);

    cout << "quick sort improved" << endl;
    testSorts(QuickSort_improved, "improved quick sort", true);

    testSorts(Insertion_sort, "insertion sort", false);

    cout << "real bucket sort" << endl;
    testSorts(BucketSort, "bucket sort", true);

    cout << "TASK2 specific bucket sort" << endl;
    test_BucketSort_forTASK2();

    test_mergeSort();

    return 0;
}
