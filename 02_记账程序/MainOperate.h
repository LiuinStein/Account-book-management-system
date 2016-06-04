#pragma once
#include <string>
//#include <fstream>
#include "Account.h"
#include "AllAccountLine.h"

//我要把所有的操作全部放入这个类中
class MainOperate
{
private:

	//读入行(Line)
	AllAccountLine allBillLastLine;
	Line fromBillLastLine;
	Line toBillLastLine;

	//写入行(Line)
	AllAccountLine allBillWriteLine;
	Line fromBillWriteLine;
	Line toBillWriteLine;

	//数据
	int operBillFromNum;	//操作账本序号[1,9]
	int operBillToNum;		//为内部资金流通准备的副账编号
	int operModeNum;		//账本操作码[1,3]
	std::string log;		//日志

///数据服务函数:

	///数据输入:
	//录入区间数[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//输入操作账本编号
	void inputOperBill(bool __isFrom);

	//是否使用默认备注/必需模板
	bool useDefNoteTem();

	//录入账本说明
	std::string inputNote();

	//录入是否必需
	bool inputIsN();

	//录入收支情况
	EIMODE ExpOrInc()const;


	///数据输出
	//输出账目清单
	void printAccBooks()const;

	//列出操作模式
	void printOperMode()const;


///文件操作函数
	//载入总账文件
	void loadAllBill();

	//通过编号载入账本
	void loadBillByNum(int __i, bool __isFrom);

	//写入所有更改账本文件
	void writeBill();

///实际操作函数

	//输入并映射账本操作模式
	void mappingOperMode();

	//通过余额写入Line
	void createLineByBal(Line & __new, Line & __prev);

	//写入账目说明
	//1. 饭 2. 内部资金流通 3. 父母给 4. New description
	void MainOperate::DescMethod(Line & __m);

	//通过资金流写入Line
	double createLineByFlow(Line & __new, Line & __prev);

	//资金流写入Line
	void flowSetLine(Line& __new, Line& __prev,
		double __mon, EIMODE __eim);

///其他函数
	//确认操作
	bool confirmOper()const;

	//main函数Yeah!
	void main();

public:
	MainOperate();
	~MainOperate();
};

