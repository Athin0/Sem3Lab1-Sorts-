#include <iostream>
#include "vector"
#include "random"
using namespace std;


template <class T>
ostream& operator<< (ostream &cout, const vector<T> &a){
    cout<< "{";
    for (auto i: a){
        cout<<i ;
    if ( i != a.back())
        cout<< ", ";
    }
    cout<< "}";
}

int main() {
    vector <int> a;
    a = {1,2,3};
    a.push_back(89);
    cout<< a;
    return 0;
}