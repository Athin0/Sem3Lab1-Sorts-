//
// Created by arina on 08.07.2021.
//

#include "Sorts.h"
#include "DynamicArraySequence.h"

template<class T>
void swap(Sequence<T> &seq, int i1, int i2) {
    T item = seq.Get(i1);
    seq.Set(i1, seq.Get(i2));
    seq.Set(i2, item);
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
void sortBubble(Sequence<T> &vec) {
    for (int i = 0; i < vec.GetLength(); i++)
        for (int j = 0; j < vec.GetLength() - i - 1; j++) {
            if (vec.Get(j) > vec.Get(j + 1)) {
                swap(vec, j, j + 1);
            }
        }
}

//Шейкерная сортировка

template<class T>
void sortCocktail(Sequence<T> &vec) {
    int begin = 0;
    int end = vec.GetLength() - 1;
    for (int i = 0; i < vec.GetLength() / 2; i++) {
        for (int j = begin; j < end; j++) {
            if (vec.Get(j) > vec.Get(j + 1)) {
                swap(vec, j, j + 1);
            }
        }
        for (int j = end; j > begin; j--) {
            if (vec.Get(j - 1) > vec.Get(j)) {
                swap(vec, j, j - 1);
            }
        }
        begin++;
        end--;
    }
}

//Сортировка вставками

template<class T>
void sortInsertion(Sequence<T> &vec) {
    for (int i = 1; i < vec.GetLength(); i++) {
        for (int j = i; j > 0 && vec.Get(j - 1) > vec.Get(j); j--) {
            swap(vec, j, j - 1);
        }
    }
}

//Сортировка Выбором

template<class T>
void sortSelection(Sequence<T> &vec) {
    for (int i = 0; i < vec.GetLength() - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < vec.GetLength(); j++) {
            if (vec[min_ind] > vec.Get(j))
                min_ind = j;
        }
        swap(vec, min_ind, i);
    }
}

//Сортировка слиянием

template<class T>
void sortMerge(Sequence<T> &array, int first, int last) {
    if (first < last - 1) {
        sortMerge(array, first, (first + last) / 2);
        sortMerge(array, (first + last) / 2, last);
        Merge(array, first, last);
    }
}

template<class T>
void Merge(Sequence<T> &array, int begin, int last) {
    ArraySequence<T> temp_array;
    int mid, first, second;
    mid = (begin + last) / 2;
    first = begin;
    second = mid;
    for (int i = begin; i < last; i++) {
        if (first < mid && (second >= last || array.Get(first) < array.Get(second))) {
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
int partition(Sequence<T> &A, int low, int high) {
    int rand = (low + high) / 2;
    T pivot = A[high];    //никакой не рандом!!!!
    int temp = low;
    for (int i = low; i < high; i++) {
        if (A[i] < pivot) {
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
void sortQuick(Sequence<T> &vec, int low, int high) {
    if (high > low) {
        int p = partition(vec, low, high);
        sortQuick(vec, low, p - 1);
        sortQuick(vec, p + 1, high);
    }
}

//Быстрая сортировка по Хаору

template<class T>
int partitionHaore(Sequence<T> &A, int low, int high) {
    T pivot = (A[low] + A[high - 1]) / 2;
    int begin = low;
    int end = high - 1;
    while (true) {
        while (A[begin] < pivot) {
            begin++;
        }
        while (A[end] > pivot) {
            end--;
        }
        if (begin >= end)
            return end;
        swap(A, begin++, end--);
    }
}

template<class T>
void sortQuickHoare(Sequence<T> &vec, int low, int high) {
    if (high > low) {
        int p = partitionHaore(vec, low, high);
        sortQuick(vec, low, p);
        sortQuick(vec, p, high);
    }
}

//Сортирока подсчетом

template<class T>
void sortCounting(Sequence<T> &vec) {
    T size = vec.GetLength();
    if (size <= 1) return;
    ArraySequence<T> temp;
    T max = vec[0];
    T min = vec[0];
    for (int i = 1; i < size; i++) {
        if (max < vec[i]) max = vec[i];
        if (min > vec[i]) min = vec[i];
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
void sortShell(Sequence<T> &vec) {
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
                if (vec[i] > vec[j])
                    swap(vec, i, j);
            }
        }
        n--;
        d = pow(2, n) - 1;
    }
}

//Сортировк Шелла с выбором диапазона (в виде массива значений)
template<class T>
void sortShell2(Sequence<T> &vec, Sequence<T> &d) {
    size_t size = vec.GetLength();
    int n = d.GetLength() - 1;
    while (n >= 0) {
        for (int i = 0; i < size; i++) {
            for (int j = i + d[n]; j < size; j += d[n]) {
                if (vec[i] > vec[j])
                    swap(vec, i, j);
            }
        }
        n--;
    }
}

//Квадратичная сортировка

template<class T>
void sortSquareSelection(Sequence<T> &vec) {
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
            if (vec[j] < vec[min])
                min = j;
        MinInGroups.Append(vec[min]);
        vec[min] = max;
    }
    while (true) {
        min = 0;
        for (int k = 1; k < nGroups; k++)
            if (MinInGroups[k] < MinInGroups[min])
                min = k;
        resultA.Append(MinInGroups[min]);

        if (resultA.GetLength() == size)
            break;

        int i = nGroups * min;
        min = i;
        for (int j = i + 1;
             j < i + nGroups && j < size; j++)  //ищем в группе в которой взяли минимальный элемент новый минимум
            if (vec[j] < vec[min])
                min = j;
        MinInGroups[(i / nGroups)] = vec[min];
        vec[min] = max;
    }

    for (int i = 0; i < size; i++)
        vec[i] = resultA[i];


}


//Сортировка двоичными вставками
template<class T>
void sortBinaryInsertion(Sequence<T> &vec) {
    T temp;
    int left, right, mid;
    for (int i = 1; i < vec.GetLength(); i++) {
        if (vec[i - 1] > vec[i]) {
            temp = vec[i];
            left = 0;
            right = i - 1;
            do {
                mid = (right + left) / 2;
                if (vec[mid] < temp) left = mid + 1;
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
    void add(Node *&root, T value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        if (root->value > value)
            add(root->left, value);
        else
            add(root->right, value);
    }

    void input(Node *&root, Sequence<T> &vec) {
        for (int i = 0; i < vec.GetLength(); i++) {
            add(root, vec[i]);
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
void sortBinaryTree(Sequence<T> &vec) {
    int i = 0;
    Node<T> *root = nullptr;
    root->input(root, vec);
    root->output(root, vec, i);
    root->cleanTree(root);
}

//Пирамидальная сортировка
template<class T>
void Heapify(Sequence<T> &vec, int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int p = 2 * i + 2;
    if (l < n && vec[i] < vec[l]) max = l;
    if (p < n && vec[max] < vec[p]) max = p;
    if (max != i) {
        swap(vec, i, max);
        Heapify(vec, n, max);
    }
}

template<class T>
void BuildMaxHeap(Sequence<T> &vec) {
    int size = vec.GetLength();
    for (int i = size / 2; i >= 0; i--)
        Heapify(vec, size, i);
}

template<class T>
void sortHeap(Sequence<T> &vec) {
    size_t size = vec.GetLength();
    BuildMaxHeap(vec);
    for (int i = size - 1; i > 0; i--) {
        swap(vec, i, 0);
        Heapify(vec, i, 0);
    }
}

template<class T>
void sortBitonic(Sequence<T> &vec) {
    size_t size = vec.GetLength();
    for (int p = 1; p < size; p *= 2)
        for (int k = p; k > 0; k /= 2)
            for (int j = k % p; j + k < size; j += 2*k)
                for (int i = 0; i < size - j - k; i++)
                    if ((j + i) / (2*p) == (j + i + k) / (2*p))
                        if (vec[j + i]> vec[j + i + k])
                            swap(vec,j+i,j+i+k);
}