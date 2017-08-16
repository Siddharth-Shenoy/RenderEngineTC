#ifndef __GRAPH_INCLUDED__
#define __GRAPH_INCLUDED__
#include "GMATH.h"
#include <math.h>
#include <fstream.h>
class Object
{
	private:
		int totalvertices;
		int **vertices;
		Matrix vertexData;
		int Col;
	public:
		Object();
		Object(int *vertices,int total);
		Object(char *file);
		void setCol(int COL);
		void DVD();
		void Translate(int x,int y);
		void Rotate(float angle);
		void Scale(float sx,float sy);
		void Shear(float shx,float shy);
		void Render();
};
Object::Object() {}
Object::Object(int *vertices,int total)
{
	this->totalvertices = total/2;
	int k = 0;
	this->vertices = new int*[this->totalvertices];
	this->vertexData.setMatrixData(this->totalvertices,3);
	int i = 0;
	for(i = 0; i < this->totalvertices; i++)
	{
		this->vertices[i] = new int[2];
	}
	for(i = 0; i < this->totalvertices; i++)
	{
		this->vertices[i][0] = vertices[k];
		this->vertices[i][1] = vertices[k+1];
		this->vertexData.setData(i,0,this->vertices[i][0]);
		this->vertexData.setData(i,1,this->vertices[i][1]);
		this->vertexData.setData(i,2,1);
		k += 2;
	}
}

void Object::setCol(int Col)
{
	this->Col = Col;
	setcolor(this->Col);

}
void Object::Render()
{
	int total = this->totalvertices;
	int x[2],y[2];
	for(int i = 0; i < this->totalvertices; i++)
	{
		x[0] = (int)(this->vertexData.getData(i,0));
		y[0] = (int)(this->vertexData.getData(i,1));
		x[1] = (int)(this->vertexData.getData( (i+1)%total , 0));
		y[1] = (int)(this->vertexData.getData( (i+1)%total , 1));
		line(x[0],y[0],x[1],y[1]);
	}
}
void Object::DVD()
{
	this->vertexData.Display();
}
void Object::Translate(int x,int y)
{
	Matrix TMat(3,3);
	TMat.setData(0,0,1);
	TMat.setData(1,1,1);
	TMat.setData(2,0,x); TMat.setData(2,1,y); TMat.setData(2,2,1);
	this->vertexData = this->vertexData.Multiply(TMat);
}
void Object::Shear(float shx,float shy)
{
	Matrix ShMat(3,3);
	ShMat.setData(0,0,1.0);
	ShMat.setData(1,0,shx);
	ShMat.setData(0,1,shy);
	ShMat.setData(1,1,1);
	ShMat.setData(2,2,1);
	this->vertexData = this->vertexData.Multiply(ShMat);

}
void Object::Rotate(float angle)
{
	//Conversion of rads to degree
	angle *= (3.14/180.0);
	Matrix RMat(3,3);
	RMat.setData(0,0,cos(angle));
	RMat.setData(0,1,sin(angle));
	RMat.setData(1,0,-1*sin(angle));
	RMat.setData(1,1,cos(angle));
	RMat.setData(2,2,1);
	this->vertexData = this->vertexData.Multiply(RMat);
}
void Object::Scale(float sx,float sy)
{
	Matrix SMat(3,3);
	SMat.setData(0,0,sx);
	SMat.setData(1,1,sy);
	SMat.setData(2,2,1.0);
	this->vertexData = this->vertexData.Multiply(SMat);
}

#endif