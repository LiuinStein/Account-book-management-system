#pragma once
#include "Line.h"
#include <string>

class AllAccountLine :
	public Line
{
private:
	std::string sheet_1;
	std::string sheet_2;

	void Analyze();

public:
	AllAccountLine();

	AllAccountLine(std::string __inp,
		std::string __s1, std::string __s2 = "无");

	//用Line创建AllAccountLine
	AllAccountLine(const Line & __now, Line & __last,
		std::string __s1, std::string __s2 = "无");

	//为sheet赋值
	void setSheet(std::string __s1, std::string __s2 = "无");

	//重载赋值运算符,直接从string中读取行
	void operator=(std::string & __str);
	
	//重载流运算符,直接向文件写入
	friend std::ofstream& operator<<(std::ofstream & __ofs, 
		AllAccountLine & __w);

	//重载流运算符,直接从文件读入
	friend std::ifstream& operator>> (std::ifstream & __ifs,
		AllAccountLine & __w);

};

