/*  Filename:       image.cpp
	Description:    Solution - MET4335 - draw object
*/

#include "draw.h"

// vertex location
class Vertex {
public:
	GLdouble x, y, z;
	Vertex(GLdouble x1, GLdouble y1, GLdouble z1) {
		x = x1;
		y = y1;
		z = z1;
	}
};

// draw face
void drawRectangle(Vertex v1, Vertex v2, Vertex v3, Vertex v4) {
	glBegin(GL_QUADS);
	glVertex3d(v1.x, v1.y, v1.z);
	glVertex3d(v2.x, v2.y, v2.z);
	glVertex3d(v3.x, v3.y, v3.z);
	glVertex3d(v4.x, v4.y, v4.z);
	glEnd();
}

// draw enemy fighter
void drawFighter(GLdouble length, GLdouble width, GLdouble height,
	GLdouble red, GLdouble green, GLdouble blue,
	GLdouble x, GLdouble y, GLdouble z) {
	// Body
	Vertex v1(length / 3 + x, height / 4 + y, width / 2 + z);			// top right up vertex
	Vertex v2(-length / 3 + x, height / 4 + y, width / 2 + z);			// top left up vertex
	Vertex v3(-length / 2 + x, height / 4 + y, -width / 3 + z);			// top right down vertex
	Vertex v4(length / 2 + x, height / 4 + y, -width / 3 + z);			// top left down vertex

	Vertex v5(length / 3 + x, -height / 4 + y, width / 2 + z);			// botton right up vertex
	Vertex v6(-length / 3 + x, -height / 4 + y, width / 2 + z);			// botton left up vertex
	Vertex v7(-length / 2 + x, -height / 4 + y, -width / 3 + z);		// botton right down vertex
	Vertex v8(length / 2 + x, -height / 4 + y, -width / 3 + z);			// botton left down vertex

	Vertex v9(length / 4.5 + x, height / 2 + y, width / 3 + z);			// top right up vrtex2
	Vertex v10(-length / 4.5 + x, height / 2 + y, width / 3 + z);		// top left up vertex2
	Vertex v11(-length / 3 + x, height / 2 + y, -width / 4.5 + z);		// top right down vertex2
	Vertex v12(length / 3 + x, height / 2 + y, -width / 4.5 + z);		// top left down vertex2

	// head
	Vertex v13(length / 10 + x, height / 10 + y, width / 1.5 + z);		// head vrtex
	Vertex v14(-length / 10 + x, height / 10 + y, width / 1.5 + z);		// head vertex2
	Vertex v15(-length / 10 + x, -height / 10 + y, width / 1.5 + z);	// head vertex3
	Vertex v16(length / 10 + x, -height / 10 + y, width / 1.5 + z);		// head vertex4

	// wing
	Vertex v17(length / 3 + x, height / 4 + y, width / 6 + z);			// wing vertex
	Vertex v18(length / 3 + x, -height / 4 + y, width / 6 + z);			// wing vertex2

	Vertex v19(length * 2 + x, height / 8 + y, -width / 6 + z);			// wing vertex3
	Vertex v20(length * 2 + x, -height / 8 + y, -width / 6 + z);		// wing vertex4
	Vertex v21(length * 2 + x, height / 8 + y, -width / 3.5 + z);		// wing vertex5
	Vertex v22(length * 2 + x, -height / 8 + y, -width / 3.5 + z);		// wing vertex6

	Vertex v23(-length / 3 + x, height / 4 + y, width / 6 + z);			// wing vertex7
	Vertex v24(-length / 3 + x, -height / 4 + y, width / 6 + z);		// wing vertex8

	Vertex v25(-length * 2 + x, height / 8 + y, -width / 6 + z);		// wing vertex9
	Vertex v26(-length * 2 + x, -height / 8 + y, -width / 6 + z);		// wing vertex10
	Vertex v27(-length * 2 + x, height / 8 + y, -width / 3.5 + z);		// wing vertex11
	Vertex v28(-length * 2 + x, -height / 8 + y, -width / 3.5 + z);		// wing vertex12

	// small wing
	Vertex v29(length * 2 + x, height / 5 + y, -width / 12 + z);		// small wing vertex
	Vertex v30(length * 2 + x, -height / 5 + y, -width / 12 + z);		// small wing vertex2
	Vertex v31(length * 2 + x, height / 5 + y, -width / 2.5 + z);		// small wing vertex3
	Vertex v32(length * 2 + x, -height / 5 + y, -width / 2.5 + z);		// small wing vertex4
	Vertex v33(length * 2.2 + x, height / 5 + y, -width / 12 + z);		// small wing vertex5
	Vertex v34(length * 2.2 + x, -height / 5 + y, -width / 12 + z);		// small wing vertex6
	Vertex v35(length * 2.2 + x, height / 5 + y, -width / 2.5 + z);		// small wing vertex7
	Vertex v36(length * 2.2 + x, -height / 5 + y, -width / 2.5 + z);	// small wing vertex8

	Vertex v37(-length * 2 + x, height / 5 + y, -width / 12 + z);		// small wing vertex9
	Vertex v38(-length * 2 + x, -height / 5 + y, -width / 12 + z);		// small wing vertex10
	Vertex v39(-length * 2 + x, height / 5 + y, -width / 2.5 + z);		// small wing vertex11
	Vertex v40(-length * 2 + x, -height / 5 + y, -width / 2.5 + z);		// small wing vertex12
	Vertex v41(-length * 2.2 + x, height / 5 + y, -width / 12 + z);		// small wing vertex13
	Vertex v42(-length * 2.2 + x, -height / 5 + y, -width / 12 + z);	// small wing vertex14
	Vertex v43(-length * 2.2 + x, height / 5 + y, -width / 2.5 + z);	// small wing vertex15
	Vertex v44(-length * 2.2 + x, -height / 5 + y, -width / 2.5 + z);	// small wing vertex16

	// engine
	Vertex v45(length / 4.5 + x, height / 6 + y, -width / 3 + z);		// engine vertex
	Vertex v46(-length / 4.5 + x, height / 6 + y, -width / 3 + z);		// engine vertex2
	Vertex v47(length / 4.5 + x, -height / 6 + y, -width / 3 + z);		// engine vertex3
	Vertex v48(-length / 4.5 + x, -height / 6 + y, -width / 3 + z);		// engine vertex4
	Vertex v49(length / 4.5 + x, height / 6 + y, -width / 2.6 + z);		// engine vertex
	Vertex v50(-length / 4.5 + x, height / 6 + y, -width / 2.6 + z);	// engine vertex2
	Vertex v51(length / 4.5 + x, -height / 6 + y, -width / 2.6 + z);	// engine vertex3
	Vertex v52(-length / 4.5 + x, -height / 6 + y, -width / 2.6 + z);	// engine vertex4

	// back wing
	Vertex v53(-length / 6 + x, height / 1.2 + y, -width / 6 + z);		// back wing vertex
	Vertex v54(-length / 4.5 + x, height / 1.2 + y, -width / 6 + z);	// back wing vertex2
	Vertex v55(-length / 6 + x, height / 1.2 + y, -width / 4.2 + z);	// back wing vertex3
	Vertex v56(-length / 4.5 + x, height / 1.2 + y, -width / 4.2 + z);	// back wing vertex4
	Vertex v57(-length / 12 + x, height / 6 + y, width / 18 + z);		// back wing vertex5
	Vertex v58(-length / 6 + x, height / 6 + y, width / 18 + z);		// back wing vertex6
	Vertex v59(-length / 12 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex7
	Vertex v60(-length / 6 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex8

	Vertex v61(length / 6 + x, height / 1.2 + y, -width / 6 + z);		// back wing vertex9
	Vertex v62(length / 4.5 + x, height / 1.2 + y, -width / 6 + z);		// back wing vertex10
	Vertex v63(length / 6 + x, height / 1.2 + y, -width / 4.2 + z);		// back wing vertex11
	Vertex v64(length / 4.5 + x, height / 1.2 + y, -width / 4.2 + z);	// back wing vertex12
	Vertex v65(length / 12 + x, height / 6 + y, width / 18 + z);		// back wing vertex13
	Vertex v66(length / 6 + x, height / 6 + y, width / 18 + z);			// back wing vertex14
	Vertex v67(length / 12 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex15
	Vertex v68(length / 6 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex16

	// driver window
	Vertex v69(length / 12 + x, height / 2.6 + y, width / 2.2 + z);		// driver window vertex
	Vertex v70(-length / 12 + x, height / 2.6 + y, width / 2.2 + z);	// driver window vertex2
	Vertex v71(length / 6 + x, height / 2.6 + y, width / 2 + z);		// driver window vertex3
	Vertex v72(-length / 6 + x, height / 2.6 + y, width / 2 + z);		// driver window vertex4
	Vertex v73(length / 12 + x, height / 2.6 + y, width / 1.9 + z);		// driver window vertex5
	Vertex v74(-length / 12 + x, height / 2.6 + y, width / 1.9 + z);	// driver window vertex6

	Vertex v75(length / 10 + x, height / 4 + y, width / 2.1 + z);		// driver window vertex7
	Vertex v76(-length / 10 + x, height / 4 + y, width / 2.1 + z);		// driver window vertex8
	Vertex v77(length / 5 + x, height / 4 + y, width / 2 + z);			// driver window vertex9
	Vertex v78(-length / 5 + x, height / 4 + y, width / 2 + z);			// driver window vertex10
	Vertex v79(length / 10 + x, height / 4 + y, width / 1.85 + z);		// driver window vertex11
	Vertex v80(-length / 10 + x, height / 4 + y, width / 1.85 + z);		// driver window vertex12

	// drawBody
	glColor3d(red * 0.85, green * 0.85, blue * 0.85);
	drawRectangle(v5, v6, v7, v8);		// botton face
	drawRectangle(v1, v5, v6, v2);		// front face
	drawRectangle(v4, v8, v7, v3);		// back face
	drawRectangle(v2, v3, v7, v6);		// left face
	drawRectangle(v1, v4, v8, v5);		// right face

	glColor3d(red * 0.9, green * 0.9, blue * 0.9);
	drawRectangle(v1, v9, v10, v2);		// top front face
	drawRectangle(v4, v12, v11, v3);	// top back face
	drawRectangle(v1, v9, v12, v4);		// top right face
	drawRectangle(v2, v10, v11, v3);	// top left face
	drawRectangle(v9, v10, v11, v12);	// top face

	// draw head
	glColor3d(red, green, blue);
	drawRectangle(v1, v13, v14, v2);	// head face
	drawRectangle(v6, v15, v16, v5);	// head face2
	drawRectangle(v1, v13, v16, v5);	// head face3
	drawRectangle(v2, v14, v15, v6);	// head face4
	drawRectangle(v13, v14, v15, v16);	// head face5

	// draw wing
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v17, v19, v21, v4);	// wing face
	glColor3d(0.7, 0.7, 0.7);
	drawRectangle(v18, v20, v22, v8);	// wing face2
	drawRectangle(v17, v18, v20, v19);	// wing face3
	drawRectangle(v4, v8, v22, v21);	// wing face4
	drawRectangle(v19, v20, v22, v21);	// wing face5

	drawRectangle(v23, v25, v27, v3);	// wing face6
	drawRectangle(v24, v26, v28, v7);	// wing face7
	drawRectangle(v23, v24, v26, v25);	// wing face8
	drawRectangle(v3, v7, v28, v27);	// wing face9
	drawRectangle(v25, v26, v28, v27);	// wing face10

	// draw small wing
	glColor3d(red, green, blue);
	drawRectangle(v29, v30, v32, v31);	// samll wing face
	drawRectangle(v29, v33, v34, v30);	// samll wing face2
	drawRectangle(v32, v36, v35, v31);	// samll wing face3
	drawRectangle(v29, v33, v35, v31);	// samll wing face4
	drawRectangle(v30, v34, v36, v32);	// samll wing face5
	drawRectangle(v33, v34, v36, v35);	// samll wing face6

	drawRectangle(v37, v38, v40, v39);	// samll wing face7
	drawRectangle(v37, v41, v42, v38);	// samll wing face8
	drawRectangle(v40, v44, v43, v39);	// samll wing face9
	drawRectangle(v37, v41, v43, v39);	// samll wing face10
	drawRectangle(v38, v42, v44, v40);	// samll wing face11
	drawRectangle(v41, v42, v44, v43);	// samll wing face12

	// draw engine
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v45, v49, v50, v46);	//	engine face
	drawRectangle(v47, v51, v52, v48);	//	engine2 face2
	drawRectangle(v45, v49, v51, v47);	//	engine3 face3
	drawRectangle(v46, v50, v52, v48);	//	engine4 face4
	glColor3d(0.7, 0.7, 0.7);
	drawRectangle(v49, v50, v52, v51);	//	engine5 face5

	// draw back wing
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v53, v54, v56, v55);	// back wing face
	drawRectangle(v53, v57, v58, v54);	// back wing face2
	drawRectangle(v55, v59, v60, v56);	// back wing face3
	drawRectangle(v53, v57, v59, v55);	// back wing face4
	drawRectangle(v54, v58, v60, v56);	// back wing face5
	glColor3d(0.7, 0.7, 0.7);
	drawRectangle(v55, v56, v60, v59);	// back wing face6

	glColor3d(0.9, 0.9, 0.9);
	drawRectangle(v61, v62, v64, v63);	// back wing face7
	drawRectangle(v61, v65, v66, v62);	// back wing face8
	drawRectangle(v63, v67, v68, v64);	// back wing face9
	drawRectangle(v61, v65, v67, v63);	// back wing face10
	drawRectangle(v62, v66, v68, v64);	// back wing face11
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v63, v64, v68, v67);	// back wing face12

	// draw driver window
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v69, v70, v72, v71);	// driver window face
	drawRectangle(v71, v72, v74, v73);	// driver window face2

	drawRectangle(v69, v70, v76, v75);	// driver window face3
	drawRectangle(v70, v72, v78, v76);	// driver window face4
	drawRectangle(v72, v74, v80, v78);	// driver window face5
	drawRectangle(v74, v73, v79, v80);	// driver window face6
	drawRectangle(v73, v71, v77, v79);	// driver window face7
	drawRectangle(v71, v69, v75, v77);	// driver window face8
}

// draw player fighter
void drawPlayerFighter(GLdouble length, GLdouble width, GLdouble height,
	GLdouble red, GLdouble green, GLdouble blue,
	GLdouble x, GLdouble y, GLdouble z) {
	// Body
	Vertex v1(length / 3 + x, height / 4 + y, width / 2 + z);			// top right up vertex
	Vertex v2(-length / 3 + x, height / 4 + y, width / 2 + z);			// top left up vertex
	Vertex v3(-length / 2 + x, height / 4 + y, -width / 3 + z);			// top right down vertex
	Vertex v4(length / 2 + x, height / 4 + y, -width / 3 + z);			// top left down vertex

	Vertex v5(length / 3 + x, -height / 4 + y, width / 2 + z);			// botton right up vertex
	Vertex v6(-length / 3 + x, -height / 4 + y, width / 2 + z);			// botton left up vertex
	Vertex v7(-length / 2 + x, -height / 4 + y, -width / 3 + z);		// botton right down vertex
	Vertex v8(length / 2 + x, -height / 4 + y, -width / 3 + z);			// botton left down vertex

	Vertex v9(length / 4.5 + x, height / 2 + y, width / 3 + z);			// top right up vrtex2
	Vertex v10(-length / 4.5 + x, height / 2 + y, width / 3 + z);		// top left up vertex2
	Vertex v11(-length / 3 + x, height / 2 + y, -width / 4.5 + z);		// top right down vertex2
	Vertex v12(length / 3 + x, height / 2 + y, -width / 4.5 + z);		// top left down vertex2

	// head
	Vertex v13(length / 10 + x, height / 10 + y, width / 1.5 + z);		// head vrtex
	Vertex v14(-length / 10 + x, height / 10 + y, width / 1.5 + z);		// head vertex2
	Vertex v15(-length / 10 + x, -height / 10 + y, width / 1.5 + z);	// head vertex3
	Vertex v16(length / 10 + x, -height / 10 + y, width / 1.5 + z);		// head vertex4

	// wing 
	Vertex v17(length / 3 + x, height / 4 + y, width / 12 + z);			// wing vertex
	Vertex v18(length / 3 + x, -height / 4 + y, width / 12 + z);		// wing vertex2

	Vertex v19(length / 1 + x, height / 6 + y, -width / 25 + z);		// wing vertex3
	Vertex v20(length / 1 + x, -height / 6 + y, -width / 25 + z);		// wing vertex4
	Vertex v21(length / 1 + x, height / 6 + y, -width / 3.5 + z);		// wing vertex5
	Vertex v22(length / 1 + x, -height / 6 + y, -width / 3.5 + z);		// wing vertex6

	Vertex v23(-length / 3 + x, height / 4 + y, width / 12 + z);		// wing vertex7
	Vertex v24(-length / 3 + x, -height / 4 + y, width / 12 + z);		// wing vertex8

	Vertex v25(-length / 1 + x, height / 6 + y, -width / 25 + z);		// wing vertex9
	Vertex v26(-length / 1 + x, -height / 6 + y, -width / 25 + z);		// wing vertex10
	Vertex v27(-length / 1 + x, height / 6 + y, -width / 3.5 + z);		// wing vertex11
	Vertex v28(-length / 1 + x, -height / 6 + y, -width / 3.5 + z);		// wing vertex12

	// small wing
	Vertex v29(length * 1.6 + x, height / 2.3 + y, width / 15 + z);		// small wing vertex
	Vertex v30(length * 1.6 + x, height / 30 + y, width / 15 + z);		// small wing vertex2
	Vertex v31(length * 1.6 + x, height / 2.3 + y, -width / 4.5 + z);	// small wing vertex3
	Vertex v32(length * 1.6 + x, height / 30 + y, -width / 4.5 + z);	// small wing vertex4
	Vertex v33(length * 1.8 + x, height / 2.3 + y, width / 15 + z);		// small wing vertex5
	Vertex v34(length * 1.8 + x, height / 30 + y, width / 15 + z);		// small wing vertex6
	Vertex v35(length * 1.8 + x, height / 2.3 + y, -width / 4.5 + z);	// small wing vertex7
	Vertex v36(length * 1.8 + x, height / 30 + y, -width / 4.5 + z);	// small wing vertex8

	Vertex v37(-length * 1.6 + x, height / 2.3 + y, width / 15 + z);	// small wing vertex9
	Vertex v38(-length * 1.6 + x, height / 30 + y, width / 15 + z);		// small wing vertex10
	Vertex v39(-length * 1.6 + x, height / 2.3 + y, -width / 4.5 + z);	// small wing vertex11
	Vertex v40(-length * 1.6 + x, height / 30 + y, -width / 4.5 + z);	// small wing vertex12
	Vertex v41(-length * 1.8 + x, height / 2.3 + y, width / 15 + z);	// small wing vertex13
	Vertex v42(-length * 1.8 + x, height / 30 + y, width / 15 + z);		// small wing vertex14
	Vertex v43(-length * 1.8 + x, height / 2.3 + y, -width / 4.5 + z);	// small wing vertex15
	Vertex v44(-length * 1.8 + x, height / 30 + y, -width / 4.5 + z);	// small wing vertex16

	// engine
	Vertex v45(length / 4.5 + x, height / 6 + y, -width / 3 + z);		// engine vertex
	Vertex v46(-length / 4.5 + x, height / 6 + y, -width / 3 + z);		// engine vertex2
	Vertex v47(length / 4.5 + x, -height / 6 + y, -width / 3 + z);		// engine vertex3
	Vertex v48(-length / 4.5 + x, -height / 6 + y, -width / 3 + z);		// engine vertex4
	Vertex v49(length / 4.5 + x, height / 6 + y, -width / 2.6 + z);		// engine vertex
	Vertex v50(-length / 4.5 + x, height / 6 + y, -width / 2.6 + z);	// engine vertex2
	Vertex v51(length / 4.5 + x, -height / 6 + y, -width / 2.6 + z);	// engine vertex3
	Vertex v52(-length / 4.5 + x, -height / 6 + y, -width / 2.6 + z);	// engine vertex4

	// back wing
	Vertex v53(-length / 6 + x, height / 1.2 + y, -width / 6 + z);		// back wing vertex
	Vertex v54(-length / 4.5 + x, height / 1.2 + y, -width / 6 + z);	// back wing vertex2
	Vertex v55(-length / 6 + x, height / 1.2 + y, -width / 4.2 + z);	// back wing vertex3
	Vertex v56(-length / 4.5 + x, height / 1.2 + y, -width / 4.2 + z);	// back wing vertex4
	Vertex v57(-length / 12 + x, height / 6 + y, width / 18 + z);		// back wing vertex5
	Vertex v58(-length / 6 + x, height / 6 + y, width / 18 + z);		// back wing vertex6
	Vertex v59(-length / 12 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex7
	Vertex v60(-length / 6 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex8

	Vertex v61(length / 6 + x, height / 1.2 + y, -width / 6 + z);		// back wing vertex9
	Vertex v62(length / 4.5 + x, height / 1.2 + y, -width / 6 + z);		// back wing vertex10
	Vertex v63(length / 6 + x, height / 1.2 + y, -width / 4.2 + z);		// back wing vertex11
	Vertex v64(length / 4.5 + x, height / 1.2 + y, -width / 4.2 + z);	// back wing vertex12
	Vertex v65(length / 12 + x, height / 6 + y, width / 18 + z);		// back wing vertex13
	Vertex v66(length / 6 + x, height / 6 + y, width / 18 + z);			// back wing vertex14
	Vertex v67(length / 12 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex15
	Vertex v68(length / 6 + x, height / 6 + y, -width / 4.2 + z);		// back wing vertex16

	// driver window
	Vertex v69(length / 8 + x, height / 2.1 + y, width / 8 + z);		// driver window vertex
	Vertex v70(-length / 8 + x, height / 2.1 + y, width / 8 + z);		// driver window vertex2
	Vertex v71(length / 4 + x, height / 1.8 + y, width / 4 + z);		// driver window vertex3
	Vertex v72(-length / 4 + x, height / 1.8 + y, width / 4 + z);		// driver window vertex4

	Vertex v73(length / 9 + x, height / 2.1 + y, width / 2 + z);		// driver window vertex5
	Vertex v74(-length / 9 + x, height / 2.1 + y, width / 2 + z);		// driver window vertex6
	Vertex v75(length / 5 + x, height / 1.8 + y, width / 2.5 + z);		// driver window vertex7
	Vertex v76(-length / 5 + x, height / 1.8 + y, width / 2.5 + z);		// driver window vertex8

	Vertex v77(length / 7.75 + x, height / 6 + y, width / 7.9 + z);		// driver window vertex9
	Vertex v78(-length / 7.75 + x, height / 6 + y, width / 7.9 + z);	// driver window vertex10
	Vertex v79(length / 3.75 + x, height / 6 + y, width / 3.9 + z);		// driver window vertex11
	Vertex v80(-length / 3.75 + x, height / 6 + y, width / 3.9 + z);	// driver window vertex12

	Vertex v81(length / 8.5 + x, height / 6 + y, width / 1.9 + z);		// driver window vertex13
	Vertex v82(-length / 8.5 + x, height / 6 + y, width / 1.9 + z);		// driver window vertex14
	Vertex v83(length / 4.5 + x, height / 6 + y, width / 2.6 + z);		// driver window vertex15
	Vertex v84(-length / 4.5 + x, height / 6 + y, width / 2.6 + z);		// driver window vertex16

	// long wing 
	Vertex v85(length * 2.5 + x, height / 2.6 + y, width / 12 + z);		// long wing vertex
	Vertex v86(length * 2.5 + x, height / 1.8 + y, width / 12 + z);		// long wing vertex2
	Vertex v87(length * 2.5 + x, height / 2.6 + y, -width / 18 + z);	// long wing vertex3
	Vertex v88(length * 2.5 + x, height / 1.8 + y, -width / 18 + z);	// long wing vertex4

	Vertex v89(-length * 2.5 + x, height / 2.6 + y, width / 12 + z);	// long wing vertex5
	Vertex v90(-length * 2.5 + x, height / 1.8 + y, width / 12 + z);	// long wing vertex6
	Vertex v91(-length * 2.5 + x, height / 2.6 + y, -width / 18 + z);	// long wing vertex7
	Vertex v92(-length * 2.5 + x, height / 1.8 + y, -width / 18 + z);	// long wing vertex8

	// drawBody
	glColor3d(red * 0.85, green * 0.85, blue * 0.85);
	drawRectangle(v5, v6, v7, v8);		// botton face
	drawRectangle(v1, v5, v6, v2);		// front face
	drawRectangle(v4, v8, v7, v3);		// back face
	drawRectangle(v2, v3, v7, v6);		// left face
	drawRectangle(v1, v4, v8, v5);		// right face

	glColor3d(red * 0.9, green * 0.9, blue * 0.9);
	drawRectangle(v1, v9, v10, v2);		// top front face
	drawRectangle(v4, v12, v11, v3);	// top back face
	drawRectangle(v1, v9, v12, v4);		// top right face
	drawRectangle(v2, v10, v11, v3);	// top left face
	drawRectangle(v9, v10, v11, v12);	// top face

	// draw head
	glColor3d(red, green, blue);
	drawRectangle(v1, v13, v14, v2);	// head face
	drawRectangle(v6, v15, v16, v5);	// head face2
	drawRectangle(v1, v13, v16, v5);	// head face3
	drawRectangle(v2, v14, v15, v6);	// head face4
	drawRectangle(v13, v14, v15, v16);	// head face5

	// draw wing
	glColor3d(red * 0.85, green * 0.85, blue * 0.85);
	drawRectangle(v17, v19, v21, v4);	// wing face
	drawRectangle(v23, v25, v27, v3);	// wing face6

	glColor3d(red * 0.8, green * 0.8, blue * 0.8);
	drawRectangle(v18, v20, v22, v8);	// wing face2
	drawRectangle(v17, v18, v20, v19);	// wing face3
	drawRectangle(v4, v8, v22, v21);	// wing face4
	drawRectangle(v19, v20, v22, v21);	// wing face5

	drawRectangle(v24, v26, v28, v7);	// wing face7
	drawRectangle(v23, v24, v26, v25);	// wing face8
	drawRectangle(v3, v7, v28, v27);	// wing face9
	drawRectangle(v25, v26, v28, v27);	// wing face10

	// draw small wing
	glColor3d(red, green, blue);
	drawRectangle(v29, v30, v32, v31);	// samll wing face
	drawRectangle(v29, v33, v34, v30);	// samll wing face2
	drawRectangle(v32, v36, v35, v31);	// samll wing face3
	drawRectangle(v29, v33, v35, v31);	// samll wing face4
	drawRectangle(v30, v34, v36, v32);	// samll wing face5
	drawRectangle(v33, v34, v36, v35);	// samll wing face6

	drawRectangle(v37, v38, v40, v39);	// samll wing face7
	drawRectangle(v37, v41, v42, v38);	// samll wing face8
	drawRectangle(v40, v44, v43, v39);	// samll wing face9
	drawRectangle(v37, v41, v43, v39);	// samll wing face10
	drawRectangle(v38, v42, v44, v40);	// samll wing face11
	drawRectangle(v41, v42, v44, v43);	// samll wing face12

	// draw engine
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v45, v49, v50, v46);	//	engine face
	drawRectangle(v47, v51, v52, v48);	//	engine2 face2
	drawRectangle(v45, v49, v51, v47);	//	engine3 face3
	drawRectangle(v46, v50, v52, v48);	//	engine4 face4
	glColor3d(0.7, 0.7, 0.7);
	drawRectangle(v49, v50, v52, v51);	//	engine5 face5

	// draw back wing
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v53, v54, v56, v55);	// back wing face
	drawRectangle(v53, v57, v58, v54);	// back wing face2
	drawRectangle(v55, v59, v60, v56);	// back wing face3
	drawRectangle(v53, v57, v59, v55);	// back wing face4
	drawRectangle(v54, v58, v60, v56);	// back wing face5
	glColor3d(0.7, 0.7, 0.7);
	drawRectangle(v55, v56, v60, v59);	// back wing face6

	glColor3d(0.9, 0.9, 0.9);
	drawRectangle(v61, v62, v64, v63);	// back wing face7
	drawRectangle(v61, v65, v66, v62);	// back wing face8
	drawRectangle(v63, v67, v68, v64);	// back wing face9
	drawRectangle(v61, v65, v67, v63);	// back wing face10
	drawRectangle(v62, v66, v68, v64);	// back wing face11
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v63, v64, v68, v67);	// back wing face12

	// draw driver window
	glColor3d(0.8, 0.8, 0.8);
	drawRectangle(v69, v70, v72, v71);	// driver window face
	drawRectangle(v73, v74, v76, v75);	// driver window face2
	drawRectangle(v71, v72, v76, v75);	// driver window face3

	drawRectangle(v69, v77, v78, v70);	// driver window face4
	drawRectangle(v70, v78, v80, v72);	// driver window face5
	drawRectangle(v72, v80, v84, v76);	// driver window face6
	drawRectangle(v76, v84, v82, v74);	// driver window face7
	drawRectangle(v74, v82, v81, v73);	// driver window face8
	drawRectangle(v73, v81, v83, v75);	// driver window face9
	drawRectangle(v75, v83, v80, v71);	// driver window face10
	drawRectangle(v71, v80, v77, v69);	// driver window face11

	// draw long wing
	glColor3d(0.65, 0.65, 0.65);
	drawRectangle(v85, v86, v88, v87);	// long wing face
	glColor3d(0.72, 0.72, 0.72);
	drawRectangle(v19, v86, v85, v20);	// long wing face2
	glColor3d(0.65, 0.65, 0.65);
	drawRectangle(v20, v85, v87, v22);	// long wing face3
	glColor3d(0.72, 0.72, 0.72);
	drawRectangle(v22, v87, v88, v21);	// long wing face4
	glColor3d(0.85, 0.85, 0.85);
	drawRectangle(v19, v86, v88, v21);	// long wing face5

	glColor3d(0.65, 0.65, 0.65);
	drawRectangle(v89, v90, v92, v91);	// long wing face6
	glColor3d(0.72, 0.72, 0.72);
	drawRectangle(v25, v90, v89, v26);	// long wing face7
	glColor3d(0.65, 0.65, 0.65);
	drawRectangle(v26, v89, v91, v28);	// long wing face8
	glColor3d(0.72, 0.72, 0.72);
	drawRectangle(v28, v91, v92, v27);	// long wing face9
	glColor3d(0.85, 0.85, 0.85);
	drawRectangle(v25, v90, v92, v27);	// long wing face10
}

// draw boss fighter
void drawBoss(GLdouble length, GLdouble width, GLdouble height,
	GLdouble red, GLdouble green, GLdouble blue,
	GLdouble x, GLdouble y, GLdouble z) {

	// wings
	Vertex v1(x, height / 2 + y, width / 8 + z);						// wings vertex
	Vertex v2(x, height / 5 + y, -width / 2 + z);						// wings vertex2

	Vertex v3(length * 3 + x, height / 20 + y, -width / 8 + z);			// wings vertex3
	Vertex v4(-length * 3 + x, height / 20 + y, -width / 8 + z);		// wings vertex4
	Vertex v5(-length * 4 + x, height / 20 + y, -width / 1.2 + z);		// wings vertex5
	Vertex v6(length * 4 + x, height / 20 + y, -width / 1.2 + z);		// wings vertex6

	Vertex v7(x, height / 5 + y, width / 2 + z);						// wings vertex7

	Vertex v8(-length * 2 + x, height / 4 + y, -width / 2.5 + z);		// wings vertex8
	Vertex v9(length * 2 + x, height / 4 + y, -width / 2.5 + z);		// wings vertex9

	Vertex v10(x, -height / 15 + y, width / 8 + z);						// wings vertex10

	Vertex v61(-length * 1.8 + x, height / 3.5 + y, -width / 3 + z);	// wings vertex61
	Vertex v62(length * 1.8 + x, height / 3.5 + y, -width / 3 + z);		// wings vertex61

	// window
	Vertex v11(length / 2 + x, height / 1.8 + y, width / 8 + z);		// window vertex1
	Vertex v12(-length / 2 + x, height / 1.8 + y, width / 8 + z);		// window vertex2
	Vertex v13(-length / 1.5 + x, height / 1.8 + y, -width / 3 + z);	// window vertex3
	Vertex v14(length / 1.5 + x, height / 1.8 + y, -width / 3 + z);		// window vertex4

	Vertex v15(x, height / 5 + y, width / 2.5 + z);						// window vertex5

	Vertex v16(length * 1.2 + x, height / 5 + y, -width / 8 + z);		// window vertex6
	Vertex v17(-length * 1.2 + x, height / 5 + y, -width / 8 + z);		// window vertex7
	Vertex v18(-length * 1.5 + x, height / 5 + y, -width / 2.5 + z);	// window vertex8
	Vertex v19(length * 1.5 + x, height / 5 + y, -width / 2.5 + z);		// window vertex9

	Vertex v20(x, height / 1.5 + y, width / 8 + z);						// window vertex10

	// back wings
	Vertex v21(length / 2 + x, height / 5 + y, -width / 2.5 + z);		// back wings vertex
	Vertex v22(length / 2 + x, height / 5 + y, -width / 5.5 + z);		// back wings vertex2
	Vertex v23(length / 1.5 + x, height / 5 + y, -width / 2.5 + z);		// back wings vertex3
	Vertex v24(length / 1.5 + x, height / 5 + y, -width / 5.5 + z);		// back wings vertex4

	Vertex v25(length * 1.5 + x, height * 1.3 + y, -width / 1.6 + z);	// back wings vertex5
	Vertex v26(length * 1.5 + x, height * 1.3 + y, -width / 1.8 + z);	// back wings vertex6

	Vertex v27(-length / 2 + x, height / 5 + y, -width / 2.5 + z);		// back wings vertex7
	Vertex v28(-length / 2 + x, height / 5 + y, -width / 5.5 + z);		// back wings vertex8
	Vertex v29(-length / 1.5 + x, height / 5 + y, -width / 2.5 + z);	// back wings vertex9
	Vertex v30(-length / 1.5 + x, height / 5 + y, -width / 5.5 + z);	// back wings vertex10

	Vertex v31(-length * 1.5 + x, height * 1.3 + y, -width / 1.6 + z);	// back wings vertex11
	Vertex v32(-length * 1.5 + x, height * 1.3 + y, -width / 1.8 + z);	// back wings vertex12

	// engine
	Vertex v33(length / 2 + x, height / 5 + y, -width / 3.5 + z);		// engine vertex
	Vertex v34(length / 2 + x, height / 5 + y, -width / 25 + z);		// engine vertex2
	Vertex v35(length * 2 + x, height / 5 + y, -width / 3.5 + z);		// engine vertex3
	Vertex v36(length * 2 + x, height / 5 + y, -width / 25 + z);		// engine vertex4

	Vertex v37(length * 1.3 + x, -height / 2.5 + y, -width / 6.5 + z);	// engine vertex5
	Vertex v38(length * 1.3 + x, -height / 2.5 + y, -width / 2.3 + z); 	// engine vertex6

	Vertex v39(-length / 2 + x, height / 5 + y, -width / 3.5 + z);		// engine vertex7
	Vertex v40(-length / 2 + x, height / 5 + y, -width / 25 + z);		// engine vertex8
	Vertex v41(-length * 2 + x, height / 5 + y, -width / 3.5 + z);		// engine vertex9
	Vertex v42(-length * 2 + x, height / 5 + y, -width / 25 + z);		// engine vertex10

	Vertex v43(-length * 1.3 + x, -height / 2.5 + y, -width / 6.5 + z);	// engine vertex11
	Vertex v44(-length * 1.3 + x, -height / 2.5 + y, -width / 2.3 + z);	// engine vertex12

	// artillery
	Vertex v45(length * 1.65 + x, height / 1.6 + y, width / 25 + z);		// artillery vertex
	Vertex v46(length * 1.65 + x, height / 1.6 + y, -width / 5 + z);		// artillery vertex2
	Vertex v47(length * 1.35 + x, height / 1.6 + y, width / 25 + z);		// artillery vertex3
	Vertex v48(length * 1.35 + x, height / 1.6 + y, -width / 5 + z);		// artillery vertex4

	Vertex v49(length * 1.8 + x, height / 8 + y, width / 12 + z);			// artillery vertex5
	Vertex v50(length * 1.8 + x, height / 8 + y, -width / 3.5 + z);		// artillery vertex6
	Vertex v51(length * 1 + x, height / 8 + y, width / 12 + z);			// artillery vertex7
	Vertex v52(length * 1 + x, height / 8 + y, -width / 3.5 + z);			// artillery vertex8

	Vertex v53(-length * 1.65 + x, height / 1.6 + y, width / 25 + z);		// artillery vertex9
	Vertex v54(-length * 1.65 + x, height / 1.6 + y, -width / 5 + z);		// artillery vertex10
	Vertex v55(-length * 1.35 + x, height / 1.6 + y, width / 25 + z);		// artillery vertex11
	Vertex v56(-length * 1.35 + x, height / 1.6 + y, -width / 5 + z);		// artillery vertex12

	Vertex v57(-length * 1.8 + x, height / 8 + y, width / 12 + z);			// artillery vertex13
	Vertex v58(-length * 1.8 + x, height / 8 + y, -width / 3.5 + z);		// artillery vertex14
	Vertex v59(-length * 1 + x, height / 8 + y, width / 12 + z);			// artillery vertex15
	Vertex v60(-length * 1 + x, height / 8 + y, -width / 3.5 + z);			// artillery vertex16


	// draw wings
	glColor3d(red * 0.85, green * 0.85, blue * 0.85);
	drawRectangle(v4, v5, v8, v1);		// wings face
	drawRectangle(v3, v6, v9, v1);		// wings face2
	glColor3d(red * 0.75, green * 0.75, blue * 0.75);
	drawRectangle(v3, v1, v1, v7);		// wings face3
	glColor3d(red * 0.7, green * 0.7, blue * 0.7);
	drawRectangle(v4, v1, v1, v7);		// wings face4
	glColor3d(red * 0.8, green * 0.8, blue * 0.8);
	drawRectangle(v8, v1, v9, v2);		// wings face5
	glColor3d(red * 0.65, green * 0.65, blue * 0.65);
	drawRectangle(v3, v10, v10, v7);	// wings face6
	drawRectangle(v4, v10, v10, v7);	// wings face7
	glColor3d(red * 0.6, green * 0.6, blue * 0.6);
	drawRectangle(v8, v10, v10, v4);	// wings face8
	drawRectangle(v10, v5, v8, v4);		// wings face9
	drawRectangle(v9, v10, v10, v3);	// wings face8
	drawRectangle(v10, v6, v9, v3);		// wings face9
	glColor3d(red * 0.55, green * 0.55, blue * 0.55);
	drawRectangle(v5, v10, v10, v2);	// wings face10
	drawRectangle(v6, v10, v10, v2);	// wings face11
	glColor3d(red * 0.75, green * 0.75, blue * 0.75);
	drawRectangle(v5, v61, v61, v2);	// wings face12
	drawRectangle(v6, v62, v62, v2);	// wings face13



	// window
	glColor3d(0.23, 0.23, 0.23);
	drawRectangle(v11, v16, v15, v15);		// window face
	drawRectangle(v12, v17, v15, v15);		// window face2

	drawRectangle(v12, v13, v18, v17);		// window face3
	drawRectangle(v13, v14, v19, v18);		// window face4

	drawRectangle(v11, v14, v19, v16);		// window face5

	glColor3d(0.25, 0.25, 0.25);
	drawRectangle(v11, v20, v15, v15);		// window face6
	drawRectangle(v12, v20, v15, v15);		// window face7
	glColor3d(0.28, 0.28, 0.28);
	drawRectangle(v11, v20, v20, v14);		// window face8
	drawRectangle(v12, v20, v20, v13);		// window face9
	glColor3d(0.32, 0.32, 0.32);
	drawRectangle(v13, v20, v20, v14);		// window face10

	// back wings
	glColor3d(red * 0.55, green *  0.55, blue *  0.55);
	drawRectangle(v21, v22, v26, v25);		// back wings face
	drawRectangle(v23, v24, v26, v25);		// back wings face2
	drawRectangle(v24, v26, v26, v22);		// back wings face3
	drawRectangle(v23, v25, v25, v21);		// back wings face3

	drawRectangle(v27, v28, v32, v31);		// back wings face4
	drawRectangle(v29, v30, v32, v31);		// back wings face5
	drawRectangle(v30, v32, v32, v28);		// back wings face6
	drawRectangle(v29, v31, v31, v27);		// back wings face7

	// engine
	glColor3d(red * 0.65, green *  0.65, blue *  0.65);
	drawRectangle(v33, v34, v37, v38);		// engine face
	drawRectangle(v35, v36, v37, v38);		// engine face2
	glColor3d(red * 0.45, green *  0.45, blue *  0.45);
	drawRectangle(v36, v37, v37, v34);		// engine face3
	drawRectangle(v35, v38, v38, v33);		// engine face3

	glColor3d(red * 0.65, green *  0.65, blue *  0.65);
	drawRectangle(v39, v40, v43, v44);		// engine face
	drawRectangle(v41, v42, v43, v44);		// engine face2
	glColor3d(red * 0.45, green *  0.45, blue *  0.45);
	drawRectangle(v42, v43, v43, v40);		// engine face3
	drawRectangle(v41, v44, v44, v39);		// engine face3

	// draw artillery
	glColor3d(0.2, 0.2, 0.2);
	drawRectangle(v45, v46, v48, v47);		// artillery face
	glColor3d(0.15, 0.15, 0.15);
	drawRectangle(v45, v46, v50, v49);		// artillery face2
	drawRectangle(v46, v48, v52, v50);		// artillery face3
	drawRectangle(v48, v47, v51, v52);		// artillery face4
	glColor3d(0.1, 0.1, 0.1);
	drawRectangle(v47, v45, v49, v51);		// artillery face5

	glColor3d(0.2, 0.2, 0.2);
	drawRectangle(v53, v54, v56, v55);		// artillery face6
	glColor3d(0.15, 0.15, 0.15);
	drawRectangle(v53, v54, v58, v57);		// artillery face7
	drawRectangle(v54, v56, v60, v58);		// artillery face8
	drawRectangle(v56, v55, v59, v60);		// artillery face9
	glColor3d(0.1, 0.1, 0.1);
	drawRectangle(v55, v53, v57, v59);		// artillery face10

}

// draw text
void textDisplay(GLint posx, GLint posy, char scorevar)
{
	glRasterPos2i(posx, posy);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorevar);
}

// draw number text
void textDisplay(GLint posx, GLint posy, GLint scorevar)
{
	glRasterPos2i(posx, posy);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorevar + '0');
}