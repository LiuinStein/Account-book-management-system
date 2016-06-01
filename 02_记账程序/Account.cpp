#include "stdafx.h"
#include "Account.h"
#include <fstream>
#include <cmath>

//构造函数
Account::Account(bool __isE, double __mon, bool __isN,
	std::string __note, double __bal, double __allC,
	double __allI) :
	isExpense(__isE), money(__mon), isNecessary(__isN),
	Note(__note), balance(__bal), allCost(__allC),
	allIncome(__allI) {}

//根据新的余额信息来生成新的Account条目
Account::Account(const Account* __last,
	double __newBalance,
	std::string __n, bool __isN) :
	isExpense(__last->balance - __newBalance > 0),
	money(fabs(__last->balance - __newBalance)),
	isNecessary(__isN), Note(__n),
	balance(__newBalance),
	allCost(isExpense ? __last->balance - __newBalance : 0),
	allIncome(isExpense ? 0 : __newBalance - __last->balance) {}

//根据流动数额多少来生成新的Account条目
Account::Account(const Account* __last, double __mon,
	bool __isE, std::string __n, bool __isN) :
	isExpense(__isE), money(__mon),
	isNecessary(__isN), Note(__n),
	balance(__isE ? __last->balance - __mon : __last->balance + __mon),
	allCost(__isE ? __mon : 0), allIncome(__isE ? 0 : __mon){}

//得到余额
double Account::getBalance() const
{
	return balance;
}

//重载流运算符,将Account直接写入文件
	std::ofstream& operator<<(std::ofstream& __ofs, Account& __w)
{
	std::string InAndOut = __w.isExpense ? "支出" : "收入";
	std::string Necessary = __w.isNecessary ? "必需" : "非必需";
	__ofs << InAndOut << '\t' << __w.money << '\t'
		<< Necessary << __w.Note << '\t' << __w.balance
		<< '\t' << __w.allCost << '\t' << __w.allIncome;
	return __ofs;
}
