#include <vector>
#include <iterator>
using namespace std;

inline void MoveLeftX(MyCube* p)
{
	if (p->m_pos.x > -10 + (p->m_size*0.7))	p->m_pos.x -=  0.2;
}

inline void MoveRightX(MyCube* p)
{
	if (p->m_pos.x < 10 - (p->m_size*0.7))	p->m_pos.x +=  0.2;
}
//
inline void MoveLeftY(MyCube* p)
{
	if (p->m_pos.y > -10 + (p->m_size*0.7))	p->m_pos.y -= 0.2;
}

inline void MoveRightY(MyCube* p)
{
	if (p->m_pos.y < 10 - (p->m_size*0.7))	p->m_pos.y += 0.2;
}
//
void MoveX(int dir, MyCube* p)
{
	if (dir == -1) 
	{
		MoveLeftX(p);
		MoveLeftX(p + 1);
		MoveLeftX(p + 2);
	}
	else 
	{
		MoveRightX(p);
		MoveRightX(p + 1);
		MoveRightX(p + 2);
	}
}

void MoveY(int dir, MyCube* p)
{
	if (dir == -1)
	{
		MoveLeftY(p);
		MoveLeftY(p + 1);
		MoveLeftY(p + 2);
	}
	else
	{
		MoveRightY(p);
		MoveRightY(p + 1);
		MoveRightY(p + 2);
	}
}

//balls
struct Ball
{
	MyVec m_pos;
	MyVec m_dir;
	double m_speed;
};

