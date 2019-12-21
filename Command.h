#pragma once
#include <iostream>
#include<fstream>
#include <cstring>
using namespace std;

//#define MAX_COL_SIZE 10
//#define MAX_ATTR_LEN 30
#define MAX_COMMAND_SEG 50
#define MAX_COMMAND_SEG_LEN 20

class Command //识别指令
{
public:
	int argc;//输入指令的单词个数
	char *argv[MAX_COMMAND_SEG];//保存每行输入的指令
	Command();
	Command(const Command& a);//拷贝构造函数
	~Command();
	friend istream & operator >> (istream &cin, Command &command);//控制台输入
	friend ifstream & operator >> (ifstream &input, Command &command);//文件输入
};

istream & operator >> (istream &cin, Command &command);
ifstream & operator >> (ifstream &input, Command &command);