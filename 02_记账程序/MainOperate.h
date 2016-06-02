#pragma once
#include <string>
#include <fstream>

//我要把所有的操作全部放入这个类中
class MainOperate
{
private:

	//输入流
	std::ifstream readAllBill;		//总账输入流
	std::ifstream readOperBillFrom;	//来源账本输入流
	std::ifstream readOperBillTo;	//为内部资金流通准备的副账输入流


	//账目信息
	std::string allBillLast;	//总账最后一条账目信息
	std::string fromBillLast;	//来源账最后一条账目信息
	std::string toBillLast;		//副账最后一条账目信息


	//数据
	int operBillFromNum;	//操作账本序号[1,9]



	//录入区间数[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//输出账目清单
	void printAccBooks()const;

public:
	MainOperate();
	~MainOperate();
};

