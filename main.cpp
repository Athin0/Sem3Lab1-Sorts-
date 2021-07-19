#include <iostream>
#include "Sorts.h"
#include "Sorts.cpp"
#include "random"
#include "DynamicArraySequence.h"
#include "LinkedListSequence.h"
using namespace std;

template< typename T>
void Correct( ArraySequence<T> &a);

int main() {
    int n=15;
    ArraySequence<int> a;
    for (int i = 0; i < n; i++) {
       a.Append(rand()%100);
    }
    cout << a <<endl;
    ArraySequence<int> k;
    k.Append(1);
    sortBinaryTree(a);

    cout<< a;
    Correct(a);
    return 0;
}



template< typename T>
void Correct( ArraySequence<T> &a){
    ArraySequence<T> b(a);
    sortCocktail(b);
    cout<< "\nПравильность:";
    int wrong=0;
    int n= a.GetLength();
    for (int i = 0; i < n; i++) {
        if(a[i]!=b[i]){
            cout<< "блять ";
            wrong++;
        }
    }
    if (!wrong) cout<< "Норм!";
}