#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include"student.h"
#include<vector>

//��ʦ��
class Teacher :public Identity
{
public:
	int m_EmpId;   //ְ����
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int emId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
};