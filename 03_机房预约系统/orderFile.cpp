#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;
	this->m_Size = 0;  //ԤԼ�ļ�¼����

	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << data << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/

		//data:1
		string key;
		string value;
		map<string, string> m;
		//��ȡ����
		int pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1); //�ڶ�������Ҳ���Բ�д��Ĭ�Ͻص�ĩβ
			m.insert(make_pair(key, value));


		}
		
		/*cout << "key=" << key;
		cout << endl << "value=" << value << endl;*/
		//ʱ���
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1); //�ڶ�������Ҳ���Բ�д��Ĭ�Ͻص�ĩβ
			m.insert(make_pair(key, value));


		}
		//ѧ��
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1); //�ڶ�������Ҳ���Բ�д��Ĭ�Ͻص�ĩβ
			m.insert(make_pair(key, value));


		}
		
		//����
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1); //�ڶ�������Ҳ���Բ�д��Ĭ�Ͻص�ĩβ
			m.insert(make_pair(key, value));


		}
		//������
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1); //�ڶ�������Ҳ���Բ�д��Ĭ�Ͻص�ĩβ
			m.insert(make_pair(key, value));


		}
		//ԤԼ״̬
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1); //�ڶ�������Ҳ���Բ�д��Ĭ�Ͻص�ĩβ
			m.insert(make_pair(key, value));


		}
		//��С��map�������뵽���map������
		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}
	ifs.close();

	//��������map����
	/*for (map<int, map<string, string>>::iterator it = m_OrderData.begin(); it != m_OrderData.end(); it++)
	{
		cout << "����Ϊ��" << it->first << "value=" << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
		{
			cout << "key=" << mit->first << "value=" << mit->second << " ";
		}
		cout << endl;
	}*/

	

}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		//ԤԼ��¼Ϊ0
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_OrderData[i]["data"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;
	}
	ofs.close(); 

}