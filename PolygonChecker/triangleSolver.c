#include <stdio.h>
#include <stdbool.h>

#include "main.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0 || (!((side1 + side2) > side3) || !((side2 + side3) > side1) || 
		!((side1 + side3) > side2))) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%d", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

void getTriangleAngles(int triangleSides[], float angles[])
{
	// finding the inside angles of the triangle 
	float a = triangleSides[0], b = triangleSides[1], c = triangleSides[2];
	angles[0] = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
	angles[1] = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c));
	angles[2] = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b));
}