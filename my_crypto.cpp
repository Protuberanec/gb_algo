//
// Created by Tr on 05.08.2021.
//

#include "my_crypto.h"

char* cesar_crypto(const char* input_mess, int bias_letter) {
    int str_size = strlen(input_mess);
    char *result_crypto = new char [str_size + 1];
    memset(result_crypto, 0x00, str_size + 1);

    for (int i = 0; i < str_size; i++) {
        result_crypto[i] = input_mess[i] + bias_letter;
    }
    return result_crypto;
}

char* cesar_decrypto(const char* input_mess, int bias_letter) {
    int str_size = strlen(input_mess);
    char *result_decrypto = new char [str_size + 1];
    memset(result_decrypto, 0x00, str_size + 1);

    for (int i = 0; i < str_size; i++) {
        result_decrypto[i] = input_mess[i] - bias_letter;
    }
    return result_decrypto;

}

char* table_crypto(const char* input_mess, int col) {
    int str_size = strlen(input_mess);
    int total_size_str = str_size;
    //get square...
    while (str_size > 0) {
        str_size -= col;
    }
    total_size_str += str_size*(-1);
    str_size = strlen(input_mess);

    char *result_crypto = new char [total_size_str + 1];
    memset(result_crypto, ' ', total_size_str + 1);

    int cur_el = 0;
    for (int i = 0; i < col; i++) {
        for (int j = i; j < total_size_str-1; j += col, cur_el++) {
            if (input_mess[j] == 0x00){
                continue;
            }
            if (j >= str_size) {
                continue;
            }
            result_crypto[cur_el] = input_mess[j];
        }
    }
    result_crypto[total_size_str] = 0x00;

    return result_crypto;
}

char* table_decrypto(const char* input_mess, int row) {
    int str_size = strlen(input_mess);
    char *result_decrypto = new char [str_size + 1];
    memset(result_decrypto, ' ', str_size + 1);

    int col = str_size / row;
    int cur_el = 0;
    for (int i = 0; i < col; i++) {
        for (int j = i; j < str_size-1; j += col, cur_el++) {
            result_decrypto[cur_el] = input_mess[j];
        }
    }
    result_decrypto[str_size] = 0x00;

    return result_decrypto;
}