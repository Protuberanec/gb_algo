//
// Created by Tr on 18.07.2021.
//

#ifndef CPP_PROJ_SORTS_H
#define CPP_PROJ_SORTS_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

#include "array_func.h"

std::pair<int,int> GetRangeNumber(int number);

void mergeArray(std::pair<int/*size*/, int* /*array*/> ar1, std::pair<int /*size*/, int* /*array*/> ar2);
template<class T>
void merge_sort(T* ar, int size) {
    if (size <= 1) {
        return;
    }

    merge_sort(&ar[0], size/2);
    merge_sort(&ar[size/2], size/2 + size%2);

    mergeArray({size/2, &ar[0]}, {size/2+size%2, &ar[size/2]});

    //    std::cout << "1 : ";
    //         array1D_Print(&ar[0], size/2);
    //    std::cout << "2 : ";
    //        array1D_Print(&ar[size/2], size/2 + size%2);
    //    std::cout << "---" << std::endl;
}

template<class T>
void Insertion_sort(T* ar, int size) {
            for (int i = 0; i < size; i++) {
                int index = array1D_GetIndexMax(&ar[0], size - i);
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

    QuickSort_improved(&ar[0], right+1);
    QuickSort_improved(&ar[left], size - left);
}

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
void BucketSort(T* ar, int size) {
            std::map<int /*range to*/, std::vector<T>/*elements in ranges*/> buckets;
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

template<class T>
void specific_BucketSort(T* ar, int size) {
    std::map<int /*range to*/, std::vector<T>/*elements in ranges*/> buckets;
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

#endif //CPP_PROJ_SORTS_H
