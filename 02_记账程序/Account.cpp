#include "stdafx.h"
#include "Account.h"
#include <fstream>
#include <cmath>

//���캯��
Account::Account(bool __isE, double __mon, bool __isN,
	std::string __note, double __bal, double __allC,
	double __allI)
	:
	isExpense(__isE), money(__mon), isNecessary(__isN),
	Note(__note), balance(__bal), allCost(__allC),
	allIncome(__allI) {}

//�����µ������Ϣ�������µ�Account��Ŀ
Account calcByBalance(const Account& __last,
	double __newBalance,
	std::string __n = "��", bool __isN = true)
{
	//========Account������Ŀ==========
	bool		isExpense{ __last.balance - __newBalance > 0 };
	double		money{ fabs(__last.balance - __newBalance) };
	bool		isNecessary{ __isN };
	std::string Note{ __n };
	double		balance{ __newBalance };
	double		allCost{ isExpense ? __last.balance - __newBalance : 0 };
	double		allIncome{ isExpense ? 0 : __newBalance - __last.balance };
	//=================================
	Account result(isExpense, money, isNecessary,
		Note, balance, allCost, allIncome);
	return result;
}

//�����������,��Accountֱ��д���ļ�
std::ofstream& operator<<(std::ofstream& __ofs, Account& __w)
{
	std::string InAndOut = __w.isExpense ? "֧��" : "����";
	std::string Necessary = __w.isNecessary ? "����" : "�Ǳ���";
	__ofs << InAndOut << '\t' << __w.money << '\t'
		<< Necessary << __w.Note << '\t' << __w.balance
		<< '\t' << __w.allCost << '\t' << __w.allIncome;
	return __ofs;
}
