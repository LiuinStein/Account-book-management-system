#pragma once
#include "Line.h"
#include <string>

class AllAccountLine :
	private Line
{
private:
	std::string sheet_1;
	std::string sheet_2;
public:
	AllAccountLine(std::string __inp,std::string __s1,std::string __s2);
	
	//�����������,ֱ�����ļ�д��
	friend std::ofstream& operator<<(std::ofstream & __ofs, AllAccountLine & __w);

};

