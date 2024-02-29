#include "maths.h"

// max and min
GLdouble Clamp(GLdouble val, GLdouble maxVal, GLdouble minVal) {
	if (val >= maxVal) {
		val = maxVal;
	}
	if (val <= minVal) {
		val = minVal;
	}
	return val;
}

// Random
GLint Random(GLint randomType) {
	// enemy color
	GLint baseVal = 0;
	if (randomType == 1)
		baseVal = int(rand() % 4 + 1);
	// wave pattern
	else if (randomType == 2)
		baseVal = int(rand() % 5 + 1);
	// boss attack pattern
	else if (randomType == 3)
		baseVal = int(rand() % 6 + 1);
	else if (randomType == 4)
		baseVal = int(rand() % 2 + 1);
	// sharking
	else if (randomType == 5)
		baseVal = int(rand() % 20 - 10);
	return baseVal;
}
