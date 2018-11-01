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
//		///�� ĭ Ȯ�� / ���
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
//		///y �� ĭ Ȯ��/���
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
//		cin >> com; //����
//		cin >> rect.top;
//		cin >> rect.left;
//		cin >> rect.bottom;
//		cin >> rect.right;
//		
//		//���� ó��
//		if (rect.left < 1 || rect.top < 1 || rect.right > 10 || rect.bottom > 10 ||
//			rect.left >= rect.right || rect.top >= rect.bottom)
//		{
//			cout << "error" << endl;
//			end = false;
//		}
//		else
//		{
//			end = true; 
//			//���忡 �簢�� �׸���
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
//	cout << "1   : �簢��" << endl;
//	cout << "----------------------" << endl;
//	cout << "x/X : x�� -/+ �� ĭ �̵�" << endl;
//	cout << "y/Y : y�� -/+ �� ĭ �̵�" << endl;
//	cout << "s/S : �� ĭ Ȯ��/���" << endl;
//	cout << "i/j : x�� �� ĭ Ȯ��/���" << endl;
//	cout << "k/l : y�� �� ĭ Ȯ��/���" << endl;
//	cout << "r  : ��� ���� �����ϰ� �ٽ� ��ǥ���� �Է¹޴´�." << endl;
//	cout << "q  : ����" << endl;
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
//	//�ʱ�ȭ
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