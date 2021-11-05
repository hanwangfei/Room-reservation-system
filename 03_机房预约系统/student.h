#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

//学生类
class Student :public Identity
{
public:
	int m_Id;   //学号
	vector<computerRoom> vCom;

	Student();   //默认构造
	Student(int id, string name, string pwd);  //有参构造
	virtual void operMenu();  //菜单界面

	void applyOrder();  //申请预约
	void showMyOrder();   //查看自身预约
	void showAllOrder();   //查看所有预约
	void cancleOrder();    //取消预约


};
