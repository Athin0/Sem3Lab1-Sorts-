//
// Created by arina on 02.10.2021.
//

#include "baseFunc.h"
#include "iostream"
#include "random"
//#include "test.h"
#define maxInt 10000
using namespace std;

int GetInt() {
    int k;
    cin >> k;
    return k;
}

int GetInt(int up) {
    int k;
    cin >> k;
    if (k > up) {
        cout << "Число вне диапозона. Повторите попытку\n";
        return GetInt(up);
    }
    return k;
}

int GetInt(int down, int up) {
    int k;
    cin >> k;
    if (k > up || k < down) {
        cout << "Число вне диапозона. Повторите попытку\n";
        return GetInt(down, up);
    }

    return k;
}


int randomInt() {
    return rand() % maxInt;
}



int GetType() {
    cout << "Введите число для работы со следующим типом данных: \n"
         << "\t1: Dynamic Array Sequence\n"
         << "\t2: Linked List Sequence\n"
         << "\t0: Выйти из функции\n"
         << ": ";
    return GetInt(0, 2);
}
//5
void testFunc() {
    cout << "Введите:\n"
            "\t- положительное число для ввода итераций тестов\n"
            "\t- нуль или отрицательное число для выхода\n: ";
    int count = GetInt();
    if (count <= 0)
        return;
                                                                            ///testAll(count, 1);

    cout << "Хотите запустить тестирование ещё раз?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";
    count = GetInt(0, 1);
    if (count == 1)
        testFunc();
}
