#pragma once
#include"Transactions.h"
#include"Branch.h"
class Accounts:public Branch
{
public:
	Accounts() :Branch(),name(), email(),password(), accountNumber(),accountType(),transferInfo(),idCard() {
		name = nullptr; email = nullptr; password = nullptr; accountNumber = nullptr; amount = nullptr; accountType = nullptr; idCard = nullptr;
	}
	void setAccount(Node* _type) { accountType = _type; }
	void setName(char*);
	void setPassword(char*);
	void setIdCard(char*);
	void setAccountNumber(char*);
	Node* getAccountType() { return accountType; }
	void createAccount();
	void setAmount(int);
	void setEmail(char*);
	void setAccountType(char*);
	void loginAccount();
	void deposit(int);
	void withDraw(int);
	void transfer(int);
	void accountInfo(int);
	void transferRecords(int);
	void display(ostream & ) ;
	void displayGrid(int);//Passing index of Node When Account Is Login
private:
	Node* name;
	Node* email;
	Node* password;
	Node* idCard;
	Node* accountNumber;
	int* amount;
	Node* accountType;
	Transactions transferInfo;
};
ostream& operator<<(ostream&,  Accounts&);


