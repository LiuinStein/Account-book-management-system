#include "stdafx.h"
#include "MainOperate.h"
#include "FilePath.h"
#include <iostream>
#include <fstream>

//�ӽ���¼��������[__s,__e]
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

//��������˱����
void MainOperate::inputOperBill(bool __isFrom)
{
	__isFrom ? operBillFromNum = inputNumber(1, 9) :
		operBillToNum = inputNumber(1, 9);
}

//�г��˱�������
void MainOperate::printOperMode() const
{
	std::cout << "There are four operate mode:" << std::endl
		<< "1. Manual entry" << std::endl
		<< "2. Create by balance" << std::endl
		<< "3. Flow of fund" << std::endl;
}

//���벢ӳ���˱�������
void MainOperate::mappingOperMode()
{
	std::cout << "Enter operate mode: ";
	operModeNum = inputNumber(1, 3);
	//TODO: ����ӳ���˱�����ģʽ
	if (operModeNum == 1)
	{
		//�ʽ���(��ĸ��,������ע��/���)
		DescMethod(fromBillWriteLine);	//д��˵��
		//д���������
		createLineByFlow(fromBillWriteLine,
			fromBillLastLine);
	}
	else if(operModeNum == 2)
	{
		//�������(У԰��)
		DescMethod(fromBillWriteLine);	//д��˵��
		createLineByBal(fromBillWriteLine,
			fromBillLastLine);
	}
	//else if (operModeNum == 3)
	//{
	//	//�ʽ���(��ĸ��,������ע��/���)
	//	createLineByFlow(fromBillWriteLine,
	//		fromBillLastLine);
	//}
	else if (operModeNum == 3)
	{
		//�ڲ��ʽ���ͨ

	}
}

//���������ļ�
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

//ͨ����������˱�
void MainOperate::loadBillByNum(int __i, bool __isFrom)
{
	/*
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

//�Ƿ�ʹ��Ĭ�ϱ�ע/����ģ��
bool MainOperate::useDefNoteTem()
{
	std::cout << "Do you want to use the default note and necessary template?" << std::endl;
	std::cout << "If you want type 1 else type 2: ";
	return inputNumber(1, 2) == 1;
}

//¼���˱�˵��
std::string MainOperate::inputNote()
{
	std::cout << "Enter your DIY note or use default(type #1): ";
	std::string tmp;
	std::cin >> tmp;
	if (tmp == "#1")
		tmp = "��";
	return tmp;
}

//¼���Ƿ����
bool MainOperate::inputIsN()
{
	std::cout << "Enter need(1) or unneed(2): ";
	return inputNumber(1, 2) == 1;
}

//ͨ�������д��Line
void MainOperate::createLineByBal(Line & __new, 
	Line & __prev)
{
	//���������
	std::cout << "Enter new balance: ";
	double newBalance{};
	do
	{
		std::cin >> newBalance;	
		if (newBalance < 0)
			std::cout << "Balance requires > 0" << std::endl
			<< "Type again: ";
	} while (newBalance < 0);
	//д��Line
	if (useDefNoteTem())
		__new.setAccount(
			new Account(__prev.getAccount(), newBalance));
	else
		__new.setAccount(
			new Account(__prev.getAccount(), newBalance,
				inputNote(), inputIsN()));

}

//¼����֧���
EIMODE MainOperate::ExpOrInc() const
{
	std::cout << "Expense or Income(1 or 2): ";
	return inputNumber(1, 2) == 1 ? Expense : Income;
}

//¼�벢ӳ����Ŀ˵��
//1. �� 2. �ڲ��ʽ���ͨ 3. ��ĸ�� 4. New description
void MainOperate::DescMethod(Line & __m)
{
	std::cout << "Choose a Income/Expense description in this option:" << std::endl;
	std::cout << "Default option: 1. �� 2. �ڲ��ʽ���ͨ 3. ��ĸ�� 4. New description" << std::endl;
	std::cout << "Enter a option number: ";
	int noteMode{ inputNumber(1, 4) };
	if (noteMode == 1)
		__m.setDescription("��");
	else if (noteMode == 2)
		__m.setDescription("�ڲ��ʽ���ͨ");
	else if (noteMode == 3)
		__m.setDescription("��ĸ��");
	else if (noteMode == 4)
	{
		std::cout << "Enter a new description: ";
		std::string tmp;
		std::cin >> tmp;
		__m.setDescription(tmp.c_str());
	}
}

//ͨ���ʽ���д��Line
void MainOperate::createLineByFlow(Line& __new, 
	Line& __prev)
{
	EIMODE expOrInc = ExpOrInc();	//�õ���֧���
	double operMoney{};		
	std::cin >> operMoney;	//�õ������ֽ���Ŀ

	if (useDefNoteTem())	//�Ƿ��ʹ��Ĭ�ϱ�ע/����ģ��
		__new.setAccount(
			new Account(__prev.getAccount(), operMoney,
				expOrInc));
	else
		__new.setAccount(
			new Account(__prev.getAccount(), operMoney,
				expOrInc, inputNote(), inputIsN()));
}

//д�����и����˱��ļ�
void MainOperate::writeBill()
{
	//д������
	std::ofstream writeBill;
	writeBill.open(AllAccount);
	writeBill << allBillWriteLine << std::endl;
	writeBill.close();

	//д����Դ�˱�
	writeBill.open(AccountBooks[operBillFromNum]);
	writeBill << fromBillWriteLine << std::endl;
	writeBill.close();

	//д�븱���˱�(����еĻ�)
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
