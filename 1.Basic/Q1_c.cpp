//#include <GL/freeglut.h>
//GLvoid Reshape(int, int);
//GLvoid drawScene(GLvoid);
//
//void main(int argc, char *argv[]) 
//{ 
//	//�ʱ�ȭ �Լ��� 
//	glutInit (&argc, argv); 
//	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGBA );// ���÷��� ��� ���� 
//	glutInitWindowPosition ( 100, 100 ); 	// �������� ��ġ���� 
//	glutInitWindowSize ( 800, 600 ); 	// �������� ũ�� ���� 
//	glutCreateWindow ( "Q1" ); 	// ������ ���� (������ �̸�) 
//	glutDisplayFunc ( drawScene );	// ��� �Լ��� ���� 
//	glutReshapeFunc (Reshape);	// �ٽ� �׸��� �Լ��� ���� 
//	glutMainLoop (); 
//} 
//
//// ������ ��� �Լ� 
//GLvoid drawScene( GLvoid ) 
//{ 
//	glClearColor (0.0f, 0.0f, 1.0f, 1.0f); 
//	// �������� 'blue' �� ���� 
//	glClear ( GL_COLOR_BUFFER_BIT ); 
//	// ������ ������ ��ü�� ĥ�ϱ�
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
//	//�ﰢ��
//	glColor3f(1.f, 1.f, 1.f);
//	glBegin(GL_POLYGON);
//	glVertex2i(-40, -40);//v1 
//	glVertex2i (40, -40);		//v2
//	glVertex2i (0, 80);	//v3 
//	glEnd ();
//
//	//��
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
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape(int w, int h) 
//{ 
//	glViewport(0, 0, w, h); 
//	glOrtho(-400.0, 400.0, -300.0, 300.0, -1.0, 1.0);
//
//}
//
