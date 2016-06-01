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
	//欢迎界面:
	cout << "Welcome to lyst Account book management system" << endl;
	cout << "Enter Password: ";
	//密码验证部分
	string key;
	bool keyCorrect{};
	do
	{
		cin >> key;
		keyCorrect = key == "1021";
		if(!keyCorrect)
		{
			cout << "Password Error!" << endl;
			cout << "Enter Password: ";
		}
	} while (!keyCorrect);
	//主程序界面
	system("cls");
	cout << "Welcome to lyst Account book management system" << endl;
	cout<<"This is 10 Account books "

	system("pause");
    return 0;
}

