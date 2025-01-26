/**
 * @file lab1.h
 * @brief Заголовочный файл для работы с данными о солдатах.
 *
 * Этот файл содержит определения структур для хранения данных о солдатах, 
 * а также функции для сортировки и работы с этими данными.
 *
 * Структуры:
 * - FIO: хранит фамилию, имя и отчество солдата.
 * - Soldier: хранит данные о солдате, включая его звание, ФИО, номер взвода и возраст.
 *
 * Операторы сравнения для структур:
 * - Операторы сравнения (==, !=, <, >, <=, >=) реализованы для структур FIO и Soldier,
 *   что позволяет удобно сравнивать объекты этих структур.
 *
 * Функции:
 * - selectionSort: сортирует вектор солдат с использованием алгоритма сортировки выбором.
 * - insertionSort: сортирует вектор солдат с использованием алгоритма сортировки вставками.
 * - heapify: вспомогательная функция для пирамидальной сортировки.
 * - heapSort: сортирует вектор солдат с использованием алгоритма пирамидальной сортировки.
 * - readSoldiersFromFile: читает данные о солдатах из указанного файла и возвращает вектор объектов Soldier.
 * - writeSoldiersToFile: записывает данные о солдатах в указанный файл.
 */

#include <string>
#include <vector>

struct FIO  {
    std::string surname;
    std::string name;
    std::string patronymic;

    FIO(const std::string &s, const std::string &n, const std::string &p);

    bool operator==(const FIO &other) const;
    bool operator!=(const FIO &other) const;
    bool operator>(const FIO &other) const;
    bool operator<(const FIO &other) const;
    bool operator>=(const FIO &other) const;
    bool operator<=(const FIO &other) const;
};

struct Soldier  {
    std::string rank;
    FIO fio;
    int platoonNumber;
    int age;

    Soldier(const std::string &r, const FIO &f, int pNum, int a);

    bool operator==(const Soldier &other) const;
    bool operator!=(const Soldier &other) const;
    bool operator>(const Soldier &other) const;
    bool operator<(const Soldier &other) const;
    bool operator>=(const Soldier &other) const;
    bool operator<=(const Soldier &other) const;
};

// а) Сортировка выбором
void selectionSort(std::vector<Soldier> &soldiers);
// в) Сортировка простыми вставками
void insertionSort(std::vector<Soldier> &soldiers);
// д) Пирамидальная сортировка
void heapify(std::vector<Soldier> &soldiers, int n, int i);
void heapSort(std::vector<Soldier> &soldiers);

std::vector<Soldier> readSoldiersFromFile(const std::string &filename);
void writeSoldiersToFile(const std::string &filename, const std::vector<Soldier> &soldiers);
