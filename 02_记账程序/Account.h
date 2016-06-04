#pragma once
#include <string>

enum EIMODE
{
	Expense, Income, Flow
};

//用于存储账本条目
class Account
{
private:
	EIMODE		EIMode;			//收入支出模式
	double		money;			//流动金额
	bool		isNecessary;	//必需为true
	std::string Note;			//备注
	double		balance;		//当前账目余额
	double		allCost;		//总花费
	double		allIncome;		//总收入
public:
	explicit Account(EIMODE __EIM, double __mon, bool __isN,
		std::string __note, double __bal,
		double __allC, double __allI);

	//根据新的余额信息来生成新的Account条目
	Account(const Account * __last, double __newBalance,
		std::string __n = "无", bool __isN = true);

	//根据流动数额多少来生成新的Account条目
	Account(const Account * __last, double __mon,
		EIMODE __EIM, std::string __n = "无", bool __isN = true);

	//得到余额
	double getBalance()const;

	//得到是否必需
	bool getIsN()const;

	//得到流动金额
	double getMon()const;

	//得到收支模式
	EIMODE getEIMODE()const;

	//得到说明
	const std::string & getNote()const;

	//重载流运算符,将Account直接写入文件
	friend std::ofstream& operator<<(std::ofstream& __ofs, Account & __w);
};

