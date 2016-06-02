#include "stdafx.h"
#include "MainOperate.h"
#include "FilePath.h"
#include <iostream>
#include <fstream>

//从界面录入区间数[__s,__e]
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

//输入操作账本编号
void MainOperate::inputOperBill(bool __isFrom)
{
	__isFrom ? operBillFromNum = inputNumber(1, 9) :
		operBillToNum = inputNumber(1, 9);
}

//列出账本操作码
void MainOperate::printOperMode() const
{
	std::cout << "There are four operate mode:" << std::endl
		<< "1. Manual entry" << std::endl
		<< "2. Create by balance" << std::endl
		<< "3. Flow of fund" << std::endl;
}

//输入并映射账本操作码
void MainOperate::mappingOperMode()
{
	std::cout << "Enter operate mode: ";
	operModeNum = inputNumber(1, 3);
	//TODO: 往下映射账本操作模式
	if (operModeNum == 1)
	{
		//资金流(父母给,单方面注入/输出)
		DescMethod(fromBillWriteLine);	//写入说明
		//写入计算数据
		createLineByFlow(fromBillWriteLine,
			fromBillLastLine);
	}
	else if(operModeNum == 2)
	{
		//根据余额(校园卡)
		DescMethod(fromBillWriteLine);	//写入说明
		createLineByBal(fromBillWriteLine,
			fromBillLastLine);
	}
	//else if (operModeNum == 3)
	//{
	//	//资金流(父母给,单方面注入/输出)
	//	createLineByFlow(fromBillWriteLine,
	//		fromBillLastLine);
	//}
	else if (operModeNum == 3)
	{
		//内部资金流通

	}
}

//载入总账文件
void MainOperate::loadAllBill()
{
	std::ifstream readAllBill;//.open(AllAccount);
	readAllBill.open(AllAccount);
	std::string tmp;
	while (readAllBill.good())
		readAllBill >> tmp;
	allBillLastLine = tmp;
	readAllBill.close();
}

//通过编号载入账本
void MainOperate::loadBillByNum(int __i, bool __isFrom)
{
	/*
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
	load->close();*/
	Line * read = __isFrom ?
		&fromBillLastLine : &toBillLastLine;
	std::ifstream load;
	load.open(AccountBooks[__i]);
	std::string tmp;
	while (load.good())
		load >> tmp;
	*read = tmp;
	load.close();
}

//是否使用默认备注/必需模板
bool MainOperate::useDefNoteTem()
{
	std::cout << "Do you want to use the default note and necessary template?" << std::endl;
	std::cout << "If you want type 1 else type 2: ";
	return inputNumber(1, 2) == 1;
}

//录入账本说明
std::string MainOperate::inputNote()
{
	std::cout << "Enter your DIY note or use default(type #1): ";
	std::string tmp;
	std::cin >> tmp;
	if (tmp == "#1")
		tmp = "无";
	return tmp;
}

//录入是否必需
bool MainOperate::inputIsN()
{
	std::cout << "Enter need(1) or unneed(2): ";
	return inputNumber(1, 2) == 1;
}

//通过余额来写入Line
void MainOperate::createLineByBal(Line & __new, 
	Line & __prev)
{
	//输入新余额
	std::cout << "Enter new balance: ";
	double newBalance{};
	do
	{
		std::cin >> newBalance;	
		if (newBalance < 0)
			std::cout << "Balance requires > 0" << std::endl
			<< "Type again: ";
	} while (newBalance < 0);
	//写入Line
	if (useDefNoteTem())
		__new.setAccount(
			new Account(__prev.getAccount(), newBalance));
	else
		__new.setAccount(
			new Account(__prev.getAccount(), newBalance,
				inputNote(), inputIsN()));

}

//录入收支情况
EIMODE MainOperate::ExpOrInc() const
{
	std::cout << "Expense or Income(1 or 2): ";
	return inputNumber(1, 2) == 1 ? Expense : Income;
}

//录入并映射账目说明
//1. 饭 2. 内部资金流通 3. 父母给 4. New description
void MainOperate::DescMethod(Line & __m)
{
	std::cout << "Choose a Income/Expense description in this option:" << std::endl;
	std::cout << "Default option: 1. 饭 2. 内部资金流通 3. 父母给 4. New description" << std::endl;
	std::cout << "Enter a option number: ";
	int noteMode{ inputNumber(1, 4) };
	if (noteMode == 1)
		__m.setDescription("饭");
	else if (noteMode == 2)
		__m.setDescription("内部资金流通");
	else if (noteMode == 3)
		__m.setDescription("父母给");
	else if (noteMode == 4)
	{
		std::cout << "Enter a new description: ";
		std::string tmp;
		std::cin >> tmp;
		__m.setDescription(tmp.c_str());
	}
}

//通过资金流写入Line
void MainOperate::createLineByFlow(Line& __new, 
	Line& __prev)
{
	EIMODE expOrInc = ExpOrInc();	//得到收支情况
	double operMoney{};		
	std::cin >> operMoney;	//得到操作现金数目

	if (useDefNoteTem())	//是否会使用默认备注/必需模板
		__new.setAccount(
			new Account(__prev.getAccount(), operMoney,
				expOrInc));
	else
		__new.setAccount(
			new Account(__prev.getAccount(), operMoney,
				expOrInc, inputNote(), inputIsN()));
}

//写入所有更改账本文件
void MainOperate::writeBill()
{
	//写入总账
	std::ofstream writeBill;
	writeBill.open(AllAccount);
	writeBill << allBillWriteLine << std::endl;
	writeBill.close();

	//写入来源账本
	writeBill.open(AccountBooks[operBillFromNum]);
	writeBill << fromBillWriteLine << std::endl;
	writeBill.close();

	//写入副账账本(如果有的话)
	if(operModeNum==4 && operBillToNum>0)
	{
		writeBill.open(AccountBooks[operBillToNum]);
		writeBill << toBillWriteLine << std::endl;
		writeBill.close();
	}
}

MainOperate::MainOperate()
{
	
}


MainOperate::~MainOperate()
{
}
