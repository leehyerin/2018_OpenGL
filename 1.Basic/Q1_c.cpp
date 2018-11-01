//#include <GL/freeglut.h>
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//
//void main(int argc, char *argv[]) 
//{ 
//	//초기화 함수들 
//	glutInit (&argc, argv); 
//	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGBA );// 디스플레이 모드 설정 
//	glutInitWindowPosition ( 100, 100 ); 	// 윈도우의 위치지정 
//	glutInitWindowSize ( 800, 600 ); 	// 윈도우의 크기 지정 
//	glutCreateWindow ( "Q1" ); 	// 윈도우 생성 (윈도우 이름) 
//	glutDisplayFunc ( drawScene );	// 출력 함수의 지정 
//	glutReshapeFunc (Reshape);	// 다시 그리기 함수의 지정 
//	glutMainLoop (); 
//} 
//
//// 윈도우 출력 함수 
//GLvoid drawScene( GLvoid ) 
//{ 
//	glClearColor (0.0f, 0.0f, 1.0f, 1.0f); 
//	// 바탕색을 'blue' 로 지정 
//	glClear ( GL_COLOR_BUFFER_BIT ); 
//	// 설정된 색으로 전체를 칠하기
//	
//	glColor3f(1.f, 0.f, 0.f);
//	glRectf(-400, 250, -350, 300);
//	
//	glColor3f(0.f, 1.f, 0.f);
//	glRectf(350, 250, 400, 300);
//
//	glColor3f(1.f, 0.f, 1.f);
//	glRectf(-400, -300, -350, -250);
//
//	glColor3f(1.f, 1.f, 0.f);
//	glRectf(350, -300, 400, -250);
//	
//	//삼각형
//	glColor3f(1.f, 1.f, 1.f);
//	glBegin(GL_POLYGON);
//	glVertex2i(-40, -40);//v1 
//	glVertex2i (40, -40);		//v2
//	glVertex2i (0, 80);	//v3 
//	glEnd ();
//
//	//선
//	glColor3f(1.f, 1.f, 1.f);
//	glBegin(GL_LINES);
//	glVertex2i(-400, 0);
//	glVertex2i(400, 0);
//	glVertex2i(0, -300);
//	glVertex2i(0, 300);
//	glEnd();
//
//
//
//	glFlush(); // 화면에 출력하기
//}
//
//GLvoid Reshape(int w, int h) 
//{ 
//	glViewport(0, 0, w, h); 
//	glOrtho(-400.0, 400.0, -300.0, 300.0, -1.0, 1.0);
//
//}
//
