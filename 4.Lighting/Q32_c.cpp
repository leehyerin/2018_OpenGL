#include "Q32.h"

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Initialization();
void Keyboard(unsigned char, int, int);


void TimerFunction(int);
void CameraReset();
//-----------------------------

int main(int argc, char *argv[])
{
	//초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Q32");
	Initialization();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);

	glutTimerFunc(100, TimerFunction, 1);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

//윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();

	glEnable(GL_LIGHTING);

	if (bLight0)	glEnable(GL_LIGHT0);	else	glDisable(GL_LIGHT0);

	if (bLight1)	glEnable(GL_LIGHT1);		else	glDisable(GL_LIGHT1);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLight);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	glEnable(GL_NORMALIZE);

	GLfloat A[3] = { 0,5,0 };
	GLfloat B[3] = { -5,0,0 };
	GLfloat C[3] = { 0,0,5 };
	GLfloat D[3] = { 5,0,0 };
	GLfloat E[3] = { 0,0,-5 };

	GLfloat* norm1 = Cross(Minus(B,C), Minus(B,A));
	GLfloat* norm2 = Cross(Minus(C,D), Minus(C,A));
	GLfloat* norm3 = Cross(Minus(D,E), Minus(D,A));
	GLfloat* norm4 = Cross(Minus(E,B), Minus(E,A));

	glBegin(GL_TRIANGLES);
	{	
		if (bNormal) glNormal3f(norm1[0], norm1[1], norm1[2]);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);

		if (bNormal) glNormal3f(norm2[0], norm2[1], norm2[2]);
		glVertex3fv(A);
		glVertex3fv(C);
		glVertex3fv(D);

		if (bNormal)glNormal3f(norm3[0], norm3[1], norm3[2]);
		glVertex3fv(A);
		glVertex3fv(D);
		glVertex3fv(E);

		if (bNormal) glNormal3f(norm4[0], norm4[1], norm4[2]);
		glVertex3fv(A);
		glVertex3fv(E);
		glVertex3fv(B);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
		glVertex3fv(E);
	}
	glEnd();

	//
	glPushMatrix();
	glTranslated(SpherePos[0], SpherePos[1], SpherePos[2]);
	glutSolidSphere(2.0, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(light0Pos[0], light0Pos[1], light0Pos[2]);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(2, 3, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(light1Pos[0], light1Pos[1], light1Pos[2]);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(2, 3, 10, 10);
	glPopMatrix();
	//-------------------------------

	glPushMatrix();
	glTranslated(-10, 0, -10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 0, 10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,0,-10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 0, 10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glutSwapBuffers();
}


void TimerFunction(int value)
{
	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정

	degree += dir * 0.1;

	tmpX = 20 * cos(degree);
	tmpZ = 20 * sin(degree);
	SpherePos[0] = tmpX;
	SpherePos[2] = tmpZ;


	tmpX = 20 * cos(degree) + SpherePos[0];
	tmpZ = 20 * sin(degree) + SpherePos[2];
	light0Pos[0] = tmpX;
	light0Pos[2] = tmpZ;
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);

	tmpX = 10 * cos(degree - 180) + SpherePos[0];
	tmpZ = 10 * sin(degree - 180) + SpherePos[2];
	light1Pos[0] = tmpX;
	light1Pos[2] = tmpZ;
	glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
}


