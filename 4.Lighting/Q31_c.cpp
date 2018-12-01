#include "Q31.h"

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
	glutCreateWindow("Q31");
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


	if(bLight1)	glEnable(GL_LIGHT1);		else	glDisable(GL_LIGHT1);
	
	glEnable(GL_COLOR_MATERIAL); 
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLight);
	glMateriali(GL_FRONT, GL_SHININESS, 64);


	glutSolidSphere(5.0, 25, 25);


	glDisable(GL_COLOR_MATERIAL);

	glPushMatrix();
		glTranslated(light0Pos[0], light0Pos[1], light0Pos[2]);
		glRotated(-90, 1, 0, 0);
		glutSolidCone(1, 2, 10, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(light1Pos[0], light1Pos[1], light1Pos[2]);
		glRotated(-90, 1, 0, 0);
		glutSolidCone(1, 2, 10, 10);
	glPopMatrix();

	//
	glutSwapBuffers();
}




void TimerFunction(int value)
{
	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정

	if (bRotation)
		degree += dir * 0.1;
	
	tmpX = 20 * cos(degree);
	tmpZ = 20 * sin(degree);
	light0Pos[0] = tmpX;
	light0Pos[2] = tmpZ;
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);

	tmpX = 10 * cos(degree - 180);
	tmpZ = 10 * sin(degree - 180);
	light1Pos[0] = tmpX;
	light1Pos[2] = tmpZ;
	glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
}


