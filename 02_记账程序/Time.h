#pragma once
#include <string>

//ʱ��
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
	explicit Time(std::string & __inp);	//���ַ����н���ʱ��
	std::string getDate()const;			//�õ�����
	std::string getTime()const;			//�õ�ʱ��
	//�����������,ֱ�����ļ�д��Time��
	friend std::ofstream& operator<<(std::ofstream& __ofs, Time & __t);
	~Time();
};

