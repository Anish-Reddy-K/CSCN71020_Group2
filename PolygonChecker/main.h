#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <math.h>

void printWelcome();
int printShapeMenu();

// Triangle
char* analyzeTriangle(int, int, int);
int* getTriangleSides(int*);
void getTriangleAngles(int triangleSides[], float angles[]);

// Rectangle
void swapSort(float*, int);
void filter(float*, int, float*);
bool isTriplet(float distinct[]);
float distanceFormula(float, float, float, float);
void rectangleFunction();