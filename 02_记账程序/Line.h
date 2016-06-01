#pragma once
#include "Time.h"
#include "Account.h"
#include <vector>

class Line
{
protected:
	Time*		NowTime;		//时间
	std::string Description;	//说明
	Account*	Accounts;		//账目
private:
	std::string LineContext;	//行信息

	void Analyze();	//行信息分析

public:
	Line();
	explicit Line(std::string & __inp);

	//写入说明
	void setDescription(const char * __s);

	//写入账目信息
	void setAccount(Account * __s);

	//读取账目信息
	const Account * getAccount()const;

	//重载流输入运算符,从文件中直接读入行
	friend std::ifstream& operator>> (std::ifstream & __ifs,Line & __l);
	
	//重载流输入运算符,直接向文件写入行
	friend std::ofstream& operator<<(std::ofstream & __ofs, Line & __l);

};

