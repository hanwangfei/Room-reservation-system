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

//ѧ����
class Student :public Identity
{
public:
	int m_Id;   //ѧ��
	vector<computerRoom> vCom;

	Student();   //Ĭ�Ϲ���
	Student(int id, string name, string pwd);  //�вι���
	virtual void operMenu();  //�˵�����

	void applyOrder();  //����ԤԼ
	void showMyOrder();   //�鿴����ԤԼ
	void showAllOrder();   //�鿴����ԤԼ
	void cancleOrder();    //ȡ��ԤԼ


};
