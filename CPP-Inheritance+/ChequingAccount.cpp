
/*****************************************************************************************************
Filename:				ChequingAccount.cpp
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
#include "ChequingAccount.h"

void ChequingAccount::monthly_operation() {
	withdraw_counter = 0;
};

double ChequingAccount::withdraw(double amount) {
	double new_balance;

	if (amount > balance) {
		std::cout << "Not enough balance to proceed" << std::endl;
		return balance;
	}

	if (withdraw_counter >= withdraw_max) {
		std::cout << "You have already processed 4 withdrawals this month. A fee of $2.00 will be computed." << std::endl;
		new_balance = (balance - amount) - additional_withdraw_fee;
	}
	else {
		new_balance = balance - amount;
	}

	if (new_balance < 0.0) {
		std::cout << "Not enough balance to proceed" << std::endl;
		return balance;
	}

	balance = new_balance;
	withdraw_counter++;

	return balance;
};
