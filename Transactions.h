#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
class Transactions
{
public:
	Transactions();
	Transactions(char*, char*, int);
	void setFromAccount(Node*);
	void setToAccount(Node*);
	void setAmount(int );
	Node* getFromAccount() { return fromAccount; }
	Node* getToAccount() { return toAccount; }
	int* getAmount() { return amount; }
	Transactions(Transactions&);
	bool operator==(Transactions&);
	void input(istream&);
	void wrt(ostream&)const;
private:
	Node* fromAccount;
	Node* toAccount;
	int* amount;
};

istream& operator>>(istream&, Transactions&);
ostream& operator<<(ostream&, const Transactions&);

