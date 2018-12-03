#include "Weather.h"
#include <GL/freeglut.h>

Weather::Weather()
{
	m_isFalling = true;
	m_type = SUNNY;
}


Weather::~Weather()
{
}


void Weather::Falling()
{
	bool col = false;
	unsigned int idx = 0;
	if (m_isFalling && m_type!=SUNNY)
	{
		for (unsigned int i = 0; i < vParticles.size(); ++i)
		{
			if (vParticles[i].y > 0)
			{
				vParticles[i].y -= 3.0;
			}
			else
			{
				vParticles.erase(vParticles.begin() + i);

				/*col = CheckCollsionbyFloor(i);
				if (col) idx = i;*/
			}
		}

		/*if (col)
		{
			vParticles.erase(vParticles.begin() + idx);
		}*/
		CreateParticles();

	}
}

bool Weather::CheckCollsionbyFloor(int idx)
{
	if (vParticles[idx].y < 0) return true;
	else 	return false;
}

void Weather::CreateParticles()
{
	double x = rand() % 400 - 200;
	double z = rand() % 400 - 200;

	vParticles.push_back(MyVec{ x,100.0,z });
}


void Weather::Draw()
{
	/*GLfloat emi[] = { 1.f,1.f,1.f,1.f };
	glMaterialfv(GL_FRONT, GL_EMISSION, emi);*/
	if (m_type != SUNNY)
	for (auto d : vParticles)
	{
		glPushMatrix();
		glTranslated(d.x, d.y, d.z);

		if (m_type == SNOWING)			{ WHITE;	glutSolidSphere(2.0, 25, 25);}
		else if (m_type == RAINNING)		{ BLUE; glScaled(1, 4, 1); glutSolidCube(2.0);}

		glPopMatrix();
	}
}

void Weather::ToggleWeather()
{
	if (m_type == SNOWING)			m_type = RAINNING;
	else if (m_type == RAINNING)		{ m_type = SUNNY; vParticles.clear(); }
	else if (m_type == SUNNY)			m_type = SNOWING;
}
