#ifndef IO_H
#define IO_H

#include "data_struct.h" // Нужно знать, что такое struct Planet
#include "../src/io.cpp"

// Прототипы функций ввода/вывода

void printRow(struct Planet p, int id);
void printPlanets(struct Planet planets[], int count);
struct Planet inputPlanet();
void arrPush(int amountElem, const int MAX_SIZE, int currentCount, struct Planet planets[]);
void arrCopy(int amountElem, int currentCount, struct Planet planets[], struct Planet initData[]);

#endif