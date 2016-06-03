#pragma once
#include "Time.h"
#include "Account.h"
#include <sstream>

class Line
{
protected:
	Time*		NowTime;		//时间
	std::string Description;	//说明
	Account*	Accounts;		//账目
	std::string LineContext;	//行信息
	std::stringstream ss;		//录入流

	void Analyze();	//行信息分析

public:
	Line();
	explicit Line(std::string & __inp);
	Line(Line & __d);

	//读出说明
	const std::string & getDescription()const;

	//写入说明
	void setDescription(const char * __s);

	//写入账目信息
	void setAccount(Account * __s);

	//读取账目信息
	const Account * getAccount()const;

	//重载赋值运算符
	void operator=(const Line & __c);

	//重载赋值运算符,直接从字符串中读入行
	void operator=(std::string & __str);

	//重载流输入运算符,从文件中直接读入行
	friend std::ifstream& operator>> (std::ifstream & __ifs,Line & __l);
	
	//重载流输入运算符,直接向文件写入行
	friend std::ofstream& operator<<(std::ofstream & __ofs, Line & __l);

};

