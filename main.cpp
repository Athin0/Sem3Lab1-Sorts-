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
/*
template<class T>
vector<T> * CreatVectorRand(int size){
    vector<T>a= new vector<T>;
    for (int i =0; i<size;i++)
        a->push_back(rand()%100);
    cout<< *a;
}
 */
template <class T>
void sortBubble(vector<T>& vec);

template <class T>
void sortInsertion(vector<T>& vec);

template <class T>
void sortSelection(vector<T>& vec);

template <class T>
void sortMerge(vector<T>& vec);

template <class T>
void swap(T &a1,T &a2) {
    T temp = a1;
    a1 =a2;
    a2 = temp;
}

int main() {
    int n =10;
    cout<< "Введите размер массива:";
    //cin >> n;
    vector <int> a;
    for (int i =0; i<n;i++)
        a.push_back(rand()%100);
    cout<< a<< endl;
    sortSelection(a);
    cout<< a<< endl;
    return 0;
}
template <class T>
void sortBubble(vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                T temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
}
template <class T>
void sortInsertion(vector<T>& vec){
    for(int i=1;i<vec.size();i++){
        for (int j=i;j>0 && vec[j-1]>vec[j];j--){
            T temp = vec[j];
            vec[j] = vec[j-1];
            vec[j-1] = temp;
        }
    }
}


template <class T>
void sortSelection(vector<T>& vec){
    for( int i=0;i<vec.size()-1;i++){
        int min_ind= i;
        for (int j=i+1;j<vec.size();j++){
            if (vec[min_ind]>vec[j])
                min_ind= j;
        }
        T temp = vec[min_ind];
        vec[min_ind] = vec[i];
        vec[i] = temp;
        //swap(vec[min_ind],vec[i]);
    }
}

template <class T>
void sortMerge(vector<T>& vec,int size){
    sortMerge(vec);

}

template<typename T>
void merge_sort(T array[], size_t size) noexcept
{
    if (size > 1)
    {
        size_t const left_size = size / 2;
        size_t const right_size = size - left_size;

        merge_sort(&array[0], left_size);
        merge_sort(&array[left_size], right_size);

        size_t lidx = 0, ridx = left_size, idx = 0;
        vector <T[]> tmp_array(new T[size]);

        while (lidx < left_size || ridx < size)
        {
            if (array[lidx] < array[ridx])
            {
                tmp_array[idx++] = move(array[lidx]);
                lidx++;
            }
            else
            {
                tmp_array[idx++] = move(array[ridx]);
                ridx++;
            }

            if (lidx == left_size)
            {
                copy(make_move_iterator(&array[ridx]),
                          make_move_iterator(&array[size]),
                          &tmp_array[idx]);
                break;
            }
            if (ridx == size)
            {
                copy(make_move_iterator(&array[lidx]),
                          make_move_iterator(&array[left_size]),
                          &tmp_array[idx]);
                break;
            }
        }

        copy(make_move_iterator(tmp_array),
                  make_move_iterator(&tmp_array[size]),
                  array);
    }
}