//
// Created by Tr on 28.07.2021.
//

#ifndef CPP_PROJ_BINARY_TREE_H
#define CPP_PROJ_BINARY_TREE_H

#include <stdio.h>
#include <map>
#include <list>
#include <iostream>

enum class NODE_TYPE {
    LEFT = -1,
    PARENT = 0,
    RIGHT = 1,
};

enum SHOW_AS{
    STRAIGHT_ORDER = 0, //обход в прямом порядке
    CENTRAL_ORDER = 1,  //центральный обход, сначало левая ветрвь, потом центр потом правая ветвь
    REVERSE_ORDER = 2,  //центральный обход, сначало левая ветрвь, потом центр потом правая ветвь
    SHOW_TREE = 3,  //просто скобочная печать дерева на экране...
};

struct DATA {

};

struct NODE {
//private:  - for safety...
    NODE* left;
    NODE* right;
    int key;
    int layer;  //my mind... useful for detect layers of elements

//no used!!!
//    struct DATA* data_node; //以防万一

    NODE(int new_key);
    NODE();
    ~NODE();
};

class BIN_SEARCH_TREE {
private :
    int height; //высота дерева
    NODE *parent;
    NODE* GetNode(int key);
    std::pair<NODE*, NODE_TYPE> GetParentNode(NODE* current_node, int key);

    void ShowNodes_straight(NODE* curr_node) const; //для копирования деревьев
    void ShowNodes_central(NODE* curr_node) const;  //аналог сортировки деревеа
    void ShowNodes_reverse(NODE* curr_node) const;  //можно использовать для удаление дерева
    void ShowNodes_Tree(NODE* curr_node) const;

    int getHeightFromNode(const NODE* current_node) const;

    bool bin_search_rec(NODE *node, int key) const;

    void delete_all_leaves(NODE* leave);

public :
    BIN_SEARCH_TREE();
    BIN_SEARCH_TREE(BIN_SEARCH_TREE* old_tree);
    BIN_SEARCH_TREE(int first_key);
    ~BIN_SEARCH_TREE();

    int insert_key(int new_key);
    int getNodeKey() const;

    int delete_node(int key_delete);

    int ShowTree(int type = 0) const;

    bool bin_search(int key) const;
    bool isBalancedTree() const;    //т.е. высота каждого поддерева не отличается больше чем на 1
    bool isFulledTree() const;  //т.е. все потомки до h-1 включительно имеют либо по два потомка, либо ни одного потомка
    bool isCompleteTree() const; //т.е. все потомки до h-1 включительно имеют по два потомка, а все "листы" находятся на одном уровне
    bool isDegeneratedTree() const; //т.е. вид его похож на связный список
};

#endif //CPP_PROJ_BINARY_TREE_H
