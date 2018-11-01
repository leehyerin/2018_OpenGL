//#include "stdafx.h"
//
//constexpr int stackSize = 10;
//int top = -1;
//int bottom = 0;
//
//struct POINT3
//{
//	int x;
//	int y;
//	int z;
//	double d;
//};
//
//
//POINT3* pStack[stackSize];
//POINT3* LoadPoint3();
//void PullStack(POINT3*);   //������ �����
//void PrintStack();
//int t;
//
//int main()
//{
//	int max, min, idx;
//	char com;
//	bool end=false;
//
//	cout << "*--------------------------------*" << endl;
//	cout << "+ x y z : ����Ʈ�� �� ���� �Է�" << endl;
//	cout << "- : ����Ʈ�� �� ������ ���" << endl;
//	cout << "e x y z : ����Ʈ�� �� �Ʒ��� �Է�" << endl;
//	cout << "d : ����Ʈ�� �� �Ʒ����� ���" << endl;
//	cout << "l : ����Ʈ�� ���̸� ���" << endl;
//	cout << "c : ����Ʈ�� ���" << endl;
//	cout << "m : �������� ���� �� �Ÿ��� �ִ� ���� ��ǥ���� ���" << endl;
//	cout << "n : �������� ���� ����� �Ÿ��� �ִ� ���� ��ǥ���� ���" << endl;
//	cout << "q : ���α׷� ����\n\n" << endl;
//	cout << "*--------------------------------*" << endl;
//
//	while (true)
//	{
//		cout << "command:";
//		cin >> com;
//
//		switch (com)
//		{
//		case '+':
//			
//			for (int i = 0; i <= top; ++i)
//			{
//				if (pStack[i] == NULL)
//				{
//					pStack[i] = LoadPoint3();
//					end = true;
//					bottom = i;
//					break;
//				}
//			}
//
//			if (!end)
//			{
//				pStack[++top] = LoadPoint3();
//			}				
//			
//			PrintStack();
//
//			break;
//		case '-':
//			delete pStack[top]; pStack[top] = NULL;
//			if (top > 0) top--;
//			else if (top == 0) top = -1;
//			PrintStack();
//			break;
//		case 'e':
//			PullStack(LoadPoint3());
//			PrintStack();
//			break;
//		case 'd':
//			if (top != -1)		delete pStack[bottom]; pStack[bottom] = NULL;
//			
//			if (top > -1) 
//				if (top  == bottom) //����� ��
//				{
//					top = -1;
//					bottom = 0;
//				}	
//				else  bottom += 1;
//
//			PrintStack();
//			break;
//		case 'l':
//			t = top + 1;
//			cout << "length of list: " << t << endl;
//			break;
//		case 'c':
//			for (int i = 0; i <= top; ++i)
//			{
//				delete pStack[i]; pStack[i] = NULL;
//			}
//			top = -1;
//			bottom = 0;
//			PrintStack();
//			break;
//		case 'm':
//			if (top != -1)
//			{
//				max = 0, idx = 0;
//				for (int i = 0; i < 10; ++i)
//				{
//					if (pStack[i] != NULL)
//						if (max < pStack[i]->d)
//						{
//							max = pStack[i]->d;
//							idx = i;
//						}
//				}
//
//				cout << "max d coord: " << pStack[idx]->x << "," << pStack[idx]->y << "," << pStack[idx]->z << endl;
//			}
//			break;
//		case 'n':
//			if (top != -1)
//			{
//				min = 100, idx = 0;
//
//				for (int i = 0; i < 10; ++i)
//				{
//					if (pStack[i] != NULL)
//						if (min > pStack[i]->d)
//						{
//							min = pStack[i]->d;
//							idx = i;
//						}
//				}
//				cout << "min d coord: " << pStack[idx]->x << "," << pStack[idx]->y << "," << pStack[idx]->z << endl;
//			}
//			break;
//		case 'q':
//			return 0;
//			break;
//		}
//	}
//}
//
//POINT3* LoadPoint3()
//{
//	POINT3* pstack = new POINT3();
//
//	cin >>pstack->x;
//	cin >>pstack->y;
//	cin >>pstack->z;
//	auto x = pstack->x;
//	auto y = pstack->y;
//	auto z = pstack->z;
//	pstack->d = sqrt(x*x + y * y + z * z);
//
//	return pstack;
//}
//
//void PullStack(POINT3* p)
//{
//	for (int i = top; i > -1; --i)
//	{
//		pStack[i+1] = pStack[i];
//	}
//
//	pStack[0] = p;
//	top++;
//}
//
//void PrintStack()
//{
//	cout << "--------------------------------" << endl;
//	for (int i = stackSize-1; i > -1; --i)
//	{
//		cout << i << " | ";
//
//		if(pStack[i]!=NULL)
//			cout<< pStack[i]->x << ' ' << pStack[i]->y << ' ' << pStack[i]->z << endl;
//		else cout << endl;
//	}
//	cout << "..........top:" << top << "  bottom:" << bottom << endl;
//	cout << "--------------------------------"<<endl;
//}
