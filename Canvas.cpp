#include "Canvas.h"
#include<iostream>
using namespace std;
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
	pix.fill(QColor(255, 255, 255, 255));
	flag = true;
}
void Canvas::saveCanvas(string name)
{
	string pic_name = name + ".bmp";
	pix.save(pic_name.c_str());
}
void Canvas::setColor(int r, int g, int b)
{
	pen.setColor(QColor(r, g, b));
}

void Canvas::translate(int dx,int dy,vector<Command>::iterator it)
{
	if (strcmp(it->argv[0], "drawLine") == 0)//平移线段
	{
		int temp = 0;
		temp = atoi(it->argv[2]);
		temp += dx;
		itoa(temp, it->argv[2], 10);
		temp = atoi(it->argv[3]);
		temp += dy;
		itoa(temp, it->argv[3], 10);

		temp = atoi(it->argv[4]);
		temp += dx;
		itoa(temp, it->argv[4], 10);
		temp = atoi(it->argv[5]);
		temp += dy;
		itoa(temp, it->argv[5], 10);
	}
	else if (strcmp(it->argv[0], "drawPolygon") == 0)//平移多边形
	{
		int temp = 0;
		int n = atoi(it->argv[2]);
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[4 + i * 2]);
			temp += dx;
			itoa(temp, it->argv[4 + i * 2], 10);
		}
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[5 + i * 2]);
			temp += dy;
			itoa(temp, it->argv[5 + i * 2], 10);
		}
	}
	else if (strcmp(it->argv[0], "drawEllipse") == 0)//平移椭圆
	{
		int temp = 0;
		temp = atoi(it->argv[2]);
		temp += dx;
		itoa(temp, it->argv[2], 10);
		temp = atoi(it->argv[3]);
		temp += dy;
		itoa(temp, it->argv[3], 10);
	}
	else if (strcmp(it->argv[0], "drawCurve") == 0)//平移曲线
	{
		int temp = 0;
		int n = atoi(it->argv[2]);
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[4 + i * 2]);
			temp += dx;
			itoa(temp, it->argv[4 + i * 2], 10);
		}
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[5 + i * 2]);
			temp += dy;
			itoa(temp, it->argv[5 + i * 2], 10);
		}
	}
}
void Canvas::rotate(int x, int y, double a, vector<Command>::iterator it)
{
	if (strcmp(it->argv[0], "drawLine") == 0)//旋转线段
	{
		double temp = 0;
		int temp_x = 0, temp_y = 0;//记录关键点
		temp_x = atoi(it->argv[2]);
		temp_y = atoi(it->argv[3]);
		temp = x + (temp_x - x)*cos(a) - (temp_y - y)*sin(a);
		itoa(int(temp + 0.5), it->argv[2], 10);
		temp = y + (temp_x - x)*sin(a) + (temp_y - y)*cos(a);
		itoa(int(temp + 0.5), it->argv[3], 10);

		temp_x = atoi(it->argv[4]);
		temp_y = atoi(it->argv[5]);
		temp = x + (temp_x - x)*cos(a) - (temp_y - y)*sin(a);
		itoa(int(temp + 0.5), it->argv[4], 10);
		temp = y + (temp_x - x)*sin(a) + (temp_y - y)*cos(a);
		itoa(int(temp + 0.5), it->argv[5], 10);
	}
	else if (strcmp(it->argv[0], "drawPolygon") == 0)//旋转多边形
	{
		double temp = 0;
		int temp_x = 0, temp_y = 0;
		int n = atoi(it->argv[2]);
		for (int i = 0; i < n; i++)
		{
			temp_x = atoi(it->argv[4 + i * 2]);
			temp_y = atoi(it->argv[5 + i * 2]);
			temp = x + (temp_x - x)*cos(a) - (temp_y - y)*sin(a);
			itoa(int(temp + 0.5), it->argv[4 + i * 2], 10);
			temp = y + (temp_x - x)*sin(a) + (temp_y - y)*cos(a);
			itoa(int(temp + 0.5), it->argv[5 + i * 2], 10);
		}
	}
	else if (strcmp(it->argv[0], "drawCurve") == 0)//旋转曲线
	{
		double temp = 0;
		int temp_x = 0, temp_y = 0;
		int n = atoi(it->argv[2]);
		for (int i = 0; i < n; i++)
		{
			temp_x = atoi(it->argv[4 + i * 2]);
			temp_y = atoi(it->argv[5 + i * 2]);
			temp = x + (temp_x - x)*cos(a) - (temp_y - y)*sin(a);
			itoa(int(temp + 0.5), it->argv[4 + i * 2], 10);
			temp = y + (temp_x - x)*sin(a) + (temp_y - y)*cos(a);
			itoa(int(temp + 0.5), it->argv[5 + i * 2], 10);
		}
	}
}
void Canvas::scale(int x, int y, float s, vector<Command>::iterator it)
{
	if (strcmp(it->argv[0], "drawLine") == 0)//缩放线段
	{
		int temp = 0;
		float transfer_to = 0;
		temp = atoi(it->argv[2]);
		transfer_to = temp*s + x*(1 - s);
		itoa(int(transfer_to + 0.5), it->argv[2], 10);
		temp = atoi(it->argv[3]);
		transfer_to = temp*s + y*(1 - s);
		itoa(int(transfer_to + 0.5), it->argv[3], 10);

		temp = atoi(it->argv[4]);
		transfer_to = temp*s + x*(1 - s);
		itoa(int(transfer_to + 0.5), it->argv[4], 10);
		temp = atoi(it->argv[5]);
		transfer_to = temp*s + y*(1 - s);
		itoa(int(transfer_to + 0.5), it->argv[5], 10);
	}
	else if (strcmp(it->argv[0], "drawPolygon") == 0)//缩放多边形
	{
		int temp = 0;
		float transfer_to = 0;
		int n = atoi(it->argv[2]);
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[4 + i * 2]);
			transfer_to = temp*s + x*(1 - s);
			itoa(int(transfer_to + 0.5), it->argv[4 + i * 2], 10);
		}
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[5 + i * 2]);
			transfer_to = temp*s + y*(1 - s);
			itoa(int(transfer_to + 0.5), it->argv[5 + i * 2], 10);
		}
	}
	else if (strcmp(it->argv[0], "drawEllipse") == 0)//缩放椭圆
	{
		int temp = 0;
		float transfer_to = 0;
		temp = atoi(it->argv[2]);
		transfer_to = temp*s + x*(1 - s);
		itoa(int(transfer_to + 0.5), it->argv[2], 10);
		temp = atoi(it->argv[3]);
		transfer_to = temp*s + y*(1 - s);
		itoa(int(transfer_to + 0.5), it->argv[3], 10);//缩放中心点

		temp = atoi(it->argv[4]);
		transfer_to = temp*s;
		itoa(int(transfer_to + 0.5), it->argv[4], 10);
		temp = atoi(it->argv[5]);
		transfer_to = temp*s;
		itoa(int(transfer_to + 0.5), it->argv[5], 10);//缩放长短轴半径
	}
	else if (strcmp(it->argv[0], "drawCurve") == 0)//缩放曲线
	{
		int temp = 0;
		float transfer_to = 0;
		int n = atoi(it->argv[2]);
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[4 + i * 2]);
			transfer_to = temp*s + x*(1 - s);
			itoa(int(transfer_to + 0.5), it->argv[4 + i * 2], 10);
		}
		for (int i = 0; i < n; i++)
		{
			temp = atoi(it->argv[5 + i * 2]);
			transfer_to = temp*s + y*(1 - s);
			itoa(int(transfer_to + 0.5), it->argv[5 + i * 2], 10);
		}
	}
}
void Canvas::clip_by_cohen_sutherland(int xL, int yB, int xR, int yT, vector<Command>::iterator &it)
{
	if (strcmp(it->argv[0], "drawLine") == 0)//缩放线段
	{
		double x1 = atoi(it->argv[2]);
		double y1 = atoi(it->argv[3]);
		double x2 = atoi(it->argv[4]);
		double y2 = atoi(it->argv[5]);
		for (int i = 0; i < 4; i++)
		{
			int area_code1 = 0, area_code2 = 0;//区域码
			if (x1 < xL)
				area_code1 |= 0b0001;
			if (x1 > xR)
				area_code1 |= 0b0010;
			if (y1 < yB)
				area_code1 |= 0b0100;
			if (y1 > yT)
				area_code1 |= 0b1000;

			if (x2 < xL)
				area_code2 |= 0b0001;
			if (x2 > xR)
				area_code2 |= 0b0010;
			if (y2 < yB)
				area_code2 |= 0b0100;
			if (y2 > yT)
				area_code2 |= 0b1000;
			if (area_code1 == 0 && area_code2 == 0)//线段完全在窗口内
			{
				itoa(int(x1 + 0.5), it->argv[2], 10);
				itoa(int(y1 + 0.5), it->argv[3], 10);
				itoa(int(x2 + 0.5), it->argv[4], 10);
				itoa(int(y2 + 0.5), it->argv[5], 10);
				return;
			}
			if ((area_code1 & area_code2) != 0)
			{
				cout << "线段不在裁剪窗口内！" << endl;
				//itoa(0, it->argv[6], 10);
				strcpy(it->argv[1], "hide");
				return;
			}
			if (area_code1 == 0)//P1与P2交换
			{
				double temp = 0;
				temp = x1;
				x1 = x2;
				x2 = temp;
				temp = y1;
				y1 = y2;
				y2 = temp;
				temp = area_code1;
				area_code1 = area_code2;
				area_code2 = temp;
			}
			if ((area_code1 & 0b1000) != 0)
			{
				x1 = (yT - y1)*(x1 - x2) / (y1 - y2) + x1;
				y1 = yT;
			}
			else if ((area_code1 & 0b0100) != 0)
			{
				x1 = (yB - y1)*(x1 - x2) / (y1 - y2) + x1;
				y1 = yB;
			}
			else if ((area_code1 & 0b0010) != 0)
			{
				y1 = (xR - x1)*(y1 - y2) / (x1 - x2) + y1;
				x1 = xR;
			}
			else if ((area_code1 & 0b0001) != 0)
			{
				y1 = (xL - x1)*(y1 - y2) / (x1 - x2) + y1;
				x1 = xL;
			}
		}
	}
}

void Canvas::update_u(double p, double q, double &u1, double &u2)
{
	double r = 0;
	if (p < 0)
	{
		r = q / p;
		if (r > u1)
			u1 = r;
	}
	else if (p > 0)
	{
		r = q / p;
		if (r < u2)
			u2 = r;
	}
	else
	{
		if (q < 0)
		{
			cout << "线段不在裁剪窗口内！" << endl;
			return;
		}
	}
}
void Canvas::clip_by_liang_barsky(int xL, int yB, int xR, int yT, vector<Command>::iterator &it)
{
	if (strcmp(it->argv[0], "drawLine") == 0)//缩放线段
	{
		double x1 = atoi(it->argv[2]);
		double y1 = atoi(it->argv[3]);
		double x2 = atoi(it->argv[4]);
		double y2 = atoi(it->argv[5]);

		double p1 = x1 - x2;
		double p2 = x2 - x1;
		double p3 = y1 - y2;
		double p4 = y2 - y1;

		double q1 = x1 - xL;
		double q2 = xR - x1;
		double q3 = y1 - yB;
		double q4 = yT - y1;

		double u1 = 0, u2 = 1;
		update_u(p1, q1, u1, u2);
		update_u(p2, q2, u1, u2);
		update_u(p3, q3, u1, u2);
		update_u(p4, q4, u1, u2);
		if (u1 <= u2)
		{
			double temp_x = x1 + u1*p2;
			double temp_y = y1 + u1*p4;
			itoa(int(temp_x + 0.5), it->argv[2], 10);
			itoa(int(temp_y + 0.5), it->argv[3], 10);

			temp_x = x1 + u2*p2;
			temp_y = y1 + u2*p4;
			itoa(int(temp_x + 0.5), it->argv[4], 10);
			itoa(int(temp_y + 0.5), it->argv[5], 10);
		}
		else
		{
			cout << "线段不在裁剪窗口内！" << endl;
			//itoa(0, it->argv[6], 10);
			strcpy(it->argv[1], "hide");
			return;
		}
	}
}
void Canvas::preprocess(string commandfile, string savepath)//图元变换处理
{
	ifstream fin(commandfile);
	if (!fin)
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	vector<Command>::iterator it;
	Command c;
	Command c1;
	while (fin >> c)
	{
		vector<Command>::iterator outset = vec.begin();//标记点
		if (strcmp(c.argv[0], "translate") == 0)//平移
		{
			int dx = atoi(c.argv[2]);
			int dy = atoi(c.argv[3]);
			for (it = outset; it != vec.end(); it++)
			{
				if (strcmp(it->argv[1], c.argv[1]) == 0)
				{
					translate(dx, dy, it);
				}
			}
		}
		else if (strcmp(c.argv[0], "rotate") == 0)//旋转
		{
			int x = atoi(c.argv[2]);
			int y = atoi(c.argv[3]);//旋转中心
			int r = atoi(c.argv[4]);//旋转角度
			double pi = 4.0*atan(1);
			double a = r*pi / 180;//角度转弧度
			for (it = outset; it != vec.end(); it++)
			{
				if (strcmp(it->argv[1], c.argv[1]) == 0)
				{
					rotate(x, y, a, it);
				}
			}
		}
		else if (strcmp(c.argv[0], "scale") == 0)//缩放
		{
			int x = atoi(c.argv[2]);
			int y = atoi(c.argv[3]);
			float s = atof(c.argv[4]);
			for (it = outset; it != vec.end(); it++)
			{
				if (strcmp(it->argv[1], c.argv[1]) == 0)
				{
					scale(x, y, s, it);
				}
			}
		}
		else if (strcmp(c.argv[0], "clip") == 0)//对线段裁剪
		{
			int xL = atoi(c.argv[2]);
			int yB = atoi(c.argv[3]);
			int xR = atoi(c.argv[4]);
			int yT = atoi(c.argv[5]);
			if (strcmp(c.argv[6], "Cohen-Sutherland") == 0)
			{
				for (it = outset; it != vec.end(); it++)
				{
					if (strcmp(it->argv[1], c.argv[1]) == 0)
					{
						clip_by_cohen_sutherland(xL, yB, xR, yT, it);
					}
				}
			}
			else if (strcmp(c.argv[6], "Liang-Barsky") == 0)
			{
				for (it = outset; it != vec.end(); it++)
				{
					if (strcmp(it->argv[1], c.argv[1]) == 0)
					{
						clip_by_liang_barsky(xL, yB, xR, yT, it);
					}
				}
			}
		}
		else if (strcmp(c.argv[0], "resetCanvas") == 0)
		{
			vec.push_back(c);
			outset = vec.end() - 1;
		}
		else if (strcmp(c.argv[0], "saveCanvas") == 0)
		{
			process(outset);
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			string fullpicture;//完整保存的图片地址
			fullpicture = savepath + c.argv[1];
			saveCanvas(fullpicture);
		}
		else if (strcmp(c.argv[0], "drawPolygon") == 0)
		{
			fin >> c1;
			c.add_command(c1);
			vec.push_back(c);
		}
		else if (strcmp(c.argv[0], "drawCurve") == 0)
		{
			fin >> c1;
			c.add_command(c1);
			vec.push_back(c);
		}
		else
			vec.push_back(c);
	}
	cout << "over" << endl;
	fin.close();
}

void Canvas::process(vector<Command>::iterator outset)
{
	vector<Command>::iterator it;
	for (it = outset; it != vec.end(); it++)
	{
		Command c= *it;
		if (strcmp(c.argv[0], "resetCanvas") == 0)//重置画布
		{
			int width, height;
			width = atoi(c.argv[1]);
			height = atoi(c.argv[2]);
			if (width < 10 || width>1000 || height < 10 || height>1000)
			{
				cout << "画布长宽超过限制！范围：[10,1000]" << endl;
				continue;
			}
			resetCanvas(width, height);
		}
		else if (strcmp(c.argv[0], "setColor") == 0)//设置画笔颜色
		{
			int r, g, b;
			r = atoi(c.argv[1]);
			g = atoi(c.argv[2]);
			b = atoi(c.argv[3]);
			if (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255)
			{
				cout << "请正确设置RGB值！范围：[0,255]" << endl;
				continue;
			}
			setColor(r, g, b);
		}
		else if (strcmp(c.argv[0], "drawLine") == 0)//绘制线段
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			if (strcmp(c.argv[1], "hide") != 0)
			{
				int x1, y1, x2, y2;
				x1 = atoi(c.argv[2]);
				y1 = atoi(c.argv[3]);
				x2 = atoi(c.argv[4]);
				y2 = atoi(c.argv[5]);
				if (x1<0 || x1>width || x2<0 || x2>width || y1<0 || y1>height || y2<0 || y2>height)
				{
					cout << "线段端点不能超过画布范围！" << endl;
					continue;
				}
				if (strcmp(c.argv[6], "DDA") == 0)
				{
					Paint p(&pix);
					p.setPen(pen);
					p.drawline_DDA(x1, y1, x2, y2);
				}
				else if (strcmp(c.argv[6], "Bresenham") == 0)
				{
					Paint p(&pix);
					p.setPen(pen);
					p.drawline_Bresenham(x1, y1, x2, y2);
				}
			}
		}
		else if (strcmp(c.argv[0], "drawPolygon") == 0)//绘制多边形
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			int n = atoi(c.argv[2]);
			int *x = new int[n];
			int *y = new int[n];
			for (int i = 0; i < n; i++)
			{
				x[i] = atoi(c.argv[2 * i + 4]);
				y[i] = atoi(c.argv[2 * i + 5]);
			}
			if (strcmp(c.argv[3], "DDA") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawpolygon_DDA(n, x, y);
			}
			else if (strcmp(c.argv[3], "Bresenham") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawpolygon_Bresenham(n, x, y);
			}
		}
		else if (strcmp(c.argv[0], "drawEllipse") == 0)//绘制椭圆
		{
			int x, y, rx, ry;
			x = atoi(c.argv[2]);
			y = atoi(c.argv[3]);
			rx = atoi(c.argv[4]);
			ry = atoi(c.argv[5]);
			Paint p(&pix);
			p.setPen(pen);
			p.drawellipse(x, y, rx, ry);
		}
		else if (strcmp(c.argv[0], "drawCurve") == 0)
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			int n = atoi(c.argv[2]);
			int *x = new int[n];
			int *y = new int[n];
			for (int i = 0; i < n; i++)
			{
				x[i] = atoi(c.argv[2 * i + 4]);
				y[i] = atoi(c.argv[2 * i + 5]);
			}
			if (strcmp(c.argv[3], "Bezier") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawcurse_Bezier(n, x, y);
			}
			else if (strcmp(c.argv[3], "B-spline") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawcurse_B_spline(n, x, y);
			}
		}
		else//待实现功能
		{
			cout << "其他功能敬请期待" << endl;
		}
	}
}
void Canvas::identify_command_by_file(string commandfile,string savepath)
{
	ifstream fin(commandfile);
	if (!fin)
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Command c;
	while (fin >> c)
	{
		if (strcmp(c.argv[0], "resetCanvas") == 0)//重置画布
		{
			int width, height;
			width = atoi(c.argv[1]);
			height = atoi(c.argv[2]);
			if (width < 10 || width>1000 || height < 10 || height>1000)
			{
				cout << "画布长宽超过限制！范围：[10,1000]" << endl;
				continue;
			}
			resetCanvas(width, height);
		}
		else if (strcmp(c.argv[0], "saveCanvas") == 0)//保存画布
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			string fullpicture;//完整保存的图片地址
			fullpicture = savepath + c.argv[1];
			saveCanvas(fullpicture);
		}
		else if (strcmp(c.argv[0], "setColor") == 0)//设置画笔颜色
		{
			int r, g, b;
			r = atoi(c.argv[1]);
			g = atoi(c.argv[2]);
			b = atoi(c.argv[3]);
			if (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255)
			{
				cout << "请正确设置RGB值！范围：[0,255]" << endl;
				continue;
			}
			setColor(r, g, b);
		}
		else if (strcmp(c.argv[0], "drawLine") == 0)//绘制线段
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			int x1, y1, x2, y2;
			x1 = atoi(c.argv[2]);
			y1 = atoi(c.argv[3]);
			x2 = atoi(c.argv[4]);
			y2 = atoi(c.argv[5]);
			if (x1<0 || x1>width || x2<0 || x2>width || y1<0 || y1>height || y2<0 || y2>height)
			{
				cout << "线段端点不能超过画布范围！" << endl;
				continue;
			}
			if (strcmp(c.argv[6], "DDA") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawline_DDA(x1, y1, x2, y2);
			}
			else if (strcmp(c.argv[6], "Bresenham") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawline_Bresenham(x1, y1, x2, y2);
			}
			else
				cout << "未实现算法！" << endl;
		}
		else if (strcmp(c.argv[0], "drawPolygon") == 0)//绘制多边形
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			int n = atoi(c.argv[2]);
			int *x = new int[n];
			int *y = new int[n];
			for (int i = 0; i < n; i++)
			{
				x[i] = atoi(c.argv[2 * i + 4]);
				y[i] = atoi(c.argv[2 * i + 5]);
			}
			if (strcmp(c.argv[3], "DDA") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawpolygon_DDA(n, x, y);
			}
			else if (strcmp(c.argv[3], "Bresenham") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawpolygon_Bresenham(n,x,y);
			}
		}
		else if (strcmp(c.argv[0], "drawEllipse") == 0)//绘制椭圆
		{
			int x, y, rx, ry;
			x = atoi(c.argv[2]);
			y = atoi(c.argv[3]);
			rx = atoi(c.argv[4]);
			ry = atoi(c.argv[5]);
			Paint p(&pix);
			p.setPen(pen);
			p.drawellipse(x, y, rx, ry);
		}
		else if (strcmp(c.argv[0], "drawCurve") == 0)
		{
			if (!flag)
			{
				cout << "请先设置画布！" << endl;
				continue;
			}
			int n = atoi(c.argv[2]);
			int *x = new int[n];
			int *y = new int[n];
			for (int i = 0; i < n; i++)
			{
				x[i] = atoi(c.argv[2 * i + 4]);
				y[i] = atoi(c.argv[2 * i + 5]);
			}
			if (strcmp(c.argv[3], "Bezier") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawcurse_Bezier(n, x, y);
			}
			else if (strcmp(c.argv[3], "B-spline") == 0)
			{
				Paint p(&pix);
				p.setPen(pen);
				p.drawcurse_B_spline(n, x, y);
			}
		}
		else//待实现功能
		{
			cout << "其他功能敬请期待" << endl;
		}
	}
	fin.close();
	cout << "over" << endl;
}

void Canvas::test()
{
	string commandfile, savepath;
	cin >> commandfile >> savepath;
	//identify_command_by_file(commandfile,savepath);
	preprocess(commandfile,savepath);
}
