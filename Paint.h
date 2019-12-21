#pragma once
#include<qpainter.h>
#include <math.h>
#include<cmath>
#include<iostream>
using namespace std;

class Paint:public QPainter//�̳�QPainter���Լ�ʵ�ֻ�ͼ��ʵ��
{
public:
	Paint(QPaintDevice* d);
	void drawline_DDA(int x1, int y1, int x2, int y2);//�����ɵ�DDA�㷨
	void drawline_Bresenham(int x1, int y1, int x2, int y2);//�߶����ɵ�Bresenham�㷨
	void drawpolygon_DDA(int n, int x[],int y[]);//���ƶ���ε�DDA�㷨
	void drawpolygon_Bresenham(int n, int x[], int y[]);//���ƶ���ε�Bresenham�㷨
	void drawellipse(int x, int y, int rx, int ry);//������Բ

	double BEZ(int k, int n,double u);//BEZ�����������������Ʊ���������
	void drawcurse_Bezier(int n, int x[],int y[]);//�������ߵı������㷨

	double F_0_3(double t);
	double F_1_3(double t);
	double F_2_3(double t);
	double F_3_3(double t);
	void drawcurse_B_spline(int n, int x[],int y[]);//�������ߵ����ξ���B�����㷨
};