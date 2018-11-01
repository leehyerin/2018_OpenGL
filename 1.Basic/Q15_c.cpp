//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <GL/freeglut.h>
//#include <time.h>
//#include <math.h>
//#include <iostream>
//#include <vector>
//#include <iterator>
//using namespace std;
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//void Keyboard(unsigned char, int, int);
//void TimerFunction(int);
//struct tm *t;
//time_t timer;
//int yRot = 0;
//float space = 0.0f;
//float blinkX = 0.0f, blinkY = 0.0f;
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ���
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 100); // �������� ��ġ����
//	glutInitWindowSize(800, 600); // �������� ũ�� ����
//	glutCreateWindow("Q15"); // ������ ���� (������ �̸�)
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutKeyboardFunc(Keyboard);
//	glutTimerFunc(100, TimerFunction, 1);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//	glutMainLoop();
//}
// //������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	timer = time(NULL);
//	t = localtime(&timer);
//	glRotatef(-30.0f, 1.0f, 1.0f, 0.0f);				// �� ���̰� ���� Ʋ��
//	glRotatef(yRot, 0.0f, 1.0f, 0.0f);				// y�� ȸ��
//													 //�ð� ���̾�
//	for (int i = 0; i < 6; ++i)
//	{
//		// 1
//		glPushMatrix();
//		glTranslatef(-0.9f + space, 0.4f, 0.0f);
//		glScalef(1.0f, 0.3f, 1.0f);
//		if ((i == 0 && (t->tm_hour / 10 != 1)) ||
//			(i == 1 && (t->tm_hour % 10 != 1 && t->tm_hour % 10 != 4)) ||
//			(i == 2 && (t->tm_min / 10 != 1 && t->tm_min / 10 != 4)) ||
//			(i == 3 && (t->tm_min % 10 != 1 && t->tm_min % 10 != 4)) ||
//			(i == 4 && (t->tm_sec / 10 != 1 && t->tm_sec / 10 != 4)) ||
//			(i == 5 && (t->tm_sec % 10 != 1 && t->tm_sec % 10 != 4)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//		{
//			glColor3f(0.7f, 0.7f, 0.7f);
//		}
//		glutWireCube(0.2f);
//		glPopMatrix();
//		// 2
//		glPushMatrix();
//		glTranslatef(-1.02f + space, 0.25f, 0.0f);
//		glScalef(0.3f, 1.0f, 1.0f);
//		if ((i == 0 && (t->tm_hour / 10 != 1)) ||
//			(i == 1 && (t->tm_hour % 10 != 1 && t->tm_hour % 10 != 2 && t->tm_hour % 10 != 3)) ||
//			(i == 2 && (t->tm_min / 10 != 1 && t->tm_min / 10 != 2 && t->tm_min / 10 != 3)) ||
//			(i == 3 && (t->tm_min % 10 != 1 && t->tm_min % 10 != 2 && t->tm_min % 10 != 3)) ||
//			(i == 4 && (t->tm_sec / 10 != 1 && t->tm_sec / 10 != 2 && t->tm_sec / 10 != 3)) ||
//			(i == 5 && (t->tm_sec % 10 != 1 && t->tm_sec % 10 != 2 && t->tm_sec % 10 != 3)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//			glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.2f);
//		glPopMatrix();
//		// 3
//		glPushMatrix();
//		glTranslatef(-0.78f + space, 0.25f, 0.0f);
//		glScalef(0.3f, 1.0f, 1.0f);
//		if ((i == 0) || (i == 1 && (t->tm_hour % 10 != 5 && t->tm_hour % 10 != 6)) || (i == 2 && (t->tm_min / 10 != 5)) ||
//			(i == 3 && (t->tm_min % 10 != 5 && t->tm_min % 10 != 6)) || (i == 4 && (t->tm_sec / 10 != 5)) || (i == 5 && (t->tm_sec % 10 != 5 && t->tm_sec % 10 != 6)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//			glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.2f);
//		glPopMatrix();
//		// 4
//		glPushMatrix();
//		glTranslatef(-0.9f + space, 0.1f, 0.0f);
//		glScalef(1.0f, 0.3f, 1.0f);
//		if ((i == 1 && (t->tm_hour % 10 != 1 && t->tm_hour % 10 != 7 && t->tm_hour % 10 != 0)) ||
//			(i == 2 && (t->tm_min / 10 != 1 && t->tm_min / 10 != 0)) ||
//			(i == 3 && (t->tm_min % 10 != 1 && t->tm_min % 10 != 7 && t->tm_min % 10 != 0)) ||
//			(i == 4 && (t->tm_sec / 10 != 1 && t->tm_sec / 10 != 0)) ||
//			(i == 5 && (t->tm_sec % 10 != 1 && t->tm_sec % 10 != 7 && t->tm_sec % 10 != 0)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//			glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.2f);
//		glPopMatrix();
//		 //5
//		glPushMatrix();
//		glTranslatef(-1.02f + space, -0.05f, 0.0f);
//		glScalef(0.3f, 1.0f, 1.0f);
//		if ((i == 0 && (t->tm_hour / 10 == 0)) ||
//			(i == 1 && (t->tm_hour % 10 == 2 || t->tm_hour % 10 == 6 || t->tm_hour % 10 == 8 || t->tm_hour % 10 == 0)) ||
//			(i == 2 && (t->tm_min / 10 == 0 || t->tm_min / 10 == 2)) ||
//			(i == 3 && (t->tm_min % 10 == 2 || t->tm_min % 10 == 6 || t->tm_min % 10 == 8 || t->tm_min % 10 == 0)) ||
//			(i == 4 && (t->tm_sec / 10 == 0 || t->tm_sec / 10 == 2)) ||
//			(i == 5 && (t->tm_sec % 10 == 2 || t->tm_sec % 10 == 6 || t->tm_sec % 10 == 8 || t->tm_sec % 10 == 0)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//			glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.2f);
//		glPopMatrix();
//		// 6
//		glPushMatrix();
//		glTranslatef(-0.78f + space, -0.05f, 0.0f);
//		glScalef(0.3f, 1.0f, 1.0f);
//		if ((i == 0) || (i == 1 && (t->tm_hour % 10 != 2)) || (i == 2 && (t->tm_min / 10 != 2)) ||
//			(i == 3 && (t->tm_min % 10 != 2)) || (i == 4 && (t->tm_sec / 10 != 2)) || (i == 5 && (t->tm_sec % 10 != 2)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//			glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.2f);
//		glPopMatrix();
//		// 7 
//		glPushMatrix();
//		glTranslatef(-0.9f + space, -0.2f, 0.0f);
//		glScalef(1.0f, 0.3f, 1.0f);
//		if ((i == 0 && (t->tm_hour / 10 != 1)) ||
//			(i == 1 && (t->tm_hour % 10 != 1 && t->tm_hour % 10 != 4 && t->tm_hour % 10 != 7)) ||
//			(i == 2 && (t->tm_min / 10 != 1 && t->tm_min / 10 != 4)) ||
//			(i == 3 && (t->tm_min % 10 != 1 && t->tm_min % 10 != 4 && t->tm_min % 10 != 7)) ||
//			(i == 4 && (t->tm_sec / 10 != 1 && t->tm_sec / 10 != 4)) ||
//			(i == 5 && (t->tm_sec % 10 != 1 && t->tm_sec % 10 != 4 && t->tm_sec % 10 != 7)))
//		{
//			glColor3f(1.f, 0.85f, 0.f);
//			glutSolidCube(0.2f);
//			glColor3f(0.0f, 0.0f, 0.0f);
//		}
//		else
//			glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.2f);
//		glPopMatrix();
//		if (i % 2 == 0) space += 0.35f;
//		else space += 0.4f;
//		if (i == 5) space = 0.0f;
//	}
//	// ������ ���̾�
//	for (int i = 0; i < 4; ++i)
//	{
//		if (i < 2) blinkX = -0.35f;
//		else blinkX = 0.4f;
//		if (i % 2 == 0) blinkY = 0.25f;
//		else blinkY = -0.05f;
//		glPushMatrix();
//		glTranslatef(blinkX, blinkY, 0.0f);
//		if (t->tm_sec % 2 == 0)
//		{
//			glColor3f(1.0f, 1.0f, 1.0f);
//			glutSolidCube(0.05f);
//		}
//		glColor3f(0.7f, 0.7f, 0.7f);
//		glutWireCube(0.05f);
//		glPopMatrix();
//	}
//	glutSwapBuffers();
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, 800.0, 0.0, 600.0, -400.0, 400.0);
//}
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case '1':
//		yRot++;
//		break;
//	case '2':
//		yRot--;
//		break;
//	case 'q': case 'Q':case VK_ESCAPE:
//		glutLeaveMainLoop();
//		break;
//	default:
//		break;
//	}
//}
//void TimerFunction(int value)
//{
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}