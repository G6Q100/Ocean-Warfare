/*  Filename:       draw.h
	Description:    Solution - MET4335 - draw object
*/

#include "GL/freeglut.h"
#include <iostream>

using namespace std;

class Vertex;

void drawRectangle(Vertex v1, Vertex v2, Vertex v3, Vertex v4);

void drawFighter(GLdouble length, GLdouble width, GLdouble height,
	GLdouble red, GLdouble green, GLdouble blue,
	GLdouble x, GLdouble y, GLdouble z);

void drawPlayerFighter(GLdouble length, GLdouble width, GLdouble height,
	GLdouble red, GLdouble green, GLdouble blue,
	GLdouble x, GLdouble y, GLdouble z);

void drawBoss(GLdouble length, GLdouble width, GLdouble height,
	GLdouble red, GLdouble green, GLdouble blue,
	GLdouble x, GLdouble y, GLdouble z);

void textDisplay(GLint posx, GLint posy, char scorevar);

void textDisplay(GLint posx, GLint posy, GLint scorevar);

class planet;

