#pragma once
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include <cstdlib>
#include<string>
#include<vector>
#include "Command.h"
#include "Paint.h"

class Canvas//管理画布、解析指令
{
	bool flag;
	int height;
	int width;
	QPixmap pix;
	QPen pen;
	vector<Command> vec;
public:
	Canvas();
	void resetCanvas(int wid, int hei);//重置画布
	void saveCanvas(string name);//保存画布
	void setColor(int r, int g, int b);//设置画笔颜色
	//void identify_command_by_console();//解析从控制台输入的指令
	void translate(int dx,int dy,vector<Command>::iterator it);
	void rotate(int x, int y, double a, vector<Command>::iterator it);
	void scale(int x, int y, float s, vector<Command>::iterator it);
	void clip_by_cohen_sutherland(int xL, int yB, int xR, int yT, vector<Command>::iterator it);
	void update_u(double p, double q, double &u1, double &u2);
	void clip_by_liang_barsky(int xL, int yB, int xR, int yT, vector<Command>::iterator it);
	void preprocess(string commandfile, string savepath);//预处理，处理平移、旋转和缩放等操作
	void process(vector<Command>::iterator outset);
	void identify_command_by_file(string commandfile,string savepath);//解析从文件中输入的指令
	void test();//测试用
};