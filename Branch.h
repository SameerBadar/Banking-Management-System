#pragma once
#include<iostream>
//#include"util.h"
using namespace std;
class Branch
{
public:
	Branch() :branchName() { branchName = nullptr; }
	Branch(char*);
	void setBranchName(Node * );
	Node* getBranchName() { return branchName; }
	Branch(const Branch&);
	void wrt(ostream&)const;
	void input(istream&);
	bool operator == (Branch&);

private:
	
	Node* branchName;
};
ostream& operator<<(ostream&, const Branch&);
istream& operator>>(istream&, Branch&);

