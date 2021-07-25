
#include <iostream>
#include <limits>
#include <assert.h>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <windows.h>
#include <sysinfoapi.h>

#include "array_func.h"
#include "ConsoleWork.h"
#include "queue.h"
#include "test_queue.h"

using namespace std;

//1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
// - неправильных — )(, ())({), (, ])}), ([(])
// для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]

QUEUE* fillListByBrackets(const char* brackets_string) {
    QUEUE *seq_brackets = new QUEUE();

    int size = strlen(brackets_string);
    for (int i = 0; i < size; i++) {
        if (brackets_string[i] == '[' || brackets_string[i] == ']' ||
            brackets_string[i] == '(' || brackets_string[i] == ')' ||
            brackets_string[i] == '{' || brackets_string[i] == '}')
        {
            seq_brackets->push(new DATA(1, new int{brackets_string[i]}), 0);
        }
    }
    return seq_brackets;
}

/*
 *  input       :   string with brackets
 *  output      :   true if brackets enough, otherwise false, and structure wich contain brackets
 *  descritpion :
 *  date        :
 *  author      :
 *  version     :
 */

std::tuple<int /*num node*/, char /*bracket*/, bool /*found*/> getNodeCloseBracket(const QUEUE* brackets_queue, int start_node = 1) {
    int current_node = start_node;
    DATA data_node;
    int size;
    int prior_current_node;
    while (brackets_queue->peek(&data_node, current_node)) {
        if (data_node.GetData(size)[0] == ')' ||
            data_node.GetData(size)[0] == ']' ||
            data_node.GetData(size)[0] == '}')
        {
            //check priority, if priority == 0... we find the brackets...
            brackets_queue->GetPriorNode(current_node, prior_current_node);
            if (prior_current_node == 0) {
                return {current_node, data_node.GetData(size)[0], true};
            }
        }

        current_node++;
    }
    return {current_node, ' ', false};
}
//decrement
std::pair<int, bool> getNodeOpenBracket(const QUEUE* brackets_queue, char bracket, int start_node = -1) {
    if (start_node == -1) {
        return {-1, false};
    }
    int current_node = start_node;
    DATA data_node;
    int size;
    int prior_current_node;
    std::map<char, char> pair_brackets = {{'(', ')'},
                                          {')', '('},
                                          {'{', '}'},
                                          {'}', '{'},
                                          {'[', ']'},
                                          {']', '['}};
    while (brackets_queue->peek(&data_node, current_node)) {
        if (data_node.GetData(size)[0] == pair_brackets[bracket]) {
            brackets_queue->GetPriorNode(current_node, prior_current_node);
            if (prior_current_node != 0) {
                current_node--;
                continue;
            }
            return {current_node, true};
        }
        else {
            //if open bracket with priority = 0... return false
            brackets_queue->GetPriorNode(current_node, prior_current_node);
            if (prior_current_node == 0) {
                if (data_node.GetData(size)[0] == '(' ||
                    data_node.GetData(size)[0] == '{' ||
                    data_node.GetData(size)[0] == '[')
                {
                    return {-1, false};
                }
            }
        }
        current_node--;
        if (current_node < 0) {
            break;
        }
    }
    return {-1, false};
}

std::pair<bool, QUEUE*>  task1_BracketsAnalyse(const char *brackets_string) {
    if (strlen(brackets_string) % 2) {
        return {false, nullptr};   //if brackets is not even, everytime don't have 1 bracket
    }
    if (brackets_string[0] == ')' ||
        brackets_string[0] == ']' ||
        brackets_string[0] == '}')
    {
        return {false, nullptr};
    }
    QUEUE *brackets_queue = fillListByBrackets(brackets_string);

    //priority will used for mark pair of brackets
    int num_brackets = 1;
    int current_close_bracket = 0;
    DATA data;
    while(brackets_queue->peek(&data, current_close_bracket)) {
        auto[num_node_close_bracket, bracket, ok] = getNodeCloseBracket(brackets_queue, current_close_bracket);
        brackets_queue->SetPriorNode(num_node_close_bracket, num_brackets);
        current_close_bracket = num_node_close_bracket + 1;
        if (ok == false) {
            delete brackets_queue;
            brackets_queue = nullptr;
            return {false, brackets_queue};
        }

        auto [num_node_open_bracket, ok1] = getNodeOpenBracket(brackets_queue, bracket, num_node_close_bracket-1); //here go left, and look for first bracket without prior, and equal to vice versa bracket
        if (ok1 == false) {
            delete brackets_queue;
            brackets_queue = nullptr;
            return {false, brackets_queue};
        }
        brackets_queue->SetPriorNode(num_node_open_bracket, num_brackets);

        num_brackets++;
    }
//if need get structure with brackets... need remove strings delete ....
    delete brackets_queue;
    brackets_queue = nullptr;
    return {true, brackets_queue};
}

void test_task1() {
    assert(task1_BracketsAnalyse("[[[[()]]]{({()})}]").first == true);
    assert(task1_BracketsAnalyse("([])()").first == true);
    assert(task1_BracketsAnalyse("([{])(})").first == false);
    assert(task1_BracketsAnalyse("[][]{}{()}()").first == true);
    assert(task1_BracketsAnalyse(")(").first == false);
    assert(task1_BracketsAnalyse("([){}(]){}").first == false);
    assert(task1_BracketsAnalyse("])})").first == false);
    assert(task1_BracketsAnalyse("}()()").first == false);
    assert(task1_BracketsAnalyse("(").first == false);
    assert(task1_BracketsAnalyse("([(])").first == false);
    assert(task1_BracketsAnalyse("([(])").first == false);
    assert(task1_BracketsAnalyse("()[]()]()").first == false);
    assert(task1_BracketsAnalyse("())").first == false);
    assert(task1_BracketsAnalyse("()").first == true);
    assert(task1_BracketsAnalyse("([{}])").first == true);
    assert(task1_BracketsAnalyse("{}()").first == true);
    assert(task1_BracketsAnalyse("())({)").first == false);
    assert(task1_BracketsAnalyse("({})()([}{])").first == false);

    cout << "test brackets passed OK" << endl;
}


//2. Создать функцию, копирующую односвязный список (без удаления первого списка).
//3. Реализуйте алгоритм, который определяет, отсортирован ли связный список.
void test_task2_and_3() {
    test_queue();   //last test is test copy one list to another
}


int main(int argc, char** argv) {

    test_queue();

    test_task1();
    test_task2_and_3();

    std::cout << "\t\tall tests passed OK" << std::endl;

    return 0;
}
