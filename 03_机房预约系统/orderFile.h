#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();
	//��¼ԤԼ����
	int m_Size;
	//��������ԤԼ��Ϣ��������keyΪ��¼����,valueΪ��¼�ļ�ֵ�Ե���Ϣ
	map<int, map<string, string>> m_OrderData;
};
