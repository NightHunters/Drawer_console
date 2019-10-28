#pragma once
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include<string>
#include "Command.h"
#include "Paint.h"

class Canvas//管理画布、解析指令
{
	bool flag;
	int height;
	int width;
	QPixmap pix;
	QPen pen;
public:
	Canvas();
	void resetCanvas(int wid, int hei);//重置画布
	void saveCanvas(string name);//保存画布
	void test();//测试用
};