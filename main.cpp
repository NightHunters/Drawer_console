#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include "Paint.h"
#include "Command.h"
#include "Canvas.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Canvas can;
	can.test();
	return a.exec();
}

/*QPixmap pixmap(400, 200);
pixmap.fill(QColor(238, 63, 77, 255));//R,G,B值，最后一位255表示不透明，127半透明，0透明
QPainter painter(&this);  //QPainter对象
QPen pen;
Paint p(&painter);
p.drawline_DDA(20, 20, 100, 100);
p.drawline_DDA(20, 100, 100, 100);
p.drawline_DDA(100, 20, 100, 100);
p.drawline_Bresenham(20, 20, 100, 30);
p.drawline_Bresenham(100, 20, 20, 30);
p.drawline_Bresenham(20, 20, 30, 100);
p.drawline_Bresenham(20, 100, 100, 100);
p.drawline_Bresenham(100, 20, 100, 100);
pixmap.save("2.bmp");*/