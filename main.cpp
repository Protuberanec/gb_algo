/*
 * решение находится в функциях:
 * задача1 - char* convert_dec_to_bin(int dec);
 * задача2 вариант1 - int myPow_1(int a, int b)
 * задача2 вариант2 - int myPow_2(int a, int b)
 * задача3 - int routes_corr_rec(int x, int y, int *obstacle)
 *
 * все функции вызываются из функций с префиксом test_, кроме последней, т.к. необходимо построить конечную карту,
 * для этого были написаны не рекурсивные функции
 *      int routes(int x, int y)
 *      int correct_route_non_rec(int _x, int _y, int* obstacle, int* real_chess)
 *      void correct(int _x, int _y, int *real_chess)
 * которая решает обход препятствий в лоб, после её отладки, была написана рекурсивная функция
 *
 */
#include <iostream>
#include <limits>
#include <assert.h>
#include <assert.h>
#include <cstring>
#include <map>

using namespace std;

//#define SHOW_DBG_TASK1
//#define SHOW_DBG_TASK3

//Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

char* convert_dec_to_bin(int dec) {
    char *bin_number;
    static int count_dig = 0;   //count signs in the number
    static int size_str = 0;    //total string size
    if (dec <= 1) {
        count_dig++;
        size_str = count_dig;
        bin_number = new char [count_dig + 1];
        memset(bin_number, 0x00, count_dig);
        bin_number[0] = 0x31;
        return bin_number;
    }
    count_dig++;
    bin_number = convert_dec_to_bin(dec / 2);

    bin_number[size_str - --count_dig] = 0x30 + dec % 2;

    return bin_number;
}

void test_convert_dec_to_bin() {
//------------------------------------------------------------------------------
    //test1
    char *temp = convert_dec_to_bin(19);
    assert(!strcmp(temp, "10011"));
#ifdef SHOW_DBG_TASK1
    cout << temp << endl;
#endif
    delete [] temp;
//------------------------------------------------------------------------------
    //test2
    temp = convert_dec_to_bin(29);  //don't forget release memory of temp
    assert(!strcmp(temp, "11101"));
#ifdef SHOW_DBG_TASK1
    cout << temp << endl;
#endif
    delete [] temp;
//------------------------------------------------------------------------------
    //test3
    temp = convert_dec_to_bin(99);  //don't forget release memory of temp
    assert(!strcmp(temp, "1100011"));
#ifdef SHOW_DBG_TASK1
    cout << temp << endl;
#endif
    delete [] temp;
//------------------------------------------------------------------------------
    //test4
    temp = convert_dec_to_bin(198);  //don't forget release memory of temp
    assert(!strcmp(temp, "11000110"));
#ifdef SHOW_DBG_TASK1
    cout << temp << endl;
#endif
    delete [] temp;
    cout << "Test " << __FUNCTION__ << " passed ok" << endl;
}

//Реализовать функцию возведения числа [a] в степень [b] двумя способами:
    //Рекурсивно.
int myPow_1(int a, int b) {
    if(b == 0) {
        return 1;
    }
    if(b == 1) {
        return a;
    }

    return a * myPow_1(a, b - 1);
}

void test_myPow_1() {
    assert(myPow_1(10, 0) == 1);
    assert(myPow_1(2, 2) == 4);
    assert(myPow_1(2, 3) == 8);
    assert(myPow_1(3, 3) == 27);
    assert(myPow_1(10, 3) == 1000);
    assert(myPow_1(10, 1) == 10);
    assert(myPow_1(11, 2) == 121);

    cout << "Test " << __FUNCTION__ << " passed ok" << endl;
}
//Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная,
//основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат умножается на
//основание, а показатель уменьшается на единицу)
int myPow_2(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }

    if (!(b % 2)) {
        b = b/2;
        return myPow_2(a*a, b);
    }
    else if ((b % 2)) {
        b = b-1;
        return a * myPow_2(a,b);
    }

    return 0;   //to exclude warning...
}

void test_myPow_2() {
    assert(myPow_2(10, 0) == 1);
    assert(myPow_2(10, 1) == 10);
    assert(myPow_2(2, 4) == 16);
    assert(myPow_2(11, 2) == 121);
    assert(myPow_2(3, 3) == 27);
    assert(myPow_2(3, 9) == 19683);
    assert(myPow_2(2, 3) == 8);
    assert(myPow_2(2, 6) == 64);
    assert(myPow_2(10, 3) == 1000);
    assert(myPow_2(10, 1) == 10);

    cout << "Test " << __FUNCTION__ << " passed ok" << endl;
}

//Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия,
// а ноль - свободная для хода клетка)
//движение короля сверху вниз, слева направо
/*
 * input        :
 * output       :
 * description  :
 * author       :   我是丹尼斯
 * date         :   二零二一年。七月。八号
 * version
 */
int routes(int x, int y) {
    if (x == 0 && y == 0) {
        return 0;
    }
    else if (x == 0 ^ y == 0) {
        return 1;
    }
    else
        return routes(x-1, y) + routes(x, y-1);
}
/*
 * input        :   x,y конечного маршрута и карта препятствий
 * output       :
 * description  :
 * author       :   我是丹尼斯
 * date         :   二零二一年。七月。八号
 * version
 */
int routes_corr_rec(int x, int y, int *obstacle) {
    if (x == 0 && y == 0) {
        return 0;
    }
    else if (x == 0 ^ y == 0) {
        if (y == 0) {
            for (int _x = x; _x >= 0; _x--) {
                if (obstacle[_x] == 1) {
                    return 0;//если до этого x было препятствие, то надо вернуть 0
                }
            }
        }
        if (x == 0) {
            for (int _y = y; _y >= 0; _y--) {
                if (obstacle[_y*8] == 1) {
                    return 0;//если до этого x было препятствие, то надо вернуть 0
                }
            }
        }
        return 1;
    }
    else {
        int tempx = 0;
        int tempy = 0;
        if (obstacle[x + 8*y] == 1) {
            tempx = 0;
            tempy = 0;
        }
        else {
            tempx = routes_corr_rec(x - 1, y, obstacle);
            tempy = routes_corr_rec(x, y - 1, obstacle);
        }

        return tempx + tempy;
    }
}

//it's non recursive and stupid solution... only for check my minds
void correct(int _x, int _y, int *real_chess) {
    for (int y = _y; y < 8; y++) {
        for (int x = _x; x < 8; x++) {
            if (real_chess[x + 8 * y] == 0) {
                continue;
            }
            int tempx = 0;
            int tempy = 0;
            if (x != 0) {
                 tempx = real_chess[(x - 1) + 8 * (y)];
            }
            if (y != 0) {
                tempy = real_chess[x + 8 * (y-1)];
            }

            real_chess[x + 8 * y] = tempx + tempy;
        }
    }
}
int correct_route_non_rec(int _x, int _y, int* obstacle, int* real_chess) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (obstacle[x + 8*y] == 1) {
                real_chess[x + 8*y] = 0;
                correct(x,y, real_chess);
            }
        }
    }
    return 0;
}
//-----------------------------------------------------------------
/*
 * input        :   chessfield, width - w, height -h
 * output       :   show in terminal data in chessfield
 * description  :   only show array = chessfield
 * author       :   我是丹尼斯
 * date         :   二零二一年。七月。八号
 * version      :   v0
 */
void ShowChessField(int *ChessField, int w, int h) {
    cout << "--------------------------------------" << endl;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << ChessField[x + y * h] << "\t";
        }
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
}
/*
 * input        :   start_coor_king = {0,0}, end_coor_king = {7,7}
 * output       :
 * description  :   была заложена идея давать королю начальное положение кроме 0,0 и конечное положение отличное от 7,7... но не хватило времени...
 * author       :   我是丹尼斯
 * date         :   二零二一年。七月。八号
 * version      :   v0
 */
int CountPossibleMoveKing(const pair<unsigned int /*X*/, unsigned int /*Y*/>& start_coor_king,
                          const pair<unsigned int /*X*/, unsigned int /*Y*/>& end_coor_king,
                          int *obstacle_chess_table) {

    auto [xE, yE] = end_coor_king;
#define SHOW_DBG
#ifdef SHOW_DBG_TASK3
    int real_chess_table[8][8];
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            real_chess_table[y][x] = routes(x,y);
        }
    }

    correct_route_non_rec(xE, yE, &obstacle_chess_table[0], &real_chess_table[0][0]);
    ShowChessField(&real_chess_table[0][0], xE+1,yE+1);
#endif
    return routes_corr_rec(xE, yE, obstacle_chess_table);
}



void test_CountPossibleMoveKing() {
    {   //    test1
#ifdef SHOW_DBG_TASK3
        cout << "--- test1 task3 --- " << endl;
#endif
        int ChessTableObstacle[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0}};

        assert(CountPossibleMoveKing({0x00, 0x00}, {7, 7}, &ChessTableObstacle[0][0]) == 3432);
#ifdef SHOW_DBG_TASK3
        cout << "passed OK" << endl;
#endif
    }

    {   //    test2
#ifdef SHOW_DBG_TASK3
        cout << "--- test2 task3 --- " << endl;
#endif
        int ChessTableObstacle[8][8] = {{0, 0, 1, 0, 1, 0, 0, 0},
                                        {1, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {1, 0, 0, 1, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 1, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 1, 0, 0, 0}};

        assert(CountPossibleMoveKing({0, 0}, {7, 7}, &ChessTableObstacle[0][0]) == 211);
#ifdef SHOW_DBG_TASK3
        cout << "passed OK" << endl;
#endif
    }

    {   //    test3
#ifdef SHOW_DBG_TASK3
        cout << "--- test3 task3 --- " << endl;
#endif
        int ChessTableObstacle[8][8] = {{0, 0, 1, 0, 1, 0, 0, 0},
                                        {1, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {1, 0, 0, 1, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 1, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 1, 0, 1, 0}};

        assert(CountPossibleMoveKing({0, 0}, {7, 7}, &ChessTableObstacle[0][0]) == 0);
#ifdef SHOW_DBG_TASK3
        cout << "passed OK" << endl;
#endif
    }
    {   //    test4
#ifdef SHOW_DBG_TASK3
        cout << "--- test4 task3 --- " << endl;
#endif
        int ChessTableObstacle[8][8] = {{0, 1, 1, 0, 1, 0, 0, 0},
                                        {1, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0},
                                        {1, 0, 0, 1, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 1, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 1, 0, 1, 0}};

        assert(CountPossibleMoveKing({0, 0}, {7, 7}, &ChessTableObstacle[0][0]) == 0);
#ifdef SHOW_DBG_TASK3
        cout << "passed OK" << endl;
#endif
    }

    {   //    test5
#ifdef SHOW_DBG_TASK3
        cout << "--- test5 task3 --- " << endl;
#endif
        int ChessTableObstacle[8][8] = {{0, 1, 1, 0, 1, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0, 0, 0},
                                        {0, 1, 0, 1, 0, 0, 0, 1},
                                        {0, 1, 0, 0, 0, 1, 0, 1},
                                        {0, 1, 0, 0, 0, 0, 0, 1},
                                        {0, 1, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 0, 0}};

        assert(CountPossibleMoveKing({0, 0}, {7, 7}, &ChessTableObstacle[0][0]) == 1);
#ifdef SHOW_DBG_TASK3
        cout << "passed OK" << endl;
#endif
    }

    cout << "Test test_CountPossibleMoveKing passed OK" << endl;
    return;
}


int main(int argc, char** argv) {
#ifdef SHOW_DBG_TASK1
    cout << "--- start task1 ---" << endl;
#endif
    test_convert_dec_to_bin();  //task 1
#ifdef SHOW_DBG_TASK1
    cout << "--- end task1 ---" << endl;
#endif
    test_myPow_1();     //task 2 - 1
    test_myPow_2();     //task 2 - 2

#ifdef SHOW_DBG_TASK3
    cout << "--- start task1 ---" << endl;
#endif
    test_CountPossibleMoveKing();   //task 3
#ifdef SHOW_DBG_TASK3
    cout << "--- end task1 ---" << endl;
#endif

    return 0;
}
