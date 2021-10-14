#include "iostream"
#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H
template<class T>
class Sequence {
public:
    class IndexOutOfRange{
    public:
        int length;
        int index;
        IndexOutOfRange(int length, int index): length(length), index(index) {};
        IndexOutOfRange(): length(-1), index(-1) {};
    };

    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) const = 0;
    virtual void Set(int index,T item) = 0;
    virtual T &operator [] (int index) = 0;
    virtual Sequence<T>* GetSubSequence( int startIndex, int endIndex) = 0;
    virtual int GetLength() const = 0;

    //friend std::ostream &operator << (std::ostream &out, Sequence<T>& arr);

    //friend bool operator==(Sequence<T>* arraySequence, Sequence<T>* arraySequence1);

    virtual void Append (T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void Insert(T item, int index) = 0;
    virtual Sequence<T>* copy() = 0;
    virtual Sequence<T>* empty() = 0;
    virtual Sequence<T>* Concat (Sequence<T> *sequence) = 0;
};


template <class T>
static std::ostream& operator << (std::ostream& cout, Sequence<T>* array){
    std:: cout << '{';
    for (int i = 0; i < array->GetLength(); i++) {
        std::cout << (*array)[i];
        if (i < array->GetLength() - 1) {
            std::cout << ", ";
        }
    }
    return std::cout << '}';
}


template <class T>
//static std::ostream& operator << (std::ostream& cout, const mySequence<T>& sequence) {
std::ostream &operator <<(std::ostream &cout,Sequence<T>& array){
    std::cout << '{';
    for (int i = 0; i < array.GetLength(); i++) {
        std::cout << array[i];
        if (i < array.GetLength() - 1) {
            std::cout << ", ";
        }
    }
    return std::cout << '}';
} ;

template<class T>
bool operator==(Sequence<T>& arraySequence, Sequence<T>& arraySequence1) {
    if (arraySequence1.GetLength() != arraySequence.GetLength())
        return false;
    for (int i = 0; i < arraySequence.GetLength(); i++) {
        if(arraySequence1.Get(i) != arraySequence.Get(i))
            return false;
    }
    return true;
}


//template<class T>
//Sequence<T>:: bool operator==(Sequence<T>* arraySequence, Sequence<T>* arraySequence1) {
//    if (arraySequence1->GetLength() != arraySequence->GetLength())
//        return false;
//    for (int i = 0; i < arraySequence->GetLength(); i++) {
//        if(arraySequence1->Get(i) != arraySequence->Get(i))
//            return 0;
//    }
//    return 1;
//}

#endif //LAB2_SEQUENCE_H
