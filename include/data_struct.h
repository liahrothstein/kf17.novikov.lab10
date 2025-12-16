#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

// Описание структуры
struct Planet {
    char name[50];          // Название
    double distFromEarth;   // Расстояние от Земли (млн км)
    double distFromSun;     // Расстояние от Солнца (млн км)
    double diameter;        // Диаметр экватора (км)
};

#endif