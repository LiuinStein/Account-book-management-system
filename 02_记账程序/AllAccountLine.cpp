#include "stdafx.h"
#include "AllAccountLine.h"
#include <fstream>

void AllAccountLine::Analyze()
{
	Line::Analyze();
	ss >> sheet_1 >> sheet_2;
}

//Ĭ�Ϲ��캯��
AllAccountLine::AllAccountLine() :Line()
{
}

AllAccountLine::AllAccountLine(std::string __inp,
	std::string __s1, std::string __s2) :
	Line(__inp), sheet_1(__s1), sheet_2(__s2) {}

//���ظ�ֵ�����,ֱ�Ӵ�string�ж�ȡ��
void AllAccountLine::operator=(std::string& __str)
{
	LineContext = __str;
	Analyze();
}

//�����������,ֱ�����ļ�д��
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

//�����������,ֱ�Ӵ��ļ�����
std::ifstream& operator>>(std::ifstream& __ifs,
	AllAccountLine& __w)
{
	std::getline(__ifs, __w.LineContext);
	__w.Analyze();
	return __ifs;
}
