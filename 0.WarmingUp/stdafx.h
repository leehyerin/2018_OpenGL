#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define SAFE_DELEFT(p)  	delete p; p = NULL;

#include <iostream>
#include <vector>
#include <cmath>
#include<time.h>
#include<stdlib.h>
#include <random>


using namespace std;

//enum DIR
//{
//	DIRleft=0,
//	DIRright=1,
//	DIRup=2,
//	DIRdown=3
//};

enum MARK
{
	Mplus,
	Mminus,
	Mdotproduct,
	Mcrossproduct,
};

enum SHAPE_TYPE
{
	RECTANGLE,
	CIRCLE
};