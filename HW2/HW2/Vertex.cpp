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
	{
		m_vVertex.push_back(MyVec{ x,y,z });
	}
}

void Vertex::MouseMotion(double a, double b, View view)
{
	vector<MyVec>::iterator d = m_vVertex.begin();
	double* A,* B;

	for (d; d != m_vVertex.end(); ++d)
	{
		if (view == TOPVIEW)			
		{
			A = &d->x; 
			B = &d->z; 

			if (CheckColl(a, b, *A, *B))
			{
				*A = a;		
				*B = b;
			}
		}

		else if (view == SIDEVIEW)	
		{
			A = &d->x;
			B = &d->y; 

			if (CheckColl(a, -b, *A, *B))
			{
				*B = -b;
			}
		}
		else break;
	}
}

void Vertex::DrawVertices()
{
	GLUquadricObj *qobj = gluNewQuadric();

	glPointSize(10.0);
	glBegin(GL_POINTS);
	for (auto d : m_vVertex)
	{
		WHITE;
		glBegin(GL_POINTS);
		glVertex3d(d.x, d.y, d.z);
		glEnd();
		YELLOW;
		glPushMatrix();
			glTranslated(d.x, d.y, d.z);
			glRotated(90, 1, 0, 0);
			gluCylinder(qobj, 5.0, 5.0, d.y, 20, 8);
		glPopMatrix();
	}
	glEnd();
}

void Vertex::DrawSpline()
{
	if (m_vVertex.size() >= 3)
	{
		glBegin(GL_LINES);
		glLineWidth(20.0);
		WHITE;
		
		double prevX{ 0 }, prevY{ 0 }, prevZ{ 0 }, currX, currY, currZ;

		for (unsigned int j = 0; j < m_vVertex.size(); ++j)
		{
			auto cnt = m_vVertex.size();

			for (double i = 0; i < 50; ++i)
			{
				double t = i / 50.0;

				currX = Curve4Point(t, m_vVertex[j % cnt].x, m_vVertex[(j + 1) % cnt].x, m_vVertex[(j + 2) % cnt].x, m_vVertex[(j + 3) % cnt].x);
				currY = Curve4Point(t, m_vVertex[j % cnt].y, m_vVertex[(j + 1) % cnt].y, m_vVertex[(j + 2) % cnt].y, m_vVertex[(j + 3) % cnt].y);
				currZ = Curve4Point(t, m_vVertex[j % cnt].z, m_vVertex[(j + 1) % cnt].z, m_vVertex[(j + 2) % cnt].z, m_vVertex[(j + 3) % cnt].z);

				if (i != 0) {glVertex3d(prevX, prevY, prevZ); glVertex3d(currX, currY, currZ); }
				
				m_vSlop.push_back(pair< Point2D, MyVec > {Point2D{ prevX,prevZ }, MyVec{ currX - prevX,currY - prevY, currZ - prevZ }});

				prevX = currX;		prevY = currY;	prevZ = currZ;
			}
		}			
		glEnd();
	}

	if (m_isTrainStart)
	{
		MoveTrain();
	}		
	
	m_vSlop.clear();
	
}

void Vertex::SetTrainInitState()
{
	if (m_vVertex.size() >= 2)
	{
		m_Train.SetPos(MyVec{ m_vVertex[0].x,m_vVertex[0].y,m_vVertex[0].z });

		m_Train.SetDir(MyVec{ m_vVertex[1].x - m_vVertex[0].x,
			m_vVertex[1].y - m_vVertex[0].y ,
			m_vVertex[1].z - m_vVertex[0].z });

		m_vSlop.push_back(pair< Point2D, MyVec > {
			Point2D{ m_vVertex[0].x, m_vVertex[0].z },
				MyVec{ m_vVertex[1].x - m_vVertex[0].x,
				m_vVertex[1].y - m_vVertex[0].y ,
				m_vVertex[1].z - m_vVertex[0].z }});
	}
}

void Vertex::MoveTrain()
{
	for (unsigned int i = 0; i < m_vSlop.size(); ++i)
	{	
		if (CheckNarrowColl(m_vVertex[0].x, m_vVertex[0].z, m_Train.pos.x, m_Train.pos.z))
		{
			if (!m_isFirst)
			{
				SetTrainInitState();
				m_isFirst = true;
				break;
			}
			else m_isFirst = true;

		}
		else m_isFirst = false;

		if (CheckLargeColl(m_vSlop[i].first.x, m_vSlop[i].first.z,m_Train.pos.x, m_Train.pos.z))
		{
			
			m_Train.ChangeDir(&m_vSlop[i].second);
			break;
		}
	}

	m_Train.Update(); 


	//-----------------draw-----------------
	glPushMatrix();
		glTranslated(m_Train.pos.x, m_Train.pos.y, m_Train.pos.z);
		RED;
		glutSolidCube(20.0);
	glPopMatrix();
}

bool Vertex::CheckCollisionRobotbyVertex(double x, double z)
{
	for (unsigned int i=0;i< m_vVertex.size();++i)
	{
		auto d = m_vVertex[i];

		if (CheckColl(x, z, d.x, d.z))
		{
			++m_CollCnt;
			if (m_CollCnt == 2) 
			{
				m_vVertex.erase(m_vVertex.begin() + i);	
				m_CollCnt = 0; 
				SetTrainInitState();
				return false;
			}
			return true;
		}
	}
	return false;
}




