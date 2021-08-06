//
// Created by Tr on 05.08.2021.
//

#ifndef CPP_PROJ_MY_CRYPTO_H
#define CPP_PROJ_MY_CRYPTO_H
#include <iostream>
#include <stdlib.h>
#include <cstring>

char* cesar_crypto(const char* input_mess, int bias_letter);
char* cesar_decrypto(const char* input_mess, int bias_letter);

char* table_crypto(const char* input_mess, int col);
char* table_decrypto(const char* input_mess, int col);

#endif //CPP_PROJ_MY_CRYPTO_H
