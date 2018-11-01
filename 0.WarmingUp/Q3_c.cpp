//#include "stdafx.h"
//#define DIRright  0
//#define DIRdown  1
//#define DIRleft  2
//#define DIRup  3
////////////////////
//void InitializeMaze();
//void CreateMaze();
//
//int CreateWall(int);
//int CheckBoundary(int);
//void Move(int d);
//
//void CreateLoad();
//void PrintMaze();
////////////////////
//         
//int Maze[25][25];
//int x = 0, y = 0;
//int currDir = DIRright;
//int DirCnt = 2;
//
//int main()
//{
//	char c = '\0';
//	while (c!='q'&& c != 'Q')
//	{	
//		CreateMaze();
//		PrintMaze();
//		cout << "reset [q:quit] :";
//		cin >> c;
//		
//		system("cls");
//	}
//
//}
//
//void InitializeMaze()
//{
//	for (int i = 0; i < 25; ++i)
//		for (int k = 0; k < 25; ++k)
//			Maze[i][k] = -1;
//
//	x = 0; y = 0;
//
//	Maze[x][y] = 0;
//
//	DirCnt = 2;
//}
//
//
//void CreateMaze()
//{
//	InitializeMaze();
//	///미로 '벽' 생성
//	CreateWall(DIRright);
//	///미로 '길' 생성
//	CreateLoad();
//}
//
//int CreateWall(int dir)
//{
//	int d = 0;
//
//
//
//	if (DirCnt > 3)
//	{
//		DirCnt = 1;
//
//		if (currDir == DIRright)
//			d = DIRdown;
//		else if (currDir == DIRleft)
//			d = DIRdown;
//		else if (currDir == DIRdown)
//			d = DIRright;
//
//		d = CheckBoundary(d);
//	}
//
//
//	else
//	{
//		d = rand() % 3;
//
//		switch (d)
//		{
//		case DIRright:
//			if (currDir == DIRleft)
//			{
//				d = DIRdown;
//			}
//			break;
//		case DIRleft:
//			if (currDir == DIRright)
//			{
//				d = DIRdown;
//			}
//			break;
//		}
//		d = CheckBoundary(d);
//	}
//	Maze[x][y] = 0;
//
//	currDir = d;
//	if (d == currDir)	DirCnt++;
//
//	Move(d);
//
//	if (x == 24 && y == 24) return 0;
//	
//	if (x == 24 && y < 24) d = DIRright;
//	else if (y == 24 && x < 24) d = DIRdown;
//
//
//	return	CreateWall(d);
//}
//
//int CheckBoundary(int d)
//{
//	int dir = d;
//
//	switch (d)
//	{
//	case DIRleft:
//		if (y == 0)//더이상 왼쪽은 놉
//		{
//			dir = DIRdown;
//			DirCnt = 2;
//		}
//		break;
//	case DIRdown:
//		if (x == 24)//더이상 다운은 놉
//		{
//			dir = DIRright;
//			DirCnt = 2;
//		}
//		break;
//	case DIRright:
//		if (y == 24)//더이상 오른쪽은 놉
//		{
//			dir = DIRdown;
//			DirCnt = 2;
//		}
//		break;
//	}
//
//	cout << "................dir"<< dir <<".....currdir"<<currDir<< "     Cnt"<< DirCnt<<endl;
//
//	return dir;
//
//}
//
//void Move(int d)
//{
//	switch (d)
//	{
//	case DIRleft:
//		y -= 1;
//		break;
//	case DIRright:
//		y += 1;
//		break;
//	case DIRup:
//		x -= 1;
//		break;
//	case DIRdown:
//		x += 1;
//		break;
//	default:
//		break;
//	}
//}
//
//void CreateLoad()
//{
//	for (int i = 0; i < 25; ++i)
//		for (int k = 0; k < 25; ++k)
//			if (Maze[i][k] == -1) Maze[i][k] = 1;
//}
//
//void PrintMaze()
//{
//	for (int i = 0; i < 25; ++i)
//	{
//		for (int k = 0; k < 25; ++k)
//			cout << Maze[i][k] << ' ';
//		cout << endl;
//	}
//}