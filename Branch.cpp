#include<iostream>
	#include"util.h"
#include"Node.h"
#include "Branch.h"
using namespace std;
Branch :: Branch(char * _value)
{
	if (branchName == nullptr) {
	Node* temp = new Node(_value);
	branchName = temp;
	}
	else {
		cout << "Cant Fill More Nodes From Here " << endl;
	}
}
void Branch::setBranchName(Node * _branchName) {
	
	branchName = _branchName;
}
Branch::Branch(const Branch & obj)
{
	branchName = obj.branchName;
}


bool Branch::operator==(Branch& obj) {
	Node* temp1 = branchName;
	Node* temp2 = obj.branchName;
	int temp1Nodes = findTotalNodes(temp1);//Find length of Nodes
	int temp2Nodes = findTotalNodes(temp2);
	int noOfTrue = 0;
	if (temp1Nodes > temp2Nodes) {
		return false;
	}
	else if (temp2Nodes > temp1Nodes) {
		return false;
	}
	//calling Bool Operator on Node Class
	else if (temp1Nodes == temp2Nodes) {
		while (temp2 != nullptr) {
			if (temp1 == temp2) {
				noOfTrue++;
			}
			temp1 = temp1->getNext();
			temp2 = temp2->getNext();
		}
		if (noOfTrue == temp1Nodes && noOfTrue == temp2Nodes) {
			return true;
	}
	}
	
	return false;
}

ostream& operator<<(ostream& fout, const Branch& obj) {
	obj.wrt(fout);
	return fout;
}
void Branch::wrt(ostream& fout)const {
	if (branchName != nullptr) {
		Node* current = branchName;
		while (current != nullptr) {
			fout << (*current) << endl;
			current = current->getNext();
		}
	}
}
void Branch::input(istream& fin) {
	if (branchName == nullptr) {
	branchName = new Node();
	fin >> (*branchName);
}
	else {
		Node* temp = new Node();
		fin >> (*temp);
		temp->setNext(branchName);
		branchName = temp;
	}
}
istream& operator>>(istream& fin, Branch& obj) {
	obj.input(fin);
	return fin;
}
