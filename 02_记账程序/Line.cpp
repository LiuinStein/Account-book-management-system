#include "stdafx.h"
#include "Line.h"
#include <fstream>
#include <sstream>


//行信息分析
void Line::Analyze()
{
	std::stringstream ss(LineContext);		//录入流
	//解析流
	//解析时间
	std::string date, time;
	ss >> date >> time;
	std::string now = date + time;
	NowTime = new Time(now);

	ss >> Description;	//解析说明

	//解析账目信息
	//=======待解析账目信息列表==========
		bool		isExpense;		//支出为true,收入为false
		double		money;			//流动金额
		bool		isNecessary;	//必需为true
		std::string Note;			//备注
		double		balance;		//当前账目余额
		double		allCost;		//总花费
		double		allIncome;		//总收入
	//=================================
	std::string tmp;
	//解析收入支出
	ss >> tmp;
	isExpense = tmp == "收入" ? false : true;
	//解析流动金额
	ss >> money;
	//解析是否必需
	ss >> tmp;
	isNecessary = tmp == "必需" ? true : false;
	//解析备注
	ss >> Note;
	//解析账目余额,总花费,总收入
	ss >> balance >> allCost >> allIncome;

	//通过解析信息构建Calc
	Accounts = new Account(isExpense, money, isNecessary,
		Note, balance, allCost, allIncome);

}

//默认构造函数
Line::Line():NowTime(new Time()),Accounts(nullptr)
{
}

//解析字符串得到一条账目信息
Line::Line(std::string & __inp):NowTime(new Time()),
	LineContext(__inp)
{
	Analyze();
}

//写入说明
void Line::setDescription(const char * __s)
{
	Description = __s;
}

//写入账目信息
void Line::setAccount(Account* __s)
{
	Accounts = __s;
}

//读取账目信息
const Account* Line::getAccount() const
{
	return Accounts;
}

//重载流输入运算符,从文件中直接读入行
std::ifstream& operator>>(std::ifstream& __ifs, Line& __l)
{
	std::string inp;
	std::getline(__ifs,inp);	//从文件中读入行
	Line tmp(inp);
	__l = tmp;
	return __ifs;
}

//重载流输入运算符,直接向文件写入行
std::ofstream & operator<<(std::ofstream & __ofs, Line & __l)
{
	__ofs << __l.NowTime << '\t' << __l.Description
		<< __l.Accounts;
	return __ofs;
}
