#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

//管理员类
class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name,string pwd);
	//菜单界面
	virtual void  operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();
	vector<Student> vStu;  //学生容器
	vector<Teacher> vTea;  //老师容器
	vector<computerRoom> vCom;  //机房信息容器

	//检测重复  ,id为检测的学号或职工号
	bool cheakRepeat(int id, int type);

};
