#pragma once
#include <string.h>
#include <math.h>

void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
void getTriangleAngles(int triangleSides[], float res[]);
char* analyzeTriangle(int side1, int side2, int side3);