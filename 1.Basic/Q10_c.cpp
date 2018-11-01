//#include <gl\freeglut.h>
//#include <iostream>
//#include <list>
//#include <time.h>
//
//using namespace std;
//
//void drawScene(void);
//void reshape(int w, int h);
//void Mouse_Input(int button, int state, int x, int y);
//void Mouse_Motion(int x, int y);
//void Eraser(int value);
//
//struct fRect
//{
//	float left, top, right, bottom;
//};
//struct fPoint
//{
//	float x, y;
//};
//
//typedef struct Move_Rect
//{
//	fRect tRect;
//	float RGB[3];
//	int iDir;
//	int iTransform;
//	int iTimer;
//}MOVERECT, *PMOVERECT;
//
//list<MOVERECT> g_MoveRectList;
//
//struct Mouse_Pos
//{
//	float x, y;
//};
//
//POINT Window_Pos = { 100,100 };
//POINT Window_Size = { 800,600 };
//
//bool bStart = true;
//bool bLeft_Button = false;
////bool bCreation = true;
//fRect fRect_Mouse;
//Mouse_Pos tMouse_Pos;
//
//void main(int argc, char** argv)
//{
//	srand((unsigned int)time(0));
//
//	glutInit(&argc, argv); // glut �ʱ�ȭ
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
//	glutInitWindowPosition(Window_Pos.x, Window_Pos.y); // ������ ��ġ ���� - ���� ��� �𼭸� ��ġ ����
//	glutInitWindowSize(Window_Size.x, Window_Size.y); // ������ ��ġ ���� - ��ġ ��ȯ
//	glutCreateWindow("Q10");// ������ ���� �� glutDestroyWindow(int Win); - ������ �ı�
//	glutDisplayFunc(drawScene);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(Mouse_Input);
//	glutMotionFunc(Mouse_Motion);
//	glutTimerFunc(10, Eraser, 1);
//	glutMainLoop(); // GLUT �̺�Ʈ ���μ��� ���� ����
//}
//
//void drawScene(void)
//{
//	list<MOVERECT>::iterator iter;
//	list<MOVERECT>::iterator iterEnd = g_MoveRectList.end();
//
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ������
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü ĥ�ϱ�
//	
//	float size = 30;
//
//	if (bStart)
//	{
//		for (int i = 0; i <30; ++i)
//		{
//			MOVERECT Move_Rect;
//
//			Move_Rect.tRect.left = (float)(rand() % Window_Size.x - 100) + 50.f;
//			Move_Rect.tRect.top = (float)(rand() % Window_Size.y - 100) + 50.f;
//			Move_Rect.tRect.right = Move_Rect.tRect.left + 30;
//			Move_Rect.tRect.bottom = Move_Rect.tRect.top + 30;
//			Move_Rect.iDir = rand() % 4;
//			Move_Rect.iTransform = 0;
//			Move_Rect.iTimer = 0;
//			for (float& d : Move_Rect.RGB)
//				d = 1.f / 255.f * (rand() % 255);
//
//			g_MoveRectList.push_back(Move_Rect);
//		}
//		bStart = false;
//	}
//	for (iter = g_MoveRectList.begin(); iter != iterEnd; ++iter)
//	{
//		glColor3f((*iter).RGB[0], (*iter).RGB[1], (*iter).RGB[2]);
//
//		if ((*iter).iTransform == 0)
//		{
//			glRectf((*iter).tRect.left, (*iter).tRect.top, (*iter).tRect.right, (*iter).tRect.bottom);
//		}
//		else if ((*iter).iTransform == 1)  //��ٸ���
//		{
//			glBegin(GL_POLYGON);
//			glVertex2f((*iter).tRect.left - 10.f , (*iter).tRect.top + size);
//			glVertex2f((*iter).tRect.left , (*iter).tRect.bottom - size);
//			glVertex2f((*iter).tRect.right + size, (*iter).tRect.bottom - size);
//			glVertex2f((*iter).tRect.right + 10.f + size, (*iter).tRect.top + size);
//			glEnd();
//		}
//		else if ((*iter).iTransform == 2)
//		{
//			glBegin(GL_TRIANGLES);
//			glVertex2f(((*iter).tRect.right + (*iter).tRect.left) / 2, (*iter).tRect.bottom);
//			glVertex2f((*iter).tRect.left, (*iter).tRect.top);
//			glVertex2f((*iter).tRect.right, (*iter).tRect.top);
//			glEnd();
//		}
//	}
//	if (bLeft_Button)
//	{
//		glColor3f(1.f, 1.f, 1.f);
//		glRectf(fRect_Mouse.left, fRect_Mouse.top, fRect_Mouse.right, fRect_Mouse.bottom);
//	}
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	gluOrtho2D(0.0, (double)w, 0.0, (double)h);
//}
//
//void Mouse_Input(int button, int state, int x, int y)
//{
//	y = Window_Size.y - y;
//	float size = 30;
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		tMouse_Pos.x = (float)x;
//		tMouse_Pos.y = (float)y;
//		fRect_Mouse.left = (float)(x - size);
//		fRect_Mouse.top = (float)(y + size);
//		fRect_Mouse.right = (float)(x + size);
//		fRect_Mouse.bottom = (float)(y - size);
//		bLeft_Button = true;
//	}
//	else
//		bLeft_Button = false;
//}
//
//void Mouse_Motion(int x, int y)
//{
//	y = Window_Size.y - y;
//
//	if (bLeft_Button)
//	{
//		tMouse_Pos.x = (float)x;
//		tMouse_Pos.y = (float)y;
//		fRect_Mouse.left = (float)(x - 30.f);
//		fRect_Mouse.top = (float)(y + 30.f);
//		fRect_Mouse.right = (float)(x + 30.f);
//		fRect_Mouse.bottom = (float)(y - 30.f);
//	}
//}
//
//void Eraser(int value)
//{
//	list<MOVERECT>::iterator iter;
//	list<MOVERECT>::iterator iterend = g_MoveRectList.end();
//
//	if (bLeft_Button)
//	{
//		fRect_Mouse.left = (float)(tMouse_Pos.x - 30.f);
//		fRect_Mouse.top = (float)(tMouse_Pos.y + 30.f);
//		fRect_Mouse.right = (float)(tMouse_Pos.x + 30.f);
//		fRect_Mouse.bottom = (float)(tMouse_Pos.y - 30.f);
//		for (iter = g_MoveRectList.begin(); iter != iterend;)
//		{
//			if ((fRect_Mouse.left < (*iter).tRect.right) && (fRect_Mouse.top >(*iter).tRect.bottom) &&
//				(fRect_Mouse.right >(*iter).tRect.left) && (fRect_Mouse.bottom < (*iter).tRect.top))
//			{
//				if ((*iter).iTransform == 0)
//				{
//					for (float& d : (*iter).RGB)
//						d = 1.f / 255.f * (rand() % 255);
//					(*iter).iTransform = 1;
//				}
//			}
//			++iter;
//		}
//	}
//	for (iter = g_MoveRectList.begin(); iter != iterend;)
//	{
//		if ((*iter).iTransform == 1)
//		{
//			if ((*iter).iTimer == 100)
//			{
//				(*iter).iTimer = 0;
//				(*iter).iTransform = 2;
//			}
//			else
//				++(*iter).iTimer;
//		}
//		if ((*iter).iTransform == 2)
//		{
//			if ((*iter).iTimer == 1000)
//			{
//				(*iter).iTimer = 0;
//				(*iter).iTransform = 0;
//			}
//			else
//				++(*iter).iTimer;
//		}
//		++iter;
//	}
//
//	for (iter = g_MoveRectList.begin(); iter != iterend;)
//	{
//		switch ((*iter).iDir)
//		{
//		case 0: // ��
//			(*iter).tRect.left += 1.f;
//			(*iter).tRect.top += 1.f;
//			(*iter).tRect.right += 1.f;
//			(*iter).tRect.bottom += 1.f;
//			if ((*iter).tRect.right > Window_Size.x) // �����ʿ� �ε����� ���
//				(*iter).iDir = 1;
//			else if ((*iter).tRect.top > Window_Size.y) // ���ʿ� �ε����� ���
//				(*iter).iDir = 3;
//			break;
//		case 1: // ��
//			(*iter).tRect.left -= 1.f;
//			(*iter).tRect.top += 1.f;
//			(*iter).tRect.right -= 1.f;
//			(*iter).tRect.bottom += 1.f;
//			if ((*iter).tRect.left < 0) // ���ʿ� �ε����� ���
//				(*iter).iDir = 0;
//			else if ((*iter).tRect.top > Window_Size.y) // ���ʿ� �ε����� ���
//				(*iter).iDir = 2;
//			break;
//		case 2: // ��
//			(*iter).tRect.left -= 1.f;
//			(*iter).tRect.top -= 1.f;
//			(*iter).tRect.right -= 1.f;
//			(*iter).tRect.bottom -= 1.f;
//			if ((*iter).tRect.left < 0) // ���ʿ� �ε����� ���
//				(*iter).iDir = 3;
//			else if ((*iter).tRect.bottom < 0) // ���ʿ� �ε����� ���
//				(*iter).iDir = 1;
//			break;
//		case 3: // ��
//			(*iter).tRect.left += 1.f;
//			(*iter).tRect.top -= 1.f;
//			(*iter).tRect.right += 1.f;
//			(*iter).tRect.bottom -= 1.f;
//			if ((*iter).tRect.bottom < 0) // ���ʿ� �ε����� ���
//				(*iter).iDir = 0;
//			else if ((*iter).tRect.right > Window_Size.x) // �����ʿ� �ε����� ��� 
//				(*iter).iDir = 2;
//			break;
//		}
//		++iter;
//	}
//	glutPostRedisplay();
//	glutTimerFunc(10, Eraser, 1);
//}
