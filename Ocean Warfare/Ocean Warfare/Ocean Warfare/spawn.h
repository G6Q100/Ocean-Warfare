/*  Filename:       spawn.h
	Description:    Solution - MET4335 - spawn object
*/

#include "GL/freeglut.h"
#include <iostream>

void SpawnFigher(GLdouble fighterX, GLdouble fighterY, GLdouble fighterZ, GLint type);

int SpawnFighterPos(int fighterNum, GLdouble valType);

void SpawnBullet(GLdouble bulletX, GLdouble bulletY, GLdouble bulletZ, GLint type);

struct Enemy
{
	GLdouble x, y, z, type;
};
