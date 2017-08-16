#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "GMATH.h"
#include "GRAPHLIB.h"
void main()
{
/*	int data;
	int i , j;
	int r, k;
	Matrix M;
	Matrix N;
	clrscr();
	printf("Enter the dimensions of the matrix:\n");
	scanf("%d%d",&i,&j);
	M.setMatrixData(i,j);
	for(r = 0; r < i; r++)
	{
		for(k = 0; k < j; k++)
		{
			scanf("%d",&data);
			M.setData(r,k,data);
		}
	}
	M.Display();
	printf("Enter the dimensions for the second matrix:\n");
	scanf("%d%d",&i,&j);
	N.setMatrixData(i,j);
	for(r = 0; r < i; r++)
	{
		for(k = 0; k < j; k++)
		{
			scanf("%d",&data);
			N.setData(r,k,data);

		}
	}
	Matrix res;
	res = M.Multiply(N);
	res.Display();
	*/
	int gd = DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int *verts = {20,20,60,20,60,60,40,100,20,60,20,20};
	int size = sizeof(verts)/sizeof(int);
	Object O(verts,size);
//	Object Second("./something.ob");
	//O.DVD();
//	O.Render();
	O.setCol(RED);
 //	O.Translate(20,0);
//	O.Scale(0.5f,0.5f);
	O.Render();
//	O.DVD();
	getch();
}