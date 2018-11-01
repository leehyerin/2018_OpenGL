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
//	//초기화 함수들 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// 디스플레이 모드 설정 
//	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
//	glutCreateWindow("Q4"); 	// 윈도우 생성 (윈도우 이름) 
//	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
//	glutMouseFunc(Mouse);   //마우스 클릭
//	glutMotionFunc(Motion); //마우스 움직임
//	glutTimerFunc(100, TimerFunction, 1); // 타이머 함수 설정 
//	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 
//	glutMainLoop();
//}
//
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
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
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc (100, TimerFunction, 1); // 타이머함수 재 설정
//}
//
//void DrawRectangle(float x, float y)
//{
//	glColor3f(R, G, B);
//	//
//	glRectf(x - radius, y - radius, x + radius, y + radius);
//	//
//}