//
// Created by arina on 08.07.2021.
//

#include "Sorts.h"
#include "DynamicArraySequence.h"
template <class T>
void swap(Sequence<T>& seq, int i1, int i2) {
    T item = seq.Get(i1);
    seq.Set( i1,seq.Get(i2));
    seq.Set(i2,item);
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
void sortMerge(Sequence<T> &array,int first, int last) {
    if (first<last-1) {
        sortMerge(array, first, (first + last) / 2);
        sortMerge(array, (first + last) / 2 , last);
        Merge(array, first, last);
    }
}

template <class T>
void Merge(Sequence<T> &array,int begin, int last){
    ArraySequence<T> temp_array;
    int mid, first,second;
    mid=(begin+last)/2;
    first= begin;
    second=mid;
    for (int i=begin;i<last;i++){
        if(first<mid && (second>=last|| array.Get(first)<array.Get(second))){
            temp_array.Append(array.Get(first));
            first++;
        } else{
            temp_array.Append(array.Get(second));
            second++;
        }
    }
    for (int j=begin; j<last; j++) array.Set(j,temp_array.Get(j-begin));
}


template <class T>
int partition(Sequence<T>& A, int low,int high){
    int rand=(low+high)/2;
    T pivot = A[high];    //никакой не рандом!!!!
    int temp = low;
    for(int i =low;i<high;i++){
        if (A[i]<pivot){
            swap(A,i,temp);
            temp++;
        }
    }
        swap(A,temp,high);
    /*
    cout<<pivot<<":::: ";
    for(int i =low;i<high;i++){
        cout<<A[i]<<" ";
    }
    cout<<"/ "<<temp<< "\n";
     */
    return temp;

};
template <class T>
void sortQuick(Sequence<T>& vec, int low,int high){
    if(high>low) {
        int p = partition(vec, low, high);
        sortQuick(vec, low, p-1);
        sortQuick(vec, p+1, high);
    }
}