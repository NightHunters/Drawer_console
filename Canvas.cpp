#include "Canvas.h"

Canvas::Canvas()
{
	pen.setColor(QColor(0, 0, 0, 255));
	height = 0;
	width = 0;
	flag = false;
}
void Canvas::resetCanvas(int wid, int hei)
{
	width = wid;
	height = hei;
	QPixmap p(wid, hei);
	pix = p.copy();
	pix.fill(QColor(238, 63, 77, 255));
}
void Canvas::saveCanvas(string name)
{
	string pic_name = name + ".bmp";
	pix.save(pic_name.c_str());
}
void Canvas::test()
{
	resetCanvas(400, 200);
	if (1)
	{
		Paint p1(&pix);
		p1.drawline_DDA(20, 20, 100, 100);
	}
	Paint p2(&pix);
	p2.drawline_DDA(20, 30, 60, 80);
	saveCanvas("4");
	resetCanvas(200, 200);
	saveCanvas("5");
}
