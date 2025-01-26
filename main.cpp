/**
 * @file main.cpp
 * @brief Главный файл программы для работы с данными о солдатах.
 *
 * Этот файл содержит основную функцию программы, которая управляет 
 * взаимодействием с пользователем и выполняет операции над данными о солдатах.
 *
 * Основные функции:
 * - main: Точка входа в программу. 
 *   - Инициализирует необходимые переменные и структуры данных.
 *   - Предоставляет пользователю меню для выбора различных операций:
 *     1. Чтение данных о солдатах из файла.
 *     2. Запись данных о солдатах в файл.
 *     3. Сортировка данных о солдатах различными методами (сортировка выбором, вставками, пирамидальная сортировка).
 *     4. Вывод данных о солдатах на экран.
 *   - Обрабатывает ввод пользователя и выполняет соответствующие функции.
 *
 * Примечания:
 * - Программа ожидает, что файл с данными о солдатах будет находиться в определенном формате.
 * - Пользовательский ввод проверяется на корректность, чтобы избежать ошибок во время выполнения.
 * - После завершения операций программа завершает свою работу, освобождая все ресурсы.
 */

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>

#include "lab1.h"

int main()  {
    std::ofstream outFile("sorting_times.csv");
    outFile << "Size,SelectionSort,InsertionSort,HeapSort,StdSort\n";
    std::string filename;
    for (int i=0; i<10; i++)  {
        // std::cout << "Введите имя файла: ";
        // std::cin >> filename;

        filename = "data" + std::to_string(i+1) + ".txt";

        std::vector<Soldier> soldiers = readSoldiersFromFile(filename);
        size_t size = soldiers.size();

        std::vector<Soldier> soldiersCopy = soldiers;
        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(soldiersCopy);
        auto end = std::chrono::high_resolution_clock::now();
        auto selectionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        writeSoldiersToFile("selection"+filename, soldiersCopy);

        soldiersCopy = soldiers;
        start = std::chrono::high_resolution_clock::now();
        insertionSort(soldiersCopy);
        end = std::chrono::high_resolution_clock::now();
        auto insertionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        writeSoldiersToFile("insertion"+filename, soldiersCopy);

        soldiersCopy = soldiers;
        start = std::chrono::high_resolution_clock::now();
        heapSort(soldiersCopy);
        end = std::chrono::high_resolution_clock::now();
        auto heapTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        writeSoldiersToFile("heap"+filename, soldiersCopy);

        soldiersCopy = soldiers;
        start = std::chrono::high_resolution_clock::now();
        std::sort(soldiersCopy.begin(), soldiersCopy.end());
        end = std::chrono::high_resolution_clock::now();
        auto stdSortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        writeSoldiersToFile("stdSort"+filename, soldiersCopy);

        outFile << size << "," 
            << selectionTime << "," 
            << insertionTime << "," 
            << heapTime << "," 
            << stdSortTime << std::endl;
    }
    outFile.close();
    return 0;
}