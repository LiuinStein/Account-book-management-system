#include "stdafx.h"
#include "String.h"
#include <fstream>
#include <cstdio>
#include <cmath>

//字符串转数字,失败返回0(测试成功)
double String::StringToNumber()
{
	double result{};
	bool LeftPoint = true;	//操作单元是否在小数点左边
	int LeftPointBit = -1;
	for (auto i = 0; i < BaseString.size(); i++)
		if (BaseString[i] >= '0' && BaseString[i] <= '9')
			if (LeftPoint)
				result = result * 10 + int(BaseString[i] - '0');
			else
				result += int(BaseString[i] - '0') * pow(10, LeftPointBit--);
		else if (BaseString[i] == '.')
			LeftPoint = false;
		else
		{
			result = 0;
			isNum = false;
			break;
		}
	isNum = true;
	return result;
}

//数字转字符串(小数保留两位)(测试成功)
std::string String::DoubleToString()
{
	std::string result;
	char buffer[15]{};
	sprintf_s(buffer, "%.2f", Number);
	result = buffer;
	return result;
}

//通过string构造String
String::String(const std::string & __str)
{
	BaseString = __str;
	Number = StringToNumber();
}

//通过double构造String
String::String(const double __num)
{
	Number = __num;
	isNum = true;
	BaseString = DoubleToString();
}

//析构函数
String::~String() {}

//重载文件输出流运算符,使String可以直接载入流
std::ofstream& operator<<(std::ofstream& __os, 
	String& __Str)
{
	__os << __Str.BaseString;
	return __os;
}

//重载文件输入流运算符,可以直接从文件中读入String
std::ifstream& operator>>(std::ifstream& __is, String& __Str)
{
	std::string tmp;
	__is >> tmp;
	__Str.BaseString = tmp;
	__Str.StringToNumber();
	return __is;
}

//重载+运算符实现字符串连接
String operator+(String& __lhs, String& __rhs)
{
	String result(__lhs.BaseString + __rhs.BaseString);
	return result;
}

String operator+(String& __lhs, const char* __rhs)
{
	String result(__lhs.BaseString + __rhs);
	return result;
}

String operator+(const char* __lhs, String& __rhs)
{
	String result(__lhs + __rhs.BaseString);
	return result;
}
