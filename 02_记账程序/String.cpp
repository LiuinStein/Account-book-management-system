#include "stdafx.h"
#include "String.h"
#include <fstream>
#include <cstdio>
#include <cmath>

//�ַ���ת����,ʧ�ܷ���0(���Գɹ�)
double String::StringToNumber()
{
	double result{};
	bool LeftPoint = true;	//������Ԫ�Ƿ���С�������
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

//����ת�ַ���(С��������λ)(���Գɹ�)
std::string String::DoubleToString()
{
	std::string result;
	char buffer[15]{};
	sprintf_s(buffer, "%.2f", Number);
	result = buffer;
	return result;
}

//ͨ��string����String
String::String(const std::string & __str)
{
	BaseString = __str;
	Number = StringToNumber();
}

//ͨ��double����String
String::String(const double __num)
{
	Number = __num;
	isNum = true;
	BaseString = DoubleToString();
}

//��������
String::~String() {}

//�����ļ�����������,ʹString����ֱ��������
std::ofstream& operator<<(std::ofstream& __os, 
	String& __Str)
{
	__os << __Str.BaseString;
	return __os;
}

//�����ļ������������,����ֱ�Ӵ��ļ��ж���String
std::ifstream& operator>>(std::ifstream& __is, String& __Str)
{
	std::string tmp;
	__is >> tmp;
	__Str.BaseString = tmp;
	__Str.StringToNumber();
	return __is;
}

//����+�����ʵ���ַ�������
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
