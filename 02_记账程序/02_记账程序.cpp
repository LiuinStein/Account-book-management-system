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

//�г���Ŀ�嵥
void ListAccBooks()
{
	cout << "There are 10 Account books:" << endl;
	cout << "1. �ֽ��ռ���.xls" << endl
		<< "2. �����Ͷ��.xls" << endl
		<< "3. ��������Ͷ��.xls" << endl
		<< "4. ��.xls" << endl
		<< "5. ����β��4852.xls" << endl
		<< "6. ����β��9776.xls" << endl
		<< "7. ����β��8261.xls" << endl
		<< "8. ����β��6525.xls" << endl
		<< "9. У԰���ռ���.xls" << endl;
}

//������Ŀ˵��
//1. �� 2. �ڲ��ʽ���ͨ 3. ��ĸ�� 4. New description
int getDescMethodNum()
{
	cout << "Choose a Income/Expense description in this option:" << endl;
	cout << "Default option: 1. �� 2. �ڲ��ʽ���ͨ 3. ��ĸ�� 4. New description" << endl;
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

//����Ŀ˵��ӳ��Ϊ�˱�˵����д��Line
void mappingDescMethod(Line & __w, int __dmn)
{
	if (__dmn == 1)
		__w.setDescription("��");
	else if (__dmn == 2)
		__w.setDescription("�ڲ��ʽ���ͨ");
	else if (__dmn == 3)
		__w.setDescription("��ĸ��");
	else if (__dmn == 4)
	{
		cout << "Enter a new description: ";
		string tmp;
		cin >> tmp;
		__w.setDescription(tmp.c_str());
	}
}

//�������
double newBalance()
{
	cout << "Enter a new balance: ";
	double result{};
	cin >> result;
	return result;
}

//�����ֽ���
double newMoney()
{
	cout << "Enter a money stream: ";
	double result{};
	cin >> result;
	return result;
}

//ʹ���ֽ�������ʱ������֧��(֧������true)
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
	//���������ļ�
	ifstream readAllAccount;
	readAllAccount.open(AllAccount);
	vector<Line> vecAllAccount;		//�洢���������е���
	while (readAllAccount.good())
	{
		Line tmp;
		readAllAccount >> tmp;
		vecAllAccount.push_back(tmp);
	}
	readAllAccount.close();
	//��ӭ����:
	cout << "Welcome to lyst Account book management system" << endl;
	cout << "Enter Password: ";
	//������֤����
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
	//���������
	system("cls");
	cout << "Welcome to lyst Account book management system" << endl;
	ListAccBooks();
	//¼������˱����
	cout << "Enter operate account book number: ";
	int doNumber{};
	do
	{
		cin >> doNumber;
		if (doNumber <= 0 || doNumber >= 10)
			cout << "Account book number error!" << endl
			<< "Enter operate account book number again: " << endl;
	} while (doNumber <= 0 || doNumber >= 10);
	//�򿪲���������˱�
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
	//����ģʽ
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
	//��Ӧ����ģʽ
	Line tarWriteLine;
	Time NowTime;		//��ȡ��ǰʱ��
	if (operMode == 1)
	{
		//˵��
		//��ȡ��Ŀ˵��
		int DescMethodNum{ getDescMethodNum() };
		//ӳ����Ŀ˵��
		mappingDescMethod(tarWriteLine, DescMethodNum);
		//������Ŀ
		//�õ���һ����Ŀ��Ϣ
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

