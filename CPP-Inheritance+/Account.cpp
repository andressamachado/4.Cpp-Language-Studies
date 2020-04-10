
/*****************************************************************************************************
Filename:				Account.cpp
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

using namespace std;

#include <string>
#include <iostream>
#include "Account.h"

int Account::get_account_number() {
	return account_number;
}

double Account::get_balance() {
	return balance;
}

double Account::deposit(double amount) {
	double new_balance = balance + amount;

	if (amount < 0.0 || new_balance < 0.0) {
		std::cout << "Operation not completed. Please, try again with a valid deposit" << std::endl;
		return balance;
	}
	
	balance = new_balance;
	return balance;
}
