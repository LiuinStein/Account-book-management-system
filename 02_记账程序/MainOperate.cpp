#include "stdafx.h"
#include "MainOperate.h"
#include "FilePath.h"
#include <iostream>

//�ӽ���¼��������
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

//�г���Ŀ�嵥
void MainOperate::printAccBooks() const
{
	std::cout << "There are 10 Account books:" << std::endl;
	std::cout << "1. �ֽ��ռ���.xls" << std::endl
		<< "2. �����Ͷ��.xls" << std::endl
		<< "3. ��������Ͷ��.xls" << std::endl
		<< "4. ��.xls" << std::endl
		<< "5. ����β��4852.xls" << std::endl
		<< "6. ����β��9776.xls" << std::endl
		<< "7. ����β��8261.xls" << std::endl
		<< "8. ����β��6525.xls" << std::endl
		<< "9. У԰���ռ���.xls" << std::endl;
}

//�г�����ģʽ
void MainOperate::printOperMode() const
{
	std::cout << "There are four operate mode:" << std::endl
		<< "1. Manual entry" << std::endl
		<< "2. Create by balance" << std::endl
		<< "3. Create by money and money direction" << std::endl
		<< "4. Flow of fund" << std::endl;
}

//���������ļ�
void MainOperate::loadAllBill()
{
	readAllBill.open(AllAccount);
	std::string tmp;
	while (readAllBill.good())
		readAllBill >> tmp;
	allBillLastLine = tmp;
	readAllBill.close();
}

//ͨ����������˱�
void MainOperate::loadBillByNum(int __i, 
	bool __isFrom)
{
	//ͨ��__isFrom����ʹ����һ��
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
