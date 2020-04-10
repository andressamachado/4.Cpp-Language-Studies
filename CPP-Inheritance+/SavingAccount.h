#pragma once

/*****************************************************************************************************
Filename:				SavingAccount.h
Version:				1.0
Author:					Andressa Pessoa de Araujo Machado [040923007]
Assignment Number:		Theory Assignment 2
Assignment Name:		Simple Bank Simulator
Course Name:			C++ Programming Course
Code:					CST8219
Lab Section Number:		302
Professor's Name:		Surbhi Bahri
Due Date:				2020/04/09
Submission Date:		2020/04/09
List of source files:	Account.cpp, Bank.cpp, ChequingAccount.cpp, SavingAccount.cpp, Main.cpp

Purpose: Management of accounts in a bank system. This program has the purpose of practice inheritance
******************************************************************************************************/

class SavingAccount : public Account {
private:
	//interest of 0.5%
	const double interest = 0.5 / 100;

public:
	SavingAccount(int account_number, double balance) : Account(account_number, balance) {};
	~SavingAccount() {};
	double withdraw(double);
	void monthly_operation();
};
