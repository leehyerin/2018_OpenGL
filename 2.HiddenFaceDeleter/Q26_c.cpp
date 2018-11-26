//3차원 공 튀기기
#include <GL/freeglut.h>
#include "Myheader.h"
#include "Q26.h"
GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void MouseMotion(int, int);
void TimerFunction(int);

//-----------------------------
void SetupRC();
void CameraReset();
//
void CreateNewBalls();
void DrawBalls();
void CheckCollision(Ball*);
//
extern void MoveX(int dir, MyCube*);
extern void MoveY(int dir, MyCube*);
//
double DegreeForAxisY, zoomZ;
double CurrPosX, CurrPosY, PrevPosX, PrevPosZ;
double  BallX, BallZ;
MyCube Cube[3];
vector<Ball> Balls;
vector<Ball>::iterator Iter;
double CubeDegree;
int dir;

void SetupRC()
{
	zoomZ = -30;
	CurrPosX, CurrPosY, PrevPosX, PrevPosZ;
	dir = 1;
	DegreeForAxisY = 0;
	BallX = BallZ = 0;
	CubeDegree = 0;

	Cube[0] = { MyVec{ 0, -9.0, 5 } ,1 };
	Cube[1] = { MyVec{ 0, -8.5, 0 } ,2 };
	Cube[2] = { MyVec{ 0, -8.0, -5 } ,3 };

	CreateNewBalls();
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Q26");
	SetupRC();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);
	glutMotionFunc(MouseMotion);
	glutTimerFunc(100, TimerFunction, 1);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutReshapeFunc(Reshape);
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	glClearColor(0.5f, 0.5f, 1.f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glShadeModel(GL_FLAT);
	glFrontFace(GL_CW);

	
	//---------------------------------------
	glLoadIdentity();
	glPushMatrix();
	glRotated(CubeDegree, 0, 0, 1);
	glColor3f(0.5f, 0.5f, 0.5f);
	//Top Face
	glBegin(GL_QUADS);
	Vertex14;
	Vertex15;
	Vertex11;
	Vertex10;
	//Bottom Face
	Vertex13;
	Vertex12;
	Vertex16;
	Vertex17;

	WHITE;
	//Left Face
	Vertex11;
	Vertex15;
	Vertex16;
	Vertex12;
	//Right Face
	Vertex14;
	Vertex10;
	Vertex13;
	Vertex17;

	BLACK;
	//Back Face
	Vertex17;
	Vertex16;
	Vertex15;
	Vertex14;
	glEnd();
	//---------------------------------------
	//Cube
	glPushMatrix();
		int D = (int)(CubeDegree) % 360;

		if ( 0 < D && D <= 90) { MoveX(-1, Cube); }
		else if ( 270 < D || D < 0) { MoveX(1, Cube); }
		else if ( 180 < D && D <= 270) { MoveX(1, Cube); }
		else if (  270 < D && D < 360) { MoveX(-1, Cube); }

		if (45 < D && D <= 90) { MoveY(-1, Cube); }
		else if (90 < D && D<= 180) { MoveY(1, Cube); } 
		else if (180 < D && D <= 270) { MoveY(1, Cube); }
		else if (270 < D && D < 360) { MoveY(-1, Cube); }


		glPushMatrix();
			RED;	glTranslated(Cube[0].m_pos.x, Cube[0].m_pos.y, Cube[0].m_pos.z);	glutSolidCube(Cube[0].m_size); 
			WHITE; glutWireCube(Cube[0].m_size);
		glPopMatrix();

		glPushMatrix();
			RED;	glTranslated(Cube[1].m_pos.x, Cube[1].m_pos.y, Cube[1].m_pos.z);	glutSolidCube(Cube[1].m_size);
			WHITE; glutWireCube(Cube[1].m_size);
		glPopMatrix();
		
		glPushMatrix();
			RED;	glTranslated(Cube[2].m_pos.x, Cube[2].m_pos.y, Cube[2].m_pos.z);	glutSolidCube(Cube[2].m_size); 
			WHITE; glutWireCube(Cube[2].m_size);
		glPopMatrix();
		//----------------------------
		DrawBalls();

	glPopMatrix();

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	CameraReset();
}

void CreateNewBalls()
{
	for (int i = 0; i < 5; ++i)
		Balls.push_back(Ball{
		MyVec{ (double)(rand() % 20 - 9), (double)(rand() % 20 - 9), (double)(rand() % 20 - 9) },
		MyVec{ (double)(rand() % 2 + 0.2),(double)(rand() % 2 + 0.2),(double)(rand() % 2 + 0.2) } ,
		0.5
			});
}

void DrawBalls()
{
	//Ball
	BLUE;
	for (Iter = Balls.begin(); Iter != Balls.end(); ++Iter)
	{
		glPushMatrix();
			//벽과의 충돌체크	- 충돌시에는 dir를 바꿔주면 된다! -이때 dir은 정규화 할 것!
			CheckCollision(&(*Iter));
			(Iter->m_pos) = *(Iter->m_pos + Iter->m_dir); //시간 나면 speed도 곱하자잉

			glTranslated(Iter->m_pos.x, Iter->m_pos.y, Iter->m_pos.z);
			glutSolidSphere(1, 10, 10);
		glPopMatrix();
	}
}

void CheckCollision(Ball* b) 
{
	auto pos = b->m_pos;

	if (pos.x <= -9 || 9 <= pos.x) b->m_dir.x *= -1;
	if (pos.y <= -9 || 9 <= pos.y) b->m_dir.y *= -1;
	if (pos.z <= -9 || 9 <= pos.z) b->m_dir.z *= -1;
}

void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoomZ);
	glRotated(DegreeForAxisY, 0, 1, 0);
}

void Keyboard(unsigned char key, int x, int y)
{
		switch (key)
		{
	case 'y':	--DegreeForAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForAxisY;		CameraReset(); break;

	case '-':	--zoomZ;		CameraReset(); break;
	case '+':	++zoomZ;		CameraReset(); break;

	case 'B': case'b': 
		CreateNewBalls();
		break;
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}


void MouseMotion(int x, int y)
{
	x = x - WINDOW_WIDTH * 0.5;
	y = WINDOW_HEIGHT  * 0.5 - y;
	
	CurrPosX = (double)x;
	if (CurrPosX > PrevPosX) --CubeDegree;
	if (CurrPosX < PrevPosX) ++CubeDegree;

	PrevPosX = CurrPosX;
}

void TimerFunction(int value)
{
	if (CubeDegree < 0) CubeDegree += 360;

	CameraReset();
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}


