#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	Node() {
		value = nullptr;
		next = nullptr;
	}
	Node( char * );
	void setValue(char*);
	Node(const Node&);
	Node* getNext() { return next; }
	void setNext(Node* _next) { next = _next; }
	char* getValue();
	void wrt(ostream & )const;
	void input(istream&);
	bool operator ==( Node&);
	~Node();
private:
	char* value;
	Node* next;

};
ostream& operator<<(ostream&, const Node&);
istream& operator>>(istream&, Node&);





