//
// Created by Tr on 18.07.2021.
//

#include "test_sorts.h"

void testSorts(void (*TypeSort)(int*, int), const string& name_sort, bool test_speed)
{
    {   //test positive numbers
        int ar[10] = {1,5,2,3,8,10,0,7,4,1};
        TypeSort(ar, 10);
        assert(array1D_isSorted(ar, 10) == true);
    }
    {   //test positive numbers large array, odd
        int size = 753;
        int *ar;
        Create1DArray(ar, size);

        TypeSort(ar, size);
        assert(array1D_isSorted(ar, size) == true);

        delete [] ar;
    }
    {   //test positive numbers large array, even
        int size = 968;
        int *ar;
        Create1DArray(ar, size);

        TypeSort(ar, size);
        assert(array1D_isSorted(ar, size) == true);

        delete [] ar;
    }
    {   //test negative array
        int ar[10] = {-1,5,-6,3,-8,10,0,23,4,-9};
        TypeSort(ar, 10);
        assert(array1D_isSorted(ar, 10) == true);
    }
    {   //test have duplicates
        int ar[10] = {5,5,-6,3,-8,-8,23,23,4,4};
        TypeSort(ar, 10);
        assert(array1D_isSorted(ar, 10) == true);
    }
    if (test_speed == true)
    {   //test for time sorts
        int size = 10000000;
        int *ar;
        Create1DArray(ar, size, true, false);
        uint64_t time_elapsed = GetTickCount();
        TypeSort(ar, size);
        time_elapsed = GetTickCount() - time_elapsed;
        cout << "\ttime of "<< name_sort <<" is " << time_elapsed << " parrots for size array = " << size << endl;
        assert(array1D_isSorted(ar, size) == true);

        delete [] ar;
    }

    cout << "\ttest " << name_sort << " passed OK" << endl;
}

void test_mergeSort() {
    {   //test merge sorted array
        const int SIZE = 10;
        int ar[SIZE] = {1, 2, 5, 92, 99, 7, 8, 12, 24, 28};
        array1D_Print(ar, SIZE);
        mergeArray({5, &ar[0]}, {5, &ar[5]});
        array1D_Print(ar, SIZE);
        assert(array1D_isSorted(ar, SIZE) == true);
    }
    {   //test merge sorted array
        const int SIZE = 10;
        int ar[SIZE] = {20, 99, 101, 6, 7, 8, 12, 24, 28, 101};
        array1D_Print(ar, SIZE);
        mergeArray({3, &ar[0]}, {7, &ar[3]});
        array1D_Print(ar, SIZE);
        assert(array1D_isSorted(ar, SIZE) == true);
    }
    {
        const int SIZE = 10;
        int ar[SIZE] = {2, 1, 9, 16, 7, 3, 21, 5, 150, 101};
        array1D_Print(ar, SIZE);
        merge_sort(&ar[0], SIZE);
        array1D_Print(ar, SIZE);
        assert(array1D_isSorted(ar, SIZE) == true);
    }
    {   //full sort of merge
        testSorts(merge_sort, "merge sort", true);
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
