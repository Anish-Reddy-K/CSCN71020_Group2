#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#include "main.h"

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1: // Triangle
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			float angles[3];

			if (strcmp(result, "Not a triangle") == 0)  
				break;

			getTriangleAngles(triangleSides, angles); // Angles fucntion

			for (int i = 0; i < 3; i++) // Printing angles
				printf("%.0f ", angles[i] * 57.2958f);  // Converting radians to degrees

			break;

		case 2: // Rectangle
			printf_s("Rectangle selected.\n");
			rectangleFunction();
			break;

		case 0: // Quit
			continueProgram = false;
			break;

		default:
			printf_s("Invalid value entered.\n");
			printf_s("Please enter again.\n");
			continueProgram = false;
			break;
		}
	}
	return 0;
}
