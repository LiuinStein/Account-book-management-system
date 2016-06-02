#include "stdafx.h"
#include "MainOperate.h"
#include "FilePath.h"
#include <iostream>

//从界面录入区间数
int MainOperate::inputNumber(int __s, int __e,
	const char * InputError)const
{
	int result{};
	do
	{
		std::cin >> result;
		if (result < __s || result > __e)
			if (InputError == nullptr)
				std::cout << "Type error! You must type a number range of ["
				<< __s << "," << __e << "]" << std::endl
				<< "Type again: " << std::endl;
			else
				std::cout << *InputError << std::endl
				<< "Type again: " << std::endl;
	} while (result < __s || result > __e);
	return result;

}

//列出账目清单
void MainOperate::printAccBooks() const
{
	std::cout << "There are 10 Account books:" << std::endl;
	std::cout << "1. 现金日记账.xls" << std::endl
		<< "2. 贵金属投资.xls" << std::endl
		<< "3. 京东金融投资.xls" << std::endl
		<< "4. 余额宝.xls" << std::endl
		<< "5. 建行尾号4852.xls" << std::endl
		<< "6. 工行尾号9776.xls" << std::endl
		<< "7. 工行尾号8261.xls" << std::endl
		<< "8. 工行尾号6525.xls" << std::endl
		<< "9. 校园卡日记账.xls" << std::endl;
}

//列出操作模式
void MainOperate::printOperMode() const
{
	std::cout << "There are four operate mode:" << std::endl
		<< "1. Manual entry" << std::endl
		<< "2. Create by balance" << std::endl
		<< "3. Create by money and money direction" << std::endl
		<< "4. Flow of fund" << std::endl;
}

//载入总账文件
void MainOperate::loadAllBill()
{
	readAllBill.open(AllAccount);
	std::string tmp;
	while (readAllBill.good())
		readAllBill >> tmp;
	allBillLastLine = tmp;
	readAllBill.close();
}

//通过编号载入账本
void MainOperate::loadBillByNum(int __i, 
	bool __isFrom)
{
	//通过__isFrom决定使用哪一个
	std::ifstream * load = __isFrom ?
		&readOperBillFrom : &readOperBillTo;
	Line * read = __isFrom ?
		&fromBillLastLine : &toBillLastLine;
	load->open(AccountBooks[__i]);
	std::string tmp;
	while (load->good())
		(*load) >> tmp;
	*read = tmp;
	load->close();
}

MainOperate::MainOperate()
{
	
}


MainOperate::~MainOperate()
{
}
