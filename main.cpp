
#include <iostream>
#include <limits>
#include <assert.h>

#include "my_crypto.h"

using namespace std;

//Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
void test_cesar_crypto() {
    cout << "\t---Caesar crypto---" << endl;
    {   //test1
        const char STR_CRYPT[] = "Denis";
        const int KEY = 5;
        char *res_code = cesar_crypto(STR_CRYPT, KEY);
        cout << "string for crypto = " << STR_CRYPT << endl;
        cout << "coded string : " << res_code << endl;
        char *res_decode = cesar_decrypto(res_code, KEY);
        cout << "decoded string : " << res_decode << endl;

        delete [] res_code;
        delete [] res_decode;
    }

    {   //test2
        const char STR_CRYPT[] = "Denis";
        const int KEY = 35;
        char *res_code = cesar_crypto(STR_CRYPT, KEY);
        cout << "string for crypto = " << STR_CRYPT << endl;
        cout << "coded string : " << res_code << endl;
        char *res_decode = cesar_decrypto(res_code, KEY);
        cout << "decoded string : " << res_decode << endl;

        delete [] res_code;
        delete [] res_decode;
    }
    {   //test2
        const char STR_CRYPT[] = "The cat love to walk on a roof!!!";
        const int KEY = 35;
        char *res_code = cesar_crypto(STR_CRYPT, KEY);
        cout << "string for crypto = " << STR_CRYPT << endl;
        cout << "coded string : " << res_code << endl;
        char *res_decode = cesar_decrypto(res_code, KEY);
        cout << "decoded string : " << res_decode << endl;

        delete [] res_code;
        delete [] res_decode;
    }
}
//Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов

void test_table_crypto() {
    cout << "\n\t---table crypto---" << endl;

    {   //test1
        cout << "---test 1---" << endl;
        const char STR[] = "The cat very like to walk on a roof!!!";
        int key = 2;
        char* res = table_crypto(STR, key);
        char* res1 = table_decrypto(res, key);
        cout << "\tstart string = \t" << STR << endl;
        cout << "\tcoded string = \t" << res << endl;
        cout << "\tdecoded string = \t" << res1 << endl;
        cout << "------" << endl;

        delete [] res;
        delete [] res1;

    }
    {   //test2
        cout << "---test 2---" << endl;
        const char STR[] = "The cat very like to walk on a roof!!!";
        int key = 3;
        char* res = table_crypto(STR, key);
        char* res1 = table_decrypto(res, key);
        cout << "\tstart string = \t" << STR << endl;
        cout << "\tcoded string = \t" << res << endl;
        cout << "\tdecoded string = \t" << res1 << endl;
        cout << "------" << endl;

        delete [] res;
        delete [] res1;
    }
    {   //test3
        cout << "---test 3---" << endl;
        const char STR[] = "The cat very like to walk on a roof!!!";
        int key = 4;
        char* res = table_crypto(STR, key);
        char* res1 = table_decrypto(res, key);
        cout << "\tstart string = \t" << STR << endl;
        cout << "\tcoded string = \t" << res << endl;
        cout << "\tdecoded string = \t" << res1 << endl;
        cout << "------" << endl;

        delete [] res;
        delete [] res1;
    }
    {   //test4
        cout << "---test 4---" << endl;
        const char STR[] = "The cat very like to walk on a roof!!!";
        int key = 7;
        char* res = table_crypto(STR, key);
        char* res1 = table_decrypto(res, key);
        cout << "\tstart string = \t" << STR << endl;
        cout << "\tcoded string = \t" << res << endl;
        cout << "\tdecoded string = \t" << res1 << endl;
        cout << "------" << endl;

        delete [] res;
        delete [] res1;
    }
    {   //test5
        cout << "---test 5---" << endl;
        const char STR[] = "The cat very like to walk on a roof!!!";
        int key = 21;
        char* res = table_crypto(STR, key);
        char* res1 = table_decrypto(res, key);
        cout << "\tstart string = \t" << STR << endl;
        cout << "\tcoded string = \t" << res << endl;
        cout << "\tdecoded str = \t" << res1 << endl;
        cout << "------" << endl;

        delete [] res;
        delete [] res1;
    }
    {   //test6
        cout << "---test 6---" << endl;
        const char STR[] = "The cat very like to walk on a roof!!!";
        int key = 31;
        char* res = table_crypto(STR, key);
        char* res1 = table_decrypto(res, key);
        cout << "\tstart string = \t" << STR << endl;
        cout << "\tcoded string = \t" << res << endl;
        cout << "\tdecoded str = \t" << res1 << endl;
        cout << "------" << endl;

        delete [] res;
        delete [] res1;
    }
}

int main(int argc, char** argv) {
    test_cesar_crypto();
    test_table_crypto();

    std::cout << "\t\tall tests passed OK" << std::endl;

    return 0;
}
