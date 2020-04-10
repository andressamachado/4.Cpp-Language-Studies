
/*****************************************************************************************************
Filename:				Bank.cpp
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

#include <iostream>
#include <string>
#include <forward_list>
#include "Account.h"
#include "ChequingAccount.h"
#include "SavingAccount.h"
#include "Bank.h"

void Bank::add_an_account(Account* new_account) {
	accounts.push_front(new_account);
	number_of_accounts++;
}

int Bank::get_num_of_accounts() {
	return number_of_accounts;
}

Account* Bank::get_account(int account_index) {

	for (auto current_account = accounts.begin(); current_account != accounts.end(); ++current_account) {

		if ((*current_account)->get_account_number() == account_index) {
			
			return *current_account;
		}
	}
	return NULL; 
}

void Bank::monthly_operation() {
	forward_list<Account*>::iterator current_account;

	for (current_account = accounts.begin(); current_account != accounts.end(); ++current_account) {

		(*current_account)->monthly_operation();

		std::cout << "Account [ " << typeid(**current_account).name() << " ] " << (*current_account)->get_account_number() << " Balance: $"<< (*current_account)->get_balance() << std::endl;
	}
}

void Bank::delete_accounts() {

	if (accounts.empty()) {
		std::cout << "This are no accounts in the bank`s record to be deleted" << std::endl;
		return;
	}

	accounts.clear();
}

void Bank::print_list_of_accounts() {
	forward_list<Account*>::iterator current_account;

	std::cout << "[	";

	for (current_account = accounts.begin(); current_account != accounts.end(); ++current_account) {

		(*current_account)->get_account_number();

		std::cout << (*current_account)->get_account_number() << "	" << std::flush;
	}

	std::cout << "] :";

}