//
// Created by Tr on 21.07.2021.
//

#include "queue.h"

DATA& DATA::operator=(const DATA& data_) {
    if (data != nullptr) {
        delete [] data;
        data = nullptr;
        size = 0;
    }
    return *new DATA(data_);
}

DATA::DATA() {
    size = 0;
    data = nullptr;
}
DATA::DATA(size_t size_, int *data_) {
    size = size_;
    data = new int [size_];
    memcpy(data, data_, size_ * sizeof(int));
    data = data_;
}

DATA::DATA(const DATA& data_) {
    data = new int [data_.size];
    size = data_.size;
    memcpy(data, data_.data, size * sizeof(int));
}

DATA::~DATA() {
    if (data != nullptr)
        delete [] data;

    size = 0;
}

void DATA::fillRandom(size_t size_) {
    size = size_;
    if (data != nullptr)
        delete [] data;

    data = new int [size];

    static int temp_seed = 0;
    srand(time(NULL) + temp_seed);
    temp_seed += 10;
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
}

size_t DATA::ShowData() {
    if (size == 0) {
        std::cout << "no data" << std::endl;
        return 0;
    }
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return size;
}

NODE::NODE() {
    priority = PRIORITY::NO;
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

NODE::~NODE() {
    if (data != nullptr)
        delete [] data;
    if (next != nullptr)
        delete next;    //delete all elements
}

NODE::NODE(const DATA &data_) {
    data = new DATA(data_);  //
    next = nullptr;
    prev = nullptr;
    priority = PRIORITY::NO;
}

size_t NODE::ShowNodeData() {
    return data->ShowData();
}

NODE *NODE::getNext() const {
    return next;
}

void NODE::setNext(NODE *next) {
    NODE::next = next;
}

NODE *NODE::getPrev() const {
    return prev;
}

void NODE::setPrev(NODE *prev) {
    NODE::prev = prev;
}

NODE::NODE(const DATA &data_, int prior) {
    data = new DATA(data_);  //
    next = nullptr;
    prev = nullptr;
}

void NODE::setPriority(int priority) {
    NODE::priority = priority;
}

void NODE::setData(const DATA *data_) {
    if (data != nullptr) {
        delete data;
    }
    data = new DATA(*data_);
}

NODE::NODE(const NODE &) {

}

QUEUE::QUEUE() {
                        //at first time HEAD will empty
    HEAD = new NODE();  //last element always will empty!!!
    TAIL = HEAD;
}

QUEUE::~QUEUE() {
    delete HEAD;
}

int QUEUE::push(const DATA *data, int prior_) {
    TAIL->setData(data);
    TAIL->setPriority(prior_);

    NODE *temp = new NODE();    //next tail
    TAIL->setNext(temp);
    temp->setPrev(TAIL);
    TAIL = temp;    //move to next elements

    return 0;
}

int QUEUE::ShowAllElements_non_rec() {
    NODE *temp_node = HEAD;

    while(temp_node->getNext() != nullptr) {
        temp_node->ShowNodeData();
        temp_node = temp_node->getNext();
    }

    return 0;
}
