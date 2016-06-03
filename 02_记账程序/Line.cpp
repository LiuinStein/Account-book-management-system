#include "stdafx.h"
#include "Line.h"
#include <fstream>
#include <sstream>


//����Ϣ����
void Line::Analyze()
{
	ss << LineContext;		//¼����
	//������
	//����ʱ��
	std::string date, time;
	ss >> date >> time;
	std::string now = date + time;
	NowTime = new Time(now);

	ss >> Description;	//����˵��

	//������Ŀ��Ϣ
	//=======��������Ŀ��Ϣ�б�==========
		EIMODE		EIMode;		
		double		money;			//�������
		bool		isNecessary;	//����Ϊtrue
		std::string Note;			//��ע
		double		balance;		//��ǰ��Ŀ���
		double		allCost;		//�ܻ���
		double		allIncome;		//������
	//=================================
	std::string tmp;
	//��������֧��
	ss >> tmp;
	EIMode = tmp == "����" ? Income : Expense;
	//�����������
	ss >> money;
	//�����Ƿ����
	ss >> tmp;
	isNecessary = tmp == "����" ? true : false;
	//������ע
	ss >> Note;
	//������Ŀ���,�ܻ���,������
	ss >> balance >> allCost >> allIncome;

	//ͨ��������Ϣ����Calc
	Accounts = new Account(EIMode, money, isNecessary,
		Note, balance, allCost, allIncome);

}

//Ĭ�Ϲ��캯��
Line::Line():NowTime(new Time()),Accounts(nullptr)
{
}

//�����ַ����õ�һ����Ŀ��Ϣ
Line::Line(std::string & __inp) : LineContext(__inp)
{
	Analyze();
}

Line::Line(Line& __d) :
	NowTime(new Time(*__d.NowTime)),
	Description(__d.Description),
	Accounts(new Account(*__d.Accounts)),
	LineContext(__d.LineContext) {}

//����˵��
const std::string& Line::getDescription() const
{
	return Description;
}

//д��˵��
void Line::setDescription(const char * __s)
{
	Description = __s;
}

//д����Ŀ��Ϣ
void Line::setAccount(Account* __s)
{
	Accounts = __s;
}

//��ȡ��Ŀ��Ϣ
const Account* Line::getAccount() const
{
	return Accounts;
}

//���ظ�ֵ�����
void Line::operator=(const Line& __c)
{	
	//��ֹ__c����ɾ��,�������ָ�����ݽ��и����ٸ�ֵ
	NowTime = new Time(*__c.NowTime);
	Description = __c.Description;
	Accounts = new Account(*__c.Accounts);	//ͬ��
	LineContext = __c.LineContext;
}

//���ظ�ֵ�����,ֱ�Ӵ��ַ����ж�����
void Line::operator=(std::string& __str)
{
	LineContext = __str;
	Analyze();
}

//���������������,���ļ���ֱ�Ӷ�����
std::ifstream& operator>>(std::ifstream& __ifs, Line& __l)
{
	std::string inp;
	std::getline(__ifs,inp);	//���ļ��ж�����
	Line tmp(inp);
	__l = tmp;
	return __ifs;
}

//���������������,ֱ�����ļ�д����
std::ofstream & operator<<(std::ofstream & __ofs, Line & __l)
{
	__ofs << __l.NowTime << '\t' << __l.Description
		<< __l.Accounts;
	return __ofs;
}
