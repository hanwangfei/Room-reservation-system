#pragma once
#include<iostream>
using namespace std;

//��ݵĳ������
class Identity
{
public:
	//�û���
	string m_Name;
	//����
	string m_Pwd;
	//���麯��
	virtual void operMenu() = 0;
};
