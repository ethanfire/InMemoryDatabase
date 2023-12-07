#include "InMemoryDB.h"
#include <iostream>
using namespace std;

void print_menu();

int main() {
	InMemoryDB DB;
	cout << "Welcome to my extra credit assignment!" << endl;
	int choice = 0;
	while (choice != -1) {
		print_menu();
		cin >> choice;

		if (choice == -1) { // quit
			cout << "Goodbye!" << endl;
			break;
		}
		else if (choice == 1) {
			if (DB.begin_transaction())
				cout << "Transaction started!" << endl;
			else 
				cout << "Transaction already in progress." << endl;
		}
		else if (choice == 2) {
			if (!DB.is_in_progress()) {
				std::cout << "No transaction in progress!" << std::endl;
				throw - 1;
			}
			cout << "Attempting to put key, value pair. . ." << endl;
			std::cout << "(1/2) Please type the key (string): ";
			string key = "";
			cin >> key;

			std::cout << "(2/2) Please type the value (int): ";
			int value = 0;
			cin >> value;
			cout << endl;

			if (DB.put(key, value)) {
				cout << "Key: \"" << key << "\" and Value: \"" << value << "\" were successfully added to the transaction." << endl;
			}
		}
		else if (choice == 3) {
			cout << "Attempting to get value. . ." << endl;
			std::cout << "Please type the key (string): ";
			string key = "";
			cin >> key;
			cout << endl;

			int* value = DB.get(key);
			cout << "Value: ";
			if (value == nullptr)
				cout << "NULL" << endl;
			else
				cout << *value << endl;
		}
		else if (choice == 4) {
			if (!DB.commit())
				cout << "No transaction in progress." << endl;
			else 
				cout << "Transaction successfully committed." << endl;
		}
		else if (choice == 5) {
			if (!DB.rollback())
				cout << "No transaction in progress." << endl;
			else
				cout << "Transaction successfully rolled back." << endl;
		}
		else if (choice == 6) {
			DB.print_DB();
		}
		else if (choice == 7) {
			DB.print_transaction();
		}
	}
	return 0;
}

void print_menu() {
	cout << "\nType the integer corresponding to your choice:" << endl;
	cout << "1) begin_transaction()" << endl;
	cout << "2) put(key, value)" << endl;
	cout << "3) get(key)" << endl;
	cout << "4) commit()" << endl;
	cout << "5) rollback()" << endl;
	cout << "6) print_database()" << endl;
	cout << "7) print_transaction()" << endl;
	cout << "-1) quit\n" << endl;
}