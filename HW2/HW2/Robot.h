#pragma once
#include "MyHeader.h"

class Robot
{
	MyVec m_Pos{ 0,5,10 };
	double m_DegreeForArms, m_RobotDir;
	bool m_MoveX, m_MoveZ;
	int m_dir{ 1 };

	bool m_bParticle;
	int m_timer;
	vector<Particle> m_vParticles;

public:
	Robot();
	~Robot();
	void Move(); 
	bool CheckCollision();
	//--------------------------
	void ParticleStart();
	void ParticleProcess();

	void Draw();
};

