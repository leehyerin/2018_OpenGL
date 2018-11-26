#include <GL/freeglut.h>
#include "Myheader.h"
#include "Q27.h"
GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);
void DefaultTimer(int);
//-----------------------------
void SetupRC();
void CameraReset();

void Move();
bool CheckRobotCollision();

void	DrawCube();
void DrawAxis();
void DrawFloor();
void DrawRobot();
void DrawTree();
void DrawRunningMachine();
void DrawLegs();
void DrawBar();
void DrawArms();
void DrawBenchPress();

void JumpInitaillization();
void RobotInitiallization();

double DegreeForAxisY, zoomZ, cameraX;
double XRobot, YRobot, ZRobot;
int dir;
double DegreeForRobotArms, DegreeForRobotDir;

bool isJump; int jump_dir;
bool isCulling, isHiddenFaceDeleter;
double DegreeforTorus, DegreeforLegs, DegreeforBar, DeltaYforWeights; 
int leg_dir, weights_dir, robotarms_dir;
double tree_size; int tree_dir;
bool RobotMoveX, RobotMoveZ;

bool bFrontFaceOpen = false;
double FrontFaceDegree;

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0); 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 
	glutCreateWindow("Q27"); 	

	SetupRC();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);
	glutTimerFunc(100, DefaultTimer, 2);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

void SetupRC()
{
	zoomZ = -30; cameraX = 20;
	XRobot = 0, YRobot = -5, ZRobot = 0;
	dir = 1;
	DegreeForRobotArms= DegreeForRobotDir = 0; 
	tree_dir = 1; tree_size = jump_dir = 1;
	DegreeforTorus = DegreeforBar = DeltaYforWeights = 0; leg_dir = weights_dir = robotarms_dir = 1;
	RobotMoveX =  RobotMoveZ = isCulling = isHiddenFaceDeleter = false;

	FrontFaceDegree = 0;
}

//윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	DrawCube();
	DrawFloor();
	DrawRobot();
	DrawTree();
	DrawRunningMachine();
	DrawLegs();
	DrawBar();
	DrawArms();
	DrawBenchPress();
	//--------------------------------


	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	CameraReset();
}

void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoomZ);
	glRotated(cameraX, 1, 0, 0);
	glRotated(DegreeForAxisY, 0, 1, 0);
}

void Move()
{
	if (RobotMoveX)
	{
		if (CheckRobotCollision()) 
		{
			isJump = true;
			RobotMoveX = false;

			dir *= -1; 
		}
		XRobot += dir * 1;
	}
	if (RobotMoveZ)
	{
		if (CheckRobotCollision())
		{
			isJump = true; 
			RobotMoveZ = false;
			
			dir *= -1;
		}
		ZRobot += dir * 1;
	}

	if (13 < XRobot || XRobot < -13)		RobotMoveX = false; // dir *= -1;
	if (13 < ZRobot || ZRobot < -13) 		RobotMoveZ = false; //dir *= -1;
}

bool CheckRobotCollision()
{
	if (ZRobot < -5 && 8 < XRobot)									return true;		//나무
	if (ZRobot < -3 && XRobot > -10 && XRobot < -4)		return true;		//벤치프레스
	if (6 < ZRobot && ZRobot < 18 && XRobot < -3)			return true; //러닝 머신
	if (10 < ZRobot && 6 < XRobot)									return true; //철봉

	return false;
}

void DrawCube()
{
	glLoadIdentity();
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);

	//---------------------------------------
	//Front Face
	glLoadIdentity();
	glPushMatrix();
	if (bFrontFaceOpen) {
		glTranslated(0, -15, 15);
		glRotated(FrontFaceDegree, 1, 0, 0);
		glTranslated(0, 15, -15);
	}
	glBegin(GL_QUADS);
		Vertex70;
		Vertex71;
		Vertex72;
		Vertex73;
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);
		//Top Face
		Vertex74;
		Vertex75;
		Vertex71;
		Vertex70;
		//Left Face
		Vertex71;
		Vertex75;
		Vertex76;
		Vertex72;
		//Right Face
		Vertex74;
		Vertex70;
		Vertex73;
		Vertex77;
		//Bottom Face
		Vertex73;
		Vertex72;
		Vertex76;
		Vertex77;
		//Back Face
		Vertex77;
		Vertex76;
		Vertex75;
		Vertex74;
	glEnd();

}

void DrawAxis()
{
	//-----------좌표계----------------
	glLoadIdentity();
	glColor3f(0.f, 0.f, 1.f);
	glTranslated(0, 10, 30);

	glPushMatrix();
	glTranslated(0.0, 0.0, -0.5);
	glScaled(0.5, 0.5, 3);
	glutSolidCube(0.3);
	glPopMatrix();

	glColor3f(1.f, 0.f, 0.f);
	glPushMatrix();
	glTranslated(0.5, 0.0, 0.0);
	glScaled(3, 0.5, 0.5);
	glutSolidCube(0.3);
	glPopMatrix();

	glColor3f(0.f, 1.f, 0.f);
	glPushMatrix();
	glTranslated(0.0, 0.5, 0);
	glScaled(0.5, 3, 0.5);
	glutSolidCube(0.3);
	glPopMatrix();
}

void DrawFloor()
{
	//-----------바닥--------------
	glLoadIdentity();
	glColor3f(0.6, 0.4, 0.4);
	glTranslated(0.0, -15.0, 0);
	glScaled(1.0, 0.1, 1.0);
	glutSolidCube(30.0);	 glColor3f(0, 0, 0);		glutWireCube(30.0);

	//-----------삼각형------------
	glLoadIdentity();
	glColor3f(0.39, 0.19, 0.02);
	glTranslated(5, -13.1, -15);
	glRotated(-90, 1, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex3d(0, 0, 0);
	glVertex3d(10, 0, 0);
	glVertex3d(10, -10, 0);
	glEnd();

	glLoadIdentity();
}

void DrawRobot()
{  //-----------객체---------------
	glLoadIdentity();
	
	glPushMatrix();
	glTranslated(XRobot, YRobot, ZRobot); //축이동
	glRotated(DegreeForRobotDir, 0, 1, 0);     //전체 자전
	glTranslated(-XRobot, -YRobot, -ZRobot);//축 원점으로

	//머리
	glPushMatrix();
		CYAN;
		glTranslated(XRobot, YRobot + 5, ZRobot);
		glScaled(2.f, 3.f, 1.f);
		glutSolidCube(1.0);	
	glPopMatrix();
	//코
	glPushMatrix();
		RED;
		glTranslated(XRobot, YRobot + 5, ZRobot + 1);
		glutSolidSphere(0.5, 5, 5);
	glPopMatrix();
	//몸통
	glPushMatrix();
		glColor3f(0.38f, 0.75f, 1.f);
		glTranslated(XRobot, YRobot, ZRobot);
		glScaled(2.f, 3.f, 1.f);
		glutSolidCube(2.0);		
	glPopMatrix();
	
	//팔
	glPushMatrix();
		WHITE;
		glTranslated(XRobot - 2.5, YRobot, ZRobot);
		glRotated(-30, 0, 0, 1);
		glTranslated(0, 2, 0);
		glRotated(DegreeForRobotArms, 1, 0, 0);
		glTranslated(0, -2, 0);
		glScaled(1, 4, 1);
		glutSolidCube(1.0);//왼팔
	glPopMatrix();

	glPushMatrix();
		YELLOW;
		glTranslated(XRobot + 2.5, YRobot , ZRobot);
		glRotated(30, 0, 0, 1);
		glTranslated(0, 2, 0);
		glRotated(-DegreeForRobotArms, 1, 0, 0);
		glTranslated(0, -2, 0);
		glScaled(1, 4, 1);
		glutSolidCube(1.0);	//오른팔
	glPopMatrix();

	//다리
	glPushMatrix();
		BLACK;
		glTranslated(XRobot - 1.5, YRobot - 5.0, ZRobot);
		glTranslated(0, 2, 0);
		glRotated(-DegreeForRobotArms, 1, 0, 0);
		glTranslated(0, -2, 0); 
		glScaled(1, 4, 1);
		glutSolidCube(1.0);	//왼다리
	glPopMatrix();

	glPushMatrix();
		GREEN;
		glTranslated(XRobot + 1.5, YRobot - 5.0, ZRobot);
		glTranslated(0, 2, 0);
		glRotated(DegreeForRobotArms, 1, 0, 0);
		glTranslated(0, -2, 0); 
		glScaled(1, 4, 1);
		glutSolidCube(1.0);	//오른쪽다리
	glPopMatrix();

	glPopMatrix();

}

void DrawTree()
{
	glLoadIdentity();
	glColor3f(0.074, 0.414, 0.132);
	glPushMatrix();
		glTranslated(13, -5, -10);
		glScaled(tree_size, tree_size, tree_size);
		glutWireCube(1);
	glPopMatrix();

	glColor3f(0.40, 0.203, 0.02);
	glPushMatrix();
		glTranslated(13, -10, -10);
		glScaled(1, 3, 1);
	glutSolidCube(2);
	glPopMatrix();
}

void DrawRunningMachine()
{
	glLoadIdentity();

	glColor3f(0, 0, 1);
	glTranslated(-10, -10, 10);
	glScaled(1.0, 0.2, 1.0);
	glRotated(DegreeforTorus, 0, 0, 1);
	glutSolidTorus(2, 3.5, 10, 20);		glColor3f(1, 1, 1);	glutWireTorus(2, 3.5, 10, 15);
}

void DrawLegs()
{
	glLoadIdentity();
	glColor3f(0, 1, 1);
	glTranslated(-10, -5, 10);
	glRotated(DegreeforLegs, 0, 0, 1);
	glScaled(0.5, 3.0, 0.5);
	glutSolidCube(1);

	glLoadIdentity();
	glColor3f(0, 1, 1);
	glTranslated(-10, -5, 13);
	glRotated(-DegreeforLegs, 0, 0, 1);
	glScaled(0.5, 3.0, 0.5);
	glutSolidCube(1);
}

void DrawBar()
{
	glLoadIdentity();
	glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(7, -9, 13);
		glScaled(1, 10, 1);
		glutSolidCube(0.7);

		glTranslated(5, 0, 0);
		glutSolidCube(0.7);
	glPopMatrix();
	
	glTranslated(9.5, -5, 13);
	glScaled(8, 1, 1);
	glutSolidCube(0.7);
}

void DrawArms()
{
	glLoadIdentity();
	glColor3f(0, 1, 1);
	//팔
	glTranslated(8.5, -5, 13);
	glRotated(DegreeforBar, 1, 0, 0);
	glTranslated(0, -1.5, 0);
	glScaled(1, 6, 1);
	glutSolidCube(0.5);

	glTranslated(2, 0, 0);
	glutSolidCube(0.5);

	glScaled(1, 0.25, 1);

	//몸통
	glTranslated(-1, -1.5, 0);
	glutSolidCube(1.5);

	//머리
	glTranslated(0, 1.5, 0);
	glutSolidSphere(0.5, 10, 10);
}

void DrawBenchPress()
{
	//벤치 프레스
	glColor3f(1, 1, 0);
	glLoadIdentity();

	glPushMatrix();
	glTranslated(-9, -10, -7);
	glScaled(4, 1, 4);
	glutSolidCube(1);
	glPopMatrix();

	glTranslated(0, DeltaYforWeights, 0);
	//역기
	glColor3f(0.5, 0, 1);
	glPushMatrix();
		glTranslated(-7, -5, -7);
		glScaled(1, 1, 0.5);
		glutSolidSphere(0.5, 10, 10);
		glTranslated(0, 0, 5);
		glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	glColor3f(0, 0, 1);
	glPushMatrix();
		glTranslated(-7, -5, -5.5);
		glScaled(0.5, 0.5, 3.5);
		glutSolidCube(0.5);
	glPopMatrix();

}



void JumpInitaillization()
{
	isJump = false; 
	YRobot = -5;
	jump_dir = 1;
}

void RobotInitiallization()
{
	//Robot
	XRobot = 0, YRobot = -5, ZRobot = 0;
	DegreeForRobotArms = DegreeForRobotDir = 0;

	//Front Face
	if (bFrontFaceOpen)	
	{
		FrontFaceDegree = 0;
		bFrontFaceOpen = false; 
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':	--DegreeForAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForAxisY;		CameraReset(); break;

	case '-':	--zoomZ;						CameraReset(); break;
	case '+':	++zoomZ;						CameraReset(); break;
		
	case 'x':	--cameraX;					CameraReset(); break;
	case 'X':	++cameraX;					CameraReset(); break;

	case 'A':case'a':
		DegreeForRobotDir = LEFT;
		dir = -1;
		RobotMoveX = true; RobotMoveZ = false; JumpInitaillization();
		break;
	case 'D':case 'd':
		DegreeForRobotDir = RIGHT;
		dir = 1; 
		RobotMoveX = true; RobotMoveZ = false; JumpInitaillization();
		break;
	case 'W':case 'w':
		DegreeForRobotDir = UP;
		dir = -1;
		RobotMoveZ = true; RobotMoveX = false; JumpInitaillization();
		break;
	case 'S':case 's':
		DegreeForRobotDir = DOWN;
		dir = 1;
		RobotMoveZ = true; RobotMoveX = false; JumpInitaillization();
		break;

	case 'j':case 'J':
		isJump = true;
		break;
	case'i':case 'I': //초기화
		JumpInitaillization();
		RobotInitiallization();
		break;
	case'h':case 'H':
		if (isHiddenFaceDeleter) 		glEnable(GL_DEPTH_TEST);
		else  									glDisable(GL_DEPTH_TEST);
		isHiddenFaceDeleter = !isHiddenFaceDeleter;
		break;
	case'c':case 'C':
		if (isCulling)		glEnable(GL_CULL_FACE);
		else					glDisable(GL_CULL_FACE);
		isCulling = !isCulling;
		break;
	case'o':case'O':
		bFrontFaceOpen = true;

		break;
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void TimerFunction(int value)
{
	Move();

	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정
}

void DefaultTimer(int value)
{
	tree_size += tree_dir * 0.5;   if (tree_size <= 1 || tree_size >= 5) tree_dir *= -1;

	++DegreeforTorus; DegreeforBar += 5;

	DegreeforLegs -= leg_dir * 5;   if (DegreeforLegs < -35 || DegreeforLegs > 35) leg_dir *= -1;

	if (isJump)    
	{
		DegreeForRobotArms = 0;
		YRobot += jump_dir ;  if (YRobot < -5 || YRobot > 2) jump_dir *= -1;
	}
	else if (RobotMoveX || RobotMoveZ)
	{
		DegreeForRobotArms -= robotarms_dir * 5;  if (DegreeForRobotArms < -30 || DegreeForRobotArms >15) robotarms_dir *= -1;
	}
	
	DeltaYforWeights += weights_dir * 0.5; if (DeltaYforWeights >= 3 || DeltaYforWeights <= 0) weights_dir *= -1;
	
	//
	if (bFrontFaceOpen)
	{
		if (FrontFaceDegree < 90) FrontFaceDegree += 2;
	}
	
	glutPostRedisplay();
	glutTimerFunc(100, DefaultTimer, 2); 
}