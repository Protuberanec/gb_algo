//
// Created by Tr on 21.07.2021.
//

#ifndef CPP_PROJ_QUEUE_H
#define CPP_PROJ_QUEUE_H

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <time.h>
#include <random>

enum PRIORITY {
    NO = 0,
    HIGH = 1,
    MEDIUM = 10,
    LOW = 20,
    LOWER = (unsigned int)-1,

};

class DATA {
private :
    int *data;
    size_t size;
public:
    DATA& operator=(const DATA& data_);

    DATA();
    DATA(size_t, int*);
    DATA(const DATA&);    //copy constructor

    ~DATA();

    int getSize() const {
        return size;
    }
    void fillRandom(size_t size_);
    size_t ShowData();
    int* GetData(int& size_) {
        size_ = size;
        return data;
    }
    //quite strange don't work operator=()...
    void CopyData(DATA *data_);

};
class NODE {
private :
    int priority;
    NODE *next;
    NODE *prev; //only for dequeue

    DATA *data_node;

public:
    int getDataNode(DATA* data_);
    int getPriority() const;

    NODE();
    NODE(const NODE&);
    NODE(const DATA& data_);
    NODE(const DATA& data_, int prior);
    ~NODE();
    size_t ShowNodeData();

    NODE *getNext() const;
    void setNext(NODE *next);
    NODE *getPrev() const;void setPrev(NODE *prev);

    void setData(const DATA *data_);
    void setPriority(int priority);


    void ReleaseNode(int node);    //important!!! delete any relations with next elements, otherwise all elements \
                                    // will delete while next will not equal nullptr
                                    //algorithm is easy, need remove relations with next elements, after call delete
};

class QUEUE {
private :
    NODE *HEAD;
    NODE *TAIL;
    int amountElements;

public:
    QUEUE();
    ~QUEUE();

    int push(const DATA* data, int prior_);
    int pop(DATA* data);  //last insterted
    int pop_by_prior(DATA* data); //with highenest priority
    int peek(const DATA* data);

    int ShowAllElements_non_rec();
    int getAmountElements();
    int ShowAllElements_rec();
};

#endif //CPP_PROJ_QUEUE_H
