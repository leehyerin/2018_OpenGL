#pragma once

#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#define  WINDOW_WIDTH_HALF 500
#define  WINDOW_HEIGHT_HALF 300

struct POINT2D {
	double x, y;
};

struct SHAPE{
	POINT2D dest;
	double centerX;
	double	centerY;
	double degree;
};

struct REST {
	POINT2D dest;
	double centerX;
	double	centerY;
	double degree;
	double destdegree;
	double active = true;
};

inline SHAPE* CreateShape()//constructor
{
	SHAPE* p = new SHAPE{
		POINT2D{ -WINDOW_WIDTH_HALF,WINDOW_HEIGHT_HALF * 0.85 + 20 },
		-WINDOW_WIDTH_HALF ,
		WINDOW_HEIGHT_HALF * 0.85,
		0 };

	return p;
}

static float MAX_COLOR = 256;
#define RAND_COLOR	(rand() % 256)/ MAX_COLOR

#define MoveX(iter) (*iter)->centerX += 2
#define CheckXSide(iter) (((*iter)->centerX > WINDOW_WIDTH_HALF)? 1:  0)
#define CheckYSide(y) ((y >= WINDOW_HEIGHT_HALF)? 1:  0)
#define AddDegree(iter) (*iter)->degree += 5
#define CheckActive(y) if (y > WINDOW_HEIGHT_HALF * 0.7)	glColor3f(0.35f, 0.35f, 0.35f) ; else glColor3f(1.f, 1.f, 1.f)
#define CheckDirFlow(rad) ((rad > 40 || rad < 20)? 1:0)


#define Gravity 0.98
#define RADIAN 0.0174532

enum SPLIT_STATE {
	UNSPLIT,
	SPLIT,
	AFTER_SPLIT
};

enum SPLIT_DIR {
	ACROSS,
	DOWN,
	DOWN_UP, 
	UP_DOWN
};