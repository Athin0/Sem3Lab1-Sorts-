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
void sortMerge(Sequence<T> *array,int size, int begin){
    ArraySequence<T> *temp_array = new ArraySequence<T>;
    if (size>1){
        int left_size = size/2;
        int right_size = size- left_size;
        sortMerge(array,left_size);
        sortMerge(array,right_size,begin+left_size);
        int left_ind =0, right_ind = left_size, ind =0;
        while(ind<right_size || right_ind< size){
            if (array->Get(left_ind)<array->Get(right_ind)){
                temp_array->Append(array->Get(left_ind));
                ind++;
                left_ind++;
            }
            else {
                temp_array->Append(array->Get(right_ind));
                ind++;
                right_ind++;
            }
            if (left_ind==left_size){
                while (ind !=size){
                    temp_array->Append( array->Get(right_ind));
                    ind++;
                    right_ind++;
                }
            }
            if (right_ind==size){
                while (ind !=size){
                    temp_array->Append( array->Get(left_ind));
                    ind++;
                    left_ind++;
                }
            }
        }
    }
    else {
        int ind = 0;
        while (ind != size) {
            temp_array->Append(array->Get(ind+begin));
            ind++;
        }
    }
    int ind = 0;
    while (ind != size) {
        array->Set(ind+begin,temp_array->Get(ind));
        ind++;
    }

    cout<< *temp_array <<"temp_arr \n" ;
delete temp_array;
}

template <class T>
void sortMerge0(Sequence<T> *array,int first, int last) {
    if (first<last) {
        sortMerge0(array, first, (first + last) / 2);
        sortMerge0(array, (first + last) / 2 + 1, last);
        Merge(array, first, last);
    }
}

template <class T>
void Merge(Sequence<T> *array,int begin, int last){
    ArraySequence<T> *temp_array = new ArraySequence<T>;
    int mid, first,second;
    mid=(begin+last)/2;
    first= begin;
    second=mid+1;
    for (int i=begin;i<=last;i++){
        if(first<=mid && (second>last|| array->Get(first)<array->Get(second))){
            temp_array->Append(array->Get(first));
            first++;
        } else{
            temp_array->Append(array->Get(second));
            second++;
        }
    }
    for (int j=begin; j<=last; j++) array->Set(j,temp_array->Get(j-begin));
    delete temp_array;
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
        Sequence <T[]> tmp_array(new T[size]);

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

//template < typename T>
//void copy(T*begin, T* end,T* place){
//    for(T* i =begin; i < end;i++){
//        place.add(*i);
//    }
//
//}