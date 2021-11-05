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

//����Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name,string pwd);
	//�˵�����
	virtual void  operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();
	vector<Student> vStu;  //ѧ������
	vector<Teacher> vTea;  //��ʦ����
	vector<computerRoom> vCom;  //������Ϣ����

	//����ظ�  ,idΪ����ѧ�Ż�ְ����
	bool cheakRepeat(int id, int type);

};
