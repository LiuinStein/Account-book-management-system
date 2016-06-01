#pragma once
#include <fstream>
#include <string>

class String
{
private:
	std::string BaseString;
	double Number;
	bool isNum;
	//字符串转数字
	double StringToNumber();

	//数字转字符串
	std::string DoubleToString();

public:
	//构造函数
	explicit String(const std::string & __str);
	explicit String(const double __num);

	//重载文件输出流运算符,使String可以直接载入流
	friend std::ofstream & operator<<(std::ofstream & __os, String & __Str);

	//重载文件输入流运算符,可以直接从文件中读入String
	friend std::ifstream & operator>> (std::ifstream & __is, String & __Str);

	//重载+运算符实现字符串连接
	friend String operator+(String & __lhs, String & __rhs);
	friend String operator+(String & __lhs,const char * __rhs);
	friend String operator+(const char * __lhs, String & __rhs);

	//析构函数
	~String();
};

