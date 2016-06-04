#pragma once
#include <string>
//#include <fstream>
#include "Account.h"
#include "AllAccountLine.h"

//��Ҫ�����еĲ���ȫ�������������
class MainOperate
{
private:

	//������(Line)
	AllAccountLine allBillLastLine;
	Line fromBillLastLine;
	Line toBillLastLine;

	//д����(Line)
	AllAccountLine allBillWriteLine;
	Line fromBillWriteLine;
	Line toBillWriteLine;

	//����
	int operBillFromNum;	//�����˱����[1,9]
	int operBillToNum;		//Ϊ�ڲ��ʽ���ͨ׼���ĸ��˱��
	int operModeNum;		//�˱�������[1,3]
	std::string log;		//��־

///���ݷ�����:

	///��������:
	//¼��������[__s,__e]
	int inputNumber(int __s, int __e,
		const char * InputError = nullptr)const;

	//��������˱����
	void inputOperBill(bool __isFrom);

	//�Ƿ�ʹ��Ĭ�ϱ�ע/����ģ��
	bool useDefNoteTem();

	//¼���˱�˵��
	std::string inputNote();

	//¼���Ƿ����
	bool inputIsN();

	//¼����֧���
	EIMODE ExpOrInc()const;


	///�������
	//�����Ŀ�嵥
	void printAccBooks()const;

	//�г�����ģʽ
	void printOperMode()const;


///�ļ���������
	//���������ļ�
	void loadAllBill();

	//ͨ����������˱�
	void loadBillByNum(int __i, bool __isFrom);

	//д�����и����˱��ļ�
	void writeBill();

///ʵ�ʲ�������

	//���벢ӳ���˱�����ģʽ
	void mappingOperMode();

	//ͨ�����д��Line
	void createLineByBal(Line & __new, Line & __prev);

	//д����Ŀ˵��
	//1. �� 2. �ڲ��ʽ���ͨ 3. ��ĸ�� 4. New description
	void MainOperate::DescMethod(Line & __m);

	//ͨ���ʽ���д��Line
	double createLineByFlow(Line & __new, Line & __prev);

	//�ʽ���д��Line
	void flowSetLine(Line& __new, Line& __prev,
		double __mon, EIMODE __eim);

///��������
	//ȷ�ϲ���
	bool confirmOper()const;

	//main����Yeah!
	void main();

public:
	MainOperate();
	~MainOperate();
};

