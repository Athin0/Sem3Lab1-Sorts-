#include <iostream>
#include "Sorts.h"
#include "Sorts.cpp"
#include "random"
#include "DynamicArraySequence.h"
#include "LinkedListSequence.h"
#include "Menu.cpp"

using namespace std;

template<typename T>
void Correct(Sequence<T> *a);

int main() {
    mainMenuSequence();
    return 0;
}
//
//    int n = 10;
//    ArraySequence<int> a;
//    for (int i = 0; i < n; i++) {
//        a.Append(rand() % 100);
//    }
//    cout << a << endl;
//    //Sequence<int> *k;
//    auto k = Sorter<int>::sortSquareSelection(a, cmp);
//
//    cout << k << endl;
//    cout << a;
//    Correct(k);
//    return 0;
//}
//
//
// template< typename T>
// void Correct( Sequence<T>* a){
//     auto b= Sorter<int>::sortCocktail(*a,cmp);
//     cout<< "\nПравильность:";
//     int wrong=0;
//     int n= a->GetLength();
//     for (int i = 0; i < n; i++) {
//         if(a->Get(i)!=b->Get(i)){
//             cout<< "ой ";
//             wrong++;
//         }
//     }
//     if (!wrong) cout<< "Норм!";
// }