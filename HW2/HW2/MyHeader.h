#pragma once
#include <iostream>
#include <vector>
using namespace std;

static int WINDOW_WIDTH_HALF = 400;
static int WINDOW_HEIGHT_HALF = 400;


struct Point2D
{
	double x, y;
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

enum View 
{
	TOPVIEW,
	SIDEVIEW,
	QUARTERVIEW
};

//--------------Direction----------------

#define LEFT		-90
#define RIGHT	 90
#define UP			-180
#define DOWN	0


//----------------Color-----------------
#define RED			glColor3f(1.f, 0.f, 0.f)
#define WHITE		glColor3f(1.f, 1.f, 1.f)
#define GREEN		glColor3f(0.0f, 1.0f, 0.0f)
#define BLACK		glColor3f(0.0f, 0.0f, 0.0f)
#define YELLOW		glColor3f(1.0f, 1.0f, 0.0f)
#define BLUE			glColor3f(0.0f, 0.0f, 1.0f)
#define CYAN			glColor3f(0.0f, 1.0f, 1.0f)
#define MAGENTA	glColor3f(1.0f, 0.0f, 1.0f)
#define BROWN		glColor3f(0.6f, 0.3f, 0.06f)
#define SOIL			glColor3f(0.6f, 0.34f, 0.12f)
