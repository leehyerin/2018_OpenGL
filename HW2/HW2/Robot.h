#pragma once
#include "MyHeader.h"
#include <GL/freeglut.h>

class Robot
{
	MyVec m_Pos{ 0,10,10 };
	double m_DegreeForArms;
	int m_ArmDir;

	int m_RobotDir;
	int m_Sign;
	bool m_MoveX, m_MoveZ;
	//
	bool m_bParticle;
	int m_Timer;
	int m_CapeTimer;
	vector<Particle> m_vParticles;
	vector<Bullet> m_vBullet;
	//
	GLfloat CapeCtrlPts[3][3][3] =
	{
		{ { -4.0, -4.0, 0.0 },{0.0, -4.0, -4.0 },{ 4.0, -4.0, 0.0 } },
		{ { -4.0, 0.0, 0.0 },{ 0.0, 0.0, -4.0 },{ 4.0, 0.0, 0.0 } },
		{ { -4.0, 4.0, 0.0 },{ 0.0, 4.0, -4.0 },{ 4.0, 4.0, 0.0 } }
	};
	int CapeWaveNum{ 0 };
public:
	Robot();
	Robot(double x, double y, double z);
	~Robot();
	double GetterPosX() { return m_Pos.x; }
	double GetterPosY() { return m_Pos.y; }
	double GetterPosZ() { return m_Pos.z; }
	int GetterDir() {return m_RobotDir;}

	void Move(); 
	void ChangeToDestDir(int destDir);
	void ChangeFromCurrDir(int currDir);
	bool CheckCollisionRobotbyObject();
	//--------------------------
	void ParticleStart(int idx);
	void ParticleProcess();
	void ParticleDraw();

	void ShotBullet();
	void ArmUpdate();
	void BulletUpdate();
	void BulletDraw();
	void Draw();
	void DrawBeige();
};

