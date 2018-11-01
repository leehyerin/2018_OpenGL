//#include <GL/freeglut.h>
//#include "Myheader.h"
//
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//void Mouse(int, int, int, int);
//void Motion(int, int);
//void TimerFunction(int);
////-----------------------------
//void DrawRectangle(float, float);
//
//vector<Point2D> v;
//bool left_button = false;
//
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ��� 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// ���÷��� ��� ���� 
//	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
//	glutCreateWindow("Q4"); 	// ������ ���� (������ �̸�) 
//	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
//	glutMouseFunc(Mouse);   //���콺 Ŭ��
//	glutMotionFunc(Motion); //���콺 ������
//	glutTimerFunc(100, TimerFunction, 1); // Ÿ�̸� �Լ� ���� 
//	glutReshapeFunc(Reshape);	// �ٽ� �׸��� �Լ��� ���� 
//	glutMainLoop();
//}
//
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//
//	//--------------------------------------------------------
//	srand((unsigned int)time(NULL));
//	
//	vector<Point2D>::iterator iter;
//	for (iter = v.begin(); iter != v.end(); ++iter)
//	{
//
//		R = (rand() % 256) / MAX_COLOR;
//		G = (rand() % 256) / MAX_COLOR;
//		B = (rand() % 256) / MAX_COLOR;
//		DrawRectangle((float)iter->x, (float)iter->y);
//	}
//	//--------------------------------------------------------
//
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -1.0, 1.0);
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//	{			
//		if (state == GLUT_UP) //Ŭ���ߴٰ� �� ��
//		{
//			left_button = true;
//
//			Point2D t;
//			t.x = x;
//			t.y = WINDOW_HEIGHT - y;
//
//			v.push_back(t);		
//			if (v.size() == 11) v.erase(v.begin());
//		}
//	}
//}
//
//void Motion(int x, int y)
//{
//	if (left_button == true) {}
//}
//
//void TimerFunction(int value)
//{
//	radius += dir;
//	if (!radius|| radius == MAX_RADIUS) dir *= -1;
//	
//
//	
//	
//	glutPostRedisplay(); // ȭ�� �� ���
//	glutTimerFunc (100, TimerFunction, 1); // Ÿ�̸��Լ� �� ����
//}
//
//void DrawRectangle(float x, float y)
//{
//	glColor3f(R, G, B);
//	//
//	glRectf(x - radius, y - radius, x + radius, y + radius);
//	//
//}