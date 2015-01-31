//#include <iostream>
//
//#include "matrix.h"
//#define MIN_ZERO 0.0000000000022204
//int main()
//{
//	int a = 5, b = 7;
//	ImageMatrix arrr = ImageMatrix(a,b);
//	for (int i = 0; i < a; ++i)
//	{
//		for (int j = 0; j < b; ++j)
//		{
//			arrr.putVal(i,j,j+1);
//		}
//		arrr.putVal(0, 0, 5.0);
//	}
//
//	ImageMatrix tem = ImageMatrix(a,b);
//	ImageMatrix temp = ImageMatrix(a, b);
//
//	tem = arrr.intPlus(1.0,temp);
//
//	tem.printMatrix();
//	std::cout << std::endl;
//	//tem = tem.select(7);
//
//
//	//std::cout << MIN_ZERO << std::endl;
//	tem = ((
//		(tem.select(1, temp).matrixMinues(tem, temp).matrixMul(tem.select(1, temp).matrixMinues(tem, temp), temp), temp)
//		.matrixPlus(
//		(tem.select(3, temp).matrixMinues(tem.select(4, temp), temp).matrixMul(tem.select(3, temp).matrixMinues(tem.select(4, temp), temp), temp)
//		).intMul(0.25, temp), temp)).intPlus(MIN_ZERO, temp))
//		.matrixsqrt(temp).intDiv(1, 1, temp);
//
//	tem = tem.select(1, temp);
//	tem.printMatrix();
//	tem = tem.matrixPlus(tem, temp);
//
//
//	tem.printMatrix();
//
//
//}