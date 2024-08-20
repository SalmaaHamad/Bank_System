// Project 2 : Banking system

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <forward_list>
using namespace std;

class Person {
	// attr
protected:
	int id;
	string name;
	string pass;
public:
	//cons
	Person() {
		id = 0;
	}
	Person(int id, string name, string pass) {
		this->id = id;
		this->name = name;
		this->pass = pass;
	}
	//setters
	void setName(string name) {
		if (name.length() < 5 || name.length() > 20) {
			cout << "Error: Name must be between 5 and 20 characters." << endl;
			return;
		}
		for (char c : name) {
			if (!isalpha(c)) {
				cout << "Error: Name must contain only alphabetic characters." << endl;
				return;
			}
		}
		this->name = name;
	}
	void setId(int id) {
		this->id = id;
	}
	void setPass(string pass) {
		if (pass.length() < 8 || pass.length() > 20) {
			cout << "Error: Password must be between 8 and 20 characters." << endl;
			return;
		}
		this->pass = pass;
	}

	//getters

	int getId() {
		return id;
	}

	string getName() {
		return name;
	}
	string getPass() {
		return pass;
	}

	void Printinfo() {
		cout << "Name =  " << name << endl;
		cout << "ID =  " << id << endl;
	//	cout << "Password =  " << "*****" << endl;
	}

	void Login(int i, string p) {

		if (i == id && p == pass)
			cout << "Access Granted";
		else
			cout << "user name or password is invalid ";
	}
};

/* ====================================Client CLASS==================================*/

class Client :public Person {
protected:
	//attr
	double balance;

public:
	//cons
	Client() {
		balance = 0;
	}

	Client(int id, string name, string pass, double balance) :Person(id, name, pass) {

		this->balance = balance;
	}
	//setters

	void setBalance(double balance) {

		if (balance < 1500) {
			cout << "Error: Balance must be at least 1500." << endl;
			return;
		}
		else {
			this->balance = balance;
		}
		
	}

	//getters
	double getBalance() {
		return balance;
	}

	//methods

	void Printinfo() {
		Person::Printinfo();
		cout << "Balance = " << balance << endl;
		cout << "\n============================\n";
	}

	double Withdraw(double  amount) {
		if (amount > balance)
			cout << "NO enough balance" << endl;
		else
			return balance -= amount;
	}

	double Deposit(double  amount) {

		return balance += amount;
	}

	void Checkbalance() {
		cout << " your available balance =  " << balance << " LE" << endl;
	}
	void Transferto(Client& c, double a) {
		if (a <= balance)
		{
			c.Deposit(a);
			balance -= a;
			cout << "Transfer successfully" << endl;
		}
		else
			cout << "NO enough balance to proceed" << endl;

	}
};

/* ====================================Employee CLASS==================================*/

class Employee :public Person {
	// attr
protected:
	double salary;

	//cons
public:
	Employee() {
		salary = 0;
	}
	Employee(int id, string name, string pass, double salary) :Person(id, name, pass) {

		this->salary = salary;
	}

	void setSalary(double salary) {

		if (salary < 5000) {
			cout << "Error: Salary must be at least 5000." << endl;
			return;
		}
		this->salary = salary;
	}

	double getSalary() {
		return salary;
	}

	//Methods

	//add new client
	Client addClient(int i, string n, string p, double b, list<Client> clients) {
		Client New(i, n, p, b);
		clients.push_back(New);
		return New;
	}
	//search for client by id
	Client searchClientId(int clientid ,list<Client> clients) {
		
		for (int i =0 ;i< clients.size();i++ ) {
			
		}
	}
	//list all clients
	void listClients(){

	}
	//edit info of client
	void editClient(Client c, string n, double b) {
		c.setName(n);
		c.setBalance(b);
	}

	void Printinfo() {
		Person::Printinfo();
		cout << " Salary = " << salary << endl;
		cout << "\n============================\n";

	}

};

/* ====================================ADMIN CLASS==================================*/

class Admin :public Employee {

	//cons
public:
	Admin() {

	}
	Admin(int id, string name, string pass, double salary) :Employee(id, name, pass, salary) {

	}
};


int main() {
	////Person p(250183, "ahmed", "123");
	////p.Printinfo();

	//Client malak(250172, "Malak", "22112023",2000);
	//Client Omar(250183, "omar", "1422019", 0);
	////malak.Printinfo();
	////malak.Login(250172, "22112023");
	//malak.Withdraw(1000);
	//malak.Printinfo();

	//malak.Deposit(5000);
	//malak.Printinfo();
	//malak.Checkbalance();

	//malak.Transferto(Omar, 20000);
	//Omar.Printinfo();
	//malak.Printinfo();

	Employee Hisham(250558, "hesham", "22222", 5000);
	Client Ahmed(250183, "elghazaly", "33333", 10000);
	Admin hassan(250993, "hassan eladmin ", "9999", 1000);

	//hassan.Login(250993, "9999");

	//Ahmed.Printinfo();
	//Hisham.setName("hisham123");
	//hassan.Printinfo();
	list<Client> l;
	Hisham.addClient(55, "salma","234",100000,l).Printinfo();

}