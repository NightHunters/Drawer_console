#pragma once
#include <QtWidgets/QApplication>
#include <Qpixmap>
#include <cstdlib>
#include<string>
#include<vector>
#include "Command.h"
#include "Paint.h"

class Canvas//������������ָ��
{
	bool flag;
	int height;
	int width;
	QPixmap pix;
	QPen pen;
	vector<Command> vec;
public:
	Canvas();
	void resetCanvas(int wid, int hei);//���û���
	void saveCanvas(string name);//���滭��
	void setColor(int r, int g, int b);//���û�����ɫ
	//void identify_command_by_console();//�����ӿ���̨�����ָ��
	void translate(int dx,int dy,vector<Command>::iterator it);
	void rotate(int x, int y, double a, vector<Command>::iterator it);
	void scale(int x, int y, float s, vector<Command>::iterator it);
	void clip_by_cohen_sutherland(int xL, int yB, int xR, int yT, vector<Command>::iterator it);
	void update_u(double p, double q, double &u1, double &u2);
	void clip_by_liang_barsky(int xL, int yB, int xR, int yT, vector<Command>::iterator it);
	void preprocess(string commandfile, string savepath);//Ԥ��������ƽ�ơ���ת�����ŵȲ���
	void process(vector<Command>::iterator outset);
	void identify_command_by_file(string commandfile,string savepath);//�������ļ��������ָ��
	void test();//������
};