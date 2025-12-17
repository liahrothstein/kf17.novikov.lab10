#include <stdio.h>
#include <string.h>

#include "../include/io.h" // Подключаем прототипы и data_struct.h

// Функция для печати строки с фиксированным количеством ВИДИМЫХ символов
void print_utf8_fixed(const char* str, int width) {
    int char_count = 0;
    const char* p = str;
    
    // Считаем количество символов (не байт)
    while (*p) {
        if ((*p & 0xc0) != 0x80) char_count++;
        p++;
    }
    
    printf("%s", str);
    // Добиваем пробелами до нужной ширины
    for (int i = 0; i < (width - char_count); i++) {
        printf(" ");
    }
}

// Реализация функций ввода/вывода

// Функция для вывода одной строки таблицы
void printRow(struct Planet p, int id) {
    printf("| %2d | ", id);
    
    // Печатаем название, фиксируя его видимую ширину в 12 символов
    print_utf8_fixed(p.name, 12);
    
    // Остальные колонки содержат только цифры (1 байт = 1 символ), поэтому %15.1f работает корректно
    printf(" | %15.1f | %15.1f | %12.1f |\n", 
           p.distFromEarth, p.distFromSun, p.diameter);
}

// Функция для вывода всех элементов массива на экран
void printPlanets(struct Planet planets[], int count) {
    // Считаем дефисы: 2(ID)+2(пробелы) + 12(имя) + 15(земля) + 15(солнце) + 12(диам) + разделители
    const char* line = "+----+--------------+-----------------+-----------------+--------------+";
    
    printf("\n%s\n", line);
    printf("| ID | Название     | От Земли (Мкм)  | От Солнца (Мкм) |  Диам. (км)  |\n");
    printf("%s\n", line);
    
    for (int i = 0; i < count; ++i) {
        printRow(planets[i], i + 1);
    }
    
    printf("%s\n", line);
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