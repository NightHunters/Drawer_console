#pragma once
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include <cstdlib>
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
	void setColor(int r, int g, int b);//���û�����ɫ
	void identify_command_by_console();//�����ӿ���̨�����ָ��
	void identify_command_by_file(string filename);//�������ļ��������ָ��
	void test();//������
};