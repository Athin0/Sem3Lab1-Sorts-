//
// Created by arina on 10.10.2021.
//

#include "DynamicArraySequence.h"
#include "baseFunc.h"
#include "Sorts.h"
#include "LinkedListSequence.h"

#ifndef SORTS_COMPARE_H
#define SORTS_COMPARE_H

void SortSequence( ArraySequence<ArraySequence<int>*> *ArrDA,
    ArraySequence<LinkedListSequence<int>*> *ArrLL);


template<class T>
void SortType(ArraySequence<Sequence<T>*> *ArrInt);

template<class T>
ArraySequence<double> *getSortTime(ArraySequence<int> &arr1);

void compare();

#endif //SORTS_COMPARE_H
