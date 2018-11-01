//#include <GL/freeglut.h>
//#include "Myheader.h"
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//
//void MouseClick(int, int, int, int);
//void Keyboard(unsigned char, int, int);
//void TimerFunction(int);
//void DrawCircle(int, int, int, int, int, double, double);
//
//vector<Shape> circle;
//vector<Shape>::iterator iter;
//
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ���
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 100); // �������� ��ġ����
//	glutInitWindowSize(800, 600); // �������� ũ�� ����
//	glutCreateWindow("Q8"); // ������ ���� (������ �̸�)
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutMouseFunc(MouseClick);
//	glutKeyboardFunc(Keyboard); //Ű�Է� 
//	glutTimerFunc(100, TimerFunction, 1);
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutMainLoop();
//}
//
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//	for (iter = circle.begin(); iter != circle.end(); ++iter)
//	{
//		DrawCircle(iter->x, iter->y, iter->rad, iter->degree, iter->rotate_dir, iter->tmpX, iter->tmpY);
//	}
//
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0, 800, 0, 600, -1, 1);
//}
//
//void MouseClick(int button, int state, int x, int y)
//{
//	srand((unsigned int)time(NULL));
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		Shape s;
//
//		s.x = x;
//		s.y = 600 - y;
//		s.rad = 5;
//		s.SaveRad = s.rad;
//		s.rotate_dir = rand() % 2;
//		s.degree = 0;
//		s.dir = 1;
//		s.tmpX = 0;
//		s.tmpY = 0;
//
//		circle.push_back(s);
//
//		if (circle.size() == 11) circle.erase(circle.begin());
//	}
//}
//
//void Keyboard(unsigned char key, int x, int y) 
//{ 
//	switch (key)
//	{
//	case VK_ESCAPE:
//		::PostQuitMessage(0);
//		break;
//	default:
//		break;
//	}
//}
//
//void TimerFunction(int value)
//{
//	srand((unsigned int)time(NULL));
//
//	for (iter = circle.begin(); iter != circle.end(); ++iter)
//	{
//		if (iter->degree == 120)		iter->dir = -1;
//		else if (iter->degree == 0)	iter->dir = +1;
//	
//		iter->degree += iter->dir * 1;
//	}
//
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}
//
//void DrawCircle(int x, int y, int rad, int degree, int rotate_dir, double tmpX, double tmpY)
//{
//	double angle;
//		
//	glColor3f(R, G, B);
//
//	glBegin(GL_POINTS);
//	glPointSize(5.f);
//
//	for (int i = 0; i < degree; ++i)
//	{
//		angle = (i * PI) / 10;
//		if (rotate_dir == REVERSE) angle *= -1;
//
//			if (i <= 60)
//			{
//				tmpX = (rad + i / 2) * cos(angle) + x;
//				tmpY = (rad + i / 2) * sin(angle) + y;
//			}
//			else
//			{
//				tmpX = (rad - (140 - i) / 2) * cos(-angle) + x + 70;
//				tmpY = (rad - (140 - i) / 2) * sin(-angle) + y;
//			}
//		glVertex2f(tmpX, tmpY);
//	}
//
//	glEnd();
//}