#include "MyDefine.h"

GLvoid drawScene(GLvoid);
GLvoid Reshape(int, int );
void DefaultTimer(int);
void CreateTriangleTimer(int);
void ChangeColorTimer(int);
void Keyboard(unsigned char, int, int);
void Mouse(int , int , int , int y);
void MouseMotion(int x, int y);

void SetupRC();
void InitRectangle();
void InitSplitTriangles(SPLIT_DIR);

void ProcessUpperSection();
void ProcessMidSection();
void ProcessLowerSection();

void CheckStarCollision();
void CheckPointCollision();
void CheckLineCollision();
float FreeFall(float, float);

void DrawLine(double, double, double, double);
void DrawTriangle(SHAPE* );
void DrawSplitTriangle(REST*);
void DrawRestTriangles(REST*);
void DrawRectangle(double , double , double );
void DrawStar(SHAPE*);

vector<SHAPE*> vTriangles;
vector<SHAPE*>::iterator triIter;
vector<SHAPE*> vStars;
vector<SHAPE*>::iterator starIter;
vector<REST*> vRests;
vector<REST*>::iterator restIter;


SHAPE sRectangle;
REST* sTriangle[2];
POINT2D sPrevPoint, sCurrPoint;
POINT2D sLeftPos, sRightPos;
//
bool bMouseFlag, bMouseTriangle0, bMouseTriangle1;
SPLIT_STATE eRectagleSplit;
float R, G, B;
double rad;
double dir;
float degree, falltime = 0;
double iLeft, iRight, iLeftStep, iRightStep;

int main(int argc, char *argv[]) 
{ 
	glutInit (&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition ( 0, 0 );
	glutInitWindowSize (WINDOW_WIDTH_HALF*2, WINDOW_HEIGHT_HALF*2);
	glutCreateWindow ( "HW1" ); 
	SetupRC();

	 //---------------콜백 함수--------------------
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);   //마우스 클릭
	glutMotionFunc(MouseMotion); //마우스 이동할 때
	glutTimerFunc(100, DefaultTimer, 1);
	glutTimerFunc(5000, CreateTriangleTimer, 2);
	glutTimerFunc(1000, ChangeColorTimer, 3);
	glutReshapeFunc(Reshape);

	glutMainLoop(); 
} 

void SetupRC()
{
	//-----Upper Section Triangle-----
	auto t = CreateShape();

	vTriangles.push_back(t);

	//-----Mid Section Rectangle------
	InitRectangle();

	//-----Varaibles Initialization------
	bMouseFlag = bMouseTriangle0 = bMouseTriangle1 = false;
	eRectagleSplit = UNSPLIT;
	R = 1.f, G = 1.f, B = 1.f;
	rad = 40;
	dir = 1;
	sTriangle[0] = sTriangle[1] = new REST{ POINT2D{0,20},0,0,0,0 };
	sLeftPos = POINT2D{ -WINDOW_WIDTH_HALF, -WINDOW_HEIGHT_HALF};
	sRightPos = POINT2D{ +WINDOW_WIDTH_HALF,-WINDOW_HEIGHT_HALF };
	iLeft = iRight = 0.1;
	iLeftStep = iRightStep = 0.0;
}

void InitRectangle()
{
	eRectagleSplit = UNSPLIT;

	sRectangle.centerX = 0;
	sRectangle.centerY = -WINDOW_HEIGHT_HALF;
	auto div = (double)(rand() % 2 + 1);  // 1 or 2
	sRectangle.degree = 90.0 / div;
}

void InitSplitTriangles(SPLIT_DIR dir)
{
	eRectagleSplit = SPLIT;

	iLeft += 0.1;
	if (iLeft == 0.7) { iLeft = 0; iLeftStep += 0.2; }
	iRight += 0.1;
	if (iRight == 0.7) { iRight = 0; iRightStep += 0.2; }
	
	sLeftPos = POINT2D{ -WINDOW_WIDTH_HALF * (1.0 - iLeft), -WINDOW_HEIGHT_HALF * (1.0 - iLeftStep) };
	sRightPos = POINT2D{ WINDOW_WIDTH_HALF * (1.0 - iRight), -WINDOW_HEIGHT_HALF * (1.0 - iRightStep) };

	switch (dir)
	{
		REST* p1;
		REST* p2;

	case ACROSS:
		p1 = new REST{ sLeftPos ,sRectangle.centerX, sRectangle.centerY + 20,0, 45};
		p2 = new REST{ sRightPos, sRectangle.centerX, sRectangle.centerY - 20 ,180,225 };
		vRests.push_back(p1);
		vRests.push_back(p2);

		sTriangle[0] = p1;
		sTriangle[1] = p2;
		break;

	case DOWN:
		p1 = new REST{ sLeftPos,sRectangle.centerX - 20, sRectangle.centerY ,90,45 };
		p2 = new REST{ sRightPos, sRectangle.centerX + 20, sRectangle.centerY  ,-90,225 };
		vRests.push_back(p1);
		vRests.push_back(p2);

		sTriangle[0] = p1;
		sTriangle[1] = p2;
	
		break;
	case DOWN_UP:
		p1 = new REST{ sLeftPos,sRectangle.centerX - 20, sRectangle.centerY + 20,45,45 };
		p2 = new REST{ sRightPos, sRectangle.centerX + 20, sRectangle.centerY - 20  ,-135,225 };
		vRests.push_back(p1);
		vRests.push_back(p2);

		sTriangle[0] = p1;
		sTriangle[1] = p2;
		break;

	case UP_DOWN:
		p1 = new REST{  sLeftPos,sRectangle.centerX - 20, sRectangle.centerY-20 ,135.45 };
		p2 = new REST{ sRightPos, sRectangle.centerX + 20, sRectangle.centerY +20 ,-45.225 };
		vRests.push_back(p1);
		vRests.push_back(p2);

		sTriangle[0] = p1;
		sTriangle[1] = p2;
		break;
	}

}

GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); 

	ProcessUpperSection();
	ProcessMidSection();
	ProcessLowerSection();

	DrawLine(sPrevPoint.x, sPrevPoint.y, sCurrPoint.x, sCurrPoint.y);

	glFlush();
}

void ProcessUpperSection()
{
	for (triIter = vTriangles.begin(); triIter != vTriangles.end();)
	{
		MoveX(triIter);
		DrawTriangle(*triIter);

		if (CheckXSide(triIter)) { triIter = vTriangles.erase(triIter);	} 
		else { ++triIter; }
	}
}

void ProcessMidSection()
{
	if (CheckYSide(sRectangle.centerY)) InitRectangle();

	if (eRectagleSplit == SPLIT)
	{
		DrawSplitTriangle(sTriangle[0]);
		DrawSplitTriangle(sTriangle[1]);
	}
	else if (eRectagleSplit == UNSPLIT)
	{
		sRectangle.centerY += 3;
		DrawRectangle(sRectangle.centerX, sRectangle.centerY, sRectangle.degree);
	}
	else InitRectangle();

	for (starIter = vStars.begin(); starIter != vStars.end(); ++starIter)
		DrawStar(*starIter);
}

void ProcessLowerSection()
{
	glColor3f(1.f, 1.f, 1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_LINES);
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	for (int i = 0; i < 5; ++i)
	{
			glVertex2d(-WINDOW_WIDTH_HALF			, - WINDOW_HEIGHT_HALF * 0.5 * (i * 0.2 + 1));
			glVertex2d(-WINDOW_WIDTH_HALF * 0.1, - WINDOW_HEIGHT_HALF * 0.5 * (i * 0.2 + 1));
	}
	//											ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	for (int i = 0; i < 5; ++i)
	{
		glVertex2d(WINDOW_WIDTH_HALF * 0.1, -WINDOW_HEIGHT_HALF * 0.5 * (i * 0.2 + 1));
		glVertex2d(WINDOW_WIDTH_HALF		   , -WINDOW_HEIGHT_HALF * 0.5 * (i * 0.2 + 1));
	}

	//| | | | | | | | | | | | | | |            | | | | | | | | | | | | | | |
	for (int i = 1; i < 20; ++i)
	{
		if (i !=10)
		{
			glVertex2d(WINDOW_WIDTH_HALF *( i * 0.1-1), -WINDOW_HEIGHT_HALF * 0.5);
			glVertex2d(WINDOW_WIDTH_HALF * (i * 0.1-1), -WINDOW_HEIGHT_HALF);
		}
	}
	// / / / / / / / / / /           
	for (int i = 0; i < 10; ++i)
	{
			glVertex2d(-WINDOW_WIDTH_HALF, -WINDOW_HEIGHT_HALF * 0.5 * (i * 0.2 + 1));
			glVertex2d(WINDOW_WIDTH_HALF *(i * 0.1 - 1), -WINDOW_HEIGHT_HALF * 0.5);
	}


	//											 ＼＼＼＼＼＼＼＼＼＼
	for (int i = 19; i > 10; --i)
	{
		glVertex2d(WINDOW_WIDTH_HALF, -WINDOW_HEIGHT_HALF * 0.5 * ((i - 10) * 0.2 + 1));
		glVertex2d(WINDOW_WIDTH_HALF *((19 - (i-1)) * 0.1), -WINDOW_HEIGHT_HALF * 0.5);
	}


	//glVertex2d(0, -WINDOW_HEIGHT_HALF );
	//glVertex2d(0, -WINDOW_HEIGHT_HALF * 0.2);


	for (restIter = vRests.begin(); restIter != vRests.end(); )
	{
		if ((*restIter)->active)
		{
			DrawRestTriangles(*restIter); 
			++restIter;
		}
		else restIter = vRests.erase(restIter);
	}


	glEnd();
}

void CheckStarCollision()
{
	for (triIter = vTriangles.begin(); triIter != vTriangles.end(); ++triIter)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (((*triIter)->centerX - 20) <= (sTriangle[i]->centerX + 20) &&
				(sTriangle[i]->centerX - 20) <= ((*triIter)->centerX + 20) &&
				((*triIter)->centerY - 20) <= (sTriangle[i]->centerY + 20) &&
				(sTriangle[i]->centerY - 20) <= ((*triIter)->centerY + 20))
			{
				SHAPE* p = new SHAPE{
					POINT2D{ (double)(rand() % (2 * WINDOW_WIDTH_HALF) - WINDOW_WIDTH_HALF),
									(double)((rand() % WINDOW_HEIGHT_HALF*0.7)) },
					sTriangle[i]->centerX,
					sTriangle[i]->centerY,
					0 };
				vStars.push_back(p);

				cout << "COl" << endl;
				if (triIter + 1 != vTriangles.end()) triIter = vTriangles.erase(triIter);
				sTriangle[i]->active = false;

				eRectagleSplit = AFTER_SPLIT;
				break;
			}
		}
	}
}

void CheckPointCollision()
{
	if (sTriangle[0]->centerX - 20 <= sCurrPoint.x &&  sCurrPoint.x <= sTriangle[0]->centerX + 20 &&
		sTriangle[0]->centerY - 20 <= sCurrPoint.y &&  sCurrPoint.y <= sTriangle[0]->centerY + 20)
	{
		bMouseTriangle0 = true; bMouseTriangle1 = false; 
		
	}
	else bMouseTriangle0 = false;

	if (sTriangle[1]->centerX - 20 <= sCurrPoint.x &&  sCurrPoint.x <= sTriangle[1]->centerX + 20 &&
		sTriangle[1]->centerY - 20 <= sCurrPoint.y &&  sCurrPoint.y <= sTriangle[1]->centerY + 20)
	{
		bMouseTriangle1 = true; bMouseTriangle0 = false;
	}
	else bMouseTriangle1 = false;
}

void CheckLineCollision()
{
	double m = (sPrevPoint.y - sCurrPoint.y) / (sPrevPoint.x - sCurrPoint.x);
	
	double x = sRectangle.centerX;
	double y = sRectangle.centerY;

	if (sRectangle.degree == 45) 
	{
		if (-0.2 <= m && m <= 0.2)
		{
			if ((m *(x - sCurrPoint.x) + sCurrPoint.y - 10) <= y &&
				(m *(x - sCurrPoint.x) + sCurrPoint.y + 10) >= y)
			{
				InitSplitTriangles(ACROSS);
			}
		}
		else if (-2.0 >= m || m >= 2.0)
		{
			if (((y - sCurrPoint.y) / m + sCurrPoint.x - 10) <= x && 
				((y - sCurrPoint.y) / m + sCurrPoint.x + 10) >= x )
			{
				InitSplitTriangles(DOWN);
			}
		}			
	}
	//
	else if (sRectangle.degree == 90)
	{
		if (-1.2 <= m && m <= -0.8)
		{
			if ((m *(x - sCurrPoint.x) + sCurrPoint.y - 10) <= y &&
				(m *(x - sCurrPoint.x) + sCurrPoint.y + 10) >= y)
			{
				InitSplitTriangles(UP_DOWN);
			}
		}
		else if (0.8 <= m && m <= 1.2)
		{
			if (((y - sCurrPoint.y) / m + sCurrPoint.x - 10) <= x &&
				((y - sCurrPoint.y) / m + sCurrPoint.x + 10) >= x)
			{
				InitSplitTriangles(DOWN_UP);
			}
		}
	}
}

float FreeFall(float falltime, float degree)
{
	float y = tan(degree * RADIAN) * falltime - 9.8f / (2 * 2 * 2 * cos(degree * RADIAN) * cos(degree * RADIAN)) * falltime * falltime;

	return y;
}

void DrawLine(double prevX, double prevY, double currX, double currY)
{
	if (bMouseFlag)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity(); 
		glColor3f(0.7f, 0.3f, 0.8f);
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(2, 0x11ff);
		glLineWidth(2.5);
		glBegin(GL_LINES);
		glVertex2d(prevX, prevY);
		glVertex2d(currX, currY);
		glEnd();

		glDisable(GL_LINE_STIPPLE);
		glLineWidth(1.0);
	}
}

void DrawTriangle(SHAPE* s)
{
	glColor3f(1.f, 1.f, 1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	glPushMatrix();
		glTranslated(s->centerX, s->centerY, 0.0);
		glRotated(s->degree++, 0, 0, 1);
		glBegin(GL_LINE_LOOP);
		//
		glVertex2d(0,20);  
		glVertex2d(-20, -20);
		glVertex2d(+20, -20);
	glPopMatrix();
	//
	glEnd();
	glLoadIdentity();
}

void DrawSplitTriangle(REST* s)
{
	glColor3f(0.5f, 0.5f, 0.5f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslated(s->centerX, s->centerY, 0.0);
	glRotated(s->degree, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	//
	glVertex2d(0, 20);
	glVertex2d(-40, -20);
	glVertex2d(+40, -20);
	glPopMatrix();
	//
	glEnd();
	glLoadIdentity();
}

void DrawRestTriangles(REST* s)
{
	double x, y;

	if ((s->dest.x == (s->centerX)) && (s->dest.y) == (s->centerY));//eRectagleSplit = AFTER_SPLIT;
	else
	{
		s->centerX += (s->dest.x - s->centerX)*0.1;
		s->centerY += (s->dest.y - s->centerY)*0.1;
	}
	if (s->degree != (int)s->destdegree)
	{
		s->degree += 1; if (s->degree >= 360) s->degree = 0;
	}
	x = s->centerX;
	y = s->centerY;

	glColor3f(0.75f, 0.75f, 0.75f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslated(s->centerX, s->centerY, 0.0);
	glRotated(s->degree, 0, 0, 1); 
	glBegin(GL_TRIANGLES);
	//
	glVertex2d(0, 20);
	glVertex2d(-40, -20);
	glVertex2d(+40, -20);
	glPopMatrix();
	//
	glEnd();
	glLoadIdentity();
}

void DrawRectangle(double x, double y, double degree)
{
	CheckActive(y); //color setting

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(x, y, 0);
	glRotated(degree, 0, 0, 1);

	glRectd(-30,  -30,  30,  30);

	glEnd();
	glMatrixMode(GL_MODELVIEW);
}

void DrawStar(SHAPE* s)
{
	double x, y;

	if ((s->dest.x == (s->centerX)) && (s->dest.y) == (s->centerY));
	else
	{
		s->centerX += (s->dest.x - s->centerX)*0.1;
		s->centerY += (s->dest.y - s->centerY)*0.1;
	}
	x = s->centerX;
	y = s->centerY;

	glColor3f(R, G, B);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
		glTranslated(x, y, 0);
		glRotated(s->degree++, 0, 0, 1);
		glBegin(GL_TRIANGLES);

		glVertex2d(0, rad);   
		glVertex2d(0 - rad, - rad/2);
		glVertex2d(0 + rad, - rad/2);

		glColor3f(R/2, G/2, B/2);

		glVertex2d(0, - rad);
		glVertex2d(0 - rad, + rad/2);
		glVertex2d(0 + rad, + rad/2);
	glPopMatrix();
	glEnd();

	rad += dir * 1;
	if(CheckDirFlow(rad)) dir *= -1;
}

GLvoid Reshape(int w, int h) 
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	glOrtho(-WINDOW_WIDTH_HALF, WINDOW_WIDTH_HALF, -WINDOW_HEIGHT_HALF, WINDOW_HEIGHT_HALF, -1.0, 1.0);
}

void DefaultTimer(int value)
{
	//-----
	if (eRectagleSplit == SPLIT)
	{
		if (bMouseTriangle0)
		{
			sTriangle[0]->centerX = sCurrPoint.x;
			sTriangle[0]->centerY = sCurrPoint.y;
		}
		else 			
		{
			sTriangle[1]->centerY -= Gravity;
		}

		if (bMouseTriangle1)
		{
			sTriangle[1]->centerX = sCurrPoint.x;
			sTriangle[1]->centerY = sCurrPoint.y;
		}
		else
		{
			sTriangle[0]->centerY -= Gravity;
		}
		
		CheckStarCollision();
	}
	//-----
	glutPostRedisplay();
	glutTimerFunc(100, DefaultTimer, 1);
}

void CreateTriangleTimer(int value)
{
	auto t = CreateShape();
	vTriangles.push_back(t);

	glutPostRedisplay();
	glutTimerFunc(5000, CreateTriangleTimer, 2);
}

void ChangeColorTimer(int)
{
	R = RAND_COLOR;
	G = RAND_COLOR;
	B = RAND_COLOR;

	glutPostRedisplay();
	glutTimerFunc(1000, ChangeColorTimer, 3);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	case '1':
		eRectagleSplit = AFTER_SPLIT;
		break;
	default:
		break;
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)  //mouse click
		{
			bMouseFlag = true;
			sPrevPoint.x = sCurrPoint.x = x - WINDOW_WIDTH_HALF;
			sPrevPoint.y = sCurrPoint.y = WINDOW_HEIGHT_HALF - y;

			if (eRectagleSplit)	CheckPointCollision();
		}
		else
		{
			bMouseFlag = bMouseTriangle0 = bMouseTriangle1 = false;
	
			CheckLineCollision();
		}
	}
}

void MouseMotion(int x, int y)
{
	if (bMouseFlag)
	{
		sCurrPoint.x = x - WINDOW_WIDTH_HALF;
		sCurrPoint.y = WINDOW_HEIGHT_HALF - y;
	}
}