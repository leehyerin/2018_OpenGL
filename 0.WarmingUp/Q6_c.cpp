//#include "stdafx.h"
//
//struct RECT
//{
//	int left;
//	int bottom;
//	int right;
//	int top;
//}; 
//
//void InitBoard();
//void InputRect();
//void PrintMenu();
//void PrintBoard();
//void ClearWindow();
//void MakeRect();
//void PrintRect();
//
//char board[10][10];
//RECT rect;
//char com;
//
//int main()
//{
//	InitBoard();
//	PrintMenu();
//	InputRect();
//	PrintBoard();
//
//	while (true)
//	{
//		cout << "input order :";
//		cin >> com;
//		switch (com)
//		{
//		case 'x':
//			if (rect.left == 1)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.left -= 1;
//				rect.right -= 1;
//				PrintRect();
//			}
//			break;
//		case 'X':
//			if (rect.right == 10)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.left += 1;
//				rect.right += 1;
//				PrintRect();
//			}
//			break;
//		case 'y':
//			if (rect.top == 10)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.top -= 1;
//				rect.bottom -= 1;
//				PrintRect();
//			}
//			break;
//		case 'Y':
//			if (rect.bottom == 1)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.top += 1;
//				rect.bottom += 1;
//				PrintRect();
//			}
//			break;
//		///한 칸 확대 / 축소
//		case 's': 
//			if ((rect.bottom == 10) || (rect.right == 10))
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.bottom += 1;
//				rect.right += 1;
//				PrintRect();
//			}
//			break;
//		case 'S':
//			if (rect.right - rect.left == 1|| (rect.bottom - rect.top == 1))
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.right -= 1;
//				rect.bottom -= 1;
//				PrintRect();
//			}
//			break;
//		case 'i':
//			if (rect.right == 10)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.right += 1;
//				PrintRect();
//			}
//			break;
//		case 'j':
//			if (rect.right - rect.left == 1)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.right -= 1;
//				PrintRect();
//			}
//			break;
//		///y 한 칸 확대/축소
//		case 'k':
//			if (rect.bottom == 10)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.bottom += 1;
//				PrintRect();
//			}
//			break;
//		case 'l':
//			if (rect.bottom-rect.top == 1)
//				cout << "wrong command" << endl;
//			else
//			{
//				rect.bottom -= 1;
//				PrintRect();
//			}
//			break;
//		case 'r':
//			ClearWindow();
//			InputRect();
//			PrintBoard();
//			break;
//		case 'q':
//			return 0;
//			break;
//		default:
//			cout << "wrong command!" << endl;
//			break;
//		}
//	}
//	return 0;
//}
//
//void InitBoard()
//{
//	for (int i = 0; i < 10; ++i)
//		for (int k = 0; k < 10; ++k)
//			board[i][k]='.';
//}
//
//void InputRect()
//{
//	int end = false;
//
//	while (!end)
//	{
//		cout << "input coord value:";
//
//		cin >> com; //무시
//		cin >> rect.top;
//		cin >> rect.left;
//		cin >> rect.bottom;
//		cin >> rect.right;
//		
//		//예외 처리
//		if (rect.left < 1 || rect.top < 1 || rect.right > 10 || rect.bottom > 10 ||
//			rect.left >= rect.right || rect.top >= rect.bottom)
//		{
//			cout << "error" << endl;
//			end = false;
//		}
//		else
//		{
//			end = true; 
//			//보드에 사각형 그리기
//			MakeRect();
//		}
//	}
//}
//
//void PrintMenu()
//{
//	com = '0';
//
//	cout << "*-----------------------------------------*" << endl;
//	cout << "1   : 사각형" << endl;
//	cout << "----------------------" << endl;
//	cout << "x/X : x축 -/+ 한 칸 이동" << endl;
//	cout << "y/Y : y축 -/+ 한 칸 이동" << endl;
//	cout << "s/S : 한 칸 확대/축소" << endl;
//	cout << "i/j : x축 한 칸 확대/축소" << endl;
//	cout << "k/l : y축 한 칸 확대/축소" << endl;
//	cout << "r  : 모든 것을 리셋하고 다시 좌표값을 입력받는다." << endl;
//	cout << "q  : 종료" << endl;
//	cout << "*-----------------------------------------*" << endl;
//}
//
//void PrintBoard()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		for (int k = 0; k < 10; ++k)
//			cout << board[i][k] << '\t';
//		cout << endl;
//	}
//}
//
//void ClearWindow()
//{
//	system("cls");
//	PrintMenu();
//}
//
//void MakeRect()
//{
//	//초기화
//	InitBoard();
//
//	for (int i = rect.left - 1; i < rect.right; ++i)
//		for (int k = rect.top - 1; k < rect.bottom; ++k)
//			board[k][i] = '0';
//}
//
//void PrintRect()
//{
//	cout << endl << endl;
//	MakeRect();
//	ClearWindow();
//	PrintBoard();
//}