//
// Created by arina on 08.07.2021.
//

#include "Sorts.h"

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
void sortMerge(T array,int size){
    if (size>1){
        int left_size = size/2;
        int right_size = size- left_size;
        sortMerge(array,left_size);
        sortMerge(array+left_size,right_size);
        int left_ind =0, right_ind = left_size, ind =0;
        T temp_array(new T[size]);
        while(ind<right_size || right_ind< size){
            if (array[left_ind]<array[right_ind]){
                temp_array[ind++] = array[left_ind];
                left_ind++;
            }
            else {
                temp_array[ind++] = array[right_ind];
                right_ind++;
            }
            if (left_ind=left_size){
                while (ind !=size){
                    temp_array[ind++] = array[right_ind];
                    right_ind++;
                }
                break;
            }
            if (right_ind=size){
                while (ind !=size){
                    temp_array[ind++] = array[left_ind];
                    left_ind++;
                }
                break;
            }
        }
    }
  // while (ind !=size){
  //     temp_array[ind++] = array[left_ind];
  //     left_ind++;
  // }

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

template < typename T>
void copy(T*begin, T* end,T* place){
    for(T* i =begin; i < end;i++){
        place.add(*i);
    }

}