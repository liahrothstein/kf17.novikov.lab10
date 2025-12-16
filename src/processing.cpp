#include <stdio.h>

#include "../include/processing.h"
#include "../include/io.h" // Нужен, чтобы вызвать printRow из findMinMaxDiameter

// Реализация функций обработки

// Функция поиска мин/макс (по диаметру)
void findMinMaxDiameter(struct Planet planets[], int count) {
    if (count == 0) return;

    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 1; i < count; ++i) {
        if (planets[i].diameter < planets[minIdx].diameter) {
            minIdx = i;
        }
        if (planets[i].diameter > planets[maxIdx].diameter) {
            maxIdx = i;
        }
    }

    printf("\n--- Результаты анализа (по диаметру) ---\n");
    printf("Планета с минимальным диаметром:\n");
    printRow(planets[minIdx], minIdx + 1);
    
    printf("\nПланета с максимальным диаметром:\n");
    printRow(planets[maxIdx], maxIdx + 1);
}