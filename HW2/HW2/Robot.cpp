#include "Robot.h"
#include <GL/freeglut.h>

Robot::Robot()
{
}

Robot::~Robot()
{
}

void Robot::Move()
{
	if (m_MoveX)
	{
		if (CheckCollision())
		{
			m_MoveX = false;
			ParticleStart();

			m_dir *= -1;
		}
		m_Pos.x += m_dir * 1;
	}
}

bool Robot::CheckCollision()
{
	return false;
}

void Robot::ParticleStart()
{
	if (false == m_bParticle)
	{
		m_bParticle = true;
		m_timer = 0;

		for (int j = 0; j < 20; ++j)
			m_vParticles.push_back(Particle{ m_Pos.x,m_Pos.z });
	}
}

void Robot::ParticleProcess()
{
	if (m_bParticle)
	{
		for (int i = 0; i < m_vParticles.size(); ++i)
		{
			++m_timer;
			m_vParticles[i].Update();
		}
		if (m_timer == 200)
		{
			m_bParticle = false; 
			m_timer = 0;
			m_vParticles.clear();
		}
	}
}

void Robot::Draw()
{
	glLoadIdentity();

	glPushMatrix();
	glTranslated(m_Pos.x, m_Pos.y, m_Pos.z); 
	glRotated(m_dir, 0, 1, 0);   
	glTranslated(-m_Pos.x, -m_Pos.y, -m_Pos.z);

	//¸Ó¸®
	glPushMatrix();
	CYAN;
	glTranslated(m_Pos.x, m_Pos.y + 5, m_Pos.z);
	glScaled(3.f, 3.f, 1.f);
	glutSolidCube(1.0);
	glPopMatrix();
	//ÄÚ
	glPushMatrix();
	RED;
	glTranslated(m_Pos.x, m_Pos.y + 5, m_Pos.z + 1);
	glutSolidSphere(0.5, 5, 5);
	glPopMatrix();
	//¸öÅë
	glPushMatrix();
	glColor3f(0.38f, 0.75f, 1.f);
	glTranslated(m_Pos.x, m_Pos.y, m_Pos.z);
	glScaled(2.f, 3.f, 1.f);
	glutSolidCube(2.0);
	glPopMatrix();

	//ÆÈ
	glPushMatrix();
	WHITE;
	glTranslated(m_Pos.x - 2.5, m_Pos.y, m_Pos.z);
	glRotated(-30, 0, 0, 1);
	glTranslated(0, 2, 0);
	glRotated(m_DegreeForArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);//¿ÞÆÈ
	glPopMatrix();

	glPushMatrix();
	YELLOW;
	glTranslated(m_Pos.x + 2.5, m_Pos.y, m_Pos.z);
	glRotated(30, 0, 0, 1);
	glTranslated(0, 2, 0);
	glRotated(-m_DegreeForArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);	//¿À¸¥ÆÈ
	glPopMatrix();

	//´Ù¸®
	glPushMatrix();
	BLACK;
	glTranslated(m_Pos.x - 1.5, m_Pos.y - 5.0, m_Pos.z);
	glTranslated(0, 2, 0);
	glRotated(-m_DegreeForArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);	//¿Þ´Ù¸®
	glPopMatrix();

	glPushMatrix();
	GREEN;
	glTranslated(m_Pos.x + 1.5, m_Pos.y - 5.0, m_Pos.z);
	glTranslated(0, 2, 0);
	glRotated(m_DegreeForArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);	//¿À¸¥ÂÊ´Ù¸®
	glPopMatrix();

	glPopMatrix();

}

