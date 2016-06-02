#pragma once
#include <string>
#include <fstream>
#include "Account.h"

//��Ҫ�����еĲ���ȫ�������������
class MainOperate
{
private:

	//�ļ�������
	std::ifstream readAllBill;		//����������
	std::ifstream readOperBillFrom;	//��Դ�˱�������
	std::ifstream readOperBillTo;	//Ϊ�ڲ��ʽ���ͨ׼���ĸ���������

	//�ļ������
	std::ofstream writeAllBill;		//���������
	std::ofstream writeOperBillFrom;//��Դ�������
	std::ofstream writeOperBillTo;	//Ϊ�ڲ��ʽ���ͨ׼���ĸ��������

	//�������Ŀ��Ϣ(�ַ���)
	std::string allBillLastStr;		//�������һ����Ŀ��Ϣ
	std::string fromBillLastStr;	//��Դ�����һ����Ŀ��Ϣ
	std::string toBillLastStr;		//�������һ����Ŀ��Ϣ

	//�������Ŀ��Ϣ(ת�����Account��)
	Account * prevLastBillFrom;		//��Դ��
	Account * prevLastBillTo;		//����

	//����
	int operBillFromNum;	//�����˱����[1,9]
	int operModeNum;		//�˱�������[1,4]


	//¼��������[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//�����Ŀ�嵥
	void printAccBooks()const;

	//�г�����ģʽ
	void printOperMode()const;

public:
	MainOperate();
	~MainOperate();
};

