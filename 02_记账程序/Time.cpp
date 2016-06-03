#include "stdafx.h"
#include "Time.h"
#include <fstream>
#include <sstream>
#include <ctime>

#define CNOUTPUT c1>>c2		//���պ���λ

//��������в�����ǰʱ��
Time::Time()
{
	time_t NowTimeLong = time(NULL);
	tm * NowTime = localtime(&NowTimeLong);
	Year = NowTime->tm_year + 1900;
	Mon = NowTime->tm_mon + 1;
	Day = NowTime->tm_mday;
	Hour = NowTime->tm_hour;
	Min = NowTime->tm_min;
	Sec = NowTime->tm_sec;
}

//���ַ����н���ʱ��
Time::Time(std::string& __inp)
{
	std::stringstream ss(__inp);
	char c1, c2;	//�������պ���λ
	ss >> Year >> CNOUTPUT >> Mon >> CNOUTPUT >> Day >> CNOUTPUT
		>> Hour >> c1 >> Min >> c1 >> Sec;
}

//�õ�����
std::string Time::getDate() const
{
	std::stringstream ss;
	ss << Year << "��" << Mon << "��" << Day << "��";
	std::string result;
	ss >> result;
	return result;
}

//�õ�ʱ��
std::string Time::getTime() const
{
	std::stringstream ss;
	ss << Hour << ":" << Min << ":" << Sec;
	std::string result;
	ss >> result;
	return result;
}

Time::~Time()
{
}

//�����������,ֱ�����ļ�д��Time��
std::ofstream & operator<<(std::ofstream & __ofs, Time & __t)
{
	__ofs << __t.getDate() << '\t' << __t.getTime();
	return __ofs;
}
