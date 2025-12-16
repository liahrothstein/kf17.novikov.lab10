#include <stdio.h>
#include <string.h>

#include "../include/io.h" // Подключаем прототипы и data_struct.h

// Реализация функций ввода/вывода

// Функция для вывода одной строки таблицы
void printRow(struct Planet p, int id) {
    // Используем форматирование ширины поля
    // %-12s - строка выравнивается по левому краю, ширина 12
    // %15.1f - дробное число, ширина 15, 1 знак после запятой
    printf("| %2d | %-12s | %15.1f | %15.1f | %12.1f |\n", 
           id, p.name, p.distFromEarth, p.distFromSun, p.diameter);
}

// Функция для вывода всех элементов массива на экран
void printPlanets(struct Planet planets[], int count) {
    printf("\n----------------------------------------------------------------------\n");
    printf("| ID | Название     | От Земли (Мкм)  | От Солнца (Мкм) | Диам. (км)   |\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printRow(planets[i], i + 1);
    }
    printf("----------------------------------------------------------------------\n");
}

// Функция для ввода новой структуры с клавиатуры
struct Planet inputPlanet() {
    struct Planet p;
    
    printf("Введите название планеты: ");
    scanf("%s", p.name); // Читаем строку (до первого пробела)
    
    printf("Введите расстояние от Земли (млн км): ");
    scanf("%lf", &p.distFromEarth); // Для double используем %lf
    
    printf("Введите расстояние от Солнца (млн км): ");
    scanf("%lf", &p.distFromSun);
    
    printf("Введите диаметр экватора (км): ");
    scanf("%lf", &p.diameter);
    
    return p;
}

// Функция для заполнения структурами массива
void arrPush(int amountElem, const int MAX_SIZE, int currentCount, struct Planet planets[]) {
    for (int i = 0; i < amountElem; ++i) {
        if (currentCount < MAX_SIZE) {
            printf("Элемент %d из %d:\n", i + 1, amountElem);
            planets[currentCount] = inputPlanet();
            currentCount++;
        } else {
            printf("Массив переполнен!\n");
        }
    }
}

// Функция для копирования элементов массива
void arrCopy(int amountElem, int currentCount, struct Planet planets[], struct Planet initData[]) {
    for(int i = 0; i < amountElem; i++) {
        planets[currentCount] = initData[i];
        currentCount++;
    }
}