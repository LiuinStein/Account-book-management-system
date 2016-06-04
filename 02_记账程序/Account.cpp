#include "stdafx.h"
#include "Account.h"
#include <fstream>
#include <cmath>

//构造函数
Account::Account(EIMODE __EIM, double __mon, bool __isN,
	std::string __note, double __bal, double __allC,
	double __allI) :
	EIMode(__EIM), money(__mon), isNecessary(__isN),
	Note(__note), balance(__bal), allCost(__allC),
	allIncome(__allI) {}

//根据新的余额信息来生成新的Account条目
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

//根据流动数额多少来生成新的Account条目
Account::Account(const Account* __last, double __mon,
	EIMODE __EIM, std::string __n, bool __isN) :
	EIMode(__EIM), money(__mon),
	isNecessary(__isN), Note(__n),
	balance(EIMode == Expense ? __last->balance - __mon : __last->balance + __mon),
	allCost(EIMode == Expense ? __mon : 0),
	allIncome(EIMode == Expense ? 0 : __mon) {}

//得到余额
double Account::getBalance() const
{
	return balance;
}

//设置余额
void Account::setBalance(double __s)
{
	balance = __s;
}

//得到是否必需
bool Account::getIsN() const
{
	return isNecessary;
}

//得到流动金额
double Account::getMon() const
{
	return money;
}

//得到收支模式
EIMODE Account::getEIMODE() const
{
	return EIMode;
}

//设置收支模式
void Account::setEIM(EIMODE __s)
{
	EIMode = __s;
}

//得到说明
const std::string& Account::getNote() const
{
	return Note;
}

//重载流运算符,将Account直接写入文件
std::ofstream& operator<<(std::ofstream& __ofs, Account& __w)
{
	std::string InAndOut;
	if (__w.EIMode == Expense)
		InAndOut = "支出";
	else if (__w.EIMode == Income)
		InAndOut = "收入";
	else
		InAndOut = "-";
	std::string Necessary = __w.isNecessary ? "必需" : "非必需";
	__ofs << InAndOut << '\t' << __w.money << '\t'
		<< Necessary << '\t' << __w.Note << '\t' << __w.balance
		<< '\t' << __w.allCost << '\t' << __w.allIncome;
	return __ofs;
}
