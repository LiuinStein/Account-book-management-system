#include "stdafx.h"
#include "Time.h"
#include <fstream>
#include <sstream>
#include <ctime>

#define CNOUTPUT c1>>c2		//吸收汉字位

//构造过程中产生当前时间
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

//从字符串中解析时间
Time::Time(std::string& __inp)
{
	std::stringstream ss(__inp);
	char c1, c2;	//用于吸收汉字位
	ss >> Year >> CNOUTPUT >> Mon >> CNOUTPUT >> Day >> CNOUTPUT
		>> Hour >> c1 >> Min >> c1 >> Sec;
}

//得到日期
std::string Time::getDate() const
{
	std::stringstream ss;
	ss << Year << "年" << Mon << "月" << Day << "日";
	std::string result;
	ss >> result;
	return result;
}

//得到时间
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

//重载流运算符,直接向文件写入Time类
std::ofstream & operator<<(std::ofstream & __ofs, Time & __t)
{
	__ofs << __t.getDate() << '\t' << __t.getTime();
	return __ofs;
}
