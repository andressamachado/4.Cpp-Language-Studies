#pragma once

/*****************************************************************************************************
Filename:				Account.h
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

class Account{
private:
	int account_number;

protected:
	double balance;

public:
	Account(int account_number, double balance) : account_number(account_number), balance(balance){};
	virtual ~Account() {};
	virtual void monthly_operation() = 0;
	int get_account_number();
	double get_balance();
	virtual double withdraw(double) = 0;
	double deposit(double);
};