
/*****************************************************************************************************
Filename:				Main.cpp
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
#include <iomanip> 
#include "Account.h"
#include "ChequingAccount.h"
#include "SavingAccount.h"
#include "Bank.h"

int main(void) {

	bool RUNNING = true;
	char user_input;

	int account_index;
	double deposit_amount;
	double withdraw_amount;
	double balance_total;
	
	Bank bank = Bank();

	Account* chequing1 = new ChequingAccount(101, 1000.00);
	bank.add_an_account(chequing1);
	Account* chequing2 = new ChequingAccount(102, 500.00);
	bank.add_an_account(chequing2);
	Account* chequing3 = new ChequingAccount(103, 12000.00);
	bank.add_an_account(chequing3);

	Account* saving1 = new SavingAccount(201, 1000.00);
	bank.add_an_account(saving1);
	Account* saving2 = new SavingAccount(202, 500.00);
	bank.add_an_account(saving2);
	Account* saving3 = new SavingAccount(203, 12000.00);
	bank.add_an_account(saving3);
	

	while (RUNNING) {

		std::cout << "== MENU ==\n[D]eposit\n[W]ithdraw\n[M]onth\n[Q]uit" << std::endl;
		std::cin >> user_input;

		switch (user_input) {

		case 'd':
		case 'D':
			
			do {
				std::cout << "Enter the desired account to be processed  " << std::flush;
				bank.print_list_of_accounts();
				std::cin >> account_index;

				if (account_index < 0 ) {
					std::cout << "Not a valid account, please check your input and try again." << std::endl;
				}
			} while ((account_index < 0));

			if (bank.get_account(account_index)) {
				do {
					std::cout << "Please, enter the desired amount to be deposited: " << std::flush;
					std::cin >> deposit_amount;

					if (deposit_amount < 0.0) {
						std::cout << "Not a valid input, please check your input and try again." << std::endl;
					}
				} while (deposit_amount < 0.0 );

				balance_total = bank.get_account(account_index)->deposit(deposit_amount);

				std::cout << "Account Balance = $";
				std::cout.precision(2);
				std::cout << std::fixed;
				std::cout << balance_total << std::endl;
				
				break;
			}

			std::cout << "Account not found. Operation could not be completed." << std::endl;
			break;


		case 'w':
		case 'W':
			do {
				std::cout << "Enter the desired account to be processed  " << std::flush;
				bank.print_list_of_accounts();
				std::cin >> account_index;

				if (account_index < 0) {
					std::cout << "Not a valid account, please check your input and try again." << std::endl;
				}
			} while ((account_index < 0));

			if (bank.get_account(account_index)) {
				do {
					std::cout << "Please, enter the desired amount to be withdrawn [ $ " << bank.get_account(account_index)->get_balance() << " available ] : " << std::flush;
					std::cin >> withdraw_amount;

					if (withdraw_amount < 0.0) {
						std::cout << "Not a valid input, please check your input and try again." << std::endl;
					}
				} while (withdraw_amount < 0.0);

				balance_total = bank.get_account(account_index)->withdraw(withdraw_amount);

				std::cout << "Account Balance = $" << balance_total << std::endl;
				break;
			}

			std::cout << "Account not found. Operation could not be completed." << std::endl;
			break;

		case 'm':
		case 'M':
			bank.monthly_operation();
			break;

		case 'q':
		case 'Q':
			bank.delete_accounts();
			RUNNING = false;
			break;

		default:
			std::cout << "Please enter a valid option" << std::endl;
			break;
		}
	}

	return 0;
}

