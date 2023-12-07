#pragma once
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>

class InMemoryDB
{
private:
	std::unordered_map<std::string, int> DB;
	std::unordered_map<std::string, int> transaction;
	bool in_progress;

public:
	InMemoryDB();
	bool is_in_progress();
	bool begin_transaction();
	bool put(std::string key, int val);
	int* get(std::string key);
	bool commit();
	bool rollback();
	void print_DB();
	void print_transaction();
};

