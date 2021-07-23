//
// Created by Tr on 22.07.2021.
//

#include "test_queue.h"


void test_queue() {
    std::cout << "test queue with priority" << std::endl;
    QUEUE *queue = new QUEUE();

    {   //test 1... get elements from empty queue
        DATA data;
        queue->pop_by_prior(&data);
        data.ShowData();
        assert(data.getSize() == 0);
    }

    {   //test 2... push elements, count elements
        DATA data;
        for (int i = 0; i < 10; i++) {
            data.fillRandom(5);
            queue->push(&data, rand() % 20 + 1);
        }
        assert(queue->getAmountElements() == 10);
    }

    {   //test 3... get 10 elements, count element and check priority elements, pushed 10 elements in previous test
        DATA data;
        int prior[10];

        for (int i = 0; i < 10; i++) {
            prior[i] = queue->pop_by_prior(&data);
        }
        assert(queue->getAmountElements() == 0);
        if (array1D_isSorted(prior, 10) == false) {
            std::cout << "prior ar = ";
            array1D_Print(prior, 10);
        }
        assert(array1D_isSorted(prior, 10) == true);
    }
    {   //test 4... put elements with similar priority
        DATA data;
        for (int i = 0; i < 5; i++) {
            data.fillRandom(5);
            queue->push(&data, 1);
        }

        for (int i = 0; i < 5; i++) {
            assert(queue->pop_by_prior(&data) == 1);
        }
    }

    {   //test 5... compare data which put and push
        const int AMOUNT_DATA = 10;
        DATA data[AMOUNT_DATA];
        int prior[AMOUNT_DATA] = {1,2,4,3,1,7,90,4,4,1};
        for (int i = 0; i < AMOUNT_DATA; i++) {
            data[i].fillRandom(rand() % 20);
            queue->push(&data[i], prior[i]);
        }

        DATA data_out;
        int size1 = 0;
        int size2 = 0;

        for (int i = 0; i < 10; i++) {
            int current_prior = queue->pop_by_prior(&data_out); //get element from queue
            int num_prior = 0;  //start look for similar priority
            for (; num_prior < AMOUNT_DATA; num_prior++) {
                if (prior[num_prior] == current_prior) {
                    break;
                }
            }
            //compare prior
            assert(current_prior == prior[num_prior]);
            prior[num_prior] = 0;   //reset test table prior
            //compare data
            assert(array1D_compareAllNumbers(data_out.GetData(size1), data[num_prior].GetData(size2), data[num_prior].getSize()));
            //compare size of test elements with poped elements
            assert(size1 == size2);
        }
    }


    {   //test pop method
        QUEUE *q1 = new QUEUE();
        const int AMOUNT_EL = 10;
        DATA data[AMOUNT_EL];
        for (int i = 0; i < AMOUNT_EL; i++) {
            data[i].fillRandom(5);
            q1->push(&data[i], rand() % 20 + 1);
        }

        DATA data_out;
        int size1, size0;
        for (int i = AMOUNT_EL-1; i >= 0; i--) {
            q1->pop(&data_out);
            assert(array1D_compareAllNumbers(data_out.GetData(size1), data[i].GetData(size0), 5) == true);
        }
    }

    delete queue;


    std::cout << "Test queue passed OK" << std::endl;

}