//#include "stdafx.h"
///////////////////////////////////////////////////////////////////////
//class CMatrix
//{
//public:
//	int m_Matrix[3][3] = { 0, };  //3차원
//	int m_4Matrix[4][4] = { 0, }; //4차원
//	int m_nCol; //행
//	int m_nRow; //열
//public:
//	CMatrix();
//	~CMatrix();
//	void InitializeMat3();
//	void PrintMatrix(int colIdx, char n);
//	void Print4Matrix(int colIdx, char n);
//};
///////////////////////////////////////////////////////////////////////
//
//CMatrix::CMatrix()
//{
//	m_nCol = m_nRow = 3;
//
//	for (int i = 0; i < m_nCol; ++i)
//		for (int k = 0; k < m_nRow; ++k)
//			m_Matrix[i][k] = rand() % 2;
//}
//
//CMatrix::~CMatrix()
//{
//}
//
//void CMatrix::InitializeMat3()
//{
//	for (int i = 0; i < 3; ++i)
//		for (int k = 0; k < 3; ++k)
//			m_Matrix[i][k] = 0;
//}
//
//void CMatrix::PrintMatrix(int colIdx, char n)
//{
//	for (int k = 0; k < m_nRow; ++k)
//	{
//		cout << m_Matrix[colIdx][k] << ' ';
//	}
//	cout << n;
//}
//
//void CMatrix::Print4Matrix(int colIdx, char n)
//{
//	for (int k = 0; k < 4; ++k)
//	{
//		cout << m_4Matrix[colIdx][k] << ' ';
//	}
//	cout << n;
//}
//
//////////////////////////////////////////////////////////
////
//CMatrix* MultiplyMatrix();
//CMatrix* AddMatrix();
//CMatrix* SubstractMatrix();
//int Determinant();
//void HomoCoord();
//void PrintResult(char);
//void PrintDeterResult(int);
//void Print4Result(char);
//
//
//CMatrix* pMatrix1 = NULL;
//CMatrix* pMatrix2 = NULL;
//CMatrix* ptemp = NULL;
//
//int main()
//{
//	char com = '0';
//	cout << "*-------------------------*" << endl;
//	cout << "M/m : 행렬의 곱셈" << endl;
//	cout << "A/a : 행렬의 덧셈" << endl;
//	cout << "D/d : 행렬의 뺄셈" << endl;
//	cout << "R/r : 행렬식의 값" << endl;
//	cout << "H/h : 동차좌표계(3x3->4x4)" << endl;
//	cout << "Q/q : 종료" << endl;
//	cout << "*------------------------*" << endl;
//
//	pMatrix1 = new CMatrix();
//	pMatrix2 = new CMatrix();
//	ptemp = new CMatrix();
//
//	while (true)
//	{
//		cin >> com;
//		int c;
//		switch (com)
//		{
//			//곱
//		case 'M':
//		case 'm':
//			ptemp = MultiplyMatrix();
//			PrintResult('*');
//			break;
//		case 'A':
//		case 'a':
//			ptemp = AddMatrix();
//			PrintResult('+');
//			break;
//		case 'D':
//		case 'd':
//			ptemp = SubstractMatrix();
//			PrintResult('-');
//			break;
//		case 'R':
//		case 'r':
//			PrintDeterResult(Determinant());
//			break;
//		case 'H':
//		case 'h':
//			HomoCoord();
//			Print4Result('>');
//			break;
//		case 'Q':
//		case 'q':
//			return 0;
//			break;
//		default:
//			cout << "잘못된 명령어입니다." << endl;
//			break;
//		}
//		cout << "--------------------------"<<endl;
//	}
//	return 0;
//}
//
//CMatrix* MultiplyMatrix()
//{
//	CMatrix* pMatix = new CMatrix();
//	pMatix->InitializeMat3();
//	
//	for (int i = 0; i < 3; ++i) //행
//		for (int k = 0; k < 3; ++k) //열
//			for (int j = 0; j < 3; ++j) //M2 행
//			{
//				pMatix->m_Matrix[i][k] += (pMatrix1->m_Matrix[i][j]) * (pMatrix2->m_Matrix[j][k]);
//			}
//
//	return pMatix;
//}
//
//CMatrix* AddMatrix()
//{
//	CMatrix* pMatix = new CMatrix();
//
//	for (int i = 0; i < 3; ++i)
//		for (int k = 0; k < 3; ++k)
//		{
//			pMatix->m_Matrix[i][k] =
//				pMatrix1->m_Matrix[i][k] +
//				pMatrix2->m_Matrix[i][k];
//		}
//	return pMatix;
//}
//
//CMatrix* SubstractMatrix()
//{
//	CMatrix* pMatix = new CMatrix();
//
//	for (int i = 0; i < 3; ++i)
//		for (int k = 0; k < 3; ++k)
//		{
//			pMatix->m_Matrix[i][k] =
//				pMatrix1->m_Matrix[i][k] -
//				pMatrix2->m_Matrix[i][k];
//		}
//	return pMatix;
//}
//
//int Determinant()
//{
//	auto mat = pMatrix1->m_Matrix;
//
//	int d = mat[0][0] * mat[1][1] * mat[2][2] +
//		mat[0][1] * mat[1][2] * mat[2][0] +
//		mat[0][2] * mat[1][0] * mat[2][1] -
//		mat[0][0] * mat[1][2] * mat[2][1] -
//		mat[0][1] * mat[1][0] * mat[2][2] -
//		mat[0][2] * mat[1][1] * mat[2][0];
//
//	return d;
//}
//
//void HomoCoord()
//{
//	auto mat3 = pMatrix1->m_Matrix;
//	auto mat4 = pMatrix1->m_4Matrix;
//
//	for (int i = 0; i < 4; ++i)
//		for (int k = 0; k < 4; ++k)
//		{
//			//4행 4열은 1로 채우기
//			if (i == 3 && k == 3)
//				mat4[3][3] = 1;
//			//4행또는 4열은 0으로 채우기
//			else if (i == 3 || k == 3)
//			{
//				mat4[i][k] = 0;
//			}
//			//그 외에는 복사
//			else
//				mat4[i][k] = mat3[i][k];
//		} 
//
//	/*for (int i = 0; i < 4; ++i)
//		for (int k = 0; k < 4; ++k)
//		{
//			pMatrix1->m_4Matrix[i][k] = mat4[i][k];
//			cout << "i:" << i << "  k:" << k << "//"<<mat4[i][k] <<endl;
//		}*/
//}
//
//void PrintResult(char mark)
//{
//	pMatrix1->PrintMatrix(0, ' ');			pMatrix2->PrintMatrix(0, ' ');		ptemp->PrintMatrix(0, '\n');
//	pMatrix1->PrintMatrix(1, mark);		pMatrix2->PrintMatrix(1, '=');		ptemp->PrintMatrix(1, '\n');
//	pMatrix1->PrintMatrix(2, ' ');			pMatrix2->PrintMatrix(2, ' ');		ptemp->PrintMatrix(2, '\n');
//}
//
//void PrintDeterResult(int det)
//{
//	pMatrix1->PrintMatrix(0, ' ');			cout << endl;
//	pMatrix1->PrintMatrix(1, '=');			cout << det << endl;
//	pMatrix1->PrintMatrix(2, ' ');			cout << endl;
//}
//
//void Print4Result(char mark)
//{
//	pMatrix1->PrintMatrix(0, ' '); 			pMatrix1->Print4Matrix(0, '\n');
//	pMatrix1->PrintMatrix(1, mark); 	pMatrix1->Print4Matrix(1, '\n');
//	pMatrix1->PrintMatrix(2, ' '); 			pMatrix1->Print4Matrix(2, '\n');
//	cout << "       ";									pMatrix1->Print4Matrix(3, '\n');
//}
