#include "Q34.h"

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Initialization();
void Keyboard(unsigned char, int, int);

void DrawFloor();
void DrawLight();
void DrawCone();
void DrawPyramid();
void DrawSnow();

bool CheckCollisionSnowbyFloor(Snow* f);
bool CheckRobotCollision();
void Move();
void ParticleStart();

void TimerFunction(int);
void SnowTimer(int);
void CameraReset();
//-----------------------------

int main(int argc, char *argv[])
{
	//초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Q34");
	Initialization();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);

	glutTimerFunc(100, TimerFunction, 1);
	glutTimerFunc(200, SnowTimer, 2);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

//윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();

	glEnable(GL_LIGHTING);

	if (bLight0)	glEnable(GL_LIGHT0);	else	glDisable(GL_LIGHT0);
	if (bLight1)	glEnable(GL_LIGHT1);		else	glDisable(GL_LIGHT1);

	//glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLight);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	DrawPyramid();

	DrawLight();

	DrawSnow();

	DrawFloor();

	//로봇 등판!
	DrawRobot();

	if(bParticle) 
		for (auto d : vParticles)
		{
			glPushMatrix();
			glTranslated(d.pos.x, d.pos.y, d.pos.z);
			glutSolidSphere(0.5, 10, 10);
			glPopMatrix();
		}

	glutSwapBuffers();
}

bool CheckCollisionSnowbyFloor(Snow* f)
{
	for (int d = 0; d < vFloor.size(); ++d)
		if (vFloor[d].x - 0.5 <= f->x && f->x <= vFloor[d].x + 0.5)
			if (vFloor[d].z - 0.5 <= f->z && f->z <= vFloor[d].z + 0.5)
			{
				vFloor[d].snowing();
				return true;
			}
	return false;
}

void Move()
{
	if (RobotMoveX)
	{
		if (CheckRobotCollision())
		{
			RobotMoveX = false;
			ParticleStart(); 

			dir *= -1;
		}
		XRobot += dir * 1;
	}

	if (RobotMoveZ)
	{
		if (CheckRobotCollision())
		{
			RobotMoveZ = false;
			ParticleStart();

			dir *= -1;
		}
		ZRobot += dir * 1;
	}

	if (19 < XRobot || XRobot < -19)		RobotMoveX = false; // dir *= -1;
	if (19 < ZRobot || ZRobot < -19) 		RobotMoveZ = false; //dir *= -1;
}

bool CheckRobotCollision()
{
	if (-4 < XRobot  &&  XRobot < 4)
		if (-4 < ZRobot && ZRobot < 4)
			return true;	

	return false;
}

void ParticleStart()
{
	if (false == bParticle)
	{
		bParticle = true;
		timer = 0;

		for (int j = 0; j < 20; ++j)
			vParticles.push_back(Particle{ XRobot,ZRobot });
	}
}

void TimerFunction(int value)
{
	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정

	degree += dir * 0.1;

	tmpX = 15 * cos(degree);
	tmpZ = 15 * sin(degree);
	SpherePos[0] = tmpX;
	SpherePos[2] = tmpZ;

	tmpX = 15 * cos(degree) + SpherePos[0];
	tmpZ = 15 * sin(degree) + SpherePos[2];
	light0Pos[0] = tmpX;
	light0Pos[2] = tmpZ;
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);

	tmpX = 10 * cos(degree - 180) + SpherePos[0];
	tmpZ = 10 * sin(degree - 180) + SpherePos[2];
	light1Pos[0] = tmpX;
	light1Pos[2] = tmpZ;
	glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
	//
	bool col{ false };
	int idx = 0;
	if (bSnow)
	{
		for (int i = 0; i < vSnow.size(); ++i)
		{
			if (vSnow[i].y > 0)
			{
				vSnow[i].y -= 0.5;
			}
			else
			{
				col = CheckCollisionSnowbyFloor(&vSnow[i]);
				if (col) idx = i;
			}
		}

		if (col)
		{
			vSnow.erase(vSnow.begin() + idx);   //눈 지우기
		}
	}
	Move();

	//

	SpotlightPos[0] = XRobot;
	SpotlightPos[1] = 5;
	SpotlightPos[2] = ZRobot;
	glLightfv(GL_LIGHT2, GL_POSITION, SpotlightPos);

	//

	if (bParticle) 
	{			
		for (int i = 0; i < vParticles.size(); ++i)
		{
			++timer;
			vParticles[i].Update();
		}
		if (timer == 200)
		{
			bParticle = false; vParticles.clear();
		}
	}
}

void SnowTimer(int value)
{
	double x = rand() % 40 - 20;
	double z = rand() % 40 - 20;
	vSnow.push_back(Snow{ x,10.0,z });

	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(200, SnowTimer, 2); // 타이머함수 재 설정
}

