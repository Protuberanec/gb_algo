
#include <iostream>
#include <limits>
#include <assert.h>
#include <cstring>
#include <string>
#include <iterator>
#include <algorithm>
#include <regex>
#include "array_func.h" //standard function to work with array... very usefull...
#include "ConsoleWork.h"    //stupid attempt to write own lib to work with console...

//#include "graph.h"
//#include "test_graph.h"


using namespace std;
struct Query {
    int type;
    char* name;

    void clear() {
        memset(name, 0x00, 128);
    }

    Query() {
        name = new char [128];
        memset(name, 0x00, 128);
    }
    ~Query() {
        delete [] name;
    }
};

/*
 *  description :   attempt overload cin
 */
istream& operator>>(istream& is, Query& q) {
    // Реализуйте эту функцию
    q.clear();
    is >> q.name;


    return is;

}

int main(int argc, char **argv) {
    istringstream input;
    input.str("Denis name");
    Query q;
    input >> q;

    std::cout << "\t\tall tests passed OK" << std::endl;

    return 0;
}
