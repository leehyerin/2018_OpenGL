#pragma once
#include <iostream>
#include <vector>
using namespace std;

static int WINDOW_WIDTH_HALF = 400;
static int WINDOW_HEIGHT_HALF = 400;

struct Point2D
{
	double x, z;
};

struct MyVec
{
	double x, y, z;
};

inline MyVec operator +(MyVec &a, MyVec &b)
{
	MyVec val;

	val.x = a.x + b.x;
	val.y = a.y + b.y;
	val.z = a.z + b.z;

	return val;
}

inline MyVec operator *(MyVec &a, double m)
{
	MyVec val;

	val.x = a.x * m;
	val.y = a.y * m;
	val.z = a.z * m;

	return val;
}

enum View 
{
	TOPVIEW,
	SIDEVIEW,
	QUARTERVIEW
};

enum WeatherType
{
	SNOWING,
	RAINNING,
	SUNNY
};

#define CheckColl(mX,mY,pX,pY) 	((mX - 10 <= pX) && (pX <= mX + 10) && (mY - 10 <= pY) && (pY <= mY + 10))? true:  false
#define CheckNarrowColl(mX,mY,pX,pY) 	((mX - 1 <= pX) && (pX <= mX + 1) && (mY - 1 <= pY) && (pY <= mY + 1))? true:  false
#define CheckLargeColl(mX,mY,pX,pY) 	((mX - 20 <= pX) && (pX <= mX + 20) && (mY - 20 <= pY) && (pY <= mY + 20))? true:  false
#define CheckBoundary(min,max,val) ((min<=val) && (val<=max))? true: false 

#define Curve3Point( t, v1, v2, v3 )			((2 * t*t - 3 * t + 1)*v1   +  (-4 * t*t + 4 * t)*v2 +(2 * t*t - t) *v3)
#define Curve4Point( t, v1, v2, v3,v4 )		((-t*t*t + 2 * t*t - t)*v1 + (3 * t*t*t - 5 * t*t + 2)*v2 + (-3 * t*t*t + 4 * t*t + t)*v3 + (t*t*t - t*t)*v4) / 2


#define STEP		2
//--------------Direction----------------
#define LEFT		-90
#define RIGHT	 90
#define UP			-180
#define DOWN	0

//----------------Color-----------------
#define RED				glColor3f(1.f, 0.f, 0.f)
#define WHITE			glColor3f(1.f, 1.f, 1.f)
#define GREEN			glColor3f(0.0f, 1.0f, 0.0f)
#define BLACK			glColor3f(0.0f, 0.0f, 0.0f)
#define YELLOW			glColor3f(1.0f, 1.0f, 0.0f)
#define BLUE				glColor3f(0.0f, 0.0f, 1.0f)
#define CYAN				glColor3f(0.0f, 1.0f, 1.0f)
#define MAGENTA		glColor3f(1.0f, 0.0f, 1.0f)
#define BROWN			glColor3f(0.6f, 0.3f, 0.06f)
#define SOIL				glColor3f(0.5f, 0.4f, 0.22f)


//--------------------------------------------------
class Particle
{
public:
	MyVec pos;
	MyVec dir;

	Particle(double x, double z)
	{
		pos.x = x + rand() % 6 - 3;
		pos.y = 3 + rand() % 6 - 3;
		pos.z = z + rand() % 6 - 3;

		dir.x = rand() % 2;
		dir.y = rand() % 2;
		dir.z = rand() % 2;

		double len = sqrt(dir.x*dir.x + dir.y*dir.y + dir.z*dir.z);
		dir.x /= len;
		dir.y /= len;
		dir.z /= len;
	}

	inline void Update()
	{
		pos = pos + dir;
	}
};

class Bullet
{
public:
	MyVec pos;
	MyVec dir;

	Bullet(double x, double z, int RobotDir)
	{
		pos.x = x;
		pos.y = 5;
		pos.z = z;

		if (RobotDir == LEFT)			 { dir.x = -1; dir.z = 0; }
		else if (RobotDir == RIGHT) { dir.x = +1; dir.z = 0; }
		else if (RobotDir == UP)		 { dir.x =0;	dir.z = -1; }
		else if (RobotDir == DOWN) { dir.x =0;	dir.z = +1; }

		dir.y = 0;

		dir = dir * 3.0;
	}

	inline void Update()
	{
		pos = pos + dir;
	}
};

class Train 
{
public:
	MyVec pos;
	MyVec dir;

	inline void SetPos(MyVec p)
	{
		pos = p;
	}
	inline void SetDir(MyVec d)
	{
		dir = d;

		Normalize();
	}
	inline void ChangeDir(MyVec* d)
	{
		dir.x = d->x;
		dir.y = d->y;
		dir.z = d->z;

		Normalize();
	}

	inline void Normalize()
	{
		double len = sqrt(dir.x*dir.x + dir.y*dir.y + dir.z*dir.z);
		dir.x /= len;
		dir.y /= len;
		dir.z /= len;
	}

	inline void Update()
	{
		if (dir.y <= 0)
			dir = dir * 2.0;
		else 
			dir = dir *0.5;

		pos = pos + dir;
	}
};