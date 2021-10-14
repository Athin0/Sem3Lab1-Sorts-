//
// Created by arina on 10.10.2021.
//

#include "DynamicArraySequence.h"
#include "baseFunc.h"
#include "Sorts.h"
#include "LinkedListSequence.h"
#include "DynamicArraySequence.h"
#include "Timer.h"

#ifndef SORTS_COMPARE_H
#define SORTS_COMPARE_H

template<class T>
static void SortType(ArraySequence<Sequence<T> *> *ArrInt) {
    int len = ArrInt->GetLength();
    if (len == 0) {
        std::cout << "Сортировать нечего..\n";
        return;
    }
    std::cout << "Выберите индекс от 0 до " << ArrInt->GetLength() - 1 << " (включительно):\n";

    int index;
    index = GetInt();
    while (index < 0 || index > len) {
        if (index < 0 || index > len)
            std::cout << "Индекс некоректен\n";
        index= GetInt();
        if (index == -1)
            return;
    }

    std::cout << "Выберите сортировку:\n"
              << "\t0 - Выход\n"
              << "\t1 - BubbleSort\n"
              << "\t2 - CocktailSort\n"
              << "\t3 - InsertionSort\n"
              << "\t4 - SelectionSort\n"
              << "\t5 - MergeSort\n"
              << "\t6 - QuickSort\n"
              << "\t7 - QuickHoareSort\n"
              << "\t8 - CountingSort\n"
              << "\t9 - ShellSort\n"
              << "\t10 - Shell2Sort\n"
              << "\t11 - SquareSelectionSort\n"
              << "\t12 - BinaryInsertionSort\n"
              << "\t13 - BinaryTreeSort\n"
              << "\t14 - HeapSort\n"
              << "\t15 - BitonicSort\n";

    int index22 = GetInt(0, 15);
    if (index22 == 0) {
        return;
    }

    //if (type == 1)
    //    ArraySequence<T> *ArrTemp = reinterpret_cast<ArraySequence<int> *>((ArrInt->Get(index))->copy());
    auto ArrTemp = (ArrInt->Get(index))->copy();
    //ArraySequence<T> ArrTemp.copy(ArrInt->Get(index));
    //if (type == 2)
    //    LinkedListSequence<T> *ArrTemp = reinterpret_cast<LinkedListSequence<int> *>((ArrInt->Get(index))->copy());

    T array1[] = {9, 5, 3, 8, 4, 1};   //для Шелла
    ArraySequence<T> arr(array1, 6);
    Sequence<T> *tempSeq;
    switch (index22) {
        case 1:
            tempSeq = Sorter<T>::sortBubble(*ArrTemp, cmp<T>);
            break;
        case 2:
            tempSeq = Sorter<T>::sortCocktail(*ArrTemp, cmp<T>);
            break;
        case 3:
            tempSeq = Sorter<T>::sortInsertion(*ArrTemp, cmp<T>);
            break;
        case 4:
            tempSeq = Sorter<T>::sortSelection(*ArrTemp, cmp<T>);
            break;
        case 5:
            tempSeq = Sorter<T>::sortMerge(*ArrTemp, cmp<T>);
            break;
        case 6:
            tempSeq = Sorter<T>::sortQuick(*ArrTemp, 0, ArrTemp->GetLength() - 1, cmp<T>);
            break;
        case 7:
            tempSeq = Sorter<T>::sortQuickHoare(*ArrTemp, 0, ArrTemp->GetLength() - 1, cmp<T>);
            break;
        case 8:
            tempSeq = Sorter<T>::sortCounting(*ArrTemp, cmp<T>);
            break;
        case 9:
            tempSeq = Sorter<T>::sortShell(*ArrTemp, cmp<T>);
            break;
        case 10:
            tempSeq = Sorter<T>::sortShell2(*ArrTemp, arr, cmp<T>);
            break;
        case 11:
            tempSeq = Sorter<T>::sortSelection(*ArrTemp, cmp<T>);
            break;
        case 12:
            tempSeq = Sorter<T>::sortBinaryInsertion(*ArrTemp, cmp<T>);
            break;
        case 13:
            tempSeq = Sorter<T>::sortBinaryTree(*ArrTemp, cmp<T>);
            break;
        case 14:
            tempSeq = Sorter<T>::sortHeap(*ArrTemp, cmp<T>);
            break;
        case 15:
            tempSeq = Sorter<T>::sortBitonic(*ArrTemp, cmp<T>);
            break;
    }

    std::cout << "Извенить существующий массив или создать новый?\n"
              << "\t1 - Изменить\n"
              << "\t2 - Создать новый\n";
    int index11 = GetInt(1, 2);
    switch (index11) {
        case 1:
            ArrInt->Set(index, tempSeq);
            break;
        case 2:
            ArrInt->Append(tempSeq);
            break;
    }
}


/*
void SortSequence( ArraySequence<ArraySequence<int>*> *ArrDA,
    ArraySequence<LinkedListSequence<int>*> *ArrLL);


template<class T>
void SortType(ArraySequence<Sequence<T>*> *ArrInt);

template<class T>
ArraySequence<double> *getSortTime(ArraySequence<int> &arr1);

void compare();
*/


static void SortSequence(ArraySequence<ArraySequence<int> *> *ArrDA, ArraySequence<LinkedListSequence<int> *> *ArrLL) {
    std::cout << "Извенить существующий массив или создать новый?\n"
              << "\t0 - Выйти\n"
              << "\t1 - Dynamic Array\n"
              << "\t2 - Linked List\n";
    int Type = GetInt(0, 2);
    if (Type == 0) {
        return;
    }

    ArraySequence<int> DAarr;
    ArraySequence<int> LLarr;

    switch (Type) {
        case 1:
            SortType(reinterpret_cast<ArraySequence<Sequence<int> *> *>(ArrDA));
            break;
        case 2:
            SortType(reinterpret_cast<ArraySequence<Sequence<int> *> *>(ArrLL));
            break;
        default:
            break;
    }
}


template<class T>
static ArraySequence<double> *getSortTime(ArraySequence<int> &arr1) {
    auto time = new ArraySequence<double>();
    Timer sort2;
    int arr[] = {9, 5, 3, 8, 4, 1};
    ArraySequence<int> array(arr, 6);
    ArraySequence<int> ArrTemp(arr1);
    Sequence<T> *res;
    for (int i = 1; i <= 15; i++) {
        switch (i) {
            case 1:
                sort2.Start();
                res = Sorter<T>::sortBubble(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 2:
                sort2.Start();
                res = Sorter<T>::sortCocktail(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 3:
                sort2.Start();
                res = Sorter<T>::sortInsertion(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 4:
                sort2.Start();
                res = Sorter<T>::sortSelection(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 5:
                sort2.Start();
                res = Sorter<T>::sortMerge(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 6:
                sort2.Start();
                res = Sorter<T>::sortQuick(arr1, 0, arr1.GetLength() - 1, cmp<T>);
                time->Append(sort2.Time());
            case 7:
                sort2.Start();
                res = Sorter<T>::sortQuickHoare(arr1, 0, arr1.GetLength() - 1, cmp<T>);
                time->Append(sort2.Time());
            case 8:
                sort2.Start();
                // res=Sorter<T>::sortCounting(arr1, cmp<T>);  //а че не робит то??
                time->Append(sort2.Time());
            case 9:
                sort2.Start();
                res = Sorter<T>::sortShell(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 10:
                sort2.Start();
                res = Sorter<T>::sortShell2(arr1, array, cmp<T>);
                time->Append(sort2.Time());
            case 11:
                sort2.Start();
                res = Sorter<T>::sortSelection(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 12:
                sort2.Start();
                res = Sorter<T>::sortBinaryInsertion(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 13:
                sort2.Start();
                res = Sorter<T>::sortBinaryTree(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 14:
                sort2.Start();
                res = Sorter<T>::sortHeap(arr1, cmp<T>);
                time->Append(sort2.Time());
            case 15:
                sort2.Start();
                res = Sorter<T>::sortBitonic(arr1, cmp<T>);
                time->Append(sort2.Time());

        }
        free(res);
    }
    return time;
}

static void compare() {

    std::string NameSorts[15] = {
            " BubbleSort ",
            " CocktailSort ",
            " InsertionSort ",
            " SelectionSort ",
            " MergeSort ",
            " QuickSort ",
            " QuickHoareSort ",
            " CountingSort ",
            " ShellSort ",
            " Shell2Sort ",
            " SquareSelectionSort ",
            " BinaryInsertionSort ",
            " BinaryTreeSort ",
            " HeapSort ",
            " BitonicSort "};


    std::cout << "Выберите количество элементовот  10 до 1000 \n";
    int length = GetInt(10, 1000);

    cout << "-------------------------------------------------------------------------------- \n";
    ArraySequence<int> arr;


    for (int i = 0; i < length; i++) {
        arr.Append(rand() % 1000000);
    }


    ArraySequence<int> arr1(arr);

    auto time1 = getSortTime<int>(arr);

    for (int i = 0; i < 16; i++) {
        cout.width(25);
        std::cout << NameSorts[i];
        cout << ":" << time1->Get(i) << " ms \n";
    }
}


#endif //SORTS_COMPARE_H
