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
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();
	//记录预约条数
	int m_Size;
	//寄了所有预约信息的容器，key为记录条数,value为记录的键值对的信息
	map<int, map<string, string>> m_OrderData;
};
