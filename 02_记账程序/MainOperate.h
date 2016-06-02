#pragma once
#include <string>
#include <fstream>
#include "Account.h"

//我要把所有的操作全部放入这个类中
class MainOperate
{
private:

	//文件输入流
	std::ifstream readAllBill;		//总账输入流
	std::ifstream readOperBillFrom;	//来源账本输入流
	std::ifstream readOperBillTo;	//为内部资金流通准备的副账输入流

	//文件输出流
	std::ofstream writeAllBill;		//总账输出流
	std::ofstream writeOperBillFrom;//来源账输出流
	std::ofstream writeOperBillTo;	//为内部资金流通准备的副账输出流

	//读入的账目信息(字符串)
	std::string allBillLastStr;		//总账最后一条账目信息
	std::string fromBillLastStr;	//来源账最后一条账目信息
	std::string toBillLastStr;		//副账最后一条账目信息

	//读入的账目信息(转化后的Account类)
	Account * prevLastBillFrom;		//来源账
	Account * prevLastBillTo;		//副账

	//数据
	int operBillFromNum;	//操作账本序号[1,9]
	int operModeNum;		//账本操作码[1,4]


	//录入区间数[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//输出账目清单
	void printAccBooks()const;

	//列出操作模式
	void printOperMode()const;

public:
	MainOperate();
	~MainOperate();
};

