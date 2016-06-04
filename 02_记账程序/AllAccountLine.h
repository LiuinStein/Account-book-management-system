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
		std::string __s1, std::string __s2 = "��");

	//��Line����AllAccountLine
	AllAccountLine(const Line & __now, Line & __last,
		std::string __s1, std::string __s2 = "��");

	//Ϊsheet��ֵ
	void setSheet(std::string __s1, std::string __s2 = "��");

	//���ظ�ֵ�����,ֱ�Ӵ�string�ж�ȡ��
	void operator=(std::string & __str);
	
	//�����������,ֱ�����ļ�д��
	friend std::ofstream& operator<<(std::ofstream & __ofs, 
		AllAccountLine & __w);

	//�����������,ֱ�Ӵ��ļ�����
	friend std::ifstream& operator>> (std::ifstream & __ifs,
		AllAccountLine & __w);

};

