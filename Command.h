#pragma once
#include <iostream>
#include<fstream>
#include <cstring>
using namespace std;

//#define MAX_COL_SIZE 10
//#define MAX_ATTR_LEN 30
#define MAX_COMMAND_SEG 50
#define MAX_COMMAND_SEG_LEN 20

class Command //ʶ��ָ��
{
public:
	int argc;//����ָ��ĵ��ʸ���
	char *argv[MAX_COMMAND_SEG];//����ÿ�������ָ��
	Command();
	Command(const Command& a);//�������캯��
	~Command();
	friend istream & operator >> (istream &cin, Command &command);//����̨����
	friend ifstream & operator >> (ifstream &input, Command &command);//�ļ�����
};

istream & operator >> (istream &cin, Command &command);
ifstream & operator >> (ifstream &input, Command &command);