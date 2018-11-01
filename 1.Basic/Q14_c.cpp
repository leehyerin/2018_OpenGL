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
////#실습 14
////이동, 회전, 신축하기
////
////- 화면에 마우스를 클릭하면 그 자리에 임의의 도형이 그려진다.
////*glut 라이브러리에서 지원하는 3차원 객체를 그려본다.
////*다른 색, 다른 크기로 그린다.
////- 그 도형이 임의의 축에 대하여 회전하며 점점 작아진다.
////*크기가 0이 되면 삭제된다.
////- 다른 곳을 클릭하면 또 다른 도형이 그려지고 회전하며 점점 작아진다.
////- 특정 키보드를 누르면 도형들이 반대 방향으로 회전한다.
////- 종료 명령을 입력할 때까지 계속된다.
////* 최대 20개까지 그리도록 한다.
//
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
//	glutCreateWindow("Q14"); 	// 윈도우 생성 (윈도우 이름) 
//	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
//	glutMouseFunc(Mouse);			//마우스입력
//	glutKeyboardFunc(Keyboard); //키입력 
//	glutTimerFunc(100, TimerFunction, 1); // 타이머 함수 설정 
//	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 
//	glutMainLoop();
//}
//
// //윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
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
//			rand() % 2,		rand() % 2,		rand() % 2,  //회전축
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
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc (100, TimerFunction, 1); // 타이머함수 재 설정
//}
