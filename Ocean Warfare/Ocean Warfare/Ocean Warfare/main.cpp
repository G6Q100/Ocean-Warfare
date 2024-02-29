/*  Filename:       main.cpp
	Description:    Ocean Warfare
*/
#include "draw.h"
#include "spawn.h"
#include "maths.h"
#include "image.h"

#include <mmsystem.h>


void initRendering() {
	glEnable(GL_DEPTH_TEST);				// makes 3D drawing work
}

void cameraSetup(int w, int h) {
	glViewport(0, 0, 900, 700);				// set the viewport
	glMatrixMode(GL_PROJECTION);			// select projection matrix
	glLoadIdentity();						// reset projection matrix
	gluPerspective(90.0, 1, 1.0, 30000.0);	// set up a perspective projection matrix
}

void initialize() {
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0);                                         // specify the clear value for the depth buffer
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // specify implementation-specific hints

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

// draw plant
class planet {
public:
	GLuint textureID;
	GLdouble selfRadius, orbitRadius;
	GLdouble rotateAngle, orbitAngle;
	GLdouble rotateSpeed, orbitSpeed;
	GLdouble scaleRatio;
	planet() {
		textureID = 0;
		selfRadius = 1.0;
		orbitRadius = 0.0;
		rotateAngle = 0.0;
		orbitAngle = 0.0;
		rotateSpeed = 0.0;
		orbitSpeed = 0.0;
		scaleRatio = 1.0;
	}
	planet(GLdouble r, GLdouble Or, GLdouble ra, GLdouble aa, GLdouble rs, GLdouble os, GLdouble sr) {
		textureID = 0;
		selfRadius = r;
		orbitRadius = Or;
		rotateAngle = ra;
		orbitAngle = aa;
		rotateSpeed = rs;
		orbitSpeed = os;
		scaleRatio = sr;
	}
	void draw() {
		glBindTexture(GL_TEXTURE_2D, this->textureID);
		GLUquadric* sphere = gluNewQuadric();
		gluQuadricNormals(sphere, GL_SMOOTH);
		gluQuadricTexture(sphere, GL_TRUE);
		gluSphere(sphere, selfRadius, 20, 200);
	}
};

GLdouble angle_around = 70;

bool topView = true, hitEnemy = false, enemyGetHited[39], alive = true, bossActive = false;

bool xPos = true, yPos = true, win = false;

GLdouble enemyZspeed = 0, enemyBaseY = 0, speed = 0.1,					// speed and enemyY
ViewNum = 0, camX = 0, maxCamRange = 26,								// cam 
playerX = 0, playerY = 0, playerZ = 20,									// player position							
tmepPlayerZ = 0, tmepPlayerY = 0,										// temp player position
bulletX = 0, bulletY = 0, bulletZ = 0,									// bullet position
enemyBulletX = 1000, enemyBulletY = 1000, enemyBulletZ = 1000,			// enemy bullet position1
enemyBulletX2 = 1000, enemyBulletY2 = 1000, enemyBulletZ2 = 1000,		// enemy bullet position2
enemyBulletColor = 0, 													// enemy bullet color
bossMovement = 0, currentBossY = 0;										// temp boss position

GLint eventTime = 0, eventNum = 0,										// wave event
attackCountDown = 0, attack = 0,										// attack count down
enemyBulletCD = 0,														// enemy attack count down
rowNum = 0, columnNum = 0, arrowAttackNum = 0, waveNum = 0,					// random number
bossHP = 200, playerHP = 5, enemyHP[39], 								// HP
playerhpY = 0, playerhpX = 0, playerMaxHP = playerHP,					// player
playerHitCD = 0,														// invincibility time
scene = 0,																// scene
addscore[5];															//score

GLuint bgTextureID = 0, bgTexture2ID = 0, bgTexture3ID = 0;				// texture

// Enemy position array
Enemy enemy[39];														// enemy val

planet BG(20000, 45.0, 45.0, 3.0, 10.0, 0.0, 10.0);						// the earth	

void display() {
	glClearColor(0.6, 0.6, 1, 1.0);										// Background Color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);					// Clear Screen and Depth Buffer

	// change score text color
	if (win == true)
		glColor3d(0, 0, 1);
	else if (playerHP <= 0)
		glColor3d(1, 0, 0);
	else if (hitEnemy == true)
		glColor3d(0, 1, 0);
	else
		glColor3d(0.8, 0.9, 0.9);

	// show score text
	if (scene == 1) {
		textDisplay(-camX - 52 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), 'S');
		textDisplay(-camX - 50 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), 'c');
		textDisplay(-camX - 48 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), 'o');
		textDisplay(-camX - 46 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), 'r');
		textDisplay(-camX - 44 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), 'e');
		textDisplay(-camX - 42 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), ':');
		if (addscore[4] > 0) {
			textDisplay(-camX - 40 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[4]);
			textDisplay(-camX - 38 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[3]);
			textDisplay(-camX - 36 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[2]);
			textDisplay(-camX - 34 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[1]);
		}
		else if (addscore[3] > 0) {
			textDisplay(-camX - 40 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[3]);
			textDisplay(-camX - 38 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[2]);
			textDisplay(-camX - 36 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[1]);
		}
		else if (addscore[2] > 0) {
			textDisplay(-camX - 40 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[2]);
			textDisplay(-camX - 38 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[1]);
		}
		else
			textDisplay(-camX - 40 + (3 * ViewNum / 69), 28 - (60 * ViewNum / 69), addscore[1]);
	}
	else if (scene != 0) {
		textDisplay(-5, -4, 'S');
		textDisplay(-4, -4, 'c');
		textDisplay(-3, -4, 'o');
		textDisplay(-2, -4, 'r');
		textDisplay(-1, -4, 'e');
		textDisplay(0, -4, ':');
		if (addscore[4] > 0) {
			textDisplay(1, -4, addscore[4]);
			textDisplay(2, -4, addscore[3]);
			textDisplay(3, -4, addscore[2]);
			textDisplay(4, -4, addscore[1]);
		}
		else if (addscore[3] > 0) {
			textDisplay(1, -4, addscore[3]);
			textDisplay(2, -4, addscore[2]);
			textDisplay(3, -4, addscore[1]);
		}
		else if (addscore[2] > 0) {
			textDisplay(1, -4, addscore[2]);
			textDisplay(2, -4, addscore[1]);
		}
		else
		{
			textDisplay(-1, -4, addscore[1]);
		}
	}
	// add score
	for (int i = 2; i <= 4; i++) {
		if (addscore[i - 1] > 9) {
			addscore[i] += 1;
			addscore[i - 1] -= 10;
		}
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// check pause
	if (scene == 1) {	// gameplay scene
		// enemy speed
		enemyZspeed += speed;														// enemy movement	

		// camera movement
		camX = Clamp(playerX, maxCamRange + (30 * ViewNum / 69),
			-maxCamRange - (30 * ViewNum / 69));

		// show HP
		for (int i = 1; i <= playerMaxHP; i++)
			if (playerHP >= i)
				SpawnFigher(-29 + (4 * i), 25, -30, 7);


		// set camera position
		glTranslated(camX, -60 + (45 * ViewNum / 69), -80 + (30 * ViewNum / 69));
		glRotated(180, 0.0, 180, 0.0);											// rotaste
		glRotated(angle_around - ViewNum, -angle_around, 0.0, 0.0);				// rotate


		// change view point
		if (topView == true) {
			// View change transition
			if (ViewNum > 0) {
				ViewNum -= 0.05;
				playerZ = tmepPlayerZ * ViewNum / 69;
				playerY = tmepPlayerY * ViewNum / 69;
			}
			else {
				ViewNum = 0;
			}
		}
		else {
			// View change transition
			if (ViewNum < 69) {
				ViewNum += 0.05;
				playerZ = tmepPlayerZ - tmepPlayerZ * ViewNum / 69;
				playerY = tmepPlayerY * ViewNum / 69;
			}
			else {
				ViewNum = 69;
			}
		}
		if (win == false) {
			// player move area
			playerX = Clamp(playerX, 90, -90);
			playerY = Clamp(playerY, 50, -25);
			playerZ = Clamp(playerZ, 80, -5);
		}
		else // change to win scene after win animation
			if (playerZ > 250)
				scene = 3;



		// player movement
		if (alive == true)
			if (win == false)
				SpawnFigher(playerX, playerY, playerZ, 0);
			else {											// win animation
				playerZ += 0.1;
				playerY += 0.01;
				SpawnFigher(playerX, playerY, playerZ, 0);
			}

		// rotated to enemy view
		glRotated(180.0, 0.0, 180.0, 1.0);

		// enemy wave
		for (int i = 1; i <= 31; i++) {
			enemy[i].x = SpawnFighterPos(i, 1 + ((2 * waveNum) - 2));
			enemy[i].z = SpawnFighterPos(i, 2 + ((2 * waveNum) - 2));
		}

		if (win == false)
			eventTime++;									// wave timer

		// wave event
		if (eventTime == 1) {
			for (int i = 1; i <= 31; i++) {
				enemyGetHited[i] = false;
				enemyHP[i] = 3;
				enemy[i].type = Random(1);
				enemyHP[35] = bossHP;
			}
		}

		if (win == false) {
			// spwan fighter
			if (eventTime > 1500 && eventTime <= 16000) {
				if (eventTime == 1501) {
					enemyZspeed = 0;
					for (int i = 1; i <= 31; i++) {
						enemyHP[i] = 3;
						enemy[i].type = Random(1);
						waveNum = Random(2);
					}
					if (bossActive == true) {
						bossActive = false;
					}
				}

				for (int i = 1; i <= 31; i++) {
					if (topView == false)
						enemyGetHited[i] = true;
					if (enemyGetHited[i] == false) {
						if (i <= 31)
							enemy[i].z += enemyZspeed;
						SpawnFigher(enemy[i].x, 0, enemy[i].z, enemy[i].type);
					}
					else
						enemy[i].z = 100;
				}

			}
			else if (eventTime > 2000 && eventTime < 30000)
				eventTime = 30000;
			// spwan boss
			else if (eventTime == 30001 && alive == true) {
				// reset boss bullet and movement
				enemyBulletX = 1000;		enemyBulletY = 1000;		enemyBulletZ = 1000;
				enemyBulletX2 = 1000;		enemyBulletY2 = 1000;		enemyBulletZ2 = enemy[35].z;
				bossMovement = 0;
				enemyBulletCD = rand() % 100 + (350 * (enemyHP[35]) / bossHP);

				if (bossActive == false)
					bossActive = true;
				if (topView == true) {
					tmepPlayerZ = playerZ;
					tmepPlayerY = playerY;
					topView = false;
				}
				else {
					tmepPlayerZ = playerZ;
					tmepPlayerY = playerY;
					topView = true;
				}
			}
			// despwan boss
			else if (eventTime > 50000 && alive == true) {
				if (topView == true) {
					tmepPlayerZ = playerZ;
					tmepPlayerY = playerY;
					topView = false;
				}
				else {
					tmepPlayerZ = playerZ;
					tmepPlayerY = playerY;
					topView = true;
				}
				eventTime = 100;
			}

		}


		// enemy alive
		for (int i = 1; i <= 31; i++)
			if (enemyHP[i] <= 0)
				enemyGetHited[i] = true;
			else
				enemyGetHited[i] = false;


		// boss movement
		enemy[35].x = 100 * sin(bossMovement / 1800);
		enemy[35].y = 50 * sin(bossMovement / 900);
		enemy[35].z = 600 - (200 * ViewNum / 69);

		// boss AI
		if (bossActive == true && win == false) {

			bossMovement++;
			enemyBulletCD++;

			// get hurt will change color
			glRotated(180.0, 0.0, 180.0, 1.0);
			if (hitEnemy == false)
				SpawnFigher(enemy[35].x, enemy[35].y, enemy[35].z, 6);
			else
				SpawnFigher(enemy[35].x, enemy[35].y, enemy[35].z, 8);
			glRotated(-180.0, 0.0, 180.0, 1.0);

			// boss attack
			if (enemyBulletCD >= 1100 + (900 * (enemyHP[35]) / bossHP)) {
				enemyBulletCD = rand() % 100 + (350 * (enemyHP[35]) / bossHP);
				enemyBulletX = -enemy[35].x;		enemyBulletY = enemy[35].y;		enemyBulletZ = enemy[35].z;
				enemyBulletX2 = enemyBulletX;		enemyBulletY2 = enemyBulletY;		enemyBulletZ2 = enemyBulletZ;
				// how many rows and column of attack
				rowNum = Random(3);
				columnNum = Random(3);
				// attack pattern
				if (rowNum + columnNum > 9) {
					enemyBulletCD -= 300;
				}
				if (rowNum + columnNum <= 3) {
					enemyBulletColor = 2;
				}
				else if (rowNum + columnNum <= 6) {
					enemyBulletColor = 3;
				}
				else if (rowNum + columnNum <= 9) {
					enemyBulletColor = 4;
				}
				else {
					enemyBulletColor = 5;
					arrowAttackNum = Random(4);
				}
			}

			if (eventTime > 30000) {
				enemyBulletZ -= speed * 4.2;
				enemyBulletZ2 -= speed * 4.5;
				// which attack pattern
				if (rowNum + columnNum <= 3) {
					enemyBulletX += speed * 1.5;
					enemyBulletX2 -= speed * 1.5;
					enemyBulletY += speed * 1.5;
					enemyBulletY2 -= speed * 1.5;
				}
				else if (rowNum + columnNum <= 6) {
					enemyBulletY += speed;
					enemyBulletY2 -= speed;
				}
				else if (rowNum + columnNum <= 9) {
					enemyBulletX += speed;
					enemyBulletX2 -= speed;
				}

				// attack pattern1
				if (rowNum + columnNum <= 9) {
					for (int i = -rowNum; i <= 0; i++)
						for (int w = -columnNum; w <= 0; w++)
							SpawnBullet(enemyBulletX + 35 * i, enemyBulletY + 35 * w, enemyBulletZ - 100, enemyBulletColor);
					for (int i = -rowNum; i <= 0; i++)
						for (int w = 1; w <= columnNum; w++)
							SpawnBullet(enemyBulletX + 35 * i, enemyBulletY2 + 35 * w, enemyBulletZ - 100, enemyBulletColor);
					for (int i = 1; i <= rowNum; i++)
						for (int w = -columnNum; w <= 0; w++)
							SpawnBullet(enemyBulletX2 + 35 * i, enemyBulletY + 35 * w, enemyBulletZ - 100, enemyBulletColor);
					for (int i = 1; i <= rowNum; i++)
						for (int w = 1; w <= columnNum; w++)
							SpawnBullet(enemyBulletX2 + 35 * i, enemyBulletY2 + 35 * w, enemyBulletZ - 100, enemyBulletColor);
				}
				else {// attack pattern2
					if (arrowAttackNum == 1) {
						for (int i = -rowNum; i <= rowNum; i++) {
							for (int w = -columnNum; w <= 0; w++) {
								if (enemyBulletZ2 - 100 + 20 * (columnNum - w) <= 250)
									SpawnBullet(enemyBulletX2 + 35 * i, enemyBulletY2 + 35 * w + 100,
										enemyBulletZ2 - 100 + 20 * (columnNum - w), enemyBulletColor);
							}
							for (int w = 1; w <= columnNum; w++) {
								if (enemyBulletZ2 - 100 + 20 * (columnNum - w) <= 250)
									SpawnBullet(enemyBulletX2 + 35 * i, enemyBulletY2 - 35 * w + 100,
										enemyBulletZ2 - 100 + 20 * (columnNum - w), enemyBulletColor);
							}
						}
					}
					else {
						for (int i = -rowNum; i <= rowNum; i++) {
							for (int w = -columnNum; w <= 0; w++) {
								if (enemyBulletZ2 - 100 + 20 * (columnNum - w) <= 250)
									SpawnBullet(enemyBulletX2 + 35 * i, enemyBulletY2 - 35 * w - 60,
										enemyBulletZ2 - 100 + 20 * (columnNum - w), enemyBulletColor);
							}
							for (int w = 1; w <= columnNum; w++) {
								if (enemyBulletZ2 - 100 + 20 * (columnNum - w) <= 250)
									SpawnBullet(enemyBulletX2 + 35 * i, enemyBulletY2 + 35 * w - 60,
										enemyBulletZ2 - 100 + 20 * (columnNum - w), enemyBulletColor);
							}
						}
					}
				}

			}
		}
		else if (win == true) {		// win animaton
			currentBossY -= speed * 3;
			enemy[35].y = currentBossY;
			glRotated(180.0, 0.0, 180.0, 1.0);
			SpawnFigher(enemy[35].x + Random(5), enemy[35].y + Random(5), enemy[35].z, 6);
			glRotated(-180.0, 0.0, 180.0, 1.0);
		}


		// check boss alive
		if (enemyHP[35] <= 0 && win == false) {
			win = true;
			topView = false;
		}

		// draw the Earth
		glTranslated(0.0, -21000.0, -6000.0);

		glColor3d(0.5, 0.5, 1);

		BG.rotateAngle += BG.rotateSpeed *0.001;
		if (BG.rotateAngle >= 360) {
			BG.rotateAngle = 0;
		}
		// self-rotate Earth
		glRotated(BG.rotateAngle, 3.0, 0.0, 0.0);
		glRotated(90, 0.0, 90.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		BG.draw();
		glDisable(GL_TEXTURE_2D);
		// rotate revert
		glRotated(-90, 0.0, 90.0, 0.0);
		glColor3d(0, 0, 0);
		glRotated(-BG.rotateAngle, 3.0, 0.0, 0.0);

		// camera position revert
		glTranslated(0.0, 21000.0, 6000.0);

		// attack
		if (alive == true && win == false) {
			attackCountDown--;
			if (attackCountDown <= 0) {
				attackCountDown = 150;
				attack += 1;
				bulletX = -playerX;		bulletY = playerY;		bulletZ = playerZ + 10;
			}

			switch (attack)
			{
			case 1:
				bulletZ += 1.5 + (0.8 * ViewNum / 69);
				if (bulletZ >= 230 + (300 * ViewNum / 69))
					bulletZ = 230 + (300 * ViewNum / 69);
				// hit fighter
				for (int i = 1; i <= 31; i++) {
					if (enemyGetHited[i] == false && hitEnemy == false)
						if (!(bulletX < enemy[i].x - 12 || bulletX > enemy[i].x + 12 ||			// the hixbox
							bulletY < enemyBaseY - 8 || bulletY > enemyBaseY + 8 ||
							bulletZ < -enemy[i].z - 12 || bulletZ > -enemy[i].z + 12)) {
							hitEnemy = true;
							enemyHP[i]--;
							addscore[1] += 1;
							if (enemyHP[i] == 0) {
								addscore[1] += 2 + enemy[i].type;
							}
						}
					// hit boss
					if (hitEnemy == false) {
						if (!(bulletX < -enemy[35].x - 130 || bulletX > -enemy[35].x + 130 ||			// the hixbox
							bulletY < enemy[35].y - 15 || bulletY > enemy[35].y + 50 ||
							bulletZ < enemy[35].z - 120 || bulletZ > enemy[35].z + 120) &&
							topView == false) {
							bulletX = 1000;
							if (!(ViewNum < 69)) {
								hitEnemy = true;
								enemyHP[35]--;
								addscore[1] += 1;
							}
							if (enemyHP[35] <= 0) {
								addscore[1] += 80;
								addscore[1] += 50 * (playerHP - 1);
							}
						}
					}
				}
				// spawn bullet if it haven't hit an ememy
				if (hitEnemy == false)
					SpawnBullet(bulletX, bulletY, bulletZ, 1);
				break;
			case 2:
				hitEnemy = false;
				attack = 1;
				break;
			default:
				break;
			}
		}

		// get damage
		playerHitCD--;
		if (alive == true && win == false) {
			// hitted by fighter
			for (int i = 1; i <= 31; i++) {
				if (enemyGetHited[i] == false && hitEnemy == false)
					if (!(-playerX < enemy[i].x - 16 || -playerX > enemy[i].x + 16 ||				// the hixbox
						playerY < enemyBaseY - 8 || playerY > enemyBaseY + 8 ||
						playerZ < -enemy[i].z - 16 || playerZ > -enemy[i].z + 16)) {
						enemyHP[i] -= 3;
						if (playerHitCD <= 0) {
							playerHP -= 2;
							playerHitCD = 500;
						}
					}
			}
			// hitted by bullet
			if (rowNum + columnNum <= 9) {										// first type boss bullet
				for (int i = -rowNum; i <= 0; i++)
					for (int w = -columnNum; w <= 0; w++) {
						if (!(-playerX < enemyBulletX + 35 * i - 10 ||			// the hixbox
							-playerX > enemyBulletX + 35 * i + 10 ||
							playerY < enemyBulletY + 35 * w - 10 ||
							playerY > enemyBulletY + 35 * w + 10 ||
							playerZ < enemyBulletZ - 100 - 10 ||
							playerZ > enemyBulletZ - 100 + 10)) {
							if (playerHitCD <= 0) {
								playerHP -= 1;
								playerHitCD = 500;
							}
						}
					}
				for (int i = -rowNum; i <= 0; i++)
					for (int w = 1; w <= columnNum; w++) {
						if (!(-playerX < enemyBulletX + 35 * i - 10 ||			// the hixbox
							-playerX > enemyBulletX + 35 * i + 10 ||
							playerY < enemyBulletY2 + 35 * w - 10 ||
							playerY > enemyBulletY2 + 35 * w + 10 ||
							playerZ < enemyBulletZ - 100 - 10 ||
							playerZ > enemyBulletZ - 100 + 10)) {
							if (playerHitCD <= 0) {
								playerHP -= 1;
								playerHitCD = 500;
							}
						}
					}
				for (int i = 1; i <= rowNum; i++)
					for (int w = -columnNum; w <= 0; w++) {
						if (!(-playerX < enemyBulletX2 + 35 * i - 10 ||			// the hixbox
							-playerX > enemyBulletX2 + 35 * i + 10 ||
							playerY < enemyBulletY + 35 * w - 10 ||
							playerY > enemyBulletY + 35 * w + 10 ||
							playerZ < enemyBulletZ - 100 - 10 ||
							playerZ > enemyBulletZ - 100 + 10)) {
							if (playerHitCD <= 0) {
								playerHP -= 1;
								playerHitCD = 500;
							}
						}
					}
				for (int i = 1; i <= rowNum; i++)
					for (int w = 1; w <= columnNum; w++) {
						if (!(-playerX < enemyBulletX2 + 35 * i - 10 ||			// the hixbox
							-playerX > enemyBulletX2 + 35 * i + 10 ||
							playerY < enemyBulletY2 + 35 * w - 10 ||
							playerY > enemyBulletY2 + 35 * w + 10 ||
							playerZ < enemyBulletZ - 100 - 10 ||
							playerZ > enemyBulletZ - 100 + 10)) {
							if (playerHitCD <= 0) {
								playerHP -= 1;
								playerHitCD = 500;
							}
						}
					}
			}
			else {																// second type boss bullet
				if (arrowAttackNum == 1) {
					for (int i = -rowNum; i <= rowNum; i++) {
						for (int w = -rowNum; w <= 0; w++) {
							if (!(-playerX < enemyBulletX2 + 35 * i - 10 ||			// the hixbox
								-playerX > enemyBulletX2 + 35 * i + 10 ||
								playerY < enemyBulletY2 + 35 * w + 100 - 10 ||
								playerY > enemyBulletY2 + 35 * w + 100 + 10 ||
								playerZ < enemyBulletZ2 - 100 + 20 * (columnNum - w) - 10 ||
								playerZ > enemyBulletZ2 - 100 + 20 * (columnNum - w) + 10)) {
								if (playerHitCD <= 0) {
									playerHP -= 1;
									playerHitCD = 500;
								}
							}
						}
						for (int w = 1; w <= columnNum; w++) {
							if (!(-playerX < enemyBulletX2 + 35 * i - 10 ||			// the hixbox
								-playerX > enemyBulletX2 + 35 * i + 10 ||
								playerY < enemyBulletY2 - 35 * w + 100 - 10 ||
								playerY > enemyBulletY2 - 35 * w + 100 + 10 ||
								playerZ < enemyBulletZ2 - 100 + 20 * (columnNum - w) - 10 ||
								playerZ > enemyBulletZ2 - 100 + 20 * (columnNum - w) + 10)) {
								if (playerHitCD <= 0) {
									playerHP -= 1;
									playerHitCD = 500;
								}
							}
						}
					}
				}
				else {
					for (int i = -rowNum; i <= rowNum; i++) {
						for (int w = -rowNum; w <= 0; w++) {
							if (!(-playerX < enemyBulletX2 + 35 * i - 10 ||			// the hixbox
								-playerX > enemyBulletX2 + 35 * i + 10 ||
								playerY < enemyBulletY2 + 35 * w - 60 - 10 ||
								playerY > enemyBulletY2 + 35 * w - 60 + 10 ||
								playerZ < enemyBulletZ2 - 100 + 20 * (columnNum - w) - 10 ||
								playerZ > enemyBulletZ2 - 100 + 20 * (columnNum - w) + 10)) {
								if (playerHitCD <= 0) {
									playerHP -= 1;
									playerHitCD = 500;
								}
							}
						}
						for (int w = 1; w <= columnNum; w++) {
							if (!(-playerX < enemyBulletX2 + 35 * i - 10 ||			// the hixbox
								-playerX > enemyBulletX2 + 35 * i + 10 ||
								playerY < enemyBulletY2 + 35 * w - 60 - 10 ||
								playerY > enemyBulletY2 + 35 * w - 60 + 10 ||
								playerZ < enemyBulletZ2 - 100 + 20 * (columnNum - w) - 10 ||
								playerZ > enemyBulletZ2 - 100 + 20 * (columnNum - w) + 10)) {
								if (playerHitCD <= 0) {
									playerHP -= 1;
									playerHitCD = 500;
								}
							}
						}
					}
				}
			}

			// check alive
			if (playerHP <= 0) {
				alive = false;
				scene = 2;
			}
		}

	}
	else {
		glTranslated(0.0, 0.0, -5.0);

		// change texture depand of scene
		if (scene == 0)
			glBindTexture(GL_TEXTURE_2D, bgTextureID);
		else if (scene == 2)
			glBindTexture(GL_TEXTURE_2D, bgTexture2ID);
		else if (scene == 3)
			glBindTexture(GL_TEXTURE_2D, bgTexture3ID);

		// display the background texture image
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glTranslated(0.0, 0.0, -1.0);
		glBegin(GL_QUADS);

		// draw rectangle
		glTexCoord2d(0.0, 0.0);   glVertex3d(-6.0, -6.0, 0.0);
		glTexCoord2d(1.0, 0.0);   glVertex3d(6.0, -6.0, 0.0);
		glTexCoord2d(1.0, 1.0);   glVertex3d(6.0, 6.0, 0.0);
		glTexCoord2d(0.0, 1.0);   glVertex3d(-6.0, 6.0, 0.0);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	glutPostRedisplay();
	glutSwapBuffers();
}



void keyboard(unsigned char key, int mousePositionX, int mousePositionY) {
	switch (key) {
	case 27: // [ESCAPE] key
		exit(0);
		break;
	case 'A':
	case 'a': // a key
		if (win == false)
			if (alive == true)
				playerX += speed * 50;
		break;
	case 'D':
	case 'd': // d key
		if (win == false)
			if (alive == true)
				playerX -= speed * 50;
		break;
	case 'W':
	case 'w': // a key
		if (win == false)
			if (alive == true)
				if (topView == true)
					playerZ += speed * 50;
				else
					playerY += speed * 50;
		break;
	case 'S':
	case 's': // d key
		if (win == false)
			if (alive == true)
				if (topView == true)
					playerZ -= speed * 50;
				else
					playerY -= speed * 50;
		break;
		//stop
	case 'P':
	case 'p': // pause key
		if (scene == 0) {
			scene = 1;
		}
		else if (scene == 1) {
			scene = 0;
		}
		break;
	case 'R':
	case 'r': // Reset key
		angle_around = 70;

		topView = true, hitEnemy = false, enemyGetHited[39], alive = true, bossActive = false,
			xPos = true, yPos = true, win = false;

		enemyZspeed = 0, enemyBaseY = 0, speed = 0.1,							// speed and enemyY
			ViewNum = 0, camX = 0, maxCamRange = 26,								// cam 
			playerX = 0, playerY = 0, playerZ = 20,									// player position							
			tmepPlayerZ = 0, tmepPlayerY = 0,										// temp player position
			bulletX = 0, bulletY = 0, bulletZ = 0,									// bullet position
			enemyBulletX = 1000, enemyBulletY = 1000, enemyBulletZ = 1000,			// enemy bullet position1
			enemyBulletX2 = 1000, enemyBulletY2 = 1000, enemyBulletZ2 = 1000,		// enemy bullet position2
			bossMovement = 0, currentBossY = 0;										// temp boss position
		eventTime = 0, eventNum = 0,											// wave event
			attackCountDown = 0, attack = 0,										// attack count down
			enemyBulletCD = 0,														// enemy attack count down
			rowNum = 0, columnNum = 0, waveNum = 0,									// random number
			bossHP = 200, playerHP = 5, 											// HP
			playerhpY = 0, playerhpX = 0, playerMaxHP = playerHP,					// player
			playerHitCD = 0,														// invincibility time
			scene = 0;																// scene
		for (int i = 1; i <= 4; i++) {
			addscore[i] = 0;
		}
		break;
	default:break;
	}
}

int main(int argc, char **argv) {
	cout << "Group 6\n";
	cout << "Compiled on " __DATE__ ", " __TIME__ << endl << endl;

	if (scene == 0) {
		PlaySound(TEXT("music/BackgroundMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	}

	// init GLUT and create Window
	glutInit(&argc, argv); // GLUT initialization
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 700);		// set the window size

	// create the window
	glutCreateWindow("Ocean Warfare");
	initRendering();					// initialize rendering

	// set handler functions
	glutDisplayFunc(display);			// display function
	glutKeyboardFunc(keyboard);			// keyboard handler
	glutReshapeFunc(cameraSetup);		// resizes window and camera setup
	initialize();

	TextureImage Texture;
	BG.textureID = Texture.loadImage("images/sea.bmp", BMP_IMAGE);
	bgTextureID = Texture.loadImage("images/main.bmp", BMP_IMAGE);
	bgTexture2ID = Texture.loadImage("images/lost.bmp", BMP_IMAGE);
	bgTexture3ID = Texture.loadImage("images/win.bmp", BMP_IMAGE);

	// random generator
	srand((unsigned)time(NULL));

	glutMainLoop();						//run GLUT mainloop
}