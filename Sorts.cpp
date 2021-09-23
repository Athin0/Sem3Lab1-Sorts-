//
// Created by arina on 08.07.2021.
//

#include "Sorts.h"
#include "DynamicArraySequence.h"
#include "Sequence.h"


template<class T>
class Sorter
{
public:
void Qsort(Sequence<T> &a){
    for (int i = 0; i < a.GetLength(); i++)
        for (int j = 0; j < a.GetLength() - i - 1; j++) {
            if (a.Get(j) > a.Get(j+1)) {
                swap(a, j, j + 1);
            }
        }
};
};

template<class T>
bool sr(T a, T b){
    return a>b;
}

template<class T>
void swap(Sequence<T> &seq, int i1, int i2) {
    T item = seq.Get(i1);
    seq.Set(i1, seq.Get(i2));
    seq.Set(i2, item);
}
template<class T>
void swap(Sequence<T> *seq, int i1, int i2) {
    T item = seq->Get(i1);
    seq->Set(i1, seq->Get(i2));
    seq->Set(i2, item);
}

template<class T>
T FindMaxMin(Sequence<T> &vec, bool tupe = 0) {
    T max = vec[0];
    T min = vec[0];
    for (int i = 1; i < vec.GetLength(); i++) {
        if (max < vec[i]) max = vec[i];
        if (min > vec[i]) min = vec[i];
    }
    if (!tupe)
        return max;
    else return min;
}

//Сортировка пузырьком

template<class T>
Sequence<T>* sortBubble(Sequence<T>* vec1,bool  (*func)(T,T)) {
    auto vec= vec1->copy();
    for (int i = 0; i < vec->GetLength(); i++)
        for (int j = 0; j < vec->GetLength() - i - 1; j++) {
            if (func(vec->Get(j), vec->Get(j + 1))) {
                swap(vec, j, j + 1);
            }
        }
    return vec;
}

//Шейкерная сортировка

template<class T>
void sortCocktail(Sequence<T> &vec,bool  (*func)(T,T)) {
    int begin = 0;
    int end = vec.GetLength() - 1;
    for (int i = 0; i < vec.GetLength() / 2; i++) {
        for (int j = begin; j < end; j++) {
            if (vec.Get(j) > vec.Get(j + 1)) {
                swap(vec, j, j + 1);
            }
        }
        for (int j = end; j > begin; j--) {
            if (func(vec.Get(j - 1), vec.Get(j))) {
                swap(vec, j, j - 1);
            }
        }
        begin++;
        end--;
    }
}

//Сортировка вставками

template<class T>
void sortInsertion(Sequence<T> &vec,bool  (*func)(T,T)) {
    for (int i = 1; i < vec.GetLength(); i++) {
        for (int j = i; j > 0 && func(vec.Get(j - 1), vec.Get(j)); j--) {
            swap(vec, j, j - 1);
        }
    }
}

//Сортировка Выбором

template<class T>
void sortSelection(Sequence<T> &vec, bool  (*func)(T,T)) {
    for (int i = 0; i < vec.GetLength() - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < vec.GetLength(); j++) {
            if (func(vec[min_ind] , vec.Get(j)))
                min_ind = j;
        }
        swap(vec, min_ind, i);
    }
}

//Сортировка слиянием

template<class T>
void sortMerge(Sequence<T> &array, int first, int last,bool  (*func)(T,T)) {
    if (first < last - 1) {
        sortMerge(array, first, (first + last) / 2);
        sortMerge(array, (first + last) / 2, last);
        Merge(array, first, last,func);
    }
}

template<class T>
void Merge(Sequence<T> &array, int begin, int last,bool  (*func)(T,T)) {
    ArraySequence<T> temp_array;
    int mid, first, second;
    mid = (begin + last) / 2;
    first = begin;
    second = mid;
    for (int i = begin; i < last; i++) {
        if (first < mid && (second >= last || func(array.Get(second),array.Get(first)))) {
            temp_array.Append(array.Get(first));
            first++;
        } else {
            temp_array.Append(array.Get(second));
            second++;
        }
    }
    for (int j = begin; j < last; j++) array.Set(j, temp_array.Get(j - begin));
}


//Быстрая сортирока (просто)

template<class T>
int partition(Sequence<T> &A, int low, int high,bool  (*func)(T,T)) {
    int rand = (low + high) / 2;
    T pivot = A[high];    //никакой не рандом!!!!
    int temp = low;
    for (int i = low; i < high; i++) {
        if (func( pivot,A[i])) {
            swap(A, i, temp);
            temp++;
        }
    }
    swap(A, temp, high);
    /*
    cout<<pivot<<":::: ";
    for(int i =low;i<high;i++){
        cout<<A[i]<<" ";
    }
    cout<<"/ "<<temp<< "\n";
     */
    return temp;

}

template<class T>
void sortQuick(Sequence<T> &vec, int low, int high,bool  (*func)(T,T)) {
    if (high > low) {
        int p = partition(vec, low, high,func);
        sortQuick(vec, low, p - 1,func);
        sortQuick(vec, p + 1, high,func);
    }
}

//Быстрая сортировка по Хаору

template<class T>
int partitionHaore(Sequence<T> &A, int low, int high,bool  (*func)(T,T)) {
    T pivot = (A[low] + A[high - 1]) / 2;
    int begin = low;
    int end = high - 1;
    while (true) {
        while (func(pivot,A[begin])) {
            begin++;
        }
        while (func(A[end] , pivot)) {
            end--;
        }
        if (begin >= end)
            return end;
        swap(A, begin++, end--);
    }
}

template<class T>
void sortQuickHoare(Sequence<T> &vec, int low, int high,bool  (*func)(T,T)) {
    if (high > low) {
        int p = partitionHaore(vec, low, high,func);
        sortQuick(vec, low, p,func);
        sortQuick(vec, p, high,func);
    }
}

//Сортирока подсчетом

template<class T>
void sortCounting(Sequence<T> &vec,bool  (*func)(T,T)) {
    T size = vec.GetLength();
    if (size <= 1) return;
    ArraySequence<T> temp;
    T max = vec[0];
    T min = vec[0];
    for (int i = 1; i < size; i++) {
        if (func(vec[i], max  )) max = vec[i];
        if (func(min , vec[i])) min = vec[i];
    }
    for (int i = min; i <= max; i++) {
        temp.Append(0);
    }
    for (int i = 0; i < size; i++) {
        temp[vec[i]]++;
    }
    int m = 0;
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < temp[i]; j++) {
            vec[m] = i;
            m++;
        }
    }
}

//Сортировка Шелла(простая)

template<class T>
void sortShell(Sequence<T> &vec,bool  (*func)(T,T)) {
    size_t size = vec.GetLength();
    //ArraySequence<T> d;
    int d = 1;
    int n = 0;
    while (d < size) {
        n++;
        d = pow(2, n) - 1;
    }
    while (d > 0) {
        for (int i = 0; i < size; i++) {
            for (int j = i + d; j < size; j += d) {
                if (func(vec[i] , vec[j]))
                    swap(vec, i, j);
            }
        }
        n--;
        d = pow(2, n) - 1;
    }
}

//Сортировк Шелла с выбором диапазона (в виде массива значений)
template<class T>
void sortShell2(Sequence<T> &vec, Sequence<T> &d,bool  (*func)(T,T)) {
    size_t size = vec.GetLength();
    int n = d.GetLength() - 1;
    while (n >= 0) {
        for (int i = 0; i < size; i++) {
            for (int j = i + d[n]; j < size; j += d[n]) {
                if (func(vec[i] , vec[j]))
                    swap(vec, i, j);
            }
        }
        n--;
    }
}

//Квадратичная сортировка

template<class T>
void sortSquareSelection(Sequence<T> &vec,bool  (*func)(T,T)) {
    T max = FindMaxMin(vec);
    int min = 0;
    size_t size = vec.GetLength();
    ArraySequence<T> resultA;
    int nGroups = (int) sqrt((double) size);
    if (pow((double) nGroups, 2) < size)
        nGroups++;

    ArraySequence<T> MinInGroups;

    for (int i = nGroups * min; i < size; i += nGroups) {   //создали массив с минимальными элментами из каждой группы
        min = i;
        for (int j = i + 1; j < i + nGroups && j < size; j++)
            if (func(vec[min],vec[j] ))
                min = j;
        MinInGroups.Append(vec[min]);
        vec[min] = max;
    }
    while (true) {
        min = 0;
        for (int k = 1; k < nGroups; k++)
            if (func(MinInGroups[min], MinInGroups[k] ))
                min = k;
        resultA.Append(MinInGroups[min]);

        if (resultA.GetLength() == size)
            break;

        int i = nGroups * min;
        min = i;
        for (int j = i + 1;
             j < i + nGroups && j < size; j++)  //ищем в группе в которой взяли минимальный элемент новый минимум
            if (func(vec[min],vec[j] ))
                min = j;
        MinInGroups[(i / nGroups)] = vec[min];
        vec[min] = max;
    }

    for (int i = 0; i < size; i++)
        vec[i] = resultA[i];

}


//Сортировка двоичными вставками
template<class T>
void sortBinaryInsertion(Sequence<T> &vec,bool  (*func)(T,T)) {
    T temp;
    int left, right, mid;
    for (int i = 1; i < vec.GetLength(); i++) {
        if (func(vec[i - 1] , vec[i])) {
            temp = vec[i];
            left = 0;
            right = i - 1;
            do {
                mid = (right + left) / 2;
                if (func( temp,vec[mid])) left = mid + 1;
                else right = mid;
            } while (left < right);
            for (int j = i - 1; j >= left; j--) {
                vec[j + 1] = vec[j];
            }
            vec[left] = temp;
        }

    }
}

//Сортировка бинарным деревом
template<typename T>
class Node {
    Node *left = nullptr;
    Node *right = nullptr;
    T value;

    explicit Node(T val) : value(val) {};

public:
    void add(Node *&root, T value,bool  (*func)(T,T)) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        if (func(root->value , value))
            add(root->left, value,func);
        else
            add(root->right, value,func);
    }

    void input(Node *&root, Sequence<T> &vec,bool  (*func)(T,T)) {
        for (int i = 0; i < vec.GetLength(); i++) {
            add(root, vec[i],func);
        }
    }

    void output(Node *&root, Sequence<T> &vec, int &i) {
        if (root == nullptr) {
            return;
        }
        output(root->left, vec, i);
        vec[i] = root->value;
        i++;
        output(root->right, vec, i);
    }

    void cleanTree(Node *&root) {
        if (root == nullptr)
            return;
        cleanTree(root->left);
        cleanTree(root->right);
        delete root;
    }
};

template<class T>
void sortBinaryTree(Sequence<T> &vec,bool  (*func)(T,T)) {
    int i = 0;
    Node<T> *root = nullptr;
    root->input(root, vec,func);
    root->output(root, vec, i);
    root->cleanTree(root);
}

//Пирамидальная сортировка
template<class T>
void Heapify(Sequence<T> &vec, int n, int i,bool  (*func)(T,T)) {
    int max = i;
    int l = 2 * i + 1;
    int p = 2 * i + 2;
    if (l < n && func(vec[l], vec[i] )) max = l;
    if (p < n && func(vec[p],vec[max])) max = p;
    if (max != i) {
        swap(vec, i, max);
        Heapify(vec, n, max);
    }
}

template<class T>
void BuildMaxHeap(Sequence<T> &vec,bool  (*func)(T,T)) {
    int size = vec.GetLength();
    for (int i = size / 2; i >= 0; i--)
        Heapify(vec, size, i,func);
}

template<class T>
void sortHeap(Sequence<T> &vec,bool  (*func)(T,T)) {
    size_t size = vec.GetLength();
    BuildMaxHeap(vec,func);
    for (int i = size - 1; i > 0; i--) {
        swap(vec, i, 0);
        Heapify(vec, i, 0,func);
    }
}

template<class T>
void sortBitonic(Sequence<T> &vec,bool  (*func)(T,T)) {
    size_t size = vec.GetLength();
    for (int p = 1; p < size; p *= 2)   //почти номер этапа (максимальная длина компаратора)
        for (int k = p; k > 0; k /= 2)    //длина мгновенного компаратора (на каком расстоянии сравниваемые элементы)
            for (int j = k % p; j + k < size; j += 2*k)  //начальный элемент сравнения и отступ
                for (int i = 0; i < size - j - k; i++)     //проход по всем элмеентам
                    if ((j + i) / (2*p) == (j + i + k) / (2*p))
                        if (func(vec[j + i], vec[j + i + k]))
                            swap(vec,j+i,j+i+k);
}