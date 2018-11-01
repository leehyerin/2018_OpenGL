//#include <GL/freeglut.h>
//#include "Myheader.h"
//
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//void Mouse(int, int, int, int);
//void Motion(int, int);
//void SpecialKeyboard(int, int, int);
//void TimerFunction(int);
////-----------------------------
//void DrawRectangle(float, float);
//void DrawTriangle(float, float);
//
//void CheckCorner(Point2D*);
//
//vector<Point2D> v;
//vector<Point2D>::iterator iter;
//ShapeType st = RECTANGLE;
//
//bool left_button = false;
//
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ��� 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// ���÷��� ��� ���� 
//	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
//	glutCreateWindow("Q5"); 	// ������ ���� (������ �̸�) 
//	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
//	glutMouseFunc(Mouse);   //���콺 Ŭ��
//	glutMotionFunc(Motion); //���콺 ������
//	glutSpecialFunc(SpecialKeyboard); //Ư�� Ű�Է� 
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
//	//--------------------------------------------------------
//	srand((unsigned int)time(NULL));
//	
//	for (iter = v.begin(); iter != v.end(); ++iter)
//	{
//		R = (rand() % 256) / MAX_COLOR;
//		G = (rand() % 256) / MAX_COLOR;
//		B = (rand() % 256) / MAX_COLOR;
//		
//		if ((iter->type) == RECTANGLE)
//			DrawRectangle((float)iter->x, (float)iter->y);
//		else
//			DrawTriangle((float)iter->x, (float)iter->y);
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
//			//�ʱ�ȭ
//			Point2D t{
//			x,
//			WINDOW_HEIGHT - y,
//			rand() % 10 + 1, //speed
//			1, //xdir
//			1, //ydir
//			t.type = st
//			};
//			//
//			v.push_back(t);		
//			if (v.size() == 11) v.erase(v.begin());
//		}
//	}
//
//}
//
//void Motion(int x, int y)
//{
//	if (left_button == true) {}
//}
//
//void SpecialKeyboard(int key, int x, int y)
//{
//	if (key == GLUT_KEY_UP)
//	{
//		for (iter = v.begin(); iter != v.end(); ++iter)
//			++(iter->speed);
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		for (iter = v.begin(); iter != v.end(); ++iter)
//			--(iter->speed);
//	}
//	else if (key == GLUT_KEY_LEFT)
//	{
//		st = TRIANGLE;
//	}
//	else if (key == GLUT_KEY_RIGHT)
//	{
//		st = RECTANGLE;
//	}
//}
//
//void TimerFunction(int value)
//{
//	//ũ�� ����
//	radius += radiusStatus;
//	if (!radius|| radius == MAX_RADIUS) radiusStatus *= MINUS;
//	//�ӵ� ����
//	for (iter = v.begin(); iter != v.end(); ++iter)
//	{
//		iter->x += (iter->speed)*(iter->xdir);
//		iter->y += (iter->speed)*(iter->ydir);
//	}
//	//�𼭸� �浹üũ
//	for (iter = v.begin(); iter != v.end(); ++iter)
//	{
//		CheckCorner(&(*iter));
//	}
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
//
//void DrawTriangle(float x, float y)
//{
//	glColor3f(1.f, 1.f, 1.f);
//	glBegin(GL_TRIANGLES);
//	//
//	glVertex2f(     x,  y + 50);   //    o
//	glVertex2f(x - 50, y - 50); 
//	glVertex2f(x + 50, y - 50); // ------
//	//
//	glEnd();
//}
//
//void CheckCorner(Point2D* p)
//{
//	if ((p->x - radius) <= 0)
//		p->xdir = 1;
//	if ((p->x + radius) >= WINDOW_WIDTH)
//		p->xdir = -1;
//	if ((p->y - radius) <= 0)
//		p->ydir = 1;
//	if ((p->y + radius )>= WINDOW_HEIGHT)
//		p->ydir = -1;
//}