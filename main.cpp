#include <iostream>
#include "Sorts.h"
#include "Sorts.cpp"
#include "random"
#include "DynamicArraySequence.h"
#include "LinkedListSequence.h"
using namespace std;

int main() {
    int n=10;
    ArraySequence<int> a;
    for (int i = 0; i < n; i++) {
       a.Append(rand()%100);
    }
    cout << a<<endl;
    sortMerge(&a,n);
    cout<< a;

    return 0;
}