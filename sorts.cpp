//
// Created by Tr on 18.07.2021.
//

#include "sorts.h"

using namespace std;

//merge sort
/*
 *  1. partition the array
 *  2. if array size is 1
 *  3. stop partition
 *  4. start merge arrays
 */
/*
 * we will merge only with first array...
 */
void mergeArray(pair<int/*size*/, int* /*array*/> ar1, pair<int /*size*/, int* /*array*/> ar2) {
    int iAr1 = 0;
    int iAr2 = 0;
    int i = 0;
    int *res_ar = new int [ar1.first + ar2.first];
    while(iAr1 < ar1.first && iAr2 < ar2.first) {
        while(ar1.second[iAr1] <= ar2.second[iAr2]) {
            res_ar[i++] = ar1.second[iAr1];
            iAr1++;
            if (iAr1 >= ar1.first) {
                break;
            }
        }
        res_ar[i++] = ar2.second[iAr2++];
    }

    for (; iAr2 < ar2.first; i++, iAr2++) {
        res_ar[i] = ar2.second[iAr2];
    }
    for (; iAr1 < ar1.first; i++, iAr1++) {
        res_ar[i] = ar1.second[iAr1];
    }

    array1D_Copy(ar1.second, &res_ar[0], ar1.first);
    array1D_Copy(ar2.second, &res_ar[ar1.first], ar2.first);

    delete [] res_ar;
}



std::pair<int,int> GetRangeNumber(int number) {
    int temp = number / 10;
    int left_side = temp*10;
    int right_side = left_side + 10;

    return make_pair(left_side, right_side);
}