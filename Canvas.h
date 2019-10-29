#pragma once
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include <cstdlib>
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
	void setColor(int r, int g, int b);//设置画笔颜色
	void identify_command_by_console();//解析从控制台输入的指令
	void identify_command_by_file(string filename);//解析从文件中输入的指令
	void test();//测试用
};