#pragma once
#include <string>

//���ڴ洢�˱���Ŀ
class Account
{
private:
	bool		isExpense;		//֧��Ϊtrue,����Ϊfalse
	double		money;			//�������
	bool		isNecessary;	//����Ϊtrue
	std::string Note;			//��ע
	double		balance;		//��ǰ��Ŀ���
	double		allCost;		//�ܻ���
	double		allIncome;		//������
public:
	explicit Account(bool __isE, double __mon, bool __isN,
		std::string __note, double __bal,
		double __allC, double __allI);

	//�����µ������Ϣ�������µ�Account��Ŀ
	friend Account calcByBalance(const Account & __last, double __newBalance,
		std::string __n = "��", bool __isN = true);

	//�����������,��Accountֱ��д���ļ�
	friend std::ofstream& operator<<(std::ofstream& __ofs, Account & __w);
};

