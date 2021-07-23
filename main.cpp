
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
std::pair<bool, QUEUE*>  task1_BracketsAnalyse(const char *brackets_string) {
    QUEUE *seq_brackets = fillListByBrackets(brackets_string);
    if (strlen(brackets_string) % 2) {
        return {false, seq_brackets};   //if brackets is not even, everytime don't have 1 bracket
    }

    //priority will used for mark pair of brackets

    std::map<char, char> pair_brackets = {{'(', ')'},
                                          {'{', '}'},
                                          {'[', ']'}};

    int current_num_node = 0;
    int current_prior_node = 0;
    DATA current_data_node;
    char current_bracket;

    int look_for_node = current_num_node + 1;
    DATA data_look_node;
    //first must be ( or [ or { otherwise return false

    int num_bracket = 1;
    while(seq_brackets->peek(&current_data_node, current_num_node)) {
        while(seq_brackets->GetPriorNode(current_num_node, current_prior_node)) {
            if (current_prior_node == 0) {  //look for bracket which will not processed
                int size;
                seq_brackets->peek(&current_data_node, current_num_node);
                current_bracket = (char)current_data_node.GetData(size)[0];
                if (current_bracket == ')' || current_bracket == ']' || current_bracket == '}'){
                    return {false, seq_brackets};   //
                }
                break;
            }
            current_num_node++;
        }

        //here we must found different open brackets ( or { or [

        seq_brackets->SetPriorNode(current_num_node, num_bracket);
        look_for_node = current_num_node + 1;
        while(seq_brackets->peek(&data_look_node, look_for_node)) {
            int temp_prior = 0;
            int temp;
            seq_brackets->GetPriorNode(look_for_node, temp_prior);
            if (pair_brackets[current_bracket] == (char)data_look_node.GetData(temp)[0] && temp_prior == 0) {
                seq_brackets->SetPriorNode(look_for_node, num_bracket);
                break;
            }
            look_for_node++;
        }
        current_num_node++;
        num_bracket++;
    }

//if need get structure with brackets... need remove this strings....
    delete seq_brackets;
    seq_brackets = nullptr;
    return {true, seq_brackets};
}

void test_task1() {
    assert(task1_BracketsAnalyse("([])()").first == true);
    assert(task1_BracketsAnalyse("[][]{}{()}()").first == true);
    assert(task1_BracketsAnalyse("[[[[()]]]{({()})}]").first == true);
    assert(task1_BracketsAnalyse(")(").first == false);
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

    cout << "test brackets passed OK" << endl;
}


//2. Создать функцию, копирующую односвязный список (без удаления первого списка).
//3. Реализуйте алгоритм, который определяет, отсортирован ли связный список.

int main(int argc, char** argv) {

    test_queue();

    test_task1();


    return 0;
}
