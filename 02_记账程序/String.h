#pragma once
#include <fstream>
#include <string>

class String
{
private:
	std::string BaseString;
	double Number;
	bool isNum;
	//�ַ���ת����
	double StringToNumber();

	//����ת�ַ���
	std::string DoubleToString();

public:
	//���캯��
	explicit String(const std::string & __str);
	explicit String(const double __num);

	//�����ļ�����������,ʹString����ֱ��������
	friend std::ofstream & operator<<(std::ofstream & __os, String & __Str);

	//�����ļ������������,����ֱ�Ӵ��ļ��ж���String
	friend std::ifstream & operator>> (std::ifstream & __is, String & __Str);

	//����+�����ʵ���ַ�������
	friend String operator+(String & __lhs, String & __rhs);
	friend String operator+(String & __lhs,const char * __rhs);
	friend String operator+(const char * __lhs, String & __rhs);

	//��������
	~String();
};

