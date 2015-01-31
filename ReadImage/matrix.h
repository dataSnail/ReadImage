#include <iostream>
#include "malloc.h"
#include "math.h"


class ImageMatrix
{
public:
	ImageMatrix(){};
	ImageMatrix(int, int);
	//void Init(int ,int );

	void putVal(int , int , double);
	double getVal(int, int);

	//点乘
	ImageMatrix* dotMul(ImageMatrix);

	//乘以数
	ImageMatrix* intMul(double);

	//除以数
	ImageMatrix* intDiv(double, int);

	//数减
	ImageMatrix* intMinus(double);

	//数加
	ImageMatrix* intPlus(double);
	////arctan
	//ImageMatrix arctan();

	//矩阵相减
	ImageMatrix* matrixMinues(ImageMatrix);
	//矩阵相加
	ImageMatrix* matrixPlus(ImageMatrix);

	//矩阵相除
	ImageMatrix* matrixDiv(ImageMatrix);

	//矩阵相乘
	ImageMatrix* matrixMul(ImageMatrix);

	//矩阵开平方
	ImageMatrix* matrixsqrt();

	//取从row_start行 到row_end行 添加row_add 行
	//ImageMatrix selectRow(int row_start,int row_end,int row_add);
	//ImageMatrix selectCol(int col_start, int col_end, int col_add);

	//四种选择
	ImageMatrix* select(int num);

	//求矩阵中所有数的和
	double sum();


	void printMatrix();

	//重载操作符


	//copy function
	void copy(ImageMatrix *img)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				img->arr[i][j] = arr[i][j];
			}
		}
	}

	~ImageMatrix()
	{
		//for (int i = 0; i<height; i++)
		//	free(arr[i]);   //free一维
		//free(arr);  //free二维的
	}

private:
	double ** arr;
	//ImageMatrix *s = NULL;
	int height;
	int width;
};