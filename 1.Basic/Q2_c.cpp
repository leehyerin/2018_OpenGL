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
//	//�ʱ�ȭ �Լ��� 
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// ���÷��� ��� ���� 
//	glutInitWindowPosition(100, 100); 	// �������� ��ġ���� 
//	glutInitWindowSize(600, 600); 	// �������� ũ�� ���� 
//	glutCreateWindow("Q2"); 	// ������ ���� (������ �̸�) 
//	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
//	glutReshapeFunc(Reshape);	// �ٽ� �׸��� �Լ��� ���� 
//	glutMainLoop();
//}
//
// //������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
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
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, 600.0, 0.0, 600.0, -1.0, 1.0);
//}
