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
    if (data != nullptr) {
        delete [] data;
    }

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
        std::cout << "no data_node" << std::endl;
        return 0;
    }
    for (int i = 0; i < size; i++) {
        std::cout << (char)data[i] << " ";  //oxox manual mode....
    }
    std::cout << std::endl;

    return size;
}

void DATA::CopyData(DATA *data_) {
    if (!size) {
        if (data_ != nullptr) {
            data_->size = 0;
        }
        return;
    }

    data_->size = size;
    if (data_->data) {
        delete [] data_->data;
    }
    data_->data = new int [size];
    for (int i = 0; i < size; i++) {
        data_->data[i] = data[i];
    }

}

NODE::NODE() {
    priority = PRIORITY::NO;
    data_node = nullptr;
    next = nullptr;
    prev = nullptr;
}

NODE::~NODE() {
    if (data_node != nullptr)
        delete data_node;

    if (next != nullptr)
        delete next;    //delete all elements
}

NODE::NODE(const DATA &data_) {
    data_node = new DATA(data_);  //
    next = nullptr;
    prev = nullptr;
    priority = PRIORITY::NO;
}

size_t NODE::ShowNodeData() {
    return data_node->ShowData();
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
    data_node = new DATA(data_);  //
    next = nullptr;
    prev = nullptr;
}

void NODE::setPriority(int priority) {
    NODE::priority = priority;
}

void NODE::setData(const DATA *data_) {
    if (data_node != nullptr) {
        delete data_node;
    }
    data_node = new DATA(*data_);
}

NODE::NODE(const NODE &) {

}

int NODE::getPriority() const {
    return priority;
}

int NODE::getDataNode(DATA* data_) {
    if (data_ == nullptr) {
        data_ = new DATA();
    }
    data_node->CopyData(data_);
    return 0;
}

QUEUE::QUEUE() {
                        //at first time HEAD will empty
    HEAD = new NODE();  //last element always will empty!!!
    TAIL = HEAD;
    amountElements = 0;
}

QUEUE::~QUEUE() {
    delete HEAD;
}

int QUEUE::push(const DATA *data, int prior_) {
    amountElements++;
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

    int current_num = 0;
    while(temp_node->getNext() != nullptr) {
        std::cout << current_num++ << ", " << temp_node->getPriority() << " : ";
        temp_node->ShowNodeData();
        temp_node = temp_node->getNext();
    }

    return 0;
}
/*
 * description  :   return elements with maxima of priority,
*                   !!!important then prior value is lower, then priority is highest
 *                   1 - high prior
 *                   1000000 - low prior
 */
int QUEUE::pop_by_prior(DATA *data) {
    if (HEAD->getNext() == nullptr) {
        return 0;
    }

    amountElements--;

    unsigned int max_prior = PRIORITY::LOWER;
    NODE *need_node;
    NODE *temp_node = HEAD;
    while (temp_node->getNext() != nullptr) {
        if (temp_node->getPriority() < max_prior) {
            need_node = temp_node;
            max_prior = temp_node->getPriority();
            if (max_prior == PRIORITY::HIGH) {
                //the element was found
                temp_node->getDataNode(data);    //get data of node
                //remove element reassign relations
                if (need_node->getPrev() != NULL) {
                    temp_node->getPrev()->setNext(temp_node->getNext());
                    temp_node->getNext()->setPrev(temp_node->getPrev());
                }
                else {
                    HEAD = need_node->getNext();
                    HEAD->setPrev(nullptr);
                }
                //delete element... remember!!! need remove only next relation
                temp_node->setNext(nullptr);
                delete temp_node;
                return PRIORITY::HIGH;
            }
        }
        temp_node = temp_node->getNext();
    }

    //the element was found
    need_node->getDataNode(data);    //get data of node
    //remove element reassign relations
    if (need_node->getPrev() != NULL) {
        need_node->getPrev()->setNext(need_node->getNext());
        need_node->getNext()->setPrev(need_node->getPrev());
    }
    else {
        HEAD = need_node->getNext();
        HEAD->setPrev(nullptr);
    }

    //delete element... remember!!! need remove only next relation
    need_node->setNext(nullptr);
    delete need_node;

    return max_prior;
}

int QUEUE::getAmountElements() {
    return amountElements;
}

int QUEUE::pop(DATA *data_) {
    if (TAIL->getPrev() == nullptr) {
        return 0;
    }
    TAIL->getPrev()->getDataNode(data_);    //because TAIL don't have data...

    NODE *temp_node = TAIL->getPrev();
    delete TAIL;
    TAIL = temp_node;
    TAIL->setNext(nullptr);

    return 1;
}

int QUEUE::peek(DATA *data, int num_node) const {
    NODE* current_node = HEAD;
    int count_node = 0;
    while (current_node->getNext() != nullptr) {
        if (count_node == num_node) {
            current_node->getDataNode(data);
            return 1;
        }

        current_node = current_node->getNext();
        count_node++;
    }
    return 0;
}

int QUEUE::SetPriorNode(int num_node, int prior) {
    int count_node = 0;
    NODE *current_node = HEAD;
    while (current_node->getNext() != nullptr) {
        if (count_node == num_node) {
            current_node->setPriority(prior);
            return 1;
        }

        current_node = current_node->getNext();
        count_node++;
    }
    return 0;
}

int QUEUE::GetPriorNode(int num_node, int& prior) const {
    int count_node = 0;
    NODE *current_node = HEAD;
    while (current_node->getNext() != nullptr) {
        if (count_node == num_node) {
            prior = current_node->getPriority();
            return 1;
        }

        current_node = current_node->getNext();
        count_node++;
    }
    return 0;
}

int QUEUE::copyLinkedListTo(QUEUE **list) {
    if (*list == nullptr) {
        *list = new QUEUE(this); //call copy constructor, if list is NULL
        return amountElements;
    }

    (*list)->erase();  //remove all elements
    //start copy elements to list
    int current_node = 0;
    int prior = 0;
    DATA current_data;
    while(peek(&current_data, current_node)) {
        GetPriorNode(current_node, prior);
        (*list)->push(&current_data, prior);
        current_node++;
    }

    return amountElements;
}


QUEUE::QUEUE(QUEUE* old_list) {
    HEAD = new NODE();
    TAIL = HEAD;

    NODE* current_node = HEAD;
    DATA current_data;
    int num_node = 0;
    int prior_current_node = 0;
    while (old_list->peek(&current_data, num_node)) {
        old_list->GetPriorNode(num_node, prior_current_node);
        push(&current_data, prior_current_node);
        num_node++;
    }
}

int QUEUE::erase() {
    DATA* temp;
    while(pop(temp));

    return 0;
}

bool QUEUE::isSortedByPriority(bool ascending) {
    int current_node = 0;

    int current_prior = 0;
    int prev_prior = std::numeric_limits<int>::min();;

    if (ascending == false) {
        prev_prior = std::numeric_limits<int>::max();
    }

    while(GetPriorNode(current_node, current_prior)) {
        if (ascending) {    //it can be put over cycle... can be economy little bit time
            if (current_prior < prev_prior) {
                return false;
            }
            prev_prior = current_prior;
        }
        else {
            if (current_prior > prev_prior) {
                return false;
            }
            prev_prior = current_prior;
        }
        current_node++;
    }

    return true;
}

