#pragma once
#include "Time.h"
#include "Account.h"
#include <sstream>

class Line
{
protected:
	Time*		NowTime;		//ʱ��
	std::string Description;	//˵��
	Account*	Accounts;		//��Ŀ
	std::string LineContext;	//����Ϣ
	std::stringstream ss;		//¼����

	void Analyze();	//����Ϣ����

public:
	Line();
	explicit Line(std::string & __inp);
	Line(Line & __d);

	//����˵��
	const std::string & getDescription()const;

	//д��˵��
	void setDescription(const char * __s);

	//д����Ŀ��Ϣ
	void setAccount(Account * __s);

	//��ȡ��Ŀ��Ϣ
	const Account * getAccount()const;

	//���ظ�ֵ�����
	void operator=(const Line & __c);

	//���ظ�ֵ�����,ֱ�Ӵ��ַ����ж�����
	void operator=(std::string & __str);

	//���������������,���ļ���ֱ�Ӷ�����
	friend std::ifstream& operator>> (std::ifstream & __ifs,Line & __l);
	
	//���������������,ֱ�����ļ�д����
	friend std::ofstream& operator<<(std::ofstream & __ofs, Line & __l);

};

