#include <stdio.h>
#include <string.h>

#include "../include/io.h" // Подключаем прототипы и data_struct.h

// Функция для печати строки с фиксированным количеством ВИДИМЫХ символов
void print_utf8_fixed(const char* str, int width) {
    int char_count = 0;
    const char* p = str;
    while (*p) {
        if ((*p & 0xc0) != 0x80) char_count++;
        p++;
    }
    printf("%s", str);
    for (int i = 0; i < (width - char_count); i++) printf(" ");
}

// Реализация функций ввода/вывода

// Функция для вывода одной строки таблицы
void printRow(struct Planet p, int id) {
    printf("| %2d | ", id);
    print_utf8_fixed(p.name, 10);
    
    // Вывод данных с учетом единиц измерения из шапки
    printf(" | %7.1f | %7.1f | %8.0f | %8.2f | %7.2f | %6.1f | %7.1f |\n", 
           p.distFromEarth, 
           p.distFromSun, 
           p.diameter, 
           p.mass, 
           p.temperature + 273.15, 
           p.gravity, 
           p.dayLength);
}

// Функция для вывода всех элементов массива на экран
void printPlanets(struct Planet planets[], int count) {
    const char* line = "+----+------------+---------+---------+----------+----------+---------+--------+---------+";
    printf("\n%s\n", line);
    printf("| ID | Название   | L_З(Мкм)| L_С(Мкм)| d (км)   | Масса(З) | T (K)   | g(м/с²)| Сутки(ч)|\n");
    printf("%s\n", line);
    for (int i = 0; i < count; i++) {
        printRow(planets[i], i + 1);
    }
    printf("%s\n", line);
}

// Функция для ввода новой структуры с клавиатуры
struct Planet inputPlanet() {
    struct Planet p;

    printf("Название: "); scanf("%s", p.name);
    printf("Раст. от Земли: "); scanf("%lf", &p.distFromEarth);
    printf("Раст. от Солнца: "); scanf("%lf", &p.distFromSun);
    printf("Диаметр: "); scanf("%lf", &p.diameter);
    printf("Масса (отн. Земли): "); scanf("%lf", &p.mass);
    printf("Температура (°C): "); scanf("%lf", &p.temperature);
    printf("Ускорение g: "); scanf("%lf", &p.gravity);
    printf("Длительность суток (ч): "); scanf("%lf", &p.dayLength);

    return p;
}

// Функция для заполнения структурами массива
void arrPush(int amountElem, const int MAX_SIZE, int *currentCount, struct Planet planets[]) {
    for (int i = 0; i < amountElem; ++i) {
        if (*currentCount < MAX_SIZE) {
            printf("Элемент %d из %d:\n", i + 1, amountElem);
            planets[*currentCount] = inputPlanet();
            (*currentCount)++;
        } else {
            printf("Массив переполнен!\n");
        }
    }
}

// Функция для копирования элементов массива
void arrCopy(int amountElem, int *currentCount, struct Planet planets[], struct Planet initData[]) {
    for(int i = 0; i < amountElem; i++) {
        planets[*currentCount] = initData[i];
        (*currentCount)++;
    }
}