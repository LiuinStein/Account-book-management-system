#pragma once
#include <string>
#include <fstream>

//��Ҫ�����еĲ���ȫ�������������
class MainOperate
{
private:

	//������
	std::ifstream readAllBill;		//����������
	std::ifstream readOperBillFrom;	//��Դ�˱�������
	std::ifstream readOperBillTo;	//Ϊ�ڲ��ʽ���ͨ׼���ĸ���������


	//��Ŀ��Ϣ
	std::string allBillLast;	//�������һ����Ŀ��Ϣ
	std::string fromBillLast;	//��Դ�����һ����Ŀ��Ϣ
	std::string toBillLast;		//�������һ����Ŀ��Ϣ


	//����
	int operBillFromNum;	//�����˱����[1,9]



	//¼��������[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//�����Ŀ�嵥
	void printAccBooks()const;

public:
	MainOperate();
	~MainOperate();
};

