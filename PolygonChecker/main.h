#pragma once
#include <string.h>
#include <math.h>

void printWelcome();
int printShapeMenu();
char* analyzeTriangle(int side1, int side2, int side3);
int* getTriangleSides(int* triangleSides);
void getTriangleAngles(int triangleSides[], float angles[]);