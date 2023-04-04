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
		case 2:
			printf_s("Rectangle selected.\n");
			int rectangleSides[4] = { 0, 0, 0, 0 };
			//rectangle
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
