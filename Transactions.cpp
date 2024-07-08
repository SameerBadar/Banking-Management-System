#include<iostream>
#include"util.h"
#include "Transactions.h"
using namespace std;
Transactions :: Transactions():fromAccount(),toAccount(){
	fromAccount = nullptr;
	toAccount = nullptr;
	amount = nullptr;
}

Transactions::Transactions(char* from, char* to, int _amount) {
	if (fromAccount == nullptr && toAccount == nullptr && amount == nullptr) {
		Node* temp1 = new Node(from);
		fromAccount = temp1;
		Node* temp2 = new Node(to);
		toAccount = temp2;
		amount = new int[1];
		amount[0] = _amount;
	}
}
bool Transactions::operator==(Transactions& obj) {
	if (this->fromAccount == obj.fromAccount && this->toAccount == obj.toAccount && this->amount == obj.amount) {
		return true;
	}
	return false;
}
void Transactions::setFromAccount(Node* _from) {
	if (fromAccount == nullptr) {
		char* ptr = _from->getValue();
		fromAccount = new Node(ptr);
	}
	else {
		char* ptr = _from->getValue();
		Node* temp = new Node(ptr);
		temp->setNext(fromAccount);
		fromAccount = temp;
	}
	//fromAccount = _from;
}

void Transactions::setToAccount(Node* _To) {
	//toAccount = _To;
	if (toAccount == nullptr) {
		char* temp = _To->getValue();
		toAccount = new Node(temp);
		}
	else {
		char* temp = _To->getValue();
		Node* temp2 = new Node(temp);
		temp2->setNext(toAccount);
		toAccount = temp2;
	}
}
void Transactions::setAmount(int _amount) {
	if (amount == nullptr) {
		amount = new int[1];
		amount[0] = _amount;
	}
	else {
	amount=singlePointerCopy(amount, toAccount);
	amount[0] = _amount;
	}
	}
Transactions::Transactions(Transactions& obj) {
	this->fromAccount = obj.fromAccount;
	this->toAccount = obj.toAccount;
	this->amount = obj.amount;
}

void Transactions::input(istream& fin) {
	if (fromAccount == nullptr) {
		fromAccount = new Node();
		fin >> (*fromAccount);
	}
	else {
		Node* temp = new Node();
		fin >> (*temp);
		temp->setNext(fromAccount);
		fromAccount = temp;
	}
	if (toAccount == nullptr) {
		toAccount = new Node();
		fin >> (*toAccount);
	}
	else {
		Node* temp = new Node();
		fin >> (*temp);
		temp->setNext(toAccount);
		toAccount = temp;
	}
	if (amount == nullptr) {
		amount = new int[1];
		fin >> amount[0];
	}
	else {
	amount=singlePointerCopy(amount, fromAccount);
	fin >> amount[0];
	}
}
istream& operator>>(istream& fin, Transactions& obj) {
	obj.input(fin);
	return fin;
}

ostream& operator<<(ostream& fout, const Transactions& obj) {
	obj.wrt(fout);
	return fout;
}
void Transactions::wrt(ostream& fout)const {
	Node* temp1 = fromAccount;
	Node* temp2 = toAccount;
	int count = 0;
	//fout << "From Account\t " << "ToAccount\t " << "Amount " << endl;
	while (temp1 != nullptr) {
		fout << temp1->getValue() << "," << temp2->getValue() << "," << amount[count] << endl;
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
		count++;
	}
}