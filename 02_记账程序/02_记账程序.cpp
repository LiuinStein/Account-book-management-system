// 02_记账程序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FilePath.h"
#include "Line.h"

using namespace std;

//录入区间数[__s,__e]
int inputNumber(int __s, int __e)
{
	int result{};
	do
	{
		cin >> result;
		if (result < __s || result > __e)
			cout << "Type error! You must type a number range of ["
			<< __s << "," << __e << "]" << endl
			<< "Type again: " << endl;
	} while (result < __s || result > __e);
	return result;
}

//列出账目清单
void ListAccBooks()
{
	cout << "There are 10 Account books:" << endl;
	cout << "1. 现金日记账.xls" << endl
		<< "2. 贵金属投资.xls" << endl
		<< "3. 京东金融投资.xls" << endl
		<< "4. 余额宝.xls" << endl
		<< "5. 建行尾号4852.xls" << endl
		<< "6. 工行尾号9776.xls" << endl
		<< "7. 工行尾号8261.xls" << endl
		<< "8. 工行尾号6525.xls" << endl
		<< "9. 校园卡日记账.xls" << endl;
}

//返回账目说明
//1. 饭 2. 内部资金流通 3. 父母给 4. New description
int getDescMethodNum()
{
	cout << "Choose a Income/Expense description in this option:" << endl;
	cout << "Default option: 1. 饭 2. 内部资金流通 3. 父母给 4. New description" << endl;
	cout << "Enter a option number: ";
	return inputNumber(1, 4);
}

//将账目说明映射为账本说明并写入Line
void mappingDescMethod(Line & __w, int __dmn)
{
	if (__dmn == 1)
		__w.setDescription("饭");
	else if (__dmn == 2)
		__w.setDescription("内部资金流通");
	else if (__dmn == 3)
		__w.setDescription("父母给");
	else if (__dmn == 4)
	{
		cout << "Enter a new description: ";
		string tmp;
		cin >> tmp;
		__w.setDescription(tmp.c_str());
	}
}

//输入余额
double newBalance()
{
	cout << "Enter a new balance: ";
	double result{};
	cin >> result;
	return result;
}

//输入现金流
double newMoney()
{
	cout << "Enter a money stream: ";
	double result{};
	cin >> result;
	return result;
}

//使用现金流操作时的收入支出(支出返回true)
bool moneyExpense()
{
	cout << "Expense or Income(1 or 2): ";
	return inputNumber(1, 2) == 1;
}

//使用默认备注/必需模板
bool useDefNoteTem()
{
	cout << "Do you want to use the default note and necessary template?" << endl;
	cout << "If you want type 1 else type 2: ";
	return inputNumber(1, 2) == 1;
}

//录入账本说明
string inputNote()
{
	cout << "Enter your DIY note or use default(type #1): ";
	string tmp;
	cin >> tmp;
	if (tmp == "#1")
		tmp = "无";
	return tmp;
}

//录入是否必需
bool inputIsN()
{
	cout << "Enter need(1) or unneed(2): ";
	return inputNumber(1, 2) == 1;
}

//现金流创建行
void CreateLineByMoney(Line & tarWriteLine,
	const Account * prevAcc)
{
	bool isExpense = moneyExpense();	//得到收支情况
	double operMoney = newMoney();		//得到操作现金数目
	if (useDefNoteTem())	//是否会使用默认备注/必需模板
		tarWriteLine.setAccount(
			new Account(prevAcc, operMoney,
				isExpense));
	else
		tarWriteLine.setAccount(
			new Account(prevAcc, operMoney,
				isExpense, inputNote(), inputIsN()));
}

int main()
{
	//载入总账文件
	ifstream readAllAccount;
	readAllAccount.open(AllAccount);
	vector<Line> vecAllAccount;		//存储总账中所有的行
	while (readAllAccount.good())
	{
		Line tmp;
		readAllAccount >> tmp;
		vecAllAccount.push_back(tmp);
	}
	readAllAccount.close();

	//欢迎界面:
	cout << "Welcome to lyst Account book management system" << endl;
	cout << "Enter Password: ";

	//密码验证部分
	string key;
	bool keyCorrect;
	do
	{
		cin >> key;
		keyCorrect = key == "1021";
		if (!keyCorrect)
		{
			cout << "Password Error!" << endl;
			cout << "Enter Password again: ";
		}
	} while (!keyCorrect);

	//主程序界面
	system("cls");
	cout << "Welcome to lyst Account book management system" << endl;
	ListAccBooks();

	//录入操作账本序号
	cout << "Enter operate account book number: ";
	int doNumber{};
	do
	{
		cin >> doNumber;
		if (doNumber <= 0 || doNumber >= 10)
			cout << "Account book number error!" << endl
			<< "Enter operate account book number again: " << endl;
	} while (doNumber <= 0 || doNumber >= 10);

	//打开并读入操作账本
	ifstream readOperAccBook;
	readOperAccBook.open(AccountBooks[doNumber]);
	string lastLineStr;
	while (readOperAccBook.good())
		readOperAccBook >> lastLineStr;
	Line lastLine(lastLineStr);
	readOperAccBook.close();

	//操作模式
	cout << "There are two operate mode:" << endl
		<< "1. Manual entry" << endl
		<< "2. Create by balance" << endl
		<< "3. Create by money and money direction" << endl
		<< "4. Flow of fund" << endl;
	cout << "Enter operate mode: ";
	int operMode = inputNumber(1, 4);
	//响应操作模式
	Line tarWriteLine;
	Time NowTime;		//获取当前时间
	//得到上一条账目信息
	const Account * prevAcc = lastLine.getAccount();
	if (operMode == 1)
	{
		//手工录入:
		//说明
		//获取账目说明
		int DescMethodNum{ getDescMethodNum() };
		//映射账目说明
		mappingDescMethod(tarWriteLine, DescMethodNum);
		//计算账目
		CreateLineByMoney(tarWriteLine, prevAcc);
	}
	else if (operMode == 2)
	{
		//根据余额
		double balance = newBalance();
		if (useDefNoteTem())
			tarWriteLine.setAccount(
				new Account(prevAcc, balance));
		else
			tarWriteLine.setAccount(
				new Account(prevAcc, balance,
					inputNote(), inputIsN()));
	}
	else if (operMode == 3)
	{
		//根据现金流
		CreateLineByMoney(tarWriteLine, prevAcc);
	}
	else if (operMode == 4)
	{
		//内部资金流通
		Line tarWriteLine_to;
		ListAccBooks();		//列账本
		cout << "From: ";
		int from{};
		cin >> from;
		cout << "To: ";
		int to{};
		cin >> to;
		cout << "Money: ";
		double money{};
		cin >> money;
		if (useDefNoteTem())
		{

		}
		else
		{

		}
	}

	//打开必要文件
	ofstream writeOperAccBook;
	writeOperAccBook.open(AccountBooks[doNumber]);
	ofstream writeAllAccBook;
	writeAllAccBook.open(AllAccount);

	//单独处理内部资金流通情况
	if (operMode != 4)
	{
		//将当前的Line写入当前操作账本
		writeOperAccBook << tarWriteLine << endl;
		//写总账	
		writeAllAccBook << tarWriteLine << '\t'
			<< AccountBooks[doNumber] << "无" << endl;
	}


	system("pause");
	return 0;
}

