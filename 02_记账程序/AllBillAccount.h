#pragma once
#include "Account.h"

class AllBillAccount :
	public Account
{
private:
	bool isFlowOfFund;

public:
	AllBillAccount();
	~AllBillAccount();
};

