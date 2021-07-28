//
// Created by Tr on 28.07.2021.
//

#include "test_bin_tree.h"

using namespace std;

void test_binary_tree() {
    {   //test 1 use balanced tree
        BIN_SEARCH_TREE *myBinTree = new BIN_SEARCH_TREE();

        const int SIZE = 15;
        int array[SIZE] = {50,25,75,12,40,60,100,6,20,30,45,55,66,90,120}; //balanced tree

        for (int i = 0; i < SIZE; i++) {
            myBinTree->insert_key(array[i]);
        }

        assert(myBinTree->isBalancedTree() == true);
        delete myBinTree;
    }
    {   //test 2 use unbalanced tree
        BIN_SEARCH_TREE *myBinTree = new BIN_SEARCH_TREE();

        const int SIZE = 15;
        int array[SIZE] = {50,40,30,20,10,35,100,60,90,95,80,220,250,260,300}; //balanced tree

        for (int i = 0; i < SIZE; i++) {
            myBinTree->insert_key(array[i]);
        }

        assert(myBinTree->isBalancedTree() == false);
        delete myBinTree;
    }
    {

        const int SIZE = 10;
        int array[][SIZE] = {{193, 101, 165, 894, 777, 546, 456, 662, 821, 820},
                             {196, 28,  65,  642, 366, 277, 619, 405, 873, 884},
                             {200, 179, 391, 390, 737, 681, 692, 955, 917, 928},
                             {203, 114, 371, 833, 475, 502, 765, 661, 780, 996},
                             {206, 120, 40,  172, 697, 542, 615, 632, 770, 837}};

        for (int j = 0; j < 5; j++) {
            BIN_SEARCH_TREE *myBinTree = new BIN_SEARCH_TREE();
            for (int i = 0; i < SIZE; i++) {
                myBinTree->insert_key(array[j][i]);
            }
            myBinTree->ShowTree(SHOW_TREE);
            cout << "balanced = " << (myBinTree->isBalancedTree() == true ? "OK" : "NOT") << endl;
            delete myBinTree;
        }
    }

    cout << "TEST balanced is OK" << endl;

    {   //test bin search
        BIN_SEARCH_TREE *myBinTree = new BIN_SEARCH_TREE();

        const int SIZE = 15;
        int array[SIZE] = {50,25,75,12,40,60,100,6,20,30,45,55,66,90,120}; //balanced tree

        for (int i = 0; i < SIZE; i++) {
            myBinTree->insert_key(array[i]);
        }

        for (int i = 0; i < SIZE; i++) {
            assert(myBinTree->bin_search(array[i]) == true);
        }
        assert(myBinTree->bin_search(-5) == false);
        assert(myBinTree->bin_search(22) == false);
        assert(myBinTree->bin_search(122) == false);
        assert(myBinTree->bin_search(0) == false);
        delete myBinTree;
    }
    cout << "TEST bin search is OK" << endl;

}
