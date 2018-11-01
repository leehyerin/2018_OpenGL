//#include <GL/freeglut.h>
//#include "Myheader.h"
//
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//void Mouse(int button, int state, int x, int y);
//void Keyboard(unsigned char, int, int );
//void TimerFunction(int);
////-----------------------------
//
//int dir = 1;
//float degree = 0.f;
//
//vector<Shape3D> v;
//vector<Shape3D>::iterator iter;
//
////#�ǽ� 14
////�̵�, ȸ��, �����ϱ�
////
////- ȭ�鿡 ���콺�� Ŭ���ϸ� �� �ڸ��� ������ ������ �׷�����.
////*glut ���̺귯������ �����ϴ� 3���� ��ü�� �׷�����.
////*�ٸ� ��, �ٸ� ũ��� �׸���.
////- �� ������ ������ �࿡ ���Ͽ� ȸ���ϸ� ���� �۾�����.
////*ũ�Ⱑ 0�� �Ǹ� �����ȴ�.
////- �ٸ� ���� Ŭ���ϸ� �� �ٸ� ������ �׷����� ȸ���ϸ� ���� �۾�����.
////- Ư�� Ű���带 ������ �������� �ݴ� �������� ȸ���Ѵ�.
////- ���� ����� �Է��� ������ ��ӵȴ�.
////* �ִ� 20������ �׸����� �Ѵ�.
//
//
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ��� 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
//	glutCreateWindow("Q14"); 	// ������ ���� (������ �̸�) 
//	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
//	glutMouseFunc(Mouse);			//���콺�Է�
//	glutKeyboardFunc(Keyboard); //Ű�Է� 
//	glutTimerFunc(100, TimerFunction, 1); // Ÿ�̸� �Լ� ���� 
//	glutReshapeFunc(Reshape);	// �ٽ� �׸��� �Լ��� ���� 
//	glutMainLoop();
//}
//
// //������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//	glMatrixMode(GL_MODELVIEW);
//	
//
//	for (iter = v.begin(); iter != v.end(); )
//	{
//		glPushMatrix();
//			glLoadIdentity();
//			glColor3f(iter->r, iter->g, iter->b);
//			glTranslatef(iter->x, iter->y, 0.f);
//			glRotatef(degree, iter->axisX, iter->axisY, iter->axisZ);
//		
//			if (iter->shape_type == 0)				glutWireSphere(iter->scale, 10, 10);
//			else if (iter->shape_type == 1)		glutWireTorus(iter->scale*0.5, iter->scale, 5, 20);
//			else if (iter->shape_type == 2)		glutWireCube(iter->scale);
//			else if (iter->shape_type == 3)		glutWireTeapot(iter->scale);
//			
//		glPopMatrix();
//
//		iter->scale -= 0.01;
//		if (iter->scale <= 0)
//			iter = v.erase(iter);
//		else 
//			++iter;
//	}
//	glutSwapBuffers();
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -400.0, 400.0);
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		srand((unsigned int)time(NULL));
//		
//		Shape3D s{
//			RAND_COLOR,
//			RAND_COLOR,
//			RAND_COLOR,
//			(double)((rand()%5) + 1)/10,
//			(float)(x - WINDOW_WIDTH*0.5) / (WINDOW_WIDTH*0.5),
//			(float)(WINDOW_HEIGHT*0.5 - y) / (WINDOW_HEIGHT*0.5),
//			rand() % 2,		rand() % 2,		rand() % 2,  //ȸ����
//			rand() % 4 
//		};
//
//		v.push_back(s);
//		if (v.size() == 21) v.erase(v.begin());
//	}
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{ 
//	switch (key)
//	{
//	case 'r':
//		dir *= -1;
//		break;
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
//	if (dir < 0)			--degree;
//	else if (dir > 0) ++degree;
//
//	glutPostRedisplay(); // ȭ�� �� ���
//	glutTimerFunc (100, TimerFunction, 1); // Ÿ�̸��Լ� �� ����
//}
