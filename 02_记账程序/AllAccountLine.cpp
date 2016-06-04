#include "stdafx.h"
#include "AllAccountLine.h"
#include <fstream>

void AllAccountLine::Analyze()
{
	Line::Analyze();
	ss >> sheet_1 >> sheet_2;
}

//默认构造函数
AllAccountLine::AllAccountLine() :Line()
{
}

AllAccountLine::AllAccountLine(std::string __inp,
	std::string __s1, std::string __s2) :
	Line(__inp), sheet_1(__s1), sheet_2(__s2) {}


//用Line来创建AllAccountLine
AllAccountLine::AllAccountLine(Line& __now,
	Line& __last, std::string __s1,
	std::string __s2) : 
	Line(__now),
	sheet_1(__s1), sheet_2(__s2)
{
	const Account * nowAcc = __now.getAccount();
	const Account * lastAcc = __last.getAccount();
	Accounts = new Account(lastAcc,
		lastAcc->getBalance() - nowAcc->getMon(),
		nowAcc->getNote(),
		nowAcc->getIsN()
	);
}


//为sheet赋值
void AllAccountLine::setSheet(std::string __s1,
	std::string __s2)
{
	sheet_1 = __s1;
	sheet_2 = __s2;
}

//重载赋值运算符,直接从string中读取行
void AllAccountLine::operator=(std::string& __str)
{
	LineContext = __str;
	Analyze();
}

//重载流运算符,直接向文件写入
std::ofstream& operator<<(std::ofstream& __ofs, 
	AllAccountLine& __w)
{
	__ofs << *__w.NowTime << '\t' <<
		__w.Description << '\t';
	__ofs << *__w.Accounts << '\t' <<
		__w.sheet_1 << '\t' << __w.sheet_2;
	return __ofs;
}

//重载流运算符,直接从文件读入
std::ifstream& operator>>(std::ifstream& __ifs,
	AllAccountLine& __w)
{
	std::getline(__ifs, __w.LineContext);
	__w.Analyze();
	return __ifs;
}
