#include <stdio.h>
#include <string.h>

#include "./include/data_struct.h"

#include "./include/io.h"
#include "./include/processing.h"

int main() {
    struct Planet planets[20]; //Объявление массива структур из 20 элементов
    int currentCount = 0;
    const int MAX_SIZE = 20;

    struct Planet initData[5] = {
        {"Меркурий", 91.7, 57.9, 4879, 0.055, 167.0, 3.7, 1407.6},
        {"Венера", 41.4, 108.2, 12104, 0.815, 464.0, 8.8, 5832.5},
        {"Земля", 0.0, 149.6, 12756, 1.000, 15.0, 9.8, 24.0},
        {"Марс", 78.3, 227.9, 6792, 0.107, -65.0, 3.7, 24.6},
        {"Юпитер", 628.7, 778.6, 142984, 317.8, -110.0, 24.7, 9.9}
    };

    // Копирование инициализированных данных в основной массив
    arrCopy(5, &currentCount, planets, initData);

    printf("Начальное состояние массива:\n");
    printPlanets(planets, currentCount);

    // Ввод с клавиатуры еще 2-х элемента
    printf("\n--- Добавление новых данных ---\n");
    arrPush(2, MAX_SIZE, &currentCount, planets);

    // Вывод всех элементов массива структур на экран
    printf("\nИтоговая таблица данных:\n");
    printPlanets(planets, currentCount);

    // Выполнение обработки (мин/макс)
    findMinMaxDiameter(planets, currentCount);

    return 0;
}