#pragma once
#include "Time.h"
#include "Account.h"
#include <vector>

class Line
{
protected:
	Time*		NowTime;		//ʱ��
	std::string Description;	//˵��
	Account*	Accounts;		//��Ŀ
private:
	std::string LineContext;	//����Ϣ

	void Analyze();	//����Ϣ����

public:
	Line();
	explicit Line(std::string & __inp);

	//���������������,���ļ���ֱ�Ӷ�����
	friend std::ifstream& operator>> (std::ifstream & __ifs,Line & __l);
	
	//���������������,ֱ�����ļ�д����
	friend std::ofstream& operator<<(std::ofstream & __ofs, Line & __l);

};

