#pragma once
#include<qpainter.h>
#include <math.h>

class Paint:public QPainter//�̳�QPainter���Լ�ʵ�ֻ�ͼ��ʵ��
{
public:
	Paint(QPaintDevice* d);
	void drawline_DDA(int x1, int y1, int x2, int y2);//�����ɵ�DDA�㷨
	void drawline_Bresenham(int x1, int y1, int x2, int y2);//�߶����ɵ�Bresenham�㷨
	//��ʵ�ֵĹ���
	void drawpolygon_DDA(int n, int a[]);//���ƶ����
	void drawpolygon_Bresenham(int n, int a[]);
	void drawellipse(int x, int y, int rx, int ry);//������Բ
	void drawcurse_Bezier(int n, int a[]);//��������
	void drawcurse_B_spline(int n, int a[]);
};