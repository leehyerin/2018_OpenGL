//#include "stdafx.h"
//
//
//struct SHAPE 
//{
//	int centerX;
//	int centerY;
//	int radius;
//	int left;
//	int bottom;
//	int right;
//	int top;
//};
//
//void Print2Rect();
//void ReArrangeShape(int, int, int);
//void CheckColl();
//
//SHAPE Shape1{ 200,200,100 };
//SHAPE Shape2{ 450,450,50 };
//
//SHAPE_TYPE type;
//
//int main()
//{
//	ReArrangeShape(1, 0, 0);
//	ReArrangeShape(2, 0, 0);
//
//	char com;
//
//	cout << "1(rectangle x rectangle) / 2(circle x circle)" << endl;
//	cout << "Command: a(left)/ d(right)/ s(down)/ w(up)" << endl;
//	cout << "Input Shape Combination: ";
//	cin >> com;
//
//	if (com == '1') type = RECTANGLE;
//	if (com == '2') type = CIRCLE;
//
//	while (true)
//	{
//		Print2Rect();
//
//		cout << "Command: ";
//		cin >> com;
//		
//		switch (com)
//		{
//		case '1':
//			break;
//		case '2':
//			break;
//		case 'a': //left
//			ReArrangeShape(2,-60, 0);
//			CheckColl();
//			break;
//		case 'd'://right
//			ReArrangeShape(2, +60, 0);
//			CheckColl();
//			break;
//		case 's': //down
//			ReArrangeShape(2, 0, -60);
//			CheckColl();
//			break;
//		case 'w'://up
//			ReArrangeShape(2, 0, +60);
//			CheckColl();
//			break;
//		case 'q':
//			return 0;
//		default:
//			cout << "error!" << endl;
//			break;
//		}
//	}
//}
//
//void Print2Rect()
//{
//	cout << "\tShape 1 :(" << Shape1.left << "," << Shape1.bottom << ")\t(" << Shape1.right << "," << Shape1.top << ")" << endl;
//	cout << "\tShape 2 :(" << Shape2.left << "," << Shape2.bottom << ")\t(" << Shape2.right << "," << Shape2.top << ")" << endl;
//}
//
//void ReArrangeShape(int nShape, int x, int y)
//{
//	SHAPE *pShape = NULL;
//
//	if (nShape == 1) pShape = &Shape1;
//	if (nShape == 2) pShape = &Shape2;
//
//	pShape->centerX += x;
//	pShape->centerY += y;
//
//	pShape->left = pShape->centerX - pShape->radius;
//	pShape->right = pShape->centerX + pShape->radius;
//	pShape->bottom= pShape->centerY - pShape->radius;
//	pShape->top = pShape->centerY + pShape->radius;
//}
//
//void CheckColl()
//{
//	bool bCheck = false;
//
//	if (type == RECTANGLE)
//	{
//		if ((Shape1.left <= Shape2.right) &&
//			(Shape1.right >= Shape2.left) &&
//			(Shape1.top >= Shape2.bottom) &&
//			(Shape1.bottom <= Shape2.top))
//
//			bCheck = true;
//
//
//		if (bCheck)
//			cout << "Rectangle 1 & Rectangle 2 Collide!" << endl;
//	}
//	
//	else if(type ==CIRCLE)
//	{
//		auto d = sqrt(pow(Shape2.centerX - Shape1.centerX, 2));
//
//		if (d <= (Shape1.radius + Shape2.radius))
//			bCheck = true;
//
//		if (bCheck)
//			cout << "Circle 1 & Circle 2 Collide!" << endl;
//	}
//}
