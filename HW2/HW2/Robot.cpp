#include "Robot.h"
#include "Vertex.h"
#include <GL/freeglut.h>
extern vector<MyVec> vTree;
extern Vertex cVertex;

Robot::Robot()
{
	m_RobotDir = LEFT;
	m_DegreeForArms = 30;
	m_ArmDir = 1;
	m_Sign = -1;
	m_MoveX = false;
	m_MoveZ = false;

	m_CapeTimer = m_Timer = 0;
}

Robot::Robot(double x, double y, double z)
{
	m_Pos.x = x; m_Pos.y = y; m_Pos.z = z;

	m_RobotDir = LEFT;
	m_DegreeForArms = 30;
	m_ArmDir = 1;
	m_Sign = -1;
	m_MoveX = false;
	m_MoveZ = false;

	m_CapeTimer = m_Timer = 0;
}

Robot::~Robot()
{
}

void Robot::Move()
{
	if (m_MoveX)
	{
		m_Pos.x += m_Sign * STEP;
	}

	else if (m_MoveZ)
	{
		m_Pos.z += m_Sign * STEP;
	}

	//--------------if end of floor---------------  
	if (m_Pos.x < -200)  { ChangeFromCurrDir(LEFT); }
	if (200 < m_Pos.x)	{ ChangeFromCurrDir(RIGHT); }
	if (m_Pos.z < -200)	{ ChangeFromCurrDir(UP); }
	if (200 < m_Pos.z)	{ ChangeFromCurrDir(DOWN); }

	if(CheckCollisionRobotbyObject()) ChangeFromCurrDir(m_RobotDir);
	if (cVertex.CheckCollisionRobotbyVertex(m_Pos.x, m_Pos.z)) ChangeFromCurrDir(m_RobotDir);
}

void Robot::ChangeToDestDir(int dir)
{
	m_RobotDir = dir;

	switch (dir)
	{
	case LEFT:
		m_MoveX = true;
		m_MoveZ = false;
		m_Sign = -1;
		break;
	case RIGHT:
		m_MoveX = true;
		m_MoveZ = false;
		m_Sign = +1;
		break;
	case UP:
		m_MoveX = false;
		m_MoveZ = true;
		m_Sign = -1;
		break;
	case DOWN:
		m_MoveX = false;
		m_MoveZ = true;
		m_Sign = +1;
		break;
	}
}

void Robot::ChangeFromCurrDir(int currDir)
{ //just switch direction which Robot was going
	switch (currDir)
	{
		case LEFT:
			m_Sign *= -1; 
			m_RobotDir = RIGHT;	 
			m_MoveX = true;
			m_MoveZ = false;
			break;
		case RIGHT:
			m_Sign *= -1; 
			m_RobotDir = LEFT;		
			m_MoveX = true;
			m_MoveZ = false; 
			break;
		case UP:
			m_Sign *= -1;
			m_RobotDir = DOWN;	
			m_MoveX = false;
			m_MoveZ = true;
			break;
		case DOWN:
			m_Sign *= -1; 
			m_RobotDir = UP;			
			m_MoveX = false;
			m_MoveZ = true;
			break;
		default:
			break;
	}
}

bool Robot::CheckCollisionRobotbyObject() //tree, column
{
	for (auto d : vTree)
		if (CheckColl(d.x, d.z, m_Pos.x, m_Pos.z))
		{
			return true;
		}
	return false;
}

void Robot::ParticleStart(int idx)
{
	if (false == m_bParticle)
	{
		{
			m_bParticle = true;
			m_Timer = 0;

			for (int j = 0; j < 20; ++j)
				m_vParticles.push_back(Particle{ m_vBullet[idx].pos.x,m_vBullet[idx].pos.z });
		}
	}
}

void Robot::ParticleProcess()
{
	if (m_bParticle)
	{
		for (unsigned int i = 0; i < m_vParticles.size(); ++i)
		{
			++m_Timer;
			m_vParticles[i].Update();
		}
		if (m_Timer == 300)
		{
			m_bParticle = false; 
			m_Timer = 0;
			m_vParticles.clear();
		}
		ParticleDraw();
	}
}

void Robot::ParticleDraw()
{
	CYAN;
	for (auto d : m_vParticles)
	{
		glPushMatrix();
		glTranslated(d.pos.x, d.pos.y, d.pos.z);
		glutSolidCube(1.5);
		glPopMatrix();
	}
}

void Robot::ShotBullet()
{
	m_vBullet.push_back(Bullet{ m_Pos.x, m_Pos.z, m_RobotDir });
}

void Robot::ArmUpdate()
{
	m_DegreeForArms += m_ArmDir * 5;
	if (m_DegreeForArms > 30 || m_DegreeForArms < -30) m_ArmDir *= -1;
}

void Robot::BulletUpdate()
{
	bool col = false;
	for (unsigned int i = 0; i < m_vBullet.size(); ++i)
	{
		if (!CheckBoundary(-200, 200, m_vBullet[i].pos.x) || !CheckBoundary(-200, 200, m_vBullet[i].pos.z))
		{
			m_vBullet.erase(m_vBullet.begin() + i);
		}
		else
		{
			for (auto d : vTree)
			{
				if (CheckColl(d.x, d.z, m_vBullet[i].pos.x, m_vBullet[i].pos.z))  //tree - bullet
				{
					ParticleStart(i); 
					m_vBullet.erase(m_vBullet.begin() + i); 
					col = true;
					break;
				}
			}
			if (cVertex.CheckCollisionRobotbyVertex(m_Pos.x, m_Pos.z))  // vertex - bullet
			{
				ParticleStart(i);
				m_vBullet.erase(m_vBullet.begin() + i);
				col = true;
				break;
			}
			
			if (!col) { m_vBullet[i].Update(); col = false; }
		}
	}
	BulletDraw();
	ParticleProcess();
}

void Robot::BulletDraw()
{
	for (auto d : m_vBullet)
	{
		glPushMatrix();
		MAGENTA;
		glTranslated(d.pos.x, d.pos.y, d.pos.z);
		glutSolidCube(3.0);
		glPopMatrix();
	}
}

void Robot::Draw()
{	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (m_MoveX || m_MoveZ) ArmUpdate();
	BulletUpdate();

	//-----------------DrawRobot---------------------
	glPushMatrix();
	{
		glTranslated(m_Pos.x, m_Pos.y, m_Pos.z);
		glRotated(m_RobotDir, 0, 1, 0);
		glTranslated(-m_Pos.x, -m_Pos.y, -m_Pos.z);

		//Head
		glPushMatrix();
		CYAN;
		glTranslated(m_Pos.x, m_Pos.y + 5, m_Pos.z);
		glScaled(3.f, 3.f, 3.f);
		glutSolidCube(1.0);
		glPopMatrix();
		//Nose
		glPushMatrix();
		RED;
		glTranslated(m_Pos.x, m_Pos.y + 5, m_Pos.z + 2);
		glutSolidSphere(0.5, 5, 5);
		glPopMatrix();
		//Body
		glPushMatrix();
		glColor3f(0.38f, 0.75f, 1.f);
		glTranslated(m_Pos.x, m_Pos.y, m_Pos.z);
		glScaled(2.f, 3.f, 1.f);
		glutSolidCube(2.0);
		glPopMatrix();
		//Arms
		glPushMatrix();
		WHITE;
		glTranslated(m_Pos.x - 2.5, m_Pos.y, m_Pos.z);
		glRotated(-30, 0, 0, 1);
		glTranslated(0, 2, 0);
		glRotated(m_DegreeForArms, 1, 0, 0);
		glTranslated(0, -2, 0);
		glScaled(1, 4, 1);
		glutSolidCube(1.0);//left
		glPopMatrix();

		glPushMatrix();
		YELLOW;
		glTranslated(m_Pos.x + 2.5, m_Pos.y, m_Pos.z);
		glRotated(30, 0, 0, 1);
		glTranslated(0, 2, 0);
		glRotated(-m_DegreeForArms, 1, 0, 0);
		glTranslated(0, -2, 0);
		glScaled(1, 4, 1);
		glutSolidCube(1.0);	//right
		glPopMatrix();

		//Legs
		glPushMatrix();
		BLACK;
		glTranslated(m_Pos.x - 1.5, m_Pos.y - 5.0, m_Pos.z);
		glTranslated(0, 2, 0);
		glRotated(-m_DegreeForArms, 1, 0, 0);
		glTranslated(0, -2, 0);
		glScaled(1, 4, 1);
		glutSolidCube(1.0);	//left
		glPopMatrix();

		glPushMatrix();
		GREEN;
		glTranslated(m_Pos.x + 1.5, m_Pos.y - 5.0, m_Pos.z);
		glTranslated(0, 2, 0);
		glRotated(m_DegreeForArms, 1, 0, 0);
		glTranslated(0, -2, 0);
		glScaled(1, 4, 1);
		glutSolidCube(1.0);	//right
		glPopMatrix();
	}
	glPopMatrix();
}

void Robot::DrawBeige()
{
	glPushMatrix();
	{
		if (m_RobotDir == LEFT)		{ glTranslated(m_Pos.x + 2, m_Pos.y, m_Pos.z); glRotated(+30, 0, 0, 1); }
		if (m_RobotDir == RIGHT)	{ glTranslated(m_Pos.x - 2, m_Pos.y, m_Pos.z); glRotated(-30, 0, 0, 1); }
		if (m_RobotDir == UP)			{ glTranslated(m_Pos.x, m_Pos.y, m_Pos.z + 2); glRotated(-30, 1, 0, 0); }
		if (m_RobotDir == DOWN)	{ glTranslated(m_Pos.x, m_Pos.y, m_Pos.z - 2); glRotated(+30, 1, 0, 0); }

		glRotated(m_RobotDir, 0, 1, 0);

		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, &CapeCtrlPts[0][0][0]);
		glEnable(GL_MAP2_VERTEX_3);
		
		glMapGrid2f(3, 0.0, 1.0, 5, 0.0, 1.0);
		glEvalMesh2(GL_LINE, 0, 3, 0, 5);

		glDisable(GL_MAP2_VERTEX_3);
	}
	glPopMatrix();



	//-----------------wave---------------
	
	if (m_CapeTimer > 10)
	{
		CapeWaveNum = (++CapeWaveNum) % 3; //0,1,2
		m_CapeTimer = 0;
	}
	else ++m_CapeTimer;
	
	if (CapeWaveNum == 1)
	{
		CapeCtrlPts[0][0][2] -= 1.0;
		CapeCtrlPts[0][1][2] += 1.0;
		CapeCtrlPts[0][2][2] += 1.0;
	}
	else
	{
		CapeCtrlPts[0][0][2] += 0.5;
		CapeCtrlPts[0][1][2] -= 0.5;
		CapeCtrlPts[0][2][2] -= 0.5;
	}
}

