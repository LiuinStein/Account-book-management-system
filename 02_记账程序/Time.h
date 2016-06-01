#pragma once
#include <string>

//时间
class Time
{
private:
	int Year;
	int Mon;
	int Day;
	int Hour;
	int Min;
	int Sec;
public:
	Time();
	explicit Time(std::string & __inp);	//从字符串中解析时间
	std::string getDate()const;			//得到日期
	std::string getTime()const;			//得到时间
	//重载流运算符,直接向文件写入Time类
	friend std::ofstream& operator<<(std::ofstream& __ofs, Time & __t);
	~Time();
};

