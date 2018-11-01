//#include "stdafx.h"
//
//struct vec
//{
//	int x{ 0 };
//	int y{ 0 };
//	int z{ 0 };
//};
//
//////////////////////////////////
//int DotVector();
//void CrossVector();
//void AddVector();
//void SubstractVector();
//void LengthVector();
//void PrintResult(char, MARK);
//
//bool err = false;
//vec vec1;
//vec vec2;
//vec* tvec = new vec();
//
//int main()
//{
//	//while (!err)
//	//{
//		cout << "input vector1: ";
//		cin >> vec1.x;
//		cin >> vec1.y;
//		cin >> vec1.z;
//		
//		cout << "input vector2: ";
//		cin >> vec2.x;
//		cin >> vec2.y;
//		cin >> vec2.z;
//	//}
//
//	char com = '0';
//	cout << "*-------------------------*" << endl;
//	cout << "+ : 두 벡터의 합" << endl;
//	cout << "- : 두 벡터의 차" << endl;
//	cout << "d : 두 벡터의 내적" << endl;
//	cout << "c : 두 벡터의 외적" << endl;
//	cout << "l :  두 벡터의 각각의 크기" << endl;
//	cout << "q : 종료" << endl;
//	cout << "*------------------------*" << endl;
//	while (true)
//	{
//		cin >> com;
//		switch (com)
//		{
//		case '+':
//			AddVector();
//			PrintResult('+',Mplus);
//			break;
//		case '-':
//			SubstractVector();
//			PrintResult('-', Mminus);
//			break;
//		case 'd':
//			PrintResult('.',Mdotproduct);
//			cout << DotVector() << endl;
//			break;
//		case 'c':
//			CrossVector();
//			PrintResult('x', Mcrossproduct);
//			break;
//		case 'l':
//			LengthVector();
//			break;
//		case 'q':
//			return 0;
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//int DotVector()
//{
//	return (vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z);
//}
//
//void CrossVector()
//{
//	tvec->x = vec1.y * vec2.z - vec1.z * vec2.y;
//	tvec->y = vec1.x * vec2.z - vec1.z * vec2.x;
//	tvec->z = vec1.x * vec2.y - vec1.y * vec2.x;
//}
//
//void AddVector()
//{
//	tvec->x = vec1.x + vec2.x;
//	tvec->y = vec1.y + vec2.y;
//	tvec->z = vec1.z + vec2.z;
//}
//
//void SubstractVector()
//{
//	tvec->x = vec1.x - vec2.x;
//	tvec->y = vec1.y - vec2.y;
//	tvec->z = vec1.z - vec2.z;
//}
//
//void LengthVector()
//{
//	auto r1 = sqrt(vec1.x*vec1.x) + sqrt(vec1.y*vec1.y) + sqrt(vec1.z*vec1.z);
//	auto r2 = sqrt(vec2.x*vec2.x) + sqrt(vec2.y*vec2.y) + sqrt(vec2.z*vec2.z);
//
//	cout << "root(" << vec1.x << ", " << vec1.y << ", " << vec1.z << ") = root(" << r1 <<
//			"), root(" << vec2.x << ", " << vec2.y << ", " << vec2.z << ") = root( " << r2 << ")" <<endl;
//
//}
//
//void PrintResult(char c, MARK m)
//{
//	if (m == Mdotproduct)
//	{
//		cout << "( " << vec1.x << ", " << vec1.y << ", " << vec1.z << ") " << c;
//		cout << "( " << vec2.x << ", " << vec2.y << ", " << vec2.z << ") = ";
//	}
//	else
//	{
//		cout << "( " << vec1.x << ", " << vec1.y << ", " << vec1.z << ") " << c;
//		cout << "( " << vec2.x << ", " << vec2.y << ", " << vec2.z << ") = ";
//		cout << "( " << tvec->x << ", " << tvec->y << ", " << tvec->z << ")" << endl;
//	}
//}
