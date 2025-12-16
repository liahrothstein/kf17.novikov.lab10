#ifndef PROCESSING_H
#define PROCESSING_H

#include "data_struct.h" // Нужно знать, что такое struct Planet
#include "../src/processing.cpp"

// Прототипы функций обработки данных

void findMinMaxDiameter(struct Planet planets[], int count);

#endif