#pragma once

/*****************************************************************************************************
Filename:				Bank.h
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

#include <forward_list>
#include "Account.h"

class Bank {
private:
	static const int max_number_of_accounts = 16;
	int number_of_accounts = 0;
	std::forward_list<Account*> accounts;

public:
	Bank(){};
	~Bank(){};

	void add_an_account(Account*);
	int get_num_of_accounts();
	Account* get_account(int);
	void monthly_operation();
	void delete_accounts();
	void print_list_of_accounts();
};
