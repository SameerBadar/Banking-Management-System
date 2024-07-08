#include<iostream>
#include<fstream>
#include "util.h"
using namespace std;
char* copyData(char* copyFrom, char* copyIn) {
int l =findLength(copyFrom);
if (l >0 ) {
	copyIn = new char[l + 1];
	copyIn[l] = '\0';
	for (int i = 0; i < l; i++) {
		copyIn[i] = copyFrom[i];
	}
	return copyIn;
}
return nullptr;
}
int findLength(char*arr) {
	int l = 0;
	if (arr != nullptr) {
		for (int i = 0; arr[i] != '\0'; i++) {
			l++;
		}
		return l;
	}
	return -1;

}
bool compareString(char* data1, char* data2) {
	
	int l1 = findLength(data1);
	int l2 = findLength(data2);
	//Here ca
	//l2 -= 1;
	if (l1 == l2) {
		
		int l3 = 0;
		for (int i = 0; i<l1; i++) {
		
			if (data1[i] == data2[i]) {
				l3++;
			}
		}
		if (l1 == l3 && l2 == l3) {
			return true;
		}
	}

	
	return false;
	
}
int findTotalNodes(Node* current) {
	int l = 0;
	while (current != nullptr) {
		l++;
		current = current->getNext();
	}
	return l;
}
int* singlePointerCopy(int* arr, Node* Top) {
	int l = findTotalNodes(Top);
	int* newArr = new int[l];
	for (int i = l - 1; i > 0; i--) {
		newArr[i] = arr[i - 1];
	}
	delete[] arr;
	arr = nullptr;
	return newArr;
}
bool checkIfStringExist(Node* temp, Node* current) {
	while (current != nullptr) {
		if (compareString(temp->getValue(), current->getValue()) == true) {
			return true;
		}
		current = current->getNext();
	}
	return false;
}

Node* readAccountNumbers(Node* accountNumber) {
	ifstream fin;
		int num = 0;
	fin.open("count.txt");
	if (!fin.is_open()) {
		cout << "Count File Not Found " << endl;
		return nullptr;
	}
	else {
		fin >> num;
	}
	fin.close();
	fin.open("accountNumber.txt");
	if (!fin.is_open()) {
		cout << "AccountNumber File Not Found " << endl;
		return nullptr;
	}
	else {
		fin.ignore();
		char* tempArr = new char[20+1];
		tempArr[20] = '\0';
		for (int i = 0; i <= num; i++) {
			if (i == num) {
				if (accountNumber == nullptr) {
					fin.getline(tempArr, 20);
					accountNumber = new Node(tempArr);
				}
				else {
					fin.getline(tempArr, 20);
					Node* temp = new Node(tempArr);
					temp->setNext(accountNumber);
					accountNumber = temp;
				}
			}
			else {
				fin.getline(tempArr,20);
			}
		}
	}
	fin.close();
	num += 1;
	ofstream fout;
	fout.open("count.txt");
	if (num == 100) {
		num = 0;
		fout << num << endl;
	}
	else {
		fout << num << endl;
	}
	fout.close();
	return accountNumber;
}

int findAccountIndex(Node* value, Node* head) {
	
	int count = 0;
	while (head != nullptr) {
		char* temp1 = value->getValue();
		char* temp2 = head->getValue();
		
		if (compareString(temp1, temp2) == true) {
			return count;
		}
		count++;
		head = head->getNext();
	}
	}

Node* getSpecificNode(Node* top, int index) {
	int count = 0;
	while (top != nullptr && count < index) {
		top = top->getNext();
		count++;
	}
	return top;
}
int findIndexForSpace(char* arr, int index) {
	for (int i = index; arr[i] != '\0'; i++) {
		if (arr[i] == ',') {
			return i; // means there is a space
		}
	}
	return -1;
}

int findIndexForCharacters(char*arr, int index) {
	for (int i = index; arr[i] != '\0'; i++) {
		if (arr[i] >= '0' && arr[i] <= '9' || arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z') {
			return i;
		}
	}
	return -1;
}


char* copyData(char* arr, int startIndex, int endIndex) {
int  l =findLength(arr, startIndex, endIndex);
char* newArr = new char[l + 1];
newArr[l] = '\0';
for (int i = startIndex, count = 0; i < endIndex; i++) {
	if (arr[i] != ',') {
	newArr[count] = arr[i];
	count++;
	}
}
return newArr;
}


int findLength(char* arr, int startIndex, int endIndex) {
	int l = 0;
	for (int i = startIndex; i < endIndex; i++) {
		
		if (arr[i] != ',') {
		l++;
		
		}
		
	}
	return l;
}
