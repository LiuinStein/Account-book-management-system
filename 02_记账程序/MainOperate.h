#pragma once
#include <string>
//#include <fstream>
#include "Account.h"
#include "AllAccountLine.h"

//��Ҫ�����еĲ���ȫ�������������
class MainOperate
{
private:

	//�ļ�������
	//std::ifstream readAllBill;		//����������
	//std::ifstream readOperBillFrom;	//��Դ�˱�������
	//std::ifstream readOperBillTo;	//Ϊ�ڲ��ʽ���ͨ׼���ĸ���������

	//�ļ������
	//std::ofstream writeAllBill;		//���������
	//std::ofstream writeOperBillFrom;//��Դ�������
	//std::ofstream writeOperBillTo;	//Ϊ�ڲ��ʽ���ͨ׼���ĸ��������

	//�������Ŀ��Ϣ(�ַ���)
	//std::string allBillLastStr;		//�������һ����Ŀ��Ϣ
	//std::string fromBillLastStr;	//��Դ�����һ����Ŀ��Ϣ
	//std::string toBillLastStr;		//�������һ����Ŀ��Ϣ	

	//������(Line)
	AllAccountLine allBillLastLine;
	Line fromBillLastLine;
	Line toBillLastLine;

	//д����(Line)
	AllAccountLine allBillWriteLine;
	Line fromBillWriteLine;
	Line toBillWriteLine;

	//�������Ŀ��Ϣ(ת�����Account��)
	//Account * prevLastAllBill;		//����
	//Account * prevLastBillFrom;		//��Դ��
	//Account * prevLastBillTo;			//����

	//����
	int operBillFromNum;	//�����˱����[1,9]
	int operBillToNum;		//Ϊ�ڲ��ʽ���ͨ׼���ĸ��˱��
	int operModeNum;		//�˱�������[1,4]


	//¼��������[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//�����Ŀ�嵥
	void printAccBooks()const;

	//��������˱����
	void inputOperBill(bool __isFrom);

	//�г�����ģʽ
	void printOperMode()const;

	//���벢ӳ���˱�����ģʽ
	void mappingOperMode();

	//���������ļ�
	void loadAllBill();

	//ͨ����������˱�
	void loadBillByNum(int __i, bool __isFrom);

	//�Ƿ�ʹ��Ĭ�ϱ�ע/����ģ��
	bool useDefNoteTem();

	//¼���˱�˵��
	std::string inputNote();

	//¼���Ƿ����
	bool inputIsN();

	//ͨ�����д��Line
	void createLineByBal(Line & __new, Line & __prev);

	//¼����֧���
	EIMODE ExpOrInc()const;

	//ͨ���ʽ���д��Line
	void creaateLineByFlow(Line & __new, Line & __prev);

	//д�����и����˱��ļ�
	void writeBill();

public:
	MainOperate();
	~MainOperate();
};

