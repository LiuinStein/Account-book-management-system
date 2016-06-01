#include "stdafx.h"
#include "AllAccountLine.h"
#include <fstream>

AllAccountLine::AllAccountLine(std::string __inp,
	std::string __s1, std::string __s2) :
	Line(__inp), sheet_1(__s1), sheet_2(__s2) {}

//重载流运算符,直接向文件写入
std::ofstream& operator<<(std::ofstream& __ofs, 
	AllAccountLine& __w)
{
	__ofs << __w.NowTime << '\t' <<
		__w.Description << '\t' <<
		__w.Accounts << '\t' <<
		__w.sheet_1 << '\t' <<
		__w.sheet_2 << std::endl;
	return __ofs;
}
