#include"manager.h"

// 默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器 并且获取到文件中的所有老师和学生信息
	this->initVector();

}

//菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录!" << endl;
	cout << "\t\t  ------------------------\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       1.添加账号       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       2.查看账号       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       3.查看机房       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       4.清空预约       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t |       0.注销登录       |\n";
	cout << "\t\t |                        |\n";
	cout << "\t\t  ------------------------\n";
	cout << "请输入您的选择：";
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

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
			//添加学生
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号：";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

		//利用追加的方式写文件
		ofs.open(fileName, ios::out | ios::app);

		int id;
		string name;
		string pwd;
		cout << tip;

		while (true)
		{
	
			cin >> id;
			bool ret = cheakRepeat(id, select);
			if (ret)  //有重复
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}

		}

		
	
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入登录密码：" << endl;
		cin >> pwd;

		//向文件中添加数据
		ofs << id << " " << name << " " << pwd << " " << endl; //注意用空格分割
		cout << "添加成功" << endl;
		ofs.close();
		system("pause");
		system("cls");

		//调用初始化容器的接口重新获取容器中的数据 防止用户重复添加相同的数据
		this->initVector();
		return;

	

}

//初始化容器
void  Manager::initVector()
{
	//确保容器清空状态
	vStu.clear();
	vTea.clear();
	vCom.clear();
	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "当前老师的数量为：" << vTea.size() << endl;
	ifs.close();

	//读取机房信息
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs>>com.m_ComId&&ifs>>com.m_MaxNum)
	{
		vCom.push_back(com);

	}
	ifs.close();


} 

//检测重复  ,id为检测的学号或职工号
bool Manager::cheakRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			return true;
		}

	}
	else
	{
		//检测老师
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
	cout << "学号：" << s.m_Id << "\t\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "职工号：" << s.m_EmpId << "\t\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;

}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号为：" << it->m_ComId << "\t机房最大容量为：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空预约成功" << endl;
	system("pause");
	system("cls");

}