#include <iostream>
#include <limits>
#include <assert.h>
//task2
int perepol(unsigned char a1, unsigned char a2) {
    int status = 0;

    unsigned char temp_max = std::numeric_limits<unsigned char>::max() / a2;

    if (a1 > temp_max) {
        status = 1;
    }
    return status;
}

void test_perpol() {
    assert(perepol(100,10) == 1);
    assert(perepol(10,10) == 0);
    assert(perepol(33,1) == 0);
    assert(perepol(33,10) == 1);
    assert(perepol(50,50) == 1);
    assert(perepol(25,25) == 1);
    assert(perepol(250,1) == 0);
    assert(perepol(200,2) == 1);
}

int main() {
	
	//hw1
    std::cout << "你好，世界" << std::endl;
    std::cout << "Hello world" << std::endl;

	//hw2 algo
	test_perpol();

    return 0;
}
