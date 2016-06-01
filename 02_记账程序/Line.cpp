#include "stdafx.h"
#include "Line.h"
#include <fstream>
#include <sstream>


//����Ϣ����
void Line::Analyze()
{
	std::stringstream ss(LineContext);		//¼����
	//������
	//����ʱ��
	std::string date, time;
	ss >> date >> time;
	std::string now = date + time;
	NowTime = new Time(now);

	ss >> Description;	//����˵��

	//������Ŀ��Ϣ
	//=======��������Ŀ��Ϣ�б�==========
		bool		isExpense;		//֧��Ϊtrue,����Ϊfalse
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
	isExpense = tmp == "����" ? false : true;
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
	Accounts = new Account(isExpense, money, isNecessary,
		Note, balance, allCost, allIncome);

}

Line::Line():NowTime(nullptr),Accounts(nullptr)
{
}

//�����ַ����õ�һ����Ŀ��Ϣ
Line::Line(std::string & __inp):NowTime(new Time()),
	LineContext(__inp)
{
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
		<< __l.Accounts << std::endl;
	return __ofs;
}
