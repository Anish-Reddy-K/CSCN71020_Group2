#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#include "main.h"

void swapSort(float* lengths, int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (lengths[i] < lengths[j])
			{
				float temp = lengths[i];
				lengths[i] = lengths[j];
				lengths[j] = temp;
			}
}

void filter(float* lengths, int len, float* distinct)
{
	int point = 0;
	for (int i = 0; i < len; i++)
		if (lengths[i] != lengths[i + 1])
			distinct[point++] = lengths[i];
}

bool isTriplet(float distinct[])
{
	if (round(pow(distinct[0], 2) + pow(distinct[1], 2)) == round(pow(distinct[2], 2)) || distinct[2] == 0)
		return true;
	return false;
}


float distanceFormula(float a, float b, float x, float y)
{
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

void rectangleFunction()
{
	printf("Please enter all the points of the rectangle: ");
	float x = 0;
	float points[8] = { 0 };
	for (int i = 0; i < 8; i++)
		x = scanf("%f", &points[i]);
	float a = points[0], b = points[1], c = points[2], d = points[3], e = points[4], f = points[5], g = points[6], h = points[7];

	float pointLengths[12] = { 0 };

	int p = 0;
	for (int i = 0; i < 8; i += 2)
	{
		for (int j = 0; j < 8; j += 2)
			if (distanceFormula(points[i], points[i + 1], points[j], points[j + 1]) != 0)
				pointLengths[p++] = distanceFormula(points[i], points[i + 1], points[j], points[j + 1]);
	}

	int counter = 0;

	swapSort(&pointLengths, 12);
	float distinct[12] = { 0 };
	filter(&pointLengths, 12, &distinct);
	for (int i = 0; i < 12; i++) if (distinct[i] != 0) counter++;
	if (counter == 3 && isTriplet(distinct))
	{
		printf("It is a rectangle\n");
		printf("The perimeter of this rectangle is: %.2f\n", (distinct[0] * 2) + (distinct[1] * 2));
		printf("The area of this rectangle is: %.2f\n", distinct[0] * distinct[1]);
	}
	else if (counter == 2 && isTriplet(distinct))
	{
		printf("It is a rectangle\n");
		printf("The perimeter of this rectangle is: %.2f\n", (distinct[0] * 2) + (distinct[0] * 2));
		printf("The area of this rectangle is: %.2f\n", distinct[0] * distinct[0]);
	}
	else
		printf("It is not a rectangle");
}