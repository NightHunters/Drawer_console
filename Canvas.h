#pragma once
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include<string>
#include "Command.h"
#include "Paint.h"

class Canvas//������������ָ��
{
	bool flag;
	int height;
	int width;
	QPixmap pix;
	QPen pen;
public:
	Canvas();
	void resetCanvas(int wid, int hei);//���û���
	void saveCanvas(string name);//���滭��
	void test();//������
};