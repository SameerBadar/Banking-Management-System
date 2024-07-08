#include "Node.h"
#include<iostream>
#include"util.h"
using namespace std;
Node::Node( char* _value){
	
	setValue(_value);
}
void Node::setValue(char* _value) {
	if (value != nullptr) {
		delete [] value;
		value = nullptr;
	}
	value = copyData(_value, value);
	next = nullptr;
}
char* Node::getValue() {
	char* tempArr = nullptr;
tempArr=copyData(value, tempArr);
return tempArr;
}
Node::Node(const Node&obj) {
	if (obj.value != nullptr) {
		this->value = copyData(obj.value, this->value);
		this->next = obj.next;	
	}

}
Node ::~Node() {
	delete[] value;
	delete next;
}
void Node::wrt(ostream & fout)const {
	for (int i = 0; value[i] != '\0'; i++) {
		fout << value[i];
	}
}

ostream& operator<<(ostream& fout, const Node& obj) {
	obj.wrt(fout);
	return fout;
}

void Node::input(istream& fin) {
	int size = 30;
	char* tempArr = new char[size + 1];
	tempArr[size] = '\0';
	cin.getline(tempArr, size);
value=copyData(tempArr, value);
}
istream& operator>>(istream& fin, Node& obj) {
	obj.input(fin);
	return fin;
}
bool Node::operator==( Node& obj) {
	if (compareString(this->value, obj.value) == true) {
		if (this->next == obj.next) {
			return true;
		}
		return false;
}
	return false;
	
}