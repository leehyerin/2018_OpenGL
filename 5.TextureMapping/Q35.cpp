#include <GL/freeglut.h>
#include "MyHeader.h"
#include "LoadBitmap.h"

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void LoadBitMap();


void TimerFunction(int);
void CameraReset();
//-----------------------------
double zoom{-50};
double DegreeForAxisY{ 30 };

static GLubyte *pBytes;
static BITMAPINFO *info;

static GLuint texture[4];


void LoadBitMap()
{
	glGenTextures(4, texture);


	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("Jigsaw1.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glBindTexture(GL_TEXTURE_2D, texture[1]);
	pBytes = LoadDIBitmap("Jigsaw2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glBindTexture(GL_TEXTURE_2D, texture[2]);
	pBytes = LoadDIBitmap("Jigsaw3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glBindTexture(GL_TEXTURE_2D, texture[3]);
	pBytes = LoadDIBitmap("Jigsaw4.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}


int main(int argc, char *argv[])
{
	//초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Q35");
	LoadBitMap();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);

	glutTimerFunc(100, TimerFunction, 1);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

//윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0, 0, 0.2, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS);
		//Front Face
		glTexCoord2f(0.0f, 1.0f);
		Vertex0;
		glTexCoord2f(0.0f, 0.0f);
		Vertex1;
		glTexCoord2f(1.0f, 0.0f);
		Vertex2;
		glTexCoord2f(1.0f, 1.0f);
		Vertex3;
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS);
		//Left Face
		glTexCoord2f(0.0f, 1.0f);
		Vertex1;
		glTexCoord2f(0.0f, 0.0f);
		Vertex5;
		glTexCoord2f(1.0f, 0.0f);
		Vertex6;
		glTexCoord2f(1.0f, 1.0f);
		Vertex2;
		glEnd();

		//Right Face
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		Vertex4;
		glTexCoord2f(0.0f, 0.0f);
		Vertex0;
		glTexCoord2f(1.0f, 0.0f);
		Vertex3;
		glTexCoord2f(1.0f, 1.0f);
		Vertex7;
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glBegin(GL_QUADS);
		//Top Face
		glTexCoord2f(0.0f, 1.0f);
		Vertex4;
		glTexCoord2f(0.0f, 0.0f);
		Vertex5;
		glTexCoord2f(1.0f, 0.0f);
		Vertex1;
		glTexCoord2f(1.0f, 1.0f);
		Vertex0;
		glEnd();

		glBegin(GL_QUADS);
		//Bottom Face
		glTexCoord2f(0.0f, 1.0f);
		Vertex3;
		glTexCoord2f(0.0f, 0.0f);
		Vertex2;
		glTexCoord2f(1.0f, 0.0f);
		Vertex6;
		glTexCoord2f(1.0f, 1.0f);
		Vertex7;
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glBegin(GL_QUADS);
		//Back Face
		glTexCoord2f(0.0f, 1.0f);
		Vertex7;
		glTexCoord2f(0.0f, 0.0f);
		Vertex6;
		glTexCoord2f(1.0f, 0.0f);
		Vertex5;
		glTexCoord2f(1.0f, 1.0f);
		Vertex4;
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	//
	glutSwapBuffers();
}

void TimerFunction(int value)
{
	DegreeForAxisY++;

	CameraReset();

	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정
}


void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoom);

	glRotated(30, 1, 0, 0);
	glRotated(DegreeForAxisY, 0, 1, 0);
}


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	CameraReset();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':	--DegreeForAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForAxisY;		CameraReset(); break;
	case 'Z':
		++zoom; CameraReset(); break;
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}