//#include <GL/freeglut.h>
//#include <ctime>
//#include <iostream>
//#include <vector>
//#include <iterator>
//using namespace std;
//
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
////-----------------------------
//void DrawGuideLine();
//void DrawLine(float, float);
//void DrawTriangle(float, float);
//void DrawRectangle(float, float);
//void DrawPentagon(float, float);
//
//void RunFunc(int, float, float);
////-----------------------------
//vector<int> v{ 2,3,4,5,4,3,2,3,4,5,4,3 };
//
//void main(int argc, char *argv[])
//{
//	// 2 3 4 5 4 3 2 3 4
//	//    3 4 5 4 3 2 3 4 5
//	//       4 5 4 3 2 3 4 5 4
//	//          5 4 3 2 3 4 5 4 3	
//	//find�� ù ������ ��ġ�� ã��, �� �ڷ� �����ؼ� ����.
//	
//	//�ʱ�ȭ �Լ��� 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// ���÷��� ��� ���� 
//	glutInitWindowPosition(100, 100); 	// �������� ��ġ���� 
//	glutInitWindowSize(600, 600); 	// �������� ũ�� ���� 
//	glutCreateWindow("Q3"); 	// ������ ���� (������ �̸�) 
//	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
//	glutReshapeFunc(Reshape);	// �ٽ� �׸��� �Լ��� ���� 
//	glutMainLoop();
//}
//
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); 
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//	
//
//	DrawGuideLine(); //���̵� ��
//	
//	srand((unsigned int)time(NULL));
//	int startNum = rand() % 4 + 2;
//
//	//--------------------------------------------------------
//	vector<int>::iterator iter;
//	
//	iter = find(v.begin(), v.end(), startNum);
//
//	for (int i = 0; i < 9; ++i, ++iter){
//		RunFunc(*iter, -200 + (i % 3) * 200, -200 + (i / 3) * 200);
//	}
//	//--------------------------------------------------------
//	//   [0]               [1]            [2] 
//	//-200, 200      0, 200    200,200
//	//   [3]               [4]            [5] 
//	//-200, 0          0,0         200,0
//	//   [6]               [7]            [8]
//	//-200,-200     0,-200   200,-200
//	//0,3,6  ...   (i%3) * 200 + - 200
//	//0,1,2  ...   (i / 3) * 200 + - 200
//
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(-300.0, 300.0, -300.0, 300.0, -1.0, 1.0);
//}
//
//void DrawGuideLine()
//{
//	glColor3f(1.f, 1.f, 1.f);
//
//	glLineWidth(2.f); //���� ����
//	
//	glBegin(GL_LINES);
//	//���μ�
//	glVertex2f(-300, 100);
//	glVertex2f(300, 100);
//	glVertex2f(-300, -100);
//	glVertex2f(300, -100);
//	//���μ�
//	glVertex2f(100, -300);
//	glVertex2f(100, 300);
//	glVertex2f(-100, -300);
//	glVertex2f(-100, 300);
//	
//	glEnd();
//}
//
//void DrawLine(float x, float y)
//{
//	glColor3f(1.f, 1.f, 0.5f);
//	glLineWidth(3.f); //���� ����
//	glBegin(GL_LINES);
//	//
//	glVertex2f(x - 50, y + 50);
//	glVertex2f(x + 50, y - 50);
//	//
//	glEnd();
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
//void DrawRectangle(float x, float y)
//{
//	glColor3f(0.5f, 0.5f, 1.f);
//	//
//	glRectf(x - 50, y - 50, x + 50, y + 50);
//	//
//}
//
//void DrawPentagon(float x, float y)
//{
//	glColor3f(0.f, 0.5f, 1.f);
//	glBegin(GL_POLYGON);
//	//
//	glVertex2i(x - 50, y + 10);
//	glVertex2i(x - 30, y - 50);
//	glVertex2i(x + 30, y - 50); 
//	glVertex2i(x + 50, y + 10);
//	glVertex2f(x        ,y + 50);
//	//
//	glEnd();
//}
//
//void RunFunc(int num, float x, float y)
//{
//	switch (num)
//	{
//	case 2:
//		DrawLine(x, y);	//����
//		break;
//	case 3:
//		DrawTriangle(x, y);	//�ﰢ��
//		break;
//	case 4:
//		DrawRectangle(x, y);	//�簢��
//		break;
//	case 5:
//		DrawPentagon(x, y);	//������
//		break;
//	default:
//		break;
//	}
//}
