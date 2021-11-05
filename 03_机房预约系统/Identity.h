#pragma once
#include<iostream>
using namespace std;

//身份的抽象基类
class Identity
{
public:
	//用户名
	string m_Name;
	//密码
	string m_Pwd;
	//纯虚函数
	virtual void operMenu() = 0;
};
