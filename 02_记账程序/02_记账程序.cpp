// 02_���˳���.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//���������ļ�
	ifstream readAllAccount;
	readAllAccount.open(AllAccount);
	vector<Line> vecAllAccount;		//�洢���������е���
	while(readAllAccount.good())
	{
		Line tmp;
		readAllAccount >> tmp;
		vecAllAccount.push_back(tmp);
	}
	//��ӭ����:
	cout << "Welcome to lyst Account book management system" << endl;
	cout << "Enter Password: ";
	//������֤����
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
	//���������
	system("cls");
	cout << "Welcome to lyst Account book management system" << endl;
	cout<<"This is 10 Account books "

	system("pause");
    return 0;
}

