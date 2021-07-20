
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

/*
 * 1. Описать в коде улучшенный алгоритм быстрой сортировки
 * 2. Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах
 * при помощи алгоритма блочной сортировки, то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]
 */


using namespace std;

//1. Описать в коде улучшенный алгоритм быстрой сортировки
template<class T>
void QuickSort(T* ar, int size)
{
    if (size <= 1) {
        return;
    }
    int left = 0;
    int right = size - 1;
    int median = ar[size/2];

    do {
        while (ar[left] < median) {
            left++;
        }
        while(ar[right] > median) {
            right--;
        }
        if (left <= right) {
            Swap(ar[right], ar[left]);
            left++;
            right--;
        }
    }while (left <= right);

    QuickSort(&ar[0], right+1);
    QuickSort(&ar[left], size - left);
}

template<class T>
inline int GetIndexMax(T* ar, int size) {
    int index_max = 0;
    for (int i = 1; i < size; i++) {
        if (ar[index_max] < ar[i]) {
            index_max = i;
        }
    }
    return index_max;
}

template<class T>
void Insertion_sort(T* ar, int size) {
    for (int i = 0; i < size; i++) {
        int index = GetIndexMax(&ar[0], size - i);
        Swap(ar[index], ar[size - 1 - i]);
    }
}

template<class T>
void QuickSort_improved(T* ar, int size) {
    if (size <= 20) {
        Insertion_sort(ar, size);
        return;
    }
    int left = 0;
    int right = size - 1;
    int median = ar[size/2];

    do {
        while (ar[left] < median) {
            left++;
        }
        while(ar[right] > median) {
            right--;
        }
        if (left <= right) {
            Swap(ar[right], ar[left]);
            left++;
            right--;
        }
    }while (left <= right);

    QuickSort(&ar[0], right+1);
    QuickSort(&ar[left], size - left);
}

template<class T>
pair<int,int> GetRangeNumber(T number) {
    int temp = number / 10;
    int left_side = temp*10;
    int right_side = left_side + 10;

    return make_pair(left_side, right_side);
}

void BucketSort(int* ar, int size) {
    map<int /*range to*/, vector<int>/*elements in ranges*/> buckets;
        //e.g. map[10] will contain elements from 0 to 9, map[20] will contain el from 10 to 19 etc
        //for negative... -10 to -1 will look like map[-1], from -20 to -11 is map[-11]
    for (int i = 0; i < size; i++) {
        auto [left, right] = GetRangeNumber(ar[i]);
        buckets[right].push_back(ar[i]);
    }

    auto bucket_data = buckets.begin(); //    map<int, list<int>>::iterator temp_iter = buckets.begin();, ругается на шаблоны... потом посмотреть...
    while(bucket_data != buckets.end()) {
        sort(bucket_data->second.begin(), bucket_data->second.end());
        bucket_data++;
    }
    bucket_data = buckets.begin();
    int i = 0;
    while(bucket_data != buckets.end()) {
        for (auto iter = bucket_data->second.begin(); iter != bucket_data->second.end(); iter++) {
            ar[i++] = *iter;
        }
        bucket_data->second.clear();
        buckets.erase(bucket_data);
        bucket_data = buckets.begin();
    }
}

// 2. Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах
//    при помощи алгоритма блочной сортировки, то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]

void specific_BucketSort(int* ar, int size) {
    map<int /*range to*/, vector<int>/*elements in ranges*/> buckets;
    //e.g. map[10] will contain elements from 0 to 9, map[20] will contain el from 10 to 19 etc
    //for negative... -10 to -1 will look like map[-1], from -20 to -11 is map[-11]
    for (int i = 0; i < size; i++) {
        auto [left, right] = GetRangeNumber(ar[i]);
        buckets[right].push_back(ar[i]);
    }

    auto bucket_data = buckets.begin(); //    map<int, list<int>>::iterator temp_iter = buckets.begin();, ругается на шаблоны... потом посмотреть...
    while(bucket_data != buckets.end()) {
        sort(bucket_data->second.begin(), bucket_data->second.end());   //или это всё превратить в обычный массив а потом с помощью любой ранее реализованной сортировкой отсортировать
        bucket_data++;
    }
    bucket_data = buckets.begin();
    int i = 0;
    while(bucket_data != buckets.end() && i < size) {
        for (auto iter = bucket_data->second.begin(); iter != bucket_data->second.end(); iter++, i++) {
            while (*iter % 2) {
                if (iter == bucket_data->second.end()) {
                    break;
                }
                iter++;
            }
            if (iter == bucket_data->second.end()) {
                break;
            }

            while (ar[i] % 2) { //check odd
                i++;
                if (i > size - 1) {
                    break;
                }
            }
            if (i > size)
                break;
            ar[i] = *iter;
        }
        bucket_data->second.clear();
        buckets.erase(bucket_data);
        bucket_data = buckets.begin();
    }
}

void test_BucketSort_forTASK2()
{
    {   //test array    [0 2 8 3 4 6 5 9 8 2 7 3]
        //result        [0 2 2 3 4 6 5 9 8 8 7 3]
        const int SIZE = 20;
        int source[SIZE] =      {56, 52, 68, 45, 28, 38, 50, 20, 00, 14, 12, 50, 36, 85, 33, 92, 11, 05, 83, 75};    //
        int result_sort[SIZE] = {00, 12, 14, 45, 20, 28, 36, 38, 50, 50, 52, 56, 68, 85, 33, 92, 11, 05, 83, 75};

        specific_BucketSort(source, SIZE);

        assert(array1D_compareAllNumbers(&source[0], &result_sort[0], SIZE) == true);
        assert(array1D_compareSortEvenNumber(&source[0], SIZE) == true);
        assert(array1D_compareODDNumber(&source[0], &result_sort[0], SIZE) == true);
    }

    {   //test array    [0 2 8 3 4 6 5 9 8 2 7 3]
        //result        [0 2 2 3 4 6 5 9 8 8 7 3]
        const int SIZE = 12;
        int source[SIZE] =      {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};    //
        int result_sort[SIZE] = {0, 2, 2, 3, 4, 6, 5, 9, 8, 8, 7, 3};

        specific_BucketSort(source, SIZE);

        assert(array1D_compareAllNumbers(&source[0], &result_sort[0], SIZE) == true);
        assert(array1D_compareSortEvenNumber(&source[0], SIZE) == true);
        assert(array1D_compareODDNumber(&source[0], &result_sort[0], SIZE) == true);
    }
    {   //test array    [0 2 8 3 4 6 5 9 0 2 7 3]
        //result        [0 0 2 2 3 4 6 5 9 8 7 3]
        const int SIZE = 12;
        int source[SIZE] =      {0, 2, 8, 3, 4, 6, 5, 9, 0, 2, 7, 3};    //
        int result_sort[SIZE] = {0, 0, 2, 3, 2, 4, 5, 9, 6, 8, 7, 3};

        specific_BucketSort(source, SIZE);

        assert(array1D_compareAllNumbers(&source[0], &result_sort[0], SIZE) == true);
        assert(array1D_compareSortEvenNumber(&source[0], SIZE) == true);
        assert(array1D_compareODDNumber(&source[0], &result_sort[0], SIZE) == true);
    }
    {  //randow array
        const int SIZE = 20;
        int source[SIZE];
        array1D_FillRandom(&source[0], SIZE);

        int result_sort[SIZE];
        array1D_Copy(result_sort, source, SIZE);

        specific_BucketSort(result_sort, SIZE);

        assert(array1D_compareODDNumber(&source[0], &result_sort[0], SIZE) == true);
        assert(array1D_compareSortEvenNumber(&result_sort[0], SIZE) == true);
    }

    cout << "\tTASK2 passed OK" << endl;
}

int main(int argc, char** argv) {
    cout << "only for me, test quick sort and insertion sort" << endl;
    test_sorts(QuickSort, "quick sort", true);
    test_sorts(Insertion_sort, "insertion sort", false);

    cout << "TASK2, quick sort improved" << endl;
    test_sorts(QuickSort_improved, "improved quick sort", true);

    cout << "real bucket sort" << endl;
    test_sorts(BucketSort, "bucket sort", true);

    cout << "TASK2 specific bucket sort" << endl;
    test_BucketSort_forTASK2();

    test_mergeSort();

    return 0;
}
