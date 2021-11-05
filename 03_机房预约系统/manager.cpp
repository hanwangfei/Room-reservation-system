#include"manager.h"

// Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ���һ�ȡ���ļ��е�������ʦ��ѧ����Ϣ
	this->initVector();

}

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼!" << endl;
	cout << "\t\t  ------------------------\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       1.����˺�       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       2.�鿴�˺�       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       3.�鿴����       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       4.���ԤԼ       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       0.ע����¼       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t  ------------------------\n";
	cout << "����������ѡ��";
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	while (true)
	{
		
		cin >> select;

		if (select == 1)
		{
			//���ѧ��
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			errorTip = "ѧ���ظ�������������";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ���ţ�";
			errorTip = "ְ�����ظ�������������";
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}

		//����׷�ӵķ�ʽд�ļ�
		ofs.open(fileName, ios::out | ios::app);

		int id;
		string name;
		string pwd;
		cout << tip;

		while (true)
		{
	
			cin >> id;
			bool ret = cheakRepeat(id, select);
			if (ret)  //���ظ�
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}

		}

		
	
		cout << "������������" << endl;
		cin >> name;
		cout << "�������¼���룺" << endl;
		cin >> pwd;

		//���ļ����������
		ofs << id << " " << name << " " << pwd << " " << endl; //ע���ÿո�ָ�
		cout << "��ӳɹ�" << endl;
		ofs.close();
		system("pause");
		system("cls");

		//���ó�ʼ�������Ľӿ����»�ȡ�����е����� ��ֹ�û��ظ������ͬ������
		this->initVector();
		return;

	

}

//��ʼ������
void  Manager::initVector()
{
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();
	vCom.clear();
	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ������Ϊ��" << vTea.size() << endl;
	ifs.close();

	//��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs>>com.m_ComId&&ifs>>com.m_MaxNum)
	{
		vCom.push_back(com);

	}
	ifs.close();


} 

//����ظ�  ,idΪ����ѧ�Ż�ְ����
bool Manager::cheakRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			return true;
		}

	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			return true;
		}

	}
	return false;
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "\t\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "ְ���ţ�" << s.m_EmpId << "\t\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;

}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������Ϊ��" << it->m_ComId << "\t�����������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "���ԤԼ�ɹ�" << endl;
	system("pause");
	system("cls");

}