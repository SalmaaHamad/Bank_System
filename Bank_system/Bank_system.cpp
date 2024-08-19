// Bank_system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <forward_list>
using namespace std;

class Person {
private:
	//Data
	int id;
	double balance;
	string name, password;
public:
	//cons
	Person() {
		id = balance = 0;
	}
	Person(int id, int balance, string name, string password) {
		this->id = id;
		this->balance = balance;
		this->name = name;
		this->password = password;
	}
	//getters
	int getId() {
		return id;
	}
	int getBalance() {
		return balance;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	//setters
	void setId(int id) {
		this->id = id;
	}
	void setBalance(int balance) {
		this->balance = balance;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPassword(string password) {
		this->password = password;
	}
};

class Client :public Person {

};




int main()
{
    std::cout << "Baaaaaaaaaaaaaaaaaaaanking\n";
}

