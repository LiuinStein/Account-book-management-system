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
	int desNumber{};
	do
	{
		cin >> desNumber;
		if (desNumber < 1 || desNumber>3)
			cout << "Option number error!"
			<< "Enter a option number again: ";
	} while (desNumber < 1 || desNumber>3);
	return desNumber;
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
	int inp{};
	do
	{
		cin >> inp;
		if (inp < 1 || inp>2)
			cout << "Expense or income number input error!" << endl
			<< "Expense or Income(1 or 2): ";
	} while (inp < 1 || inp>2);
	return inp == 1;
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
	vector<Line> vecOperAccBook;
	while (readOperAccBook.good())
	{
		Line tmp;
		readOperAccBook >> tmp;
		vecOperAccBook.push_back(tmp);
	}
	readOperAccBook.close();
	//操作模式
	cout << "There are two operate mode:" << endl
		<< "1. Manual entry" << endl
		<< "2. Create by balance" << endl
		<< "3. Create by money and money direction" << endl;
	cout << "Enter operate mode: ";
	int operMode{};
	do
	{
		cin >> operMode;
		if (operMode < 1 || operMode>3)
			cout << "Operate number error!" << endl
			<< "Enter operate mode again: " << endl;
	} while (operMode < 1 || operMode>3);
	//响应操作模式
	Line tarWriteLine;
	Time NowTime;		//获取当前时间
	if (operMode == 1)
	{
		//说明
		//获取账目说明
		int DescMethodNum{ getDescMethodNum() };
		//映射账目说明
		mappingDescMethod(tarWriteLine, DescMethodNum);
		//计算账目
		//得到上一条账目信息
		const Account * prevAcc = (--vecOperAccBook.end())->getAccount();
		//Account newAcc(prevAcc,)

	}
	else if (operMode == 2)
	{

	}
	else if (operMode == 3)
	{

	}

	system("pause");
	return 0;
}

