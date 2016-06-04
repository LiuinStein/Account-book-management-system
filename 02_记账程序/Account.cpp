#include "stdafx.h"
#include "Account.h"
#include <fstream>
#include <cmath>

//���캯��
Account::Account(EIMODE __EIM, double __mon, bool __isN,
	std::string __note, double __bal, double __allC,
	double __allI) :
	EIMode(__EIM), money(__mon), isNecessary(__isN),
	Note(__note), balance(__bal), allCost(__allC),
	allIncome(__allI) {}

//�����µ������Ϣ�������µ�Account��Ŀ
Account::Account(const Account* __last,
	double __newBalance,
	std::string __n, bool __isN) :
	EIMode(
		__last->balance - __newBalance > 0 ?
		Expense : Income
	),
	money(fabs(__last->balance - __newBalance)),
	isNecessary(__isN), Note(__n),
	balance(__newBalance),
	allCost(EIMode == Expense ? __last->balance - __newBalance : 0),
	allIncome(EIMode == Expense ? 0 : __newBalance - __last->balance) {}

//����������������������µ�Account��Ŀ
Account::Account(const Account* __last, double __mon,
	EIMODE __EIM, std::string __n, bool __isN) :
	EIMode(__EIM), money(__mon),
	isNecessary(__isN), Note(__n),
	balance(EIMode == Expense ? __last->balance - __mon : __last->balance + __mon),
	allCost(EIMode == Expense ? __mon : 0),
	allIncome(EIMode == Expense ? 0 : __mon) {}

//�õ����
double Account::getBalance() const
{
	return balance;
}

//�������
void Account::setBalance(double __s)
{
	balance = __s;
}

//�õ��Ƿ����
bool Account::getIsN() const
{
	return isNecessary;
}

//�õ��������
double Account::getMon() const
{
	return money;
}

//�õ���֧ģʽ
EIMODE Account::getEIMODE() const
{
	return EIMode;
}

//������֧ģʽ
void Account::setEIM(EIMODE __s)
{
	EIMode = __s;
}

//�õ�˵��
const std::string& Account::getNote() const
{
	return Note;
}

//�����������,��Accountֱ��д���ļ�
std::ofstream& operator<<(std::ofstream& __ofs, Account& __w)
{
	std::string InAndOut;
	if (__w.EIMode == Expense)
		InAndOut = "֧��";
	else if (__w.EIMode == Income)
		InAndOut = "����";
	else
		InAndOut = "-";
	std::string Necessary = __w.isNecessary ? "����" : "�Ǳ���";
	__ofs << InAndOut << '\t' << __w.money << '\t'
		<< Necessary << '\t' << __w.Note << '\t' << __w.balance
		<< '\t' << __w.allCost << '\t' << __w.allIncome;
	return __ofs;
}
