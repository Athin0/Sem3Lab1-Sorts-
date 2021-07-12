#include <iostream>
#include "Sorts.h"
#include "Sorts.cpp"
#include "random"
#include "DynamicArraySequence.h"
#include "LinkedListSequence.h"
using namespace std;

int main() {
    int n=16;
    ArraySequence<int> a;
    for (int i = 0; i < n; i++) {
       a.Append(rand()%100);
    }
    ArraySequence<int> b(a);
    //cout << a<<endl;
    sortBubble(b);
    sortCocktail(a);
    cout<< a;
    for (int i = 0; i < n; i++) {
        if(a[i]!=b[i]) cout<< "блять";
    }
    return 0;
}