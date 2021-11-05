#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int emId, string name, string pwd)
{
	this->m_EmpId = emId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼!" << endl;
	cout << "\t\t  ------------------------\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       1.�鿴����ԤԼ   |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       2.���ԤԼ       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       0.ע����¼       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t  ------------------------\n";
	cout << "����������ѡ��";

}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	Student().showAllOrder();  //ֱ�ӵ�������ѧ��������ʾ����ԤԼ

}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["data"];
			cout << "\tʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "\t������ţ�" << of.m_OrderData[i]["roomId"];
			cout << "\tѧ����ţ�" << of.m_OrderData[i]["stuId"];
			cout << "\tѧ��������" << of.m_OrderData[i]["stuName"];
			string status = "\t״̬�������";
			cout << status << endl;


		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;   //��˽��

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˵Ľ����" << endl;
				cout << "1��ͨ��" << endl << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ��
					of.m_OrderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					//��ͨ��
					of.m_OrderData[v[select - 1]]["status"] = "-1";

				}
				of.updateOrder();
				cout << "������" << endl;
				break;

			}

		}
		else
		{
			cout << "������������������" << endl;
		}

	}
	system("pause");
	system("cls");

}