//
// Created by arina on 02.10.2021.
//

#ifndef SORTS_MENU_H
#define SORTS_MENU_H

#include "Sequence.h"
#include <iostream>
#include "DynamicArraySequence.h"
#include "LinkedListSequence.h"
void mainMenuSequence();
int getType();

//1
void readSequence(ArraySequence<ArraySequence<int> *> *arrDA,
ArraySequence<LinkedListSequence<int> *> *arrLL);

template<class T>
void readTypeSequence(ArraySequence<Sequence<T>*> *arr, int count);

template<class T>
void readTypeSequence(Sequence<ArraySequence<T>*> *arr, int count);

template<class T>
void readTypeSequence(Sequence<LinkedListSequence<T>*> *arr, int count);

template<class T>
void generateRandomSequence(ArraySequence<Sequence<T>*> *arr, int count, T (*func)());


template<class T>
void generateRandomSequence(ArraySequence<LinkedListSequence<T>*> *arr, int count, T (*func)());


template<class T>
void generateRandomSequence(ArraySequence<ArraySequence<T>*> *arr, int count, T (*func)());

//2
void operationWithSequence(ArraySequence<ArraySequence<int> *> *arrDA,
ArraySequence<LinkedListSequence<int> *> *arrLL);

template<class T>
void operationTypeWithSequence(ArraySequence<Sequence<T>*> *arr);

//3
void printSequence(ArraySequence<ArraySequence<int> *> *arrDA,
ArraySequence<LinkedListSequence<int> *> *arrLL);

template<class T>
void printTypeSequence(ArraySequence<Sequence<T>*> *arr);


//4
void deleteSequence(ArraySequence<ArraySequence<int> *> *arrDA,
ArraySequence<LinkedListSequence<int> *> *arrLL);

template<class T>
void deleteTypeSequence(ArraySequence<Sequence<T>*> *arr);

//5
void testFunc();

#endif //SORTS_MENU_H
