//
// Created by Tr on 28.07.2021.
//

#include "binary_tree.h"

using namespace std;

BIN_SEARCH_TREE::BIN_SEARCH_TREE() {
    parent = nullptr;
    height = 0;
#ifdef NO_CHECK_FIRST_ELEMENT
    parent = new NODE();
    parent->left = nullptr;
    parent->right = nullptr;
#endif
}

BIN_SEARCH_TREE::BIN_SEARCH_TREE(int first_key) {
    parent = new NODE();
    parent->left = nullptr;
    parent->right = nullptr;
    parent->key = first_key;
    height = 0;
}


BIN_SEARCH_TREE::~BIN_SEARCH_TREE() {
    //need remove all elements from tree
    delete_all_leaves(parent);

}
/*  input       :   key
 *  output      :   element put to left = -1, right = 1, parent = 0
 *  descritpion :   put to tree element depend on it element
 *  author      :   丹尼斯
 *  date        :   今天是二零二一年七月二十八好
 *  vesrion     :   v1
 */
int BIN_SEARCH_TREE::insert_key(int key) {
    if (parent == nullptr) {
        parent = new NODE();
        parent->left = nullptr;
        parent->right = nullptr;
        parent->key = key;
        parent->layer = 0;  //parent...
        return 0;
    }
    auto parent_node = GetParentNode(parent, key);
    NODE* new_node = new NODE(key);
    new_node->layer = parent_node.first->layer + 1;
    if (height < new_node->layer) {
        height = new_node->layer;
    }
    switch(parent_node.second) {
        case NODE_TYPE::LEFT :
            parent_node.first->left = new_node;
        break;
        case NODE_TYPE::RIGHT :
            parent_node.first->right = new_node;
        break;
    }

    return static_cast<int>(parent_node.second);
}

/*
 *  input       :   current node, and key... needed to insert
 *  output      :   return parent node, and left or right place new key
 *  descritpion :   function is recursive жрёт много памяти at large tree... possible to rewrite as simple non recursive function
 *  author      :   丹尼斯
 *  date        :   今天是二零二一年七月二十八好
 *  version     :   v1
 */
std::pair<NODE*, NODE_TYPE> BIN_SEARCH_TREE::GetParentNode(NODE* current_node, int key) {
//      ****this situation is unlike****
//    if (current_node == nullptr) {
//        return {nullptr, NODE_TYPE::PARENT};
//    }

    if (current_node->key < key) {
        if (current_node->right == nullptr) {
            return {current_node, NODE_TYPE::RIGHT};
        }
        return GetParentNode(current_node->right, key);
    }

    if (current_node->left == nullptr) {
        return {current_node, NODE_TYPE::LEFT};
    }
    return GetParentNode(current_node->left, key);
}
/*
 *  input       :
 *  output      :
 *  descritpion :
 *  author      :   丹尼斯
 *  date        :   later as I will have a free time
 *  version     :   v
 */
int BIN_SEARCH_TREE::ShowTree(int type) const {
    switch (type) {
        case STRAIGHT_ORDER :
            ShowNodes_straight(parent);
        break;
        case CENTRAL_ORDER :
            ShowNodes_central(parent);
        break;

        case REVERSE_ORDER :
            ShowNodes_reverse(parent);
        break;
        case SHOW_TREE :
            ShowNodes_Tree(parent);
        break;
    }
    cout << endl;
    return 0;
}

void BIN_SEARCH_TREE::ShowNodes_straight(NODE *curr_node) const {
    if (curr_node != nullptr) {
        cout << curr_node->key << " ";
        ShowNodes_straight(curr_node->left);
        ShowNodes_straight(curr_node->right);
    }
}

//это сортировка массива!!!!
void BIN_SEARCH_TREE::ShowNodes_central(NODE *curr_node) const {
    if (curr_node != nullptr) {
        ShowNodes_central(curr_node->left);
        cout << curr_node->key << " ";
        ShowNodes_central(curr_node->right);
    }
}

void BIN_SEARCH_TREE::ShowNodes_reverse(NODE *curr_node) const {
    if (curr_node != nullptr) {
        ShowNodes_reverse(curr_node->left);
        ShowNodes_reverse(curr_node->right);
        cout << curr_node->key << " ";
    }
}

/*
 *  input       :
 *  output      :
 *  descritpion :   without recursion, but with recursion is more simple,
 *                  instead of list<NODE*> possible to use stack
 *  author      :   丹尼斯
 *  date        :   later as I will have a free time
 *  version     :   v
 */
bool BIN_SEARCH_TREE::isBalancedTree() const {
    NODE* temp_child = parent;
    list<NODE*> untracked_childs;
    while (abs(getHeightFromNode(temp_child->left) - getHeightFromNode(temp_child->right)) <= 1) {
        if (temp_child->right != nullptr) {
            untracked_childs.push_back(temp_child->right);
        }
        temp_child = temp_child->left;

        if (temp_child == nullptr) {
            //leave....
            if (untracked_childs.empty()) {
                return true;
            }
            temp_child = untracked_childs.front();
            untracked_childs.erase(untracked_childs.begin());
        }
    }
    return false;
}

int BIN_SEARCH_TREE::getHeightFromNode(const NODE* current_node) const {
    if (current_node == nullptr) {
        return 0;
    }
    int height_left = 0;
    NODE *temp_child = (NODE*)current_node;
    while(temp_child->left != nullptr) {
        height_left++;
        temp_child = temp_child->left;
    }
    int height_right = 0;
    temp_child = (NODE*)current_node;
    while(temp_child->right != nullptr) {
        height_right++;
        temp_child = temp_child->right;
    }

    return height_left > height_right ? height_left : height_right;
}

BIN_SEARCH_TREE::BIN_SEARCH_TREE(BIN_SEARCH_TREE* old_tree) {

}

bool BIN_SEARCH_TREE::bin_search(int key) const {
    if (parent == nullptr) {
        return false;
    }

    return bin_search_rec(parent, key);

}

bool BIN_SEARCH_TREE::bin_search_rec(NODE *node, int key) const {
    if (node == nullptr) {
        return false;
    }
    if (node->key == key) {
        return true;
    }

    NODE* temp_node = node->right;
    if (key < node->key) {
        temp_node = node->left;
    }
    return bin_search_rec(temp_node, key);
}

void BIN_SEARCH_TREE::delete_all_leaves(NODE *leave) {
    if (leave != nullptr) {
        delete_all_leaves(leave->left);
        delete_all_leaves(leave->right);
        delete leave;
        leave = nullptr;
    }
}

void BIN_SEARCH_TREE::ShowNodes_Tree(NODE *curr_node) const {
    if (curr_node == nullptr) {
        return;
    }
    cout << curr_node->key;
    if (curr_node->left || curr_node->right) {
        cout << "(";
        if (curr_node->left) {
            ShowNodes_Tree(curr_node->left);
        }
        else {
            cout << "N";
        }
        cout << ",";
        if (curr_node->right) {
            ShowNodes_Tree(curr_node->right);
        }
        else {
            cout << "N";
        }
        cout << ")";
    }
}

NODE::NODE(int key) : key(key) {
    left = nullptr;
    right = nullptr;
}

NODE::NODE() {
    left = nullptr;
    right = nullptr;
    key = -1;
}

NODE::~NODE() {
    //here can be removed all nodes... call delete for left and right...every time will called this destructor...
}