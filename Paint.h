#pragma once
#include<qpainter.h>
#include <math.h>

class Paint:public QPainter//��ͼ��
{
	//QPainter *painter;
	//QPen pen;
public:
	Paint(QPaintDevice* d);
	//~Paint();
	//Paint(QPainter *pa);//���캯��
	//void changeCanvas(QPixmap &pix);//��������
	//void setcolor(int r, int g, int b);//���û�����ɫ
	void drawline_DDA(int x1, int y1, int x2, int y2);//�����ɵ�DDA�㷨
	void drawline_Bresenham(int x1, int y1, int x2, int y2);//�߶����ɵ�Bresenham�㷨
};