#pragma once
#include <string>

enum EIMODE
{
	Expense, Income, Flow
};

//���ڴ洢�˱���Ŀ
class Account
{
private:
	EIMODE		EIMode;			//����֧��ģʽ
	double		money;			//�������
	bool		isNecessary;	//����Ϊtrue
	std::string Note;			//��ע
	double		balance;		//��ǰ��Ŀ���
	double		allCost;		//�ܻ���
	double		allIncome;		//������
public:
	explicit Account(EIMODE __EIM, double __mon, bool __isN,
		std::string __note, double __bal,
		double __allC, double __allI);

	//�����µ������Ϣ�������µ�Account��Ŀ
	Account(const Account * __last, double __newBalance,
		std::string __n = "��", bool __isN = true);

	//����������������������µ�Account��Ŀ
	Account(const Account * __last, double __mon,
		EIMODE __EIM, std::string __n = "��", bool __isN = true);

	//�õ����
	double getBalance()const;

	//�õ��Ƿ����
	bool getIsN()const;

	//�õ��������
	double getMon()const;

	//�õ���֧ģʽ
	EIMODE getEIMODE()const;

	//�õ�˵��
	const std::string & getNote()const;

	//�����������,��Accountֱ��д���ļ�
	friend std::ofstream& operator<<(std::ofstream& __ofs, Account & __w);
};

