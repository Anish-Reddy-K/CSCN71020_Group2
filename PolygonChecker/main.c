#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			float sol[3];
			if (!(strcmp(result, "Not a triangle")))
				break;
			getTriangleAngles(triangleSides, sol);
			for (int i = 0; i < 3; i++) 
				printf("%.0f ", sol[i] * 57.2958f);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			continueProgram = false;
			break;
		}
	}
	return 0;
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

void getTriangleAngles(int triangleSides[], float res[])
{
	// finding the inside angles of the triangle 
	float a = triangleSides[0], b = triangleSides[1], c = triangleSides[2];
	res[0] = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
	res[1] = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c));
	res[2] = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b));
}

