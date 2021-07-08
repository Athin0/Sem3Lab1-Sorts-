//
// Created by arina on 08.07.2021.
//

#ifndef SORTS_SORTS_H
#define SORTS_SORTS_H
#include <iostream>
#include "vector"
#include "random"
using namespace std;
template <class T>
void sortBubble(vector<T>& vec);

template <class T>
void sortInsertion(vector<T>& vec);

template <class T>
void sortSelection(vector<T>& vec);

template <class T>
void sortMerge(T, int);

template <class T>
void swap(T &a1,T &a2) {
    T temp = a1;
    a1 =a2;
    a2 = temp;
}
#endif //SORTS_SORTS_H