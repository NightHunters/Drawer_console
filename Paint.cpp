#include "Paint.h"

Paint::Paint(QPaintDevice* d):QPainter(d)
{
	//painter = NULL;
}

/*Paint::Paint(QPainter *pa) //:painter(pa)//���캯��
{
	QPainter a;
	*painter = a;
	painter = pa;
	pen.setColor(QColor(0, 0, 0, 255));
	painter->setPen(pen);
}*/
/*void Paint::changeCanvas(QPixmap &pix)
{
	QPainter p1(&pix);
	painter = &p1;
}*/
/*void Paint::setcolor(int r, int g, int b)//���û�����ɫ
{
	pen.setColor(QColor(r, g, b, 255));
	painter->setPen(pen);
}*/
void Paint::drawline_DDA(int x1, int y1, int x2, int y2)//�����ɵ�DDA�㷨
{
	double dx, dy;
	int steps, i;
	if (abs(x2 - x1) > abs(y2 - y1))
		steps = abs(x2 - x1);
	else
		steps = abs(y2 - y1);
	dx = (double)(x2 - x1) / steps;
	dy = (double)(y2 - y1) / steps;
	double x = x1;
	double y = y1;
	for (i = 0; i < steps; i++)
	{
		drawPoint(x, y); //��(x��y)������
		x += dx;
		y += dy;
	}
}
void Paint::drawline_Bresenham(int x1, int y1, int x2, int y2)//�߶����ɵ�Bresenham�㷨
{
	int x0 = x1, y0 = y1, xe = x2, ye = y2;
	int steps;
	if (abs(x2 - x1) > abs(y2 - y1))
	{
		if (x1 > x2)
		{
			x0 = x2;
			y0 = y2;
			xe = x1;
			ye = y1;
		}
		int deltax = xe - x0;
		int deltay = ye - y0;
		int p1x = 2 * deltay - 2 * deltax;
		int p2x = -2 * deltay - 2 * deltax;
		int px = 2 * deltay - deltax;
		int x = x0;
		int y = y0;
		drawPoint(x, y);
		steps = xe - x0;
		if (ye > y0)
		{
			for (int i = 0; i < steps; i++)
			{
				x += 1;
				if (px < 0)
				{
					drawPoint(x, y);
					px += 2 * deltay;
				}
				else
				{
					y++;
					drawPoint(x, y);
					px += p1x;
				}
			}
		}
		else
		{
			px = -2 * deltax - deltax;
			for (int i = 0; i < steps; i++)
			{
				x += 1;
				if (px < 0)
				{
					drawPoint(x, y);
					px -= 2 * deltay;
				}
				else
				{
					y--;
					drawPoint(x, y);
					px += p2x;
				}
			}
		}
	}
	else
	{
		if (y1 > y2)
		{
			x0 = x2;
			y0 = y2;
			xe = x1;
			ye = y1;
		}
		int deltax = xe - x0;
		int deltay = ye - y0;
		int p1y = 2 * deltax - 2 * deltay;
		int p2y = -2 * deltax - 2 * deltay;
		int py = 2 * deltax - deltay;
		int x = x0;
		int y = y0;
		steps = ye - y0;
		if (xe > x0)
		{
			for (int i = 0; i < steps; i++)
			{
				y += 1;
				if (py < 0)
				{
					drawPoint(x, y);
					py += 2 * deltax;
				}
				else
				{
					x++;
					drawPoint(x, y);
					py += p1y;
				}
			}
		}
		else
		{
			py = -2 * deltay - deltay;
			for (int i = 0; i < steps; i++)
			{
				y += 1;
				if (py < 0)
				{
					drawPoint(x, y);
					py -= 2 * deltax;
				}
				else
				{
					x--;
					drawPoint(x, y);
					py += p2y;
				}
			}
		}
	}
}

