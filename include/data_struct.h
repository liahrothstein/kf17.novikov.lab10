#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

// Описание структуры
struct Planet {
    char name[50];          // Название
    double distFromEarth;   // Расстояние от Земли (млн км)
    double distFromSun;     // Расстояние от Солнца (млн км)
    double diameter;        // Диаметр экватора (км)
    double mass;            // в массах Земли (или 10^24 кг)
    double temperature;     // средняя температура в °C
    double gravity;         // ускорение своб. падения м/с²
    double dayLength;       // продолжительность суток в часах
};

#endif