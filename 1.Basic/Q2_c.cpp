//#include <ctime>
//#include <GL/freeglut.h>
//#include <iostream>
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//
//int divide = 50;
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// 디스플레이 모드 설정 
//	glutInitWindowPosition(100, 100); 	// 윈도우의 위치지정 
//	glutInitWindowSize(600, 600); 	// 윈도우의 크기 지정 
//	glutCreateWindow("Q2"); 	// 윈도우 생성 (윈도우 이름) 
//	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
//	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 
//	glutMainLoop();
//}
//
// //윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	srand((unsigned int)time(NULL));
//
//	float r = rand() % 256;
//	float g = rand() % 256;
//	float b = rand() % 256;
//
//	divide = 5 * (rand() % 30 + 1);
//	
//	float distance = 600.f / (float)divide;
//
//	for (int i = 0; i < divide; ++i)
//	{
//		for (int k = divide; k > 0; --k)
//		{
//			glColor3f(
//				(r - (k-i) ) / 256.f, 
//				(g - i*3) / 256.f,
//				(b - k*2) / 256.f
//			);
//
//			glRectf(i * distance, k * distance, (i * distance) + distance, (k * distance) - distance);
//		}
//	}
//
//	glFlush(); // 화면에 출력하기
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, 600.0, 0.0, 600.0, -1.0, 1.0);
//}
