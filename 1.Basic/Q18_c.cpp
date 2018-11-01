//#include <GL/freeglut.h>
//#include "Myheader.h"
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//void Keyboard(unsigned char, int, int);
//void TimerFunction(int);
////-----------------------------
//void DrawShape();
//void DrawSolidShape();
//void SetupRC();
//void RotateAxis();
//void RotateLeft();
//void RotateRight();
//void CameraReset();
//
//GLUquadricObj *qobj;
//int type;
//bool isForward;
//double DegreeForAxisX, DegreeForAxisY, DegreeForAxisZ;
//double DegreeForLeft, DegreeForRight;
//double zoom, DegreeForCameraY;
//
//int main(int argc, char *argv[])
//{
//	//초기화 함수들 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  // 더블 버퍼링과 3차원으로 그린다. 
//	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
//	glutCreateWindow("Q18"); 	// 윈도우 생성 (윈도우 이름) 
//	SetupRC();
//	// 필요한 콜백 함수 설정 
//	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
//	glutKeyboardFunc(Keyboard); //키입력 
//	glutTimerFunc(100, TimerFunction, 1); // 타이머 함수 설정 
//	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 
//	
//	glutMainLoop();
//}
//
////윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	//-----------좌표계----------------
//	glLoadIdentity();
//	RotateAxis();
//	glColor3f(0.f, 0.f, 1.f);
//	glPushMatrix();
//		glTranslated(0.0, 0.0, -1.5);
//		glScaled(0.5, 0.5, 3);
//		glutSolidCube(1.0);
//	glPopMatrix();
//
//	glColor3f(1.f, 0.f, 0.f);
//	glPushMatrix();
//		glTranslated(1.5, 0.0, 0.0);
//		glScaled(3, 0.5, 0.5);
//		glutSolidCube(1.0);
//	glPopMatrix();
//
//	glColor3f(0.f, 1.f, 0.f);
//	glPushMatrix();
//		glTranslated(0.0, 1.5, 0);
//		glScaled(0.5, 3, 0.5);
//		glutSolidCube(1.0);
//	glPopMatrix();
//
//	//-----------바닥 -------------
//	glLoadIdentity();
//	RotateAxis();
//	glColor3f(0.6, 0.4, 0.4);
//	glTranslated(0.0, -10.0, 0);
//	glScaled(1.0, 0.1, 1.0);
//	glutSolidCube(30.0);
//
//	//-----------객체---------------
//	glColor3f(1.f, 1.f, 1.f);
//	glLoadIdentity();
//	qobj = gluNewQuadric(); // 객체 생성하기
//	gluQuadricNormals(qobj, GLU_SMOOTH); // 생략 가능 
//	gluQuadricOrientation(qobj, GLU_OUTSIDE); // 생략 가능 
//	RotateAxis(); //전체 좌표계
//	glPushMatrix();
//		glScaled(3.f, 3.f, 3.f);
//		glPushMatrix();
//			glTranslated(-3, 0, 0);
//			RotateLeft();
//			DrawShape();
//		glPopMatrix();
//
//		glTranslated(3, 0, 0);
//		RotateRight();
//		DrawSolidShape();
//	glPopMatrix();
//	//--------------------------------
//
//	glutSwapBuffers();
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	CameraReset();
//}
//
//void SetupRC()
//{
//	type = CUBE;
//	zoom = -30;
//	DegreeForCameraY = 0;
//	isForward = true;
//}
//
//void RotateAxis()
//{
//	glRotated(DegreeForAxisX, 1.0, 0.0, 0.0);
//	glRotated(DegreeForAxisY, 0.0, 1.0, 0.0);
//	glRotated(DegreeForAxisZ, 0.0, 0.0, 1.0);
//}
//
//void RotateLeft()
//{
//	glRotated(DegreeForLeft, 0.0, 1.0, 0.0);
//}
//
//void RotateRight()
//{
//	glRotated(DegreeForRight, 0.0, 1.0, 0.0);
//}
//
//void CameraReset()
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);
//	glTranslated(0.0, 0.0, zoom);
//	glRotated(DegreeForCameraY, 0.0, 1.0, 0.0);
//	cout << zoom << endl;
//	if (zoom >= 0) {
//		zoom = -30;	isForward = !isForward;
//	}
//	if (!isForward)glRotated(180, 0.0, 1.0, 0.0);
//	else;
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'x':	--DegreeForAxisX; 		break;
//	case 'X':	++DegreeForAxisX; 		break;
//
//	case 'y':	--DegreeForAxisY;		break;
//	case 'Y':	++DegreeForAxisY;		break;
//
//	case 'z':	--DegreeForAxisZ;		break;
//	case 'Z':	++DegreeForAxisZ;		break;
//		
//	//카메라를 z축에 대해 줌인 / 줌아웃 한다
//	case 'i': case 'I':
//		zoom += 3;
//		CameraReset();
//		break;
//	case 'o': case 'O':
//		zoom -= 3;
//		CameraReset();
//		break;
//	case '+':
//		++DegreeForCameraY;
//		CameraReset();
//		break;
//	case '-':
//		--DegreeForCameraY;
//		CameraReset();
//		break;
//	case 'c':	case 'C':
//		type = rand() % 4;
//		break;
//	case '1':		type = CUBE;				break;
//	case '2':		type = CYLINDER;		break;
//	case '3':		type = TEAPOT;			break;
//	case '4':		type = SPHERE;			break;
//
//	case VK_ESCAPE: 	case 'Q':	case 'q':
//		::PostQuitMessage(0);
//		break;
//	default:
//		break;
//	}
//}
//
//void TimerFunction(int value)
//{
//	++DegreeForLeft;
//	++DegreeForRight;
//
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정
//}
//
//void DrawShape()
//{
//	gluQuadricDrawStyle(qobj, GLU_LINE);
//
//	switch (type)
//	{
//	case CUBE:
//		glutWireCube(1.0);
//		break;
//	case CYLINDER:
//		gluCylinder(qobj, 1.0, 0.0, 2.0, 20, 8);
//		break;
//	case TEAPOT:
//		glutWireTeapot(1.0);
//		break;
//	case SPHERE:
//		gluSphere(qobj, 1.5, 30, 10);
//		break;
//	default:
//		break;
//	}
//}
//
//void DrawSolidShape()
//{
//	gluQuadricDrawStyle(qobj, GLU_FILL);
//
//	switch (type)
//	{
//	case CUBE:
//		glutSolidCube(1.0);
//		break;
//	case CYLINDER:
//		gluCylinder(qobj, 1.0, 0.0, 2.0, 20, 8);
//		break;
//	case TEAPOT:
//		glutSolidTeapot(1.0);
//		break;
//	case SPHERE:
//		gluSphere(qobj, 1.5, 30, 10);
//		break;
//	default:
//		break;
//	}
//}