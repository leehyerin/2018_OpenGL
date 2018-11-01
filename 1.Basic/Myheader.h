#pragma once

#include <ctime>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

extern const int WINDOW_WIDTH = 1400;
extern const int WINDOW_HEIGHT = 800;

enum ShapeType
{
	RECTANGLE = 0,
	TRIANGLE = 1
};

enum ShapeStatus
{
	DEFAULT = 0,
	ROTATING = 1
};


#define	CUBE			0
#define	CYLINDER	1
#define	TEAPOT		2
#define	SPHERE		3

struct myVec{
	double x, y, z;
};

#define FORWARD  0
#define REVERSE  1

typedef struct
{
	float x;
	float y;
	float speed;
	float xdir;
	float ydir;
	ShapeType type;
	ShapeStatus status;
} Point2D;


#define MAX_RADIUS 50
#define ADD 1
#define MINUS -1
int radius = 50;
int radiusStatus = MINUS;

#define PI 3.141592
#define RADIAN 0.0174532

static float MAX_COLOR = 256;
#define RAND_COLOR	(rand() % 256)/ MAX_COLOR
float R = 1.f;
float G = 1.f;
float B = 1.f;

typedef struct {
	int x, y;
	double rad;
	double SaveRad;
	int rotate_dir;
	int degree;
	float dir;
	double tmpX, tmpY;
} Shape;


typedef struct {
	float r, g, b;
	double scale;
	double x, y;
	//»∏¿¸√‡
	double axisX, axisY, axisZ;
	int shape_type;
} Shape3D;
