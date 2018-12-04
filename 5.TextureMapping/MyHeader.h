#pragma once
static int WINDOW_WIDTH = 800;
static int WINDOW_HEIGHT = 800;

GLint p0[3] = { 10, 10, 10 };
GLint p1[3] = { -10, 10, 10 };
GLint p2[3] = { -10, -10, 10 };
GLint p3[3] = { 10, -10, 10 };

GLint p4[3] = { 10, 10, -10 };
GLint p5[3] = { -10, 10, -10 };
GLint p6[3] = { -10, -10, -10 };
GLint p7[3] = { 10, -10, -10 };

#define Vertex0 glVertex3iv(p0)
#define Vertex1 	glVertex3iv(p1)
#define Vertex2 glVertex3iv(p2)
#define Vertex3 glVertex3iv(p3)

#define Vertex4 glVertex3iv(p4); 
#define Vertex5 glVertex3iv(p5);
#define Vertex6 glVertex3iv(p6); 
#define Vertex7 glVertex3iv(p7);



struct MyVec
{
	double x, y, z;
};

MyVec operator +(MyVec &a, MyVec &b)
{
	MyVec val;

	val.x = a.x + b.x;
	val.y = a.y + b.y;
	val.z = a.z + b.z;

	return val;
}

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

inline GLfloat* Cross(const GLfloat* v1, const GLfloat *v2)
{
	//GLfloat val[3]; --------------------두개 차이 꼭 비교해보자잉
	GLfloat* val = new GLfloat[3];

	val[0] = v1[1] * v2[2] - v1[2] * v2[1];
	val[1] = v1[2] * v2[0] - v1[0] * v2[2];
	val[2] = v1[0] * v2[1] - v1[1] * v2[0];

	return val;
}

inline GLfloat* Minus(const GLfloat* v1, const GLfloat *v2)
{
	GLfloat* val = new GLfloat[3];

	val[0] = v2[0] - v1[0];
	val[1] = v2[1] - v1[1];
	val[2] = v2[2] - v1[2];

	return val;
}