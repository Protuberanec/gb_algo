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
    NO = -1,
    HIGH = 0,
    MEDIUM = 10,
    LOW = 20,

};

class DATA {
private :
    int *data;
    size_t size;
public:
    DATA& operator=(const DATA& data);

    DATA();
    DATA(size_t, int*);
    DATA(const DATA&);    //copy constructor

    ~DATA();

    void fillRandom(size_t size_);
    size_t ShowData();

};
class NODE {
private :
    int priority;

    DATA *data;
    NODE *next;
    NODE *prev; //only for dequeue

public:
    NODE& operator=(const NODE& new_node) {
        if (data != nullptr) {
            delete [] data;
            data = nullptr;
        }
        return *new NODE(new_node);
    }
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
};

class QUEUE {
private :
    NODE *HEAD;
    NODE *TAIL;

public:
    QUEUE();
    ~QUEUE();

    int push(const DATA* data, int prior_);
    int pop(const DATA* data);
    int peek(const DATA* data);

    int ShowAllElements_non_rec();
    int ShowAllElements_rec();
};

#endif //CPP_PROJ_QUEUE_H
