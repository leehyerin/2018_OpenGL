////#include <GL/freeglut.h>
////#include "Myheader.h"
////
////GLvoid Reshape(int, int);
////GLvoid drawScene(GLvoid);
////void Mouse(int, int, int, int);
////void Keyboard(unsigned char, int, int);
////void SpecialKeyboard(int, int, int);
////void TimerFunction(int);
//////-----------------------------
////void DrawRectangle(float, float);
////void KeyFunc(int);
////void CheckCorner(Point2D*);
////
////vector<Point2D> v;
////vector<Point2D>::iterator iter;
////ShapeType st = RECTANGLE;
////
////bool Ice = false;
////
////void main(int argc, char *argv[])
////{
////	//초기화 함수들 
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// 디스플레이 모드 설정 
////	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
////	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
////	glutCreateWindow("Q5"); 	// 윈도우 생성 (윈도우 이름) 
////	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
////	glutMouseFunc(Mouse);   //마우스 클릭
////	glutKeyboardFunc(Keyboard); //키입력 
////	glutSpecialFunc(SpecialKeyboard); //특수 키입력 
////	glutTimerFunc(100, TimerFunction, 1); // 타이머 함수 설정 
////	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 
////	glutMainLoop();
////}
////
////// 윈도우 출력 함수
////GLvoid drawScene(GLvoid)
////{
////	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
////	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
////
////	//--------------------------------------------------------
////	srand((unsigned int)time(NULL));
////	
////	for (iter = v.begin(); iter != v.end(); ++iter)
////	{
////		R = (rand() % 256) / MAX_COLOR;
////		G = (rand() % 256) / MAX_COLOR;
////		B = (rand() % 256) / MAX_COLOR;
////		
////		DrawRectangle((float)iter->x, (float)iter->y);
////	}
////	//--------------------------------------------------------
////
////	glFlush(); // 화면에 출력하기
////}
////
////GLvoid Reshape(int w, int h)
////{
////	glViewport(0, 0, w, h);
////	glOrtho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -1.0, 1.0);
////}
////
////void Mouse(int button, int state, int x, int y)
////{
////	if (button == GLUT_LEFT_BUTTON)
////	{			
////		if (state == GLUT_UP) //클릭했다가 뗄 때
////		{
////			//초기화
////			Point2D t{
////			x,
////			WINDOW_HEIGHT - y,
////			rand() % 10 + 1, //speed
////			1, //xdir
////			1, //ydir
////			st,
////			DEFAULT
////			};
////			//
////			v.push_back(t);		
////			if (v.size() == 10) v.erase(v.begin());
////		}
////	}
////}
////
////void Keyboard(unsigned char key, int x, int y) 
////{ 
////	switch (key)
////	{
////	case 's':
////	case 'S':
////		Ice = true;
////		break;
////	case 'p':
////	case 'P':
////		Ice = false;
////		break;
////	case VK_ESCAPE:
////		::PostQuitMessage(0);
////		break;
////	case '1':
////	case '2':
////	case '3':
////	case '4':
////	case '5':
////	case '6':
////	case '7':
////	case '8':
////	case '9':
////		KeyFunc(key);
////		cout << key << endl;
////		break;
////	}
////}
////
////void SpecialKeyboard(int key, int x, int y)
////{
////	if (key == GLUT_KEY_UP)
////	{
////		for (iter = v.begin(); iter != v.end(); ++iter)
////			++(iter->speed);
////	}
////	else if (key == GLUT_KEY_DOWN)
////	{
////		for (iter = v.begin(); iter != v.end(); ++iter)
////			--(iter->speed);
////	}
////}
////
////void TimerFunction(int value)
////{
////	if (!Ice)
////	{	//크기 변경
////		radius += radiusStatus;
////		if (!radius || radius == MAX_RADIUS) radiusStatus *= MINUS;
////		//속도 변경
////		for (iter = v.begin(); iter != v.end(); ++iter)
////		{
////			iter->x += (iter->speed)*(iter->xdir);
////			iter->y += (iter->speed)*(iter->ydir);
////		}
////		//모서리 충돌체크
////		for (iter = v.begin(); iter != v.end(); ++iter)
////		{
////			CheckCorner(&(*iter));
////		}
////	}
////	glutPostRedisplay(); // 화면 재 출력
////	glutTimerFunc (100, TimerFunction, 1); // 타이머함수 재 설정
////}
////
////void DrawRectangle(float x, float y)
////{
////	glColor3f(R, G, B);
////	//
////	glRectf(x - radius, y - radius, x + radius, y + radius);
////	//
////}
////
////void KeyFunc(int idx)
////{
////	int i = 0;
////	for (iter = v.begin(); iter != v.end(); ++iter)
////	{
////		if (idx == ++i)
////		{
////			cout << "나야나" << i << endl;
////			break;
////		}
////	}
////	iter->status = ROTATING;
////}
////
////void CheckCorner(Point2D* p)
////{
////	if ((p->x - radius) <= 0)
////		p->xdir = 1;
////	if ((p->x + radius) >= WINDOW_WIDTH)
////		p->xdir = -1;
////	if ((p->y - radius) <= 0)
////		p->ydir = 1;
////	if ((p->y + radius )>= WINDOW_HEIGHT)
////		p->ydir = -1;
////}
//
//#include <gl\freeglut.h>
//#include <time.h>
//#include <iostream>
//
//using namespace std;
//
//typedef struct fRect
//{
//	float left, top, right, bottom;
//};
//
//struct Rect_Obj
//{
//	fRect tRect;
//	fRect tStart_Save;
//	float fspeed;
//	bool bState;
//	bool bSelect;
//	float RGB[3] = {};
//	int	isize_count = 0;
//	int iDir = 0; // 0 ↗ 1 ↖ 2 ↙ 3 ↘
//};
//
//void drawScene(void);
//void reshape(int w, int h);
//void Mouse(int button, int state, int x, int y);
//void TimerFunction(int value);
//void MoveFunction(int value);
//void Keyboard(unsigned char key, int x, int y);
//
//POINT Window_Pos = { 100,100 };
//POINT Window_Size = { 800,600 };
//
//Rect_Obj tRect[9] = {};
//int iCount = 0;
//bool iStop = false;
//
//void main(int argc, char** argv)
//{
//	srand((unsigned)time(0));
//
//	glutInit(&argc, argv); // glut 초기화
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(Window_Pos.x, Window_Pos.y); // 윈도우 위치 설정 - 좌측 상단 모서리 위치 지정
//	glutInitWindowSize(Window_Size.x, Window_Size.y); // 윈도우 위치 설정 - 위치 변환
//	glutCreateWindow("Q6");// 윈도우 생성 ↔ glutDestroyWindow(int Win); - 윈도우 파괴
//	glutDisplayFunc(drawScene);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(Mouse);
//	glutKeyboardFunc(Keyboard);
//	glutTimerFunc(1000, TimerFunction, 1);
//	glutTimerFunc(10, MoveFunction, 2);
//	glutMainLoop(); // GLUT 이벤트 프로세싱 루프 실행
//}
//
//void drawScene(void)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // 바탕색
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체 칠하기
//	for (int i = 0; i < 9; ++i)
//	{
//		if (tRect[i].bState)
//		{
//			glColor3f(tRect[i].RGB[0], tRect[i].RGB[1], tRect[i].RGB[2]);
//			glRectf(tRect[i].tRect.left, tRect[i].tRect.top, tRect[i].tRect.right, tRect[i].tRect.bottom);
//		}
//	}
//	glEnd();
//	glFlush(); // 화면에 출력하기
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	gluOrtho2D(0.0, (double)w, 0.0, (double)h);
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	srand((unsigned)time(0));
//
//	y = Window_Size.y - y;
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		tRect[iCount].tRect = { (float)x,(float)y,(float)(x + ((rand() % 50) + 20)),(float)(y + ((rand() % 50) + 20)) };
//		tRect[iCount].tStart_Save = tRect[iCount].tRect;
//		tRect[iCount].fspeed = (float)((rand() % 15) + 5);
//		tRect[iCount].iDir = rand() % 4;
//		tRect[iCount].isize_count = 0;
//		tRect[iCount].bState = true;
//		tRect[iCount].bSelect = false;
//
//		for (int i = 0; i < 3; ++i)
//		{
//			tRect[iCount].RGB[i] = 1.0f / 255.0f * (rand() % 255);
//		}
//		++iCount;
//
//		if (10 == iCount)
//		{
//			iCount = 0;
//		}
//	}
//}
//
//void TimerFunction(int value)
//{
//	if (iStop == false)
//	{
//		for (int i = 0; i < 9; ++i)
//		{
//			if (tRect[i].bState == true && tRect[i].bSelect == false)
//			{
//				if (0 == tRect[i].isize_count || 1 == tRect[i].isize_count)
//				{
//					tRect[i].tRect.left -= 5.f;
//					tRect[i].tRect.top += 5.f;
//					tRect[i].tRect.right += 5.f;
//					tRect[i].tRect.bottom -= 5.f;
//					++tRect[i].isize_count;
//				}
//				else if (2 == tRect[i].isize_count)
//				{
//					tRect[i].tRect.left += 5.f;
//					tRect[i].tRect.top -= 5.f;
//					tRect[i].tRect.right -= 5.f;
//					tRect[i].tRect.bottom += 5.f;
//					++tRect[i].isize_count;
//				}
//				else if (3 == tRect[i].isize_count)
//				{
//					tRect[i].tRect.left += 5.f;
//					tRect[i].tRect.top -= 5.f;
//					tRect[i].tRect.right -= 5.f;
//					tRect[i].tRect.bottom += 5.f;
//					tRect[i].isize_count = 0;
//				}
//			}
//		}
//		glutPostRedisplay();
//		glutTimerFunc(1000, TimerFunction, 1);
//	}
//}
//
//void MoveFunction(int value)
//{
//	if (iStop == false)
//	{
//		for (int i = 0; i < 9; ++i)
//		{
//			if (tRect[i].bState == true)
//			{
//				if (tRect[i].bSelect == false)
//				{
//					switch (tRect[i].iDir)
//					{
//					case 0://↗
//						tRect[i].tRect.left += tRect[i].fspeed;
//						tRect[i].tRect.top += tRect[i].fspeed;
//						tRect[i].tRect.right += tRect[i].fspeed;
//						tRect[i].tRect.bottom += tRect[i].fspeed;
//
//						if (tRect[i].tRect.right > (float)Window_Size.x) // 오른쪽 충돌
//						{
//							tRect[i].iDir = 1; // ↖
//						}
//						else if (tRect[i].tRect.top > (float)Window_Size.y - 50.f) // 위쪽 충돌
//						{
//							tRect[i].iDir = 3; // ↘
//						}
//						break;
//					case 1:// ↖
//						tRect[i].tRect.left -= tRect[i].fspeed;
//						tRect[i].tRect.top += tRect[i].fspeed;
//						tRect[i].tRect.right -= tRect[i].fspeed;
//						tRect[i].tRect.bottom += tRect[i].fspeed;
//
//						if (tRect[i].tRect.top > (float)Window_Size.y - 50.f) // ↙
//						{
//							tRect[i].iDir = 2;
//						}
//						else if (tRect[i].tRect.left < (float)Window_Size.x - 800.f - 10.f)// ↗
//						{
//							tRect[i].iDir = 0;
//						}
//						break;
//					case 2: // ↙
//						tRect[i].tRect.left -= tRect[i].fspeed;
//						tRect[i].tRect.top -= tRect[i].fspeed;
//						tRect[i].tRect.right -= tRect[i].fspeed;
//						tRect[i].tRect.bottom -= tRect[i].fspeed;
//
//						if (tRect[i].tRect.left < (float)Window_Size.x - 800.f)
//						{
//							tRect[i].iDir = 3;
//						}
//						else if (tRect[i].tRect.bottom < (float)Window_Size.y - 600.f + 50.f)
//						{
//							tRect[i].iDir = 0;
//						}
//						break;
//					case 3:
//						tRect[i].tRect.left += tRect[i].fspeed;
//						tRect[i].tRect.top -= tRect[i].fspeed;
//						tRect[i].tRect.right += tRect[i].fspeed;
//						tRect[i].tRect.bottom -= tRect[i].fspeed;
//
//						if (tRect[i].tRect.bottom < (float)Window_Size.y - 600.f + 50.f)
//						{
//							tRect[i].iDir = 0;
//						}
//						else if (tRect[i].tRect.right >(float)Window_Size.y) // ↙
//						{
//							tRect[i].iDir = 2;
//						}
//						break;
//					}
//				}
//				else if (tRect[i].bSelect == true)
//				{
//					switch (tRect[i].iDir)
//					{
//					case 4:// →
//						tRect[i].tRect.left += 15.f;
//						tRect[i].tRect.right += 15.f;
//
//						if (tRect[i].tRect.right > (float)Window_Size.x)// 오른쪽 충돌
//						{
//							tRect[i].iDir = 5; // ↓
//						}
//						break;
//					case 5:// ↓
//						tRect[i].tRect.top -= 15.f;
//						tRect[i].tRect.bottom -= 15.f;
//
//						if (tRect[i].tRect.bottom < (float)Window_Size.y - 600.f + 50.f)
//						{
//							tRect[i].iDir = 6;
//						}
//						break;
//					case 6: // ←
//						tRect[i].tRect.left -= 15.f;
//						tRect[i].tRect.right -= 15.f;
//
//						if (tRect[i].tRect.left < (float)Window_Size.x - 800.f)
//						{
//							tRect[i].iDir = 7;
//						}
//						break;
//					case 7: // ↑
//						tRect[i].tRect.top += 15.f;
//						tRect[i].tRect.bottom += 15.f;
//
//						if (tRect[i].tRect.top > tRect[i].tStart_Save.top)
//						{
//							tRect[i].iDir = 8;
//						}
//						break;
//					case 8: // →
//						tRect[i].tRect.left += 15.f;
//						tRect[i].tRect.right += 15.f;
//
//						if (tRect[i].tRect.right > tRect[i].tStart_Save.right)
//						{
//							tRect[i].bSelect = false;
//							tRect[i].iDir = rand() % 4;
//							tRect[i].tRect = tRect[i].tStart_Save;
//						}
//						break;
//					}
//				}
//			}
//		}
//	}
//	glutPostRedisplay();
//	glutTimerFunc(100, MoveFunction, 2);
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case '1':
//		if (tRect[0].bState)
//		{
//			tRect[0].tStart_Save = tRect[0].tRect;
//			tRect[0].bSelect = true;
//			tRect[0].iDir = 4;
//		}
//		break;
//	case '2':
//		if (tRect[1].bState)
//		{
//			tRect[1].tStart_Save = tRect[1].tRect;
//			tRect[1].bSelect = true;
//			tRect[1].iDir = 4;
//		}
//		break;
//	case '3':
//		if (tRect[2].bState)
//		{
//			tRect[2].tStart_Save = tRect[2].tRect;
//			tRect[2].bSelect = true;
//			tRect[2].iDir = 4;
//		}
//		break;
//	case '4':
//		if (tRect[3].bState)
//		{
//			tRect[3].tStart_Save = tRect[3].tRect;
//			tRect[3].bSelect = true;
//			tRect[3].iDir = 4;
//		}
//		break;
//	case '5':
//		if (tRect[4].bState)
//		{
//			tRect[4].tStart_Save = tRect[4].tRect;
//			tRect[4].bSelect = true;
//			tRect[4].iDir = 4;
//		}
//		break;
//	case '6':
//		if (tRect[5].bState)
//		{
//			tRect[5].tStart_Save = tRect[4].tRect;
//			tRect[5].bSelect = true;
//			tRect[5].iDir = 4;
//		}
//		break;
//	case '7':
//		if (tRect[6].bState)
//		{
//			tRect[6].tStart_Save = tRect[4].tRect;
//			tRect[6].bSelect = true;
//			tRect[6].iDir = 4;
//		}
//		break;
//	case '8':
//		if (tRect[7].bState)
//		{
//			tRect[7].tStart_Save = tRect[4].tRect;
//			tRect[7].bSelect = true;
//			tRect[7].iDir = 4;
//		}
//		break;
//	case '9':
//		if (tRect[8].bState)
//		{
//			tRect[8].tStart_Save = tRect[4].tRect;
//			tRect[8].bSelect = true;
//			tRect[8].iDir = 4;
//		}
//		break;
//	case '0':
//		for (int i = 0; i < 9; ++i)
//		{
//			if (tRect[i].bState)
//			{
//				tRect[i].tStart_Save = tRect[i].tRect;
//				tRect[i].bSelect = true;
//				tRect[i].iDir = 4;
//			}
//		}
//		break;
//	case 's':
//		if (iStop == false)
//			iStop = true;
//		break;
//	case 'q':
//		if (iStop)
//			iStop = false;
//		break;
//	}
//}
