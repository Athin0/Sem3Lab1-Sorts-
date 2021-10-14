//
// Created by arina on 02.10.2021.
//

#include "Menu.h"


//1
template<class T>
void readSequence(ArraySequence<ArraySequence<T>*> *arrDA,
                  LinkedListSequence<ArraySequence<T> *> *arrLL) {

    int count = 0;

    std::cout << "Введите длину последовательности или -1 для выхода\n: ";
    do {
        if (count < 0) {
            std::cout << "Последовательности длины не поддерживаются!\n: ";
        }
        count= GetInt();

        if (count == -1)
            return;
    } while (count < 0);

    auto item = GetType();
    if (item == 0) return;

    std::cout << "Сгенерировать вектор автоматически или ввести вручную?:\n"
            "\t0: выход\n"
            "\t1: ввести вектор вручную\n"
            "\t2: сгенерировать вектор\n: ";

    int item2 = GetInt(0, 2);
    if (item2 == 0) return;

    if (item2 == 1) {
        switch (item) {
            case 1:
                readTypeSequence(arrDA, count);
                break;
            case 2:
                readTypeSequence(arrLL, count);
                break;
            default:
                break;
        }
    }
    if (item2 == 2) {
        switch (item) {
            case 1:
                generateRandomSequence(arrDA,count,randomInt);
                break;
            case 2:
                generateRandomSequence(arrLL, count, randomInt);
                //generateRandomSequence(reinterpret_cast<ArraySequence<Sequence<int>*> *>(arrLL), count, randomInt);
                break;
            default:
                break;
        }
    }

    std::cout << "Хотите ввести ещё один вектор?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";

    item = GetInt(0, 1);
    if (item) {
        readSequence(arrDA, arrLL);
    }
}

template<class T>
void readTypeSequence(Sequence<ArraySequence<T>*> *arr, int count) {
    std::cout << "Введите координаты вектора\n:";

    auto vec= (*arr).copy();
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        T item;
        item =GetInt();
        element.Append(item);
    }


    std::cout << "Вы ввели: " << element
         << "\nЗаписать этот вектор? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
    int item;
    item =GetInt();

    switch (item) {
        default:
            break;
        case 0:
            readTypeSequence<T>(arr, count);
            break;
        case 1:
            auto res= element.copy();
            arr->Append(res);
            break;
    }
}

template<class T>
void readTypeSequence(Sequence<LinkedListSequence<T>*> *arr, int count) {
    std::cout << "Введите элементы последовательности\n:";

    auto vec= (*arr).copy();
    LinkedListSequence<T> element;
    for (int i = 0; i < count; i++) {
        T item;
        item =GetInt();
        element.Append(item);
    }


    std::cout << "Вы ввели: " << element
         << "\nЗаписать этe последовательность? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
    int item;
    item=GetInt();

    switch (item) {
        default:
            break;
        case 0:
            readTypeSequence<T>(arr, count);
            break;
        case 1:
            auto res= element.copy();
            arr->Append(res);
            break;
    }
}
/*
template<class T>
void generateRandomSequence(ArraySequence<Sequence<T> *> *arr, int count, T (*func)()) {
    auto element= (*arr).copy();
    for (int i = 0; i < count; i++) {
        element.Append(func());
    }

    LinkedListSequence<T> vec(element);
    std::cout << "Сгенерировано \"" << vec << "\". Записать или сгенерировать новую последовательность?\n"
                                         "\t-1: выход\n"
                                         "\t 0: сгенерировать новую\n"
                                         "\t 1: записать последовательность в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomSequence(arr, count, func);
            break;
        case 1:

            auto *res= (element).copy();
            //auto *res = new Sequence<T>(element);
            arr->Append(res);
            break;
    }
}
*/
template<class T>
void generateRandomSequence(ArraySequence<ArraySequence<T> *> *arr, int count, T (*func)()) {
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        element.Append(func());
    }
    ArraySequence<T> vec(element);
    std::cout << "Сгенерировано \"" << vec << "\". Записать или сгенерировать новую последовательность?\n"
                                        "\t-1: выход\n"
                                        "\t 0: сгенерировать новую\n"
                                        "\t 1: записать последовательность в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomSequence(arr, count, func);
            break;
        case 1:
            auto *res = new ArraySequence<T>(element);
            arr->Append(res);
            break;
    }
}


template<class T>
void generateRandomSequence(ArraySequence<LinkedListSequence<T> *> *arr, int count, T (*func)());

//3
void printSequence(ArraySequence<ArraySequence<int> *> *arrDA,
                   ArraySequence<LinkedListSequence<int> *> *arrLL) {
    int type = GetType();
    switch (type) {
        default:
            break;
        case 1:
            printTypeSequence(reinterpret_cast<ArraySequence<Sequence<int>*>*>(arrDA));//<int>(arrDA);
            break;
        case 2:
            printTypeSequence(reinterpret_cast<ArraySequence<Sequence<int>*>*>(arrLL)); //<int>(arrLL);
            break;
    }
}


template<class T>
void printTypeSequence(ArraySequence<Sequence<T> *> *arr) {
    if (arr->GetLength() == 0) {
        std::cout << "Таких векторов нет!";
        return;
    }
    int item;
    do {
        std::cout << "В памяти находится \"" << arr->GetLength() << "\" векторов этого типа, введите:\n"
                                                               "\t- Индекс элемента для его вывода в консоль\n"
                                                               "\t- Число, больше чем количество векторов для вывода всех векторов "
                                                               "этого типа\n"
                                                               "\t- Число меньше нуля для выхода из функции\n:";
        item = GetInt();

        if (item < 0) break;

        if (item < arr->GetLength()) {
            std::cout << item << ": " << arr->Get(item) << endl;
        }

        if (item >= arr->GetLength())
            std::cout << arr;
        std::cout << endl;
    } while (item >= 0);
}

//4
void deleteSequence(ArraySequence<ArraySequence<int> *> *arrDA,
                    ArraySequence<LinkedListSequence<int> *> *arrLL) {

    auto item = GetType();
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeSequence(reinterpret_cast<ArraySequence<Sequence<int>*>*>(arrDA));//(arrDA);
            break;
        case 2:
            deleteTypeSequence(reinterpret_cast<ArraySequence<Sequence<int>*>*>(arrLL));//(arrLL);
            break;
        default:
            break;
    }
}


template<class T>
void deleteTypeSequence(ArraySequence<Sequence<T> *> *arr) {
    if (arr->GetLength() == 0) {
        std::cout << "Таких векторов нет!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            std::cout << "Больше не осталось векторов этого типа! Автоматический выход из функции\n";
            break;
        }
        std::cout << "В памяти находится \"" << len << "\" векторов, введите:\n"
                                                  "\t- Число меньше нуля для выхода из функции\n"
                                                  "\t- Индекс элемента, для его выбора\n"
                                                  "\t- Число, больше длины массива, для вывода векторов в консоль\n: ";

        item = GetInt();

        if (item < 0) break;

        if (item >= arr->GetLength()) {
            std::cout << arr;;
            continue;
        }

        std::cout << "Выберите операцию:"
                "\t-1: вернуться к выбору индекса\n"
                "\t 0: для удаления элемента\n: ";
        int item2 = GetInt(-1, 0);

        if (item2 == -1) continue;

        if (item2 == 0) {
            std::cout << "Вы действительно хотите удалить \"" << arr->Get(item) << "\" ?\n"
                                                                               "\t0 - нет\n"
                                                                               "\t1 - да\n: ";
            item2 = GetInt(0, 1);
            if (item2 == 1) {
                arr->Pop(item);
            }
            continue;
        }
    }
}

template<class T>
void generateRandomSequence(ArraySequence<LinkedListSequence<T> *> *arr, int count, T (*func)()) {
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        element.Append(func());
    }
    LinkedListSequence<T> vec(element);
    std::cout << "Сгенерировано \"" << vec << "\". Записать или сгенерировать новую последовательность?\n"
                                              "\t-1: выход\n"
                                              "\t 0: сгенерировать новую\n"
                                              "\t 1: записать последовательность в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomSequence(arr, count, func);
            break;
        case 1:
            auto *res = new LinkedListSequence<T>(element);
            arr->Append(res);
            break;
    }
}

void mainMenuSequence() {
    ArraySequence<ArraySequence<int> *> arrDA;
    ArraySequence<LinkedListSequence<int> *> arrLL;
    int item;
    while (true) {
        std::cout << "Программа имеет следующие возможности: \n"
                  << "\t1: Ввести и запомнить последовательность\n"
                  << "\t2: Вывести последовательность в консоль\n"
                  << "\t3: Сортировка последовательности\n"
                  << "\t4: Удалить последовательность в памяти\n"
                  << "\t5: Запустить функцию тестирования последовательность\n"
                  << "\t6: Сравнить тайминги\n"
                  << "\t7: Закончить выполнение программы\n"
                  << "Введите число: ";
        item= GetInt();
        if (item < 1 || item > 7) {
            std::cout << "Ошибка! Нет такого пункта! Повторите попытку\n";
            continue;
        }

        if (item == 7)
            break;

        switch (item) {
            case 1:
                readSequence(&arrDA, &arrLL);
                break;
            case 2:
                printSequence(&arrDA, &arrLL);
                break;
            case 3:
                SortSequence(&arrDA, &arrLL);
                break;
            case 4:
                deleteSequence(&arrDA, &arrLL);
                break;
            case 5:
                testFunc();
                break;
            case 6:
                compare();
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < arrDA.GetLength(); i++) {
        delete arrDA.Get(i);
    }

    for (int i = 0; i < arrLL.GetLength(); i++) {
        delete arrLL.Get(i);
    }

}


/**/