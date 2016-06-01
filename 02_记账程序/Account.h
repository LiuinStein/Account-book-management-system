#pragma once
#include <string>

//用于存储账本条目
class Account
{
private:
	bool		isExpense;		//支出为true,收入为false
	double		money;			//流动金额
	bool		isNecessary;	//必需为true
	std::string Note;			//备注
	double		balance;		//当前账目余额
	double		allCost;		//总花费
	double		allIncome;		//总收入
public:
	explicit Account(bool __isE, double __mon, bool __isN,
		std::string __note, double __bal,
		double __allC, double __allI);

	//根据新的余额信息来生成新的Account条目
	friend Account calcByBalance(const Account & __last, double __newBalance,
		std::string __n = "无", bool __isN = true);

	//重载流运算符,将Account直接写入文件
	friend std::ofstream& operator<<(std::ofstream& __ofs, Account & __w);
};

