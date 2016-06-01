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

int main()
{
	//载入总账文件
	ifstream readAllAccount;
	readAllAccount.open(AllAccount);
	vector<Line> vecAllAccount;		//存储总账中所有的行
	while(readAllAccount.good())
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
		if(!keyCorrect)
		{
			cout << "Password Error!" << endl;
			cout << "Enter Password again: ";
		}
	} while (!keyCorrect);
	//主程序界面
	system("cls");
	cout << "Welcome to lyst Account book management system" << endl;
	cout << "There are 10 Account books:" << endl;
	cout <<"1. 现金日记账.xls" << endl
		<< "2. 贵金属投资.xls" << endl
		<< "3. 京东金融投资.xls" << endl
		<< "4. 余额宝.xls" << endl
		<< "5. 建行尾号4852.xls" << endl
		<< "6. 工行尾号9776.xls" << endl
		<< "7. 工行尾号8261.xls" << endl
		<< "8. 工行尾号6525.xls" << endl
		<< "9. 校园卡日记账.xls" << endl;
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
	while(readOperAccBook.good())
	{
		Line tmp;
		readOperAccBook >> tmp;
		vecOperAccBook.push_back(tmp);
	}
	readOperAccBook.close();
	//操作模式
	cout << "There are two operate mode:" << endl
		<< "1. Manual entry" << endl
		<< "2. Create by balance" << endl;
	cout << "Enter operate mode: ";
	int operMode{};
	do
	{
		cin >> operMode;
		if (operMode < 1 || operMode>2)
			cout << "Operate number error!" << endl
			<< "Enter operate mode again: " << endl;
	} while (operMode < 1 || operMode>2);
	//响应操作模式
	if(operMode==1)
	{
		
	}
	else if(operMode==2)
	{
		
	}


	system("pause");
    return 0;
}

