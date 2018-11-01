//#include <GL/freeglut.h>
//#include "Myheader.h"
//
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//void Mouse(int, int, int, int);
//void Motion(int, int);
//void SpecialKeyboard(int, int, int);
//void TimerFunction(int);
//-----------------------------
//void DrawRectangle(float, float);
//void DrawTriangle(float, float);
//
//void CheckCorner(Point2D*);
//
//vector<Point2D> v;
//vector<Point2D>::iterator iter;
//
//bool left_button = false;
//
//void main(int argc, char *argv[])
//{
//	초기화 함수들 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// 디스플레이 모드 설정 
//	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
//	glutCreateWindow("Q7"); 	// 윈도우 생성 (윈도우 이름) 
//	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
//	glutMouseFunc(Mouse);   //마우스 클릭
//	glutMotionFunc(Motion); //마우스 움직임
//	glutSpecialFunc(SpecialKeyboard); //특수 키입력 
//	glutTimerFunc(100, TimerFunction, 1); // 타이머 함수 설정 
//	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 
//	glutMainLoop();
//}
//
// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//								  --------------------------------------------------------
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
//	--------------------------------------------------------
//
//	glFlush(); // 화면에 출력하기
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
//		if (state == GLUT_UP) //클릭했다가 뗄 때
//		{
//			left_button = true;
//			초기화
//			Point2D t{
//				x,
//				WINDOW_HEIGHT - y,
//				rand() % 10 + 1, //speed
//				1, //xdir
//				1, //ydir
//				t.type = RECTANGLE
//			};
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
//}
//
//void TimerFunction(int value)
//{
//	크기 변경
//	radius += radiusStatus;
//	if (!radius || radius == MAX_RADIUS) radiusStatus *= MINUS;
//	속도 변경
//	for (iter = v.begin(); iter != v.end(); ++iter)
//	{
//		iter->x += (iter->speed)*(iter->xdir);
//		iter->y += (iter->speed)*(iter->ydir);
//	}
//	모서리 충돌체크
//	for (iter = v.begin(); iter != v.end(); ++iter)
//	{
//		CheckCorner(&(*iter));
//	}
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정
//}
//
//void DrawRectangle(float x, float y)
//{
//	glColor3f(R, G, B);
//	
//	glRectf(x - radius, y - radius, x + radius, y + radius);
//	
//}
//
//
//#include <GL/freeglut.h>
//#include "Myheader.h"
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//
//void Mouse(int, int, int, int);
//void TimerFunction(int);
//void DrawCircle(int, int, int);
//
//vector<Shape> circle;
//vector<Shape>::iterator iter;
//
//void main(int argc, char *argv[])
//{
//	초기화 함수들
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
//	glutInitWindowSize(800, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Q7"); // 윈도우 생성 (윈도우 이름)
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutMouseFunc(Mouse);
//	glutTimerFunc(100, TimerFunction, 1);
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutMainLoop();
//}
//
// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	for (iter = circle.begin(); iter != circle.end(); ++iter)
//	{
//		if (iter->rotate_dir == 0)
//		{
//			R = (rand() % 256) / 256.0f;
//			G = (rand() % 256) / 256.0f;
//			B = (rand() % 256) / 256.0f;
//		}
//		else
//		{
//			R = 1.f;
//			G = 1.0f;
//			B = 0.0f;
//		}
//
//		DrawCircle(iter->x, iter->y, iter->rad);
//	}
//
//	glFlush(); // 화면에 출력하기
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0, 800, 0, 600, -1, 1);
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	srand((unsigned int)time(NULL));
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		Shape s;
//
//		s.x = x;
//		s.y = 600 - y;
//		s.rad = rand() % 30 + 30;
//		s.SaveRad = s.rad;
//		s.rotate_dir = rand() % 2;
//
//		circle.push_back(s);
//
//		if (circle.size() == 6) circle.erase(circle.begin());
//	}
//}
//
//void TimerFunction(int value)
//{
//	srand((unsigned int)time(NULL));
//
//	for (iter = circle.begin(); iter != circle.end(); ++iter)
//	{
//		iter->rad += 10;
//
//		if (iter->rotate_dir != 0 && iter->rad >= 150)
//		{
//			iter->rad = iter->SaveRad;
//		}
//	}
//
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}
//
//void DrawCircle(int x, int y, int rad)
//{
//	glColor3f(R, G, B);
//
//	glBegin(GL_POINTS);
//
//	for (int i = 0; i < 360; i++)
//	{
//		double angle = i * PI / 30;
//		double tmpX = rad * cos(angle) + x;
//		double tmpY = rad * sin(angle) + y;
//		glVertex2f(tmpX, tmpY);
//	}
//
//	glEnd();
//}