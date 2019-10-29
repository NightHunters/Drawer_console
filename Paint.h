#pragma once
#include<qpainter.h>
#include <math.h>

class Paint:public QPainter//继承QPainter，自己实现画图的实现
{
public:
	Paint(QPaintDevice* d);
	void drawline_DDA(int x1, int y1, int x2, int y2);//线生成的DDA算法
	void drawline_Bresenham(int x1, int y1, int x2, int y2);//线段生成的Bresenham算法
	//待实现的功能
	void drawpolygon_DDA(int n, int a[]);//绘制多边形
	void drawpolygon_Bresenham(int n, int a[]);
	void drawellipse(int x, int y, int rx, int ry);//绘制椭圆
	void drawcurse_Bezier(int n, int a[]);//绘制曲线
	void drawcurse_B_spline(int n, int a[]);
};