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

void Canvas::identify_command_by_console()
{
	Command c;
	while (cin >> c)
	{
		/*cout << c.argc << endl;
		for (int i = 0; i < c.argc; i++)
		{
			cout << c.argv[i] << endl;
		}*/
		if (strcmp(c.argv[0],"resetCanvas")==0)//���û���
		{
			int width, height;
			width = atoi(c.argv[1]);
			height = atoi(c.argv[2]);
			if (width < 10 || width>1000 || height < 10 || height>1000)
			{
				cout << "�������������ƣ���Χ��[10,1000]" << endl;
				continue;
			}
			resetCanvas(width, height);
		}
		else if (strcmp(c.argv[0], "saveCanvas") == 0)//���滭��
		{
			if (!flag)
			{
				cout << "�������û�����" << endl;
				continue;
			}
			//string name = c.argv[1];
			saveCanvas(c.argv[1]);
		}
		else if (strcmp(c.argv[0], "setColor") == 0)//���û�����ɫ
		{
			int r, g, b;
			r = atoi(c.argv[1]);
			g = atoi(c.argv[2]);
			b = atoi(c.argv[3]);
			if (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255)
			{
				cout << "����ȷ����RGBֵ����Χ��[0,255]" << endl;
				continue;
			}
			setColor(r, g, b);
		}
		else if (strcmp(c.argv[0], "drawLine") == 0)//�����߶�
		{
			if (!flag)
			{
				cout << "�������û�����" << endl;
				continue;
			}
			int x1, y1, x2, y2;
			x1 = atoi(c.argv[2]);
			y1 = atoi(c.argv[3]);
			x2 = atoi(c.argv[4]);
			y2 = atoi(c.argv[5]);
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
				cout << "δʵ���㷨��" << endl;
		}
		else//��ʵ�ֹ���
		{
			cout << "�������ܾ����ڴ�" << endl;
		}
	}
}

void Canvas::identify_command_by_file(string filename)
{
	ifstream fin(filename);
	if (!fin)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Command c;
	while (fin >> c)
	{
		if (strcmp(c.argv[0], "resetCanvas") == 0)//���û���
		{
			int width, height;
			width = atoi(c.argv[1]);
			height = atoi(c.argv[2]);
			if (width < 10 || width>1000 || height < 10 || height>1000)
			{
				cout << "�������������ƣ���Χ��[10,1000]" << endl;
				continue;
			}
			resetCanvas(width, height);
		}
		else if (strcmp(c.argv[0], "saveCanvas") == 0)//���滭��
		{
			if (!flag)
			{
				cout << "�������û�����" << endl;
				continue;
			}
			//string name = c.argv[1];
			saveCanvas(c.argv[1]);
		}
		else if (strcmp(c.argv[0], "setColor") == 0)//���û�����ɫ
		{
			int r, g, b;
			r = atoi(c.argv[1]);
			g = atoi(c.argv[2]);
			b = atoi(c.argv[3]);
			if (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255)
			{
				cout << "����ȷ����RGBֵ����Χ��[0,255]" << endl;
				continue;
			}
			setColor(r, g, b);
		}
		else if (strcmp(c.argv[0], "drawLine") == 0)//�����߶�
		{
			if (!flag)
			{
				cout << "�������û�����" << endl;
				continue;
			}
			int x1, y1, x2, y2;
			x1 = atoi(c.argv[2]);
			y1 = atoi(c.argv[3]);
			x2 = atoi(c.argv[4]);
			y2 = atoi(c.argv[5]);
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
				cout << "δʵ���㷨��" << endl;
		}
		else//��ʵ�ֹ���
		{
			cout << "�������ܾ����ڴ�" << endl;
		}
	}
	fin.close();
	cout << "over" << endl;
}

void Canvas::test()
{
	//identify_command_by_console();
	identify_command_by_file("input.txt");
}
