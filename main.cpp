#include <iostream>
#include "vector"
using namespace std;
int main() {
    vector <int> a;
    a = {1,2,3};
    a.push_back(89);
    //cout<< a;
    for(auto i: a)
        cout<<i << endl;
    return 0;
}
