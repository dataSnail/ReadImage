#include "matrix.h"


ImageMatrix::ImageMatrix(int _height, int _width)
{
	//初始化图片数组

	height = _height;
	width = _width;

	//arr = (double**)malloc(sizeof(double*)*height);
	//for (int j = 0; j < height; j++)
	//{
	//	arr[j] = (double*)malloc(sizeof(double)*width);
	//}
	
	arr = new double *[width];
	for (int j = 0; j < height; j++)
	{
		arr[j] = new double[height];
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			arr[i][j] = 0.0;
		}
	}
}


//void ImageMatrix::Init( int _height, int _width)
//{
//
//}

void ImageMatrix::putVal(int ii,int jj,double value)
{
	arr[ii][jj] = value;
}

double ImageMatrix::getVal(int i, int j)
{
	return arr[i][j];
}

//点乘
ImageMatrix* ImageMatrix::dotMul(ImageMatrix arr2)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);


	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			arr[i][j] *= arr2.getVal(i,j);
		}
	}
	return this;
}

//乘以数
ImageMatrix* ImageMatrix::intMul(double num)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, arr[i][j] * num);
			arr[i][j] *= num;
		}
	}

	return this;
}

ImageMatrix* ImageMatrix::intDiv(double num, int flag)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (flag == 0)
			{
				//tem.putVal(i, j, arr[i][j] / num);
				arr[i][j] /= num;
			}
			else if (flag ==1)
			{
				/*tem.putVal(i, j, num/arr[i][j] );*/
				arr[i][j] = num / arr[i][j];
			}
		}
	}
	return this;
}


ImageMatrix* ImageMatrix::intMinus(double num)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, num-arr[i][j]);
			arr[i][j] = num - arr[i][j];
		}
	}
	return this;
}

ImageMatrix* ImageMatrix::intPlus(double num)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			arr[i][j] += num;
			//tem.putVal(i, j, arr[i][j] + num);
		}
	}

	return this;
}

ImageMatrix* ImageMatrix::matrixsqrt()
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, sqrt(arr[i][j]));
			arr[i][j] = sqrt(arr[i][j]);
		}
	}

	return this;
}



double ImageMatrix::sum()
{
	double total = 0;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			total += arr[i][j];
		}
	}
	return total;
}

ImageMatrix* ImageMatrix::select(int num)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);
	//列选择
	//2~n,n
	if (num==1){
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (j != width - 1)
				{
					//tem.putVal(i, j, arr[i][j + 1]);
					arr[i][j] = arr[i][j + 1];
				}
				else{
					//tem.putVal(i,j,arr[i][j]);
				}
			}
		}
	}
	else if (num == 2)//1,1~n-1
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (j == 0)
				{
					//tem.putVal(i, j, arr[i][j]);
				}else{
					//tem.putVal(i, j, arr[i][j-1]);
					arr[i][j] = arr[i][j - 1];
				}
			}
		}
	}
	//行选择
	else if (num == 3)//2~n,n
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (i != height-1)
				{
					//tem.putVal(i, j, arr[i+1][j]);
					arr[i][j] = arr[i + 1][j];
				}
				else{
					//tem.putVal(i, j, arr[i][j]);
				}
			}
		}
	}
	else if (num == 4)//1,1~n-1
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (i == 0)
				{
					//tem.putVal(i, j, arr[i][j]);
				}
				else{
					//tem.putVal(i, j, arr[i - 1][j]);
					arr[i][j] = arr[i - 1][j];
				}
			}
		}
	}
	else{
		std::cout << "select error!" << std::endl;
	}


	return this;
}

ImageMatrix* ImageMatrix::matrixMinues(ImageMatrix arr2)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, arr[i][j]-arr2.getVal(i,j));
			arr[i][j] -= arr2.getVal(i, j);
		}
	}

	return this;
}

ImageMatrix* ImageMatrix::matrixPlus(ImageMatrix arr2)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, arr[i][j] + arr2.getVal(i, j));
			arr[i][j] += arr2.getVal(i, j);
		}
	}

	return this;
}


ImageMatrix* ImageMatrix::matrixMul(ImageMatrix arr2)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, arr[i][j] * arr2.getVal(i, j));
			arr[i][j] *= arr2.getVal(i, j);
		}
	}

	return this;
}

ImageMatrix* ImageMatrix::matrixDiv(ImageMatrix arr2)
{
	//ImageMatrix tem = ImageMatrix(height, width);
	//tem.Init(height, width);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			//tem.putVal(i, j, arr[i][j] / arr2.getVal(i, j));
			arr[i][j] /= arr2.getVal(i, j);
		}
	}

	return this;
}


void ImageMatrix::printMatrix()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			 std::cout<< arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}