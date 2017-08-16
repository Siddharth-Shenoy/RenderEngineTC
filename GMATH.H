#ifndef __MATH_INCLUDED__
#define __MATH_INCLUDED__

class Matrix
{
	private:
		int rows;
		int cols;
		float **data;
	public:
		Matrix();
		Matrix(int rows,int cols);
		int getRows();
		int getCols();
		void setMatrixData(int rows,int cols);
		void setData(int i,int j,float data);
		float getData(int i,int j);
		Matrix Multiply(Matrix M);
		void Display();
};
Matrix::Matrix()
{
}
Matrix::Matrix(int rows,int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->data = new float*[rows];
	int i =0,j = 0;
	for(i = 0; i < this->rows; i++)
	{
		this->data[i] = new float[this->cols];
	}
	for(i = 0; i < this->rows; i++)
	{
		for(j = 0; j < this->cols; j++)
		{
			this->data[i][j] = 0.0;
		}
	}
}
void Matrix::setMatrixData(int x, int y)
{
	this->rows = x;
	this->cols = y;

	this->data = new float*[this->rows];
	for(int i = 0; i < this->cols; i++)
	{
		this->data[i] = new float[this->cols];
	}
}
void Matrix::setData(int x,int y,float data)
{
	this->data[x][y] = data;
}
float Matrix::getData(int x,int y)
{
	return this->data[x][y];
}
int Matrix::getRows()
{
	return this->rows;
}
int Matrix::getCols()
{
	return this->cols;
}
void Matrix::Display()
{
	for(int i = 0; i < this->rows; i++)
	{
		for(int j = 0; j < this->cols; j++)
		{
			printf("%f\t",this->data[i][j]);
		}
		printf("\n");
	}
}
Matrix Matrix::Multiply(Matrix M)
{
	Matrix res(this->rows,M.getCols());
	for(int i = 0; i < this->rows; i++)
	{
		for(int j = 0; j < M.getCols(); j++)
		{
			for(int k = 0; k < this->cols; k++)
			{
				res.setData(i,j,res.getData(i,j) + this->data[i][k]*M.getData(k,j));
			}
		}
	}
	return res;
}

#endif
