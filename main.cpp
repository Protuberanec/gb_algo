#include <iostream>
#include <limits>
#include <assert.h>
#include <assert.h>

using namespace std;

bool isNaturalNumb(int num) {
    int count_del = 0;

    for (int i = 2; i <= num/2; i++) {
        if (!(num % i)) {
            if (i != num) {
                return false;
            }
        }
    }

    return true;    //natural number
}

void Test_isNaturalNumb() {
    assert(isNaturalNumb(1) == true);
    assert(isNaturalNumb(2) == true);
    assert(isNaturalNumb(4) == false);
    assert(isNaturalNumb(9) == false);
    assert(isNaturalNumb(11) == true);
    assert(isNaturalNumb(131) == true);
    assert(isNaturalNumb(132) == false);
    assert(isNaturalNumb(657) == false);
    assert(isNaturalNumb(1001) == false);   //7
    assert(isNaturalNumb(1003) == false);    //17
}



int main(int argc, char** argv) {
    Test_isNaturalNumb();
	if (argc < 2) {
	    cout << "give me an integer number, as parameter of program" << endl;
	    return 1;
	}

	//always assume, that number is integer
	cout << "Number is ";
    cout << (isNaturalNumb(atoi(argv[1])) == true ? "natural" : "not natural") << endl;

    return 0;
}
