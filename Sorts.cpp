//
// Created by arina on 08.07.2021.
//

#include "Sorts.h"
#include "DynamicArraySequence.h"
template <class T>
void swap(Sequence<T>& seq, int i1, int i2) {
    T item = seq.Get(i1);
    seq.Set(seq.Get(i2), i1);
    seq.Set(item, i2);
}

template <class T>
void sortBubble(Sequence<T>& vec) {
    for (int i = 0; i < vec.GetLength(); i++)
        for (int j = 0; j < vec.GetLength() - 1; j++) {
            if (vec.Get(j) > vec.Get(j + 1) ){
                swap(vec,j,j+1);
            }
        }
}
template <class T>
void sortInsertion(Sequence<T>& vec){
    for(int i=1;i<vec.GetLength();i++){
        for (int j=i;j>0 && vec.Get(j-1)>vec.Get(j);j--){
            swap(vec,j,j-1);
        }
    }
}

template <class T>
void sortSelection(Sequence<T>& vec){
    for( int i=0;i<vec.GetLength()-1;i++){
        int min_ind= i;
        for (int j=i+1;j<vec.GetLength();j++){
            if (vec[min_ind]>vec.Get(j))
                min_ind= j;
        }
        swap(vec,min_ind,i);
    }
}


template <class T>
void sortMerge0(Sequence<T> *array,int first, int last) {
    if (first<last-1) {
        sortMerge0(array, first, (first + last) / 2);
        sortMerge0(array, (first + last) / 2 , last);
        Merge(array, first, last);
    }
}

template <class T>
void Merge(Sequence<T> *array,int begin, int last){
    ArraySequence<T> *temp_array = new ArraySequence<T>;
    int mid, first,second;
    mid=(begin+last)/2;
    first= begin;
    second=mid;
    for (int i=begin;i<last;i++){
        if(first<mid && (second>=last|| array->Get(first)<array->Get(second))){
            temp_array->Append(array->Get(first));
            first++;
        } else{
            temp_array->Append(array->Get(second));
            second++;
        }
    }
    for (int j=begin; j<last; j++) array->Set(j,temp_array->Get(j-begin));
    delete temp_array;
}


//template < typename T>
//void copy(T*begin, T* end,T* place){
//    for(T* i =begin; i < end;i++){
//        place.add(*i);
//    }
//
//}