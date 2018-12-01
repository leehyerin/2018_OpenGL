#include "Vertex.h"
#include <iterator>
#include <GL/freeglut.h>

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

void Vertex::Pushback(double x, double y, double z, View view)
{
	if (view == TOPVIEW)
		m_vVertex.push_back(MyVec{ x,y,z });
}

void Vertex::MouseMotion(double a, double b, View view)
{
	vector<MyVec>::iterator d = m_vVertex.begin();
	double* A,* B;

	for (d; d != m_vVertex.end(); ++d)
	{
		if (view == TOPVIEW)			{ A =&d->x; B = &d->z; }
		else if (view == SIDEVIEW) { A = &d->x; B = &d->y; }
		else break;
		cout << d->y << ", ¸¶¿ì½º" << b <<endl;
		if ((a - 10 <= *A) && (*A <= a + 10) && (b - 10 <= *B) && (*B <= b + 10))
		{
			*A = a;  

			if (view == SIDEVIEW) *B = -b;	 			else	*B = b;
		}
	}
}

void Vertex::DrawVertices()
{
	WHITE;
	glPointSize(10.0);
	glBegin(GL_POINTS);
	for (auto d : m_vVertex)
	{
		glVertex3d(d.x, d.y, d.z);
	}
	glEnd();
}

