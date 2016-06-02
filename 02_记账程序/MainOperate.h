#pragma once
#include <string>
//#include <fstream>
#include "Account.h"
#include "AllAccountLine.h"

//我要把所有的操作全部放入这个类中
class MainOperate
{
private:

	//文件输入流
	//std::ifstream readAllBill;		//总账输入流
	//std::ifstream readOperBillFrom;	//来源账本输入流
	//std::ifstream readOperBillTo;	//为内部资金流通准备的副账输入流

	//文件输出流
	//std::ofstream writeAllBill;		//总账输出流
	//std::ofstream writeOperBillFrom;//来源账输出流
	//std::ofstream writeOperBillTo;	//为内部资金流通准备的副账输出流

	//读入的账目信息(字符串)
	//std::string allBillLastStr;		//总账最后一条账目信息
	//std::string fromBillLastStr;	//来源账最后一条账目信息
	//std::string toBillLastStr;		//副账最后一条账目信息	

	//读入行(Line)
	AllAccountLine allBillLastLine;
	Line fromBillLastLine;
	Line toBillLastLine;

	//写入行(Line)
	AllAccountLine allBillWriteLine;
	Line fromBillWriteLine;
	Line toBillWriteLine;

	//读入的账目信息(转化后的Account类)
	//Account * prevLastAllBill;		//总账
	//Account * prevLastBillFrom;		//来源账
	//Account * prevLastBillTo;			//副账

	//数据
	int operBillFromNum;	//操作账本序号[1,9]
	int operBillToNum;		//为内部资金流通准备的副账编号
	int operModeNum;		//账本操作码[1,4]


	//录入区间数[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//输出账目清单
	void printAccBooks()const;

	//输入操作账本编号
	void inputOperBill(bool __isFrom);

	//列出操作模式
	void printOperMode()const;

	//输入并映射账本操作模式
	void mappingOperMode();

	//载入总账文件
	void loadAllBill();

	//通过编号载入账本
	void loadBillByNum(int __i, bool __isFrom);

	//是否使用默认备注/必需模板
	bool useDefNoteTem();

	//录入账本说明
	std::string inputNote();

	//录入是否必需
	bool inputIsN();

	//通过余额写入Line
	void createLineByBal(Line & __new, Line & __prev);

	//录入收支情况
	EIMODE ExpOrInc()const;

	//通过资金流写入Line
	void creaateLineByFlow(Line & __new, Line & __prev);

	//写入所有更改账本文件
	void writeBill();

public:
	MainOperate();
	~MainOperate();
};

