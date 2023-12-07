#include "InMemoryDB.h"

InMemoryDB::InMemoryDB() {
	in_progress = false;
}

bool InMemoryDB::is_in_progress() {
	return in_progress;
}
bool InMemoryDB::begin_transaction() {
	if (in_progress)
		return false; // let's user know we are already in a transaction
	in_progress = true;
	return true;	// transaction has begun
}
bool InMemoryDB::put(std::string key, int val) {
	if (!in_progress) {
		std::cout << "No transaction in progress!" << std::endl;
		throw - 1;
	}
	transaction[key] = val;
	return true;
}
int* InMemoryDB::get(std::string key) {
	if (DB.count(key))
		return &DB[key];
	return nullptr;
}
bool InMemoryDB::commit() {
	if (!in_progress) {
		std::cout << "No transaction in progress" << std::endl;
		throw - 2;
		return false;	// we are not in a transaction
	}

	for (auto iter : transaction) {
		DB[iter.first] = iter.second;
	}
	transaction.clear();
	in_progress = false;
	return true;	// successfully commited
}
bool InMemoryDB::rollback() {
	if (!in_progress) {
		std::cout << "No transaction in progress" << std::endl;
		throw - 3;
		return false;	// we are not in a transaction
	}
	transaction.clear();
	in_progress = false;
	return true;	// successfully rolled back
}

void InMemoryDB::print_DB() {
	std::cout << "Printing Database. . ." << std::endl;
	std::cout << "Key | Value" << std::endl;
	for (auto iter : DB) {
		std::cout << iter.first << ", " << iter.second << std::endl;
	}
}
void InMemoryDB::print_transaction() {
	if (!in_progress) {
		std::cout << "No transaction in progress" << std::endl;
		return;
	}
	std::cout << "Printing Current Transaction. . ." << std::endl;
	std::cout << "Key | Value" << std::endl;
	for (auto iter : transaction) {
		std::cout << iter.first << ", " << iter.second << std::endl;
	}
}