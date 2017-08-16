#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "GMATH.h"
#include "GRAPHLIB.h"
void main()
{
	int gd = DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int *verts = {20,20,60,20,60,60,40,100,20,60,20,20};
	int size = sizeof(verts)/sizeof(int);
	Object O(verts,size);
	O.setCol(RED);
	O.Render();
	getch();
}
