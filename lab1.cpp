/**
 * @file lab1.cpp
 * @brief Реализация функций для работы с данными о солдатах.
 *
 * Этот файл содержит реализацию методов для структур FIO и Soldier, 
 * а также функций для сортировки и работы с данными солдат.
 *
 * Реализация методов:
 * - FIO::FIO: Конструктор для инициализации объекта FIO с заданными фамилией, именем и отчеством.
 * - Операторы сравнения для FIO: реализованы операторы ==, !=, <, >, <=, >= для сравнения объектов FIO.
 *
 * - Soldier::Soldier: Конструктор для инициализации объекта Soldier с заданным званием, ФИО, номером взвода и возрастом.
 * - Операторы сравнения для Soldier: реализованы операторы ==, !=, <, >, <=, >= для сравнения объектов Soldier.
 *
 * Функции сортировки:
 * - selectionSort: Реализует алгоритм сортировки выбором для сортировки вектора солдат.
 * - insertionSort: Реализует алгоритм сортировки вставками для сортировки вектора солдат.
 * - heapify: Вспомогательная функция для поддержания свойств кучи в пирамидальной сортировке.
 * - heapSort: Реализует алгоритм пирамидальной сортировки для сортировки вектора солдат.
 *
 * Функции для работы с файлами:
 * - readSoldiersFromFile: Читает данные о солдатах из указанного файла и возвращает вектор объектов Soldier.
 *   Ожидает, что каждая строка файла содержит информацию о солдате в определенном формате.
 * - writeSoldiersToFile: Записывает данные о солдатах в указанный файл в текстовом формате.
 *
 * Примечание:
 * Все функции обработки и сортировки работают с вектором объектов Soldier, 
 * который содержит информацию о солдатах и их характеристиках.
 */

#include "lab1.h"

#include <fstream>
#include <iostream>
#include <sstream>

FIO::FIO(const std::string &s, const std::string &n, const std::string &p)
        : surname(s), name(n), patronymic(p)  {}

bool FIO::operator==(const FIO &other) const {
    return surname == other.surname && name == other.name && patronymic == other.patronymic;
}

bool FIO::operator!=(const FIO &other) const {
    return !(*this == other);
}

bool FIO::operator<(const FIO &other) const {
    if (surname != other.surname)  {
        return surname < other.surname;
    }
    if (name != other.name)  {
        return name < other.name;
    }
    return patronymic < other.patronymic;
}

bool FIO::operator>(const FIO &other) const {
    return other < *this;
}

bool FIO::operator<=(const FIO &other) const {
    return !(*this > other);
}

bool FIO::operator>=(const FIO &other) const {
    return !(*this < other);
}

Soldier::Soldier(const std::string &r, const FIO &f, int pNum, int a)
        : fio(f), rank(r), platoonNumber(pNum), age(a)  {}

bool Soldier::operator==(const Soldier &other) const {
    return rank == other.rank && fio == other.fio && platoonNumber == other.platoonNumber;
}

bool Soldier::operator!=(const Soldier &other) const {
    return !(*this == other);
}

bool Soldier::operator<(const Soldier &other) const {
    if (rank != other.rank)  {
        return rank < other.rank;
    }
    if (fio != other.fio)  {
        return fio < other.fio;
    }
    return platoonNumber < other.platoonNumber;
}

bool Soldier::operator>(const Soldier &other) const {
    return other < *this;
}

bool Soldier::operator<=(const Soldier &other) const {
    return !(*this > other);
}

bool Soldier::operator>=(const Soldier &other) const {
    return !(*this < other);
}

void selectionSort(std::vector<Soldier> &soldiers)  {
    int n = soldiers.size();
    for (int i = 0; i < n; i++)  {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)  {
            if (soldiers[j] < soldiers[minIndex])  {
                minIndex = j;
            }
        }
        if (i != minIndex)  {
            Soldier buf = soldiers[i];
            soldiers[i] = soldiers[minIndex];
            soldiers[minIndex] = buf;
        }
    }
}

void insertionSort(std::vector<Soldier> &soldiers)  {
    int n = soldiers.size();
    for (int i = 1; i < n; i++)  {
        Soldier key = soldiers[i];
        int j = i - 1;
        while (j >= 0 && soldiers[j] > key)  {
            soldiers[j + 1] = soldiers[j];
            j--;
        }
        soldiers[j + 1] = key;
    }
}

void heapify(std::vector<Soldier> &soldiers, int n, int i)  {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && soldiers[left] > soldiers[largest])  {
        largest = left;
    }

    if (right < n && soldiers[right] > soldiers[largest])  {
        largest = right;
    }

    if (largest != i)  {
        Soldier buf = soldiers[i];
        soldiers[i] = soldiers[largest];
        soldiers[largest] = buf;
        heapify(soldiers, n, largest);
    }
}

void heapSort(std::vector<Soldier> &soldiers)  {
    int n = soldiers.size();

    for (int i = n / 2 - 1; i >= 0; i--)  {
        heapify(soldiers, n, i);
    }

    for (int i = n - 1; i > 0; i--)  {
        Soldier buf = soldiers[0];
        soldiers[0] = soldiers[i];
        soldiers[i] = buf;
        heapify(soldiers, i, 0); 
    }
}

std::vector<Soldier> readSoldiersFromFile(const std::string &filename)  {
    std::ifstream file(filename);
    std::vector<Soldier> soldiers;
    if (!file.is_open())  {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return soldiers;
    }

    std::string line;
    while (std::getline(file, line))  {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss, token, ','))  {
            tokens.push_back(token);
        }
        if (tokens.size() == 6)  {
            soldiers.push_back(Soldier(tokens[3], FIO(tokens[0], tokens[1], tokens[2]), std::stoi(tokens[4]), std::stoi(tokens[5])));
        }
        else if (tokens.size() == 7)  {
            soldiers.push_back(Soldier(tokens[3] + " " + tokens[4], FIO(tokens[0], tokens[1], tokens[2]), std::stoi(tokens[5]), std::stoi(tokens[6])));
        }
        else {
            std::cerr << "Ошибка: неверный формат строки: " << line << std::endl;
        }
    }
    file.close();
    return soldiers;
}


void writeSoldiersToFile(const std::string &filename, const std::vector<Soldier> &soldiers)  {
    std::ofstream file(filename);
    if (!file.is_open())  {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return;
    }

    for (const auto &soldier : soldiers)  {
        file << soldier.fio.surname << " "
             << soldier.fio.name << " "
             << soldier.fio.patronymic << " "
             << soldier.rank << " "
             << soldier.platoonNumber << " "
             << soldier.age << std::endl;
    }

    file.close();
}