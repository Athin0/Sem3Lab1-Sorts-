//
// Created by arina on 14.10.2021.
//

#ifndef SORTS_TESTS_H
#define SORTS_TESTS_H

#include "Sorts.h"

//bool (*cmp)(int,int)= Sorter<int>:: cmp;

static void testFunc() {
    ArraySequence<int> Arr;
    int length = 6;
    //rand()%100;

    for (int i = 0; i < length; i++) {
        Arr.Append(rand() % 1000);
    }
    ArraySequence<int> ar(Arr);
    auto pattern = Sorter<int>::sortBubble(ar, cmp);
    int array[] = {9, 5, 3, 8, 4, 1};
    ArraySequence<int> arra(array, 6);

    for (int i = 1; i <= 15; i++) {
        std::cout << i << ": ";
        switch (i) {
            Sequence<int> *result;
            case 1:
                result = Sorter<int>::sortBubble(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 2:
                result = Sorter<int>::sortCocktail(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 3:
                result = Sorter<int>::sortInsertion(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 4:
                result = Sorter<int>::sortSelection(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 5:
                result = Sorter<int>::sortMerge(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 6:
                result = Sorter<int>::sortQuick(Arr, 0, Arr.GetLength(), cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 7:
                result = Sorter<int>::sortQuickHoare(Arr, 0, Arr.GetLength() - 1, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 8:
                result = Sorter<int>::sortCounting(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 9:
                result = Sorter<int>::sortShell(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 10:
                result = Sorter<int>::sortShell2(Arr, arra, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
           //case 11:
           //    result =Sorter<int>::sortSquareSelection(Arr,cmp);
           //    if (*pattern == *result)
           //        std::cout << "Ну оно типо работает!\n";
           //    else
           //        std::cout << "Не работает ...\n";
           //    delete (result);
           //    break;
            case 12:
                result = Sorter<int>::sortBinaryInsertion(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 13:
                result = Sorter<int>::sortHeap(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 14:
                result = Sorter<int>::sortBinaryTree(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
            case 15:
                result = Sorter<int>::sortBitonic(Arr, cmp);
                if (*pattern == *result)
                    std::cout << "Ну оно типо работает!\n";
                else
                    std::cout << "Не работает ...\n";
                delete (result);
                break;
        }

    }


}


#endif //SORTS_TESTS_H
