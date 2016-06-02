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

//¼��������[__s,__e]
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
	return inputNumber(1, 4);
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
	return inputNumber(1, 2) == 1;
}

//ʹ��Ĭ�ϱ�ע/����ģ��
bool useDefNoteTem()
{
	cout << "Do you want to use the default note and necessary template?" << endl;
	cout << "If you want type 1 else type 2: ";
	return inputNumber(1, 2) == 1;
}

//¼���˱�˵��
string inputNote()
{
	cout << "Enter your DIY note or use default(type #1): ";
	string tmp;
	cin >> tmp;
	if (tmp == "#1")
		tmp = "��";
	return tmp;
}

//¼���Ƿ����
bool inputIsN()
{
	cout << "Enter need(1) or unneed(2): ";
	return inputNumber(1, 2) == 1;
}

//�ֽ���������
void CreateLineByMoney(Line & tarWriteLine,
	const Account * prevAcc)
{
	bool isExpense = moneyExpense();	//�õ���֧���
	double operMoney = newMoney();		//�õ������ֽ���Ŀ
	if (useDefNoteTem())	//�Ƿ��ʹ��Ĭ�ϱ�ע/����ģ��
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
	string lastLineStr;
	while (readOperAccBook.good())
		readOperAccBook >> lastLineStr;
	Line lastLine(lastLineStr);
	readOperAccBook.close();

	//����ģʽ
	cout << "There are two operate mode:" << endl
		<< "1. Manual entry" << endl
		<< "2. Create by balance" << endl
		<< "3. Create by money and money direction" << endl
		<< "4. Flow of fund" << endl;
	cout << "Enter operate mode: ";
	int operMode = inputNumber(1, 4);
	//��Ӧ����ģʽ
	Line tarWriteLine;
	Time NowTime;		//��ȡ��ǰʱ��
	//�õ���һ����Ŀ��Ϣ
	const Account * prevAcc = lastLine.getAccount();
	if (operMode == 1)
	{
		//�ֹ�¼��:
		//˵��
		//��ȡ��Ŀ˵��
		int DescMethodNum{ getDescMethodNum() };
		//ӳ����Ŀ˵��
		mappingDescMethod(tarWriteLine, DescMethodNum);
		//������Ŀ
		CreateLineByMoney(tarWriteLine, prevAcc);
	}
	else if (operMode == 2)
	{
		//�������
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
		//�����ֽ���
		CreateLineByMoney(tarWriteLine, prevAcc);
	}
	else if (operMode == 4)
	{
		//�ڲ��ʽ���ͨ
		Line tarWriteLine_to;
		ListAccBooks();		//���˱�
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

	//�򿪱�Ҫ�ļ�
	ofstream writeOperAccBook;
	writeOperAccBook.open(AccountBooks[doNumber]);
	ofstream writeAllAccBook;
	writeAllAccBook.open(AllAccount);

	//���������ڲ��ʽ���ͨ���
	if (operMode != 4)
	{
		//����ǰ��Lineд�뵱ǰ�����˱�
		writeOperAccBook << tarWriteLine << endl;
		//д����	
		writeAllAccBook << tarWriteLine << '\t'
			<< AccountBooks[doNumber] << "��" << endl;
	}


	system("pause");
	return 0;
}

