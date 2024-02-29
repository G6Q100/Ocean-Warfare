/*  Filename:       spawn.cpp
	Description:    Solution - MET4335 - spawn oject
*/

#include "spawn.h"
#include "draw.h"

void SpawnFigher(GLdouble fighterX, GLdouble fighterY, GLdouble fighterZ, GLint type) {
	//enem
	switch (type) {
	case 0:
		drawPlayerFighter(5.0, 25.0, 5.0, 0.3, 0.3, 1.0, fighterX, fighterY, fighterZ);	// player
		break;
	case 1:
		drawFighter(5.0, 25.0, 5.0, 1.0, 0.3, 0.3, fighterX, fighterY, fighterZ);		// red
		break;
	case 2:
		drawFighter(5.0, 25.0, 5.0, 0.3, 0.6, 0.3, fighterX, fighterY, fighterZ);		// green
		break;
	case 3:
		drawFighter(5.0, 25.0, 5.0, 0.8, 0.8, 0.3, fighterX, fighterY, fighterZ);		// yellow
		break;
	case 4:
		drawFighter(5.0, 25.0, 5.0, 1.0, 1.0, 1.0, fighterX, fighterY, fighterZ);		// white
		break;
	case 6:
		drawBoss(50, 250.0, 60.0, 0.5, 0.3, 0.36, fighterX, fighterY, fighterZ);		// miniboss
		break;
	case 7:
		drawPlayerFighter(1.0, 5.0, 1.0, 0.3, 0.3, 1.0, fighterX, fighterY, fighterZ);	// hp
		break;
	case 8:
		drawBoss(50, 250.0, 60.0, 1, 1, 1, fighterX, fighterY, fighterZ);				// Boss + Boss got hit color
		break;


		break;
	}
}

//spawn fighter position
int SpawnFighterPos(int fighterNum, GLdouble waveType) {
	int val = 1000;
	if (waveType == 1) {										// X position
		if (fighterNum <= 3)
			val = -20 + 30 * (fighterNum - 1);
		else if (fighterNum <= 6)
			val = 20 - 30 * (fighterNum - 4);
		else if (fighterNum <= 12)
			val = -100 + 40 * (fighterNum - 7);
		else if (fighterNum <= 18)
			val = 100 - 40 * (fighterNum - 13);
		else if (fighterNum <= 21)
			val = -90 + 30 * (fighterNum - 19);
		else if (fighterNum <= 24)
			val = -30 - 30 * (fighterNum - 22);
		else if (fighterNum <= 28)
			val = 90 - 30 * (fighterNum - 25);
		else if (fighterNum <= 31)
			val = 30 + 30 * (fighterNum - 29);

		return val;
	}
	else if (waveType == 2) {											// Z position
		// right 3 red, left 3 red
		if (fighterNum <= 3)
			val = -250 - 50 * fighterNum;
		else if (fighterNum <= 6)
			val = -300 - 50 * fighterNum;
		// 2 rows of red
		else if (fighterNum <= 12)
			val = -700 - 30 * (fighterNum - 7);
		else if (fighterNum <= 18)
			val = -920 - 30 * (fighterNum - 13);
		// cross row of red
		else if (fighterNum <= 21)
			val = -1210 - 30 * (fighterNum - 19);
		else if (fighterNum <= 24)
			val = -1330 - 30 * (fighterNum - 22);
		else if (fighterNum <= 31)
			val = -1210 - 30 * (fighterNum - 25);
		return val;
	}
	else if (waveType == 3) {								// X position
		// rom1
		if (fighterNum <= 3)
			val = -30 + 40 * (fighterNum - 1);
		else if (fighterNum <= 6)
			val = 30 - 40 * (fighterNum - 4);
		// 2 rows of red
		else if (fighterNum <= 12)
			val = -90 + 30 * (fighterNum - 7);
		else if (fighterNum <= 18)
			val = -40 + 25 * (fighterNum - 13);
		else if (fighterNum <= 21)
			val = 85 - 25 * (fighterNum - 19);
		else if (fighterNum <= 24)
			val = -65 + 30 * (fighterNum - 22);
		// cross row of red
		else if (fighterNum <= 28)
			val = -80 + 35 * (fighterNum - 25);
		else if (fighterNum <= 31)
			val = 95 - 35 * (fighterNum - 29);                
		return val;
	}
	else if (waveType == 4) {											// Z position
		// right 3 red, left 3 red
		if (fighterNum <= 3)
			val = -250 - 50 * fighterNum;
		else if (fighterNum <= 6)
			val = -300 - 50 * fighterNum;
		// 2 rows of red
		else if (fighterNum <= 12)
			val = -700 - 30 * (fighterNum - 7);
		else if (fighterNum <= 18)
			val = -920 - 30 * (fighterNum - 13);
		else if (fighterNum <= 24)
			val = -1210 - 25 * (fighterNum - 19);
		else if (fighterNum <= 31)
			val = -1210 - 30 * (fighterNum - 25);
		return val;
	}
	else if (waveType == 5) {                                // X position
	// rom1
		if (fighterNum <= 4)
			val = -30 - 20 * (fighterNum - 1);
		else if (fighterNum <= 8)
			val = -10 + 20 * (fighterNum - 4);

		else if (fighterNum <= 12)
			val = 50 - 30 * (fighterNum - 9);
		else if (fighterNum <= 15)
			val = -60 + 30 * (fighterNum - 13);
		else if (fighterNum <= 19)
			val = 90 - 30 * (fighterNum - 16);
		else if (fighterNum <= 26)
			val = -10 + 20 * (fighterNum - 23);
		else if (fighterNum <= 31)
			val = 40 - 20 * (fighterNum - 29);
		return val;
	}
	else if (waveType == 6) {                                            // Z position
		// right 3 red, left 3 red
		if (fighterNum <= 4)
			val = -250 - 30 * (fighterNum - 1);
		else if (fighterNum <= 8)
			val = -250 - 30 * (fighterNum - 5);
		else if (fighterNum <= 12)
			val = -400;
		else if (fighterNum <= 15)
			val = -600 - 40 * (fighterNum - 13);
		else if (fighterNum <= 31)
			val = -850 - 45 * (fighterNum - 20);
		return val;
	}
	else if (waveType == 7) {                                // X position
		if (fighterNum <= 4)
			val = -20 + 30 * (fighterNum - 1);
		else if (fighterNum <= 8)
			val = 20 - 30 * (fighterNum - 4);
		else if (fighterNum <= 12)
			val = 90 - 50 * (fighterNum - 9);
		else if (fighterNum <= 15)
			val = -90 + 40 * (fighterNum - 13);
		else if (fighterNum <= 19)
			val = 85 - 35 * (fighterNum - 16);
		else if (fighterNum <= 26)
			val = -70 + 45 * (fighterNum - 23);
		else if (fighterNum <= 31)
			val = 40 - 30 * (fighterNum - 29);
		return val;
	}
	else if (waveType == 8) {                                            // Z position
		if (fighterNum <= 4)
			val = -250 - 20 * (fighterNum - 1);
		else if (fighterNum <= 8)
			val = -350 - 20 * (fighterNum - 5);
		else if (fighterNum <= 12)
			val = -600;
		else if (fighterNum <= 16)
			val = -700 - 35 * (fighterNum - 13);
		else if (fighterNum <= 31)
			val = -850 - 45 * (fighterNum - 20);
		return val;
	}
	else if (waveType == 9) {								// X position
		if (fighterNum <= 2)
			val = -40 + 80 * (fighterNum - 1);
		else if (fighterNum <= 5)
			val = -80 + 80 * (fighterNum - 3);
		else if (fighterNum <= 7)
			val = -90 + 180 * (fighterNum - 6);
		else if (fighterNum == 8)
			val = 0;
		else if (fighterNum <= 10)
			val = -60 + 120 * (fighterNum - 9);
		else if (fighterNum <= 15)
			val = -90 + 35 * (fighterNum - 11);
		else if (fighterNum <= 19)
			val = +85 - 35 * (fighterNum - 16);
		else if (fighterNum <= 22)
			val = 0 - 30 * (fighterNum - 20);
		else if (fighterNum <= 28)
			val = -90 + 30 * (fighterNum - 23);
		else if (fighterNum <= 31)
			val = 90 - 30 * (fighterNum - 29);
		return val;
	}
	else if (waveType == 10) {											// Z position
		// right 3 red, left 3 red
		if (fighterNum <= 2)
			val = -250;
		else if (fighterNum <= 5)
			val = -350;
		else if (fighterNum <= 7)
			val = -500;
		else if (fighterNum == 8)
			val = -550;
		else if (fighterNum <= 10)
			val = -600;
		else if (fighterNum <= 19)
			val = -700 - 40 * (fighterNum - 11);
		else if (fighterNum <= 31)
			val = -850 - 45 * (fighterNum - 20);
		return val;
	}
	return val;
}

// spawn bullet
void SpawnBullet(GLdouble bulletX, GLdouble bulletY, GLdouble bulletZ, GLint type) {	
	glTranslated(bulletX, bulletY, -bulletZ);
	if (type == 1) {
		glColor3d(1, 1, 1);
		glutSolidSphere(2, 10, 10);
	}
	else if(type == 2) {
		glColor3d(1, 0.1, 0.1);
		glutSolidSphere(10, 10, 10);
	}
	else if (type == 3) {
		glColor3d(0.7, 0.7, 0.1);
		glutSolidSphere(10, 10, 10);
	}
	else if (type == 4) {
		glColor3d(0.2, 0.7, 0.2);
		glutSolidSphere(10, 10, 10);
	}
	else if (type == 5) {
		glColor3d(0.6, 0.1, 0.6);
		glutSolidSphere(10, 10, 10);
	}
	glTranslated(-bulletX, -bulletY, bulletZ);
}