#include<iostream>
#include"util.h"
#include"Node.h"
#include"Branch.h"
#include"Transactions.h"
#include"Accounts.h"
#include<fstream>
void display(Accounts & );
Accounts readAccounts(Accounts & );
using namespace std;
int main() {
	Accounts account;
	display(account);
	return 0;
}


Accounts readAccounts(Accounts& accounts) {
	ifstream fin;
	int lengthOfLines = 0;
	fin.open("accounts.txt");
	if (!fin.is_open()) {
		cout << "File Not Found " << endl;
	}
	else {
		char ch;
		while (fin.get(ch)) {
			if (ch == '\n') {
				lengthOfLines++;
			}
		}
		//cout << lengthOfLines;
	}

	fin.close();
	fin.open("accounts.txt");
	for (int i = 0; i < lengthOfLines; i++) {
		if (i == 0) {
		int size = 200;
		char* temp = new char[size + 1];
		temp[size] = '\0';
		fin.getline(temp, size,'\n');
		//cout << temp << endl;
		}
		else {	
			int size = 200;
			char* temp = new char[size + 1];
			temp[size] = '\0';
			fin.getline(temp, size);
			int loc = findIndexForSpace(temp, 0);	
			char* newArr = copyData(temp, 0, loc);
			int l = 0;
			accounts.setEmail(newArr);
			int loc2 = findIndexForCharacters(temp, loc);
			loc = findIndexForSpace(temp, loc2);
			newArr = copyData(temp, loc2, loc);
				accounts.setPassword(newArr);
				loc2=findIndexForCharacters(temp, loc);
			loc = findIndexForSpace(temp, loc2);
			newArr = copyData(temp, loc2, loc);
			accounts.setIdCard(newArr);
			loc2 = findIndexForCharacters(temp, loc);
			loc = findIndexForSpace(temp, loc2);
			newArr = copyData(temp, loc2, loc);
			accounts.setAccountNumber(newArr);
			loc2 = findIndexForCharacters(temp, loc);
			loc = findIndexForSpace(temp, loc2);
			newArr = copyData(temp, loc2, loc);
			int amount = 0;
			for (int i = 0; newArr[i] != '\0'; i++) {
				if (newArr[i] >= '0' && newArr[i] <= '9') {
					amount = amount * 10 + (newArr[i] - '0');
				}
			}
			accounts.setAmount(amount);
			// Now Doing Coding For Attributes Which contains spaces such as BranchName accountType And Name
			loc2 = findIndexForCharacters(temp, loc);
			for (int i = loc2; temp[i] != '\0'; i++) {
				if (temp[i] == ',') {
					loc = i;
					break;
				}
			}
			newArr = copyData(temp, loc2, loc);
			Node* tempBranch = accounts.getBranchName();
			if (tempBranch == nullptr) {
				tempBranch = new Node(newArr);
				accounts.setBranchName(tempBranch);
			}
			else {
				Node* newTemp = new Node(newArr);
				newTemp->setNext(tempBranch);
				tempBranch = newTemp;
				accounts.setBranchName(tempBranch);
			}
			loc2 = findIndexForCharacters(temp, loc);
			for (int i = loc2; temp[i] != '\0'; i++) {
				if (temp[i] == ',') {
					loc = i;
					break;
				}
			}
			newArr = copyData(temp, loc2, loc);
			accounts.setAccountType(newArr);
			loc2 = findIndexForCharacters(temp, loc);
			for (int i = loc2; temp[i] != '\0'; i++) {
				if (temp[i + 1] == '\0') {
					loc = i + 1;
				}
			}
			newArr = copyData(temp, loc2, loc);
			accounts.setName(newArr);

			
		}
	}
	fin.close();
	return accounts;
}


void display(Accounts & obj) {
	int opt = 0;
	//Accounts obj;  // Create the Accounts object outside the loop
	obj = readAccounts(obj);
	do {
		cout << "Press 1 To Create Account " << endl;
		cout << "Press 2 To Login " << endl;
		cout << "Press 3 To Exit " << endl;
		cin >> opt;
		if (opt == 1) {
			int opt2 = 0;
			while (opt2 != 5) {
				cout << "Press 1 For MCB Bank " << endl;
				cout << "Press 2 For Al-Bakrah Bank " << endl;
				cout << "Press 3 For HBL Bank " << endl;
				cout << "Press 4 For UBL Bank " << endl;
				cout << "Press 5 To Return " << endl;
				cin >> opt2;

				if (opt2 == 1) {
					Node* tempBranch = obj.getBranchName();
					if (tempBranch == nullptr) {
						char tempArr[] = "MCB Bank";
						tempBranch = new Node(tempArr);
						obj.setBranchName(tempBranch);
						tempBranch = obj.getBranchName();

					}
					else {
						char tempArr[] = "MCB Bank";
						Node* temp2 = new Node(tempArr);
						temp2->setNext(tempBranch);
						tempBranch = temp2;
						obj.setBranchName(tempBranch);
					}

					int opt3 = 0;

					cout << "Press 1 For Personal Account " << endl;
					cout << "Press 2 For Business Account " << endl;
					cout << "Enter Your Choice " << endl;
					cin >> opt3;
					if (opt3 == 1) {
						Node* temp = obj.getAccountType();
						if (temp == nullptr) {
							char arr[] = "Personal Account";
							temp = new Node(arr);
							obj.setAccount(temp);
							//obj.createAccount();
						}
						else {
							char arr[] = "Personal Account";
							Node* temp2 = new Node(arr);
							temp2->setNext(temp);
							temp = temp2;
							obj.setAccount(temp);
						}
						cin.ignore();
						obj.createAccount();
						ofstream fout;
						fout.open("accounts.txt");
						fout << obj;
						fout.close();
						break;
					}
					if (opt3 == 2) {
						Node* temp = obj.getAccountType();
						if (temp == nullptr) {
							char arr[] = "Buisness Account";
							temp = new Node(arr);
							obj.setAccount(temp);
							//obj.createAccount();
						}
						else {
							char arr[] = "Buisness Account";
							Node* temp2 = new Node(arr);
							temp2->setNext(temp);
							temp = temp2;
							obj.setAccount(temp);
						}
						cin.ignore();

						obj.createAccount();
						ofstream fout;
						fout.open("accounts.txt");
						fout << obj;
						fout.close();
						break;
					}
				}
				else if (opt2 == 2) {
					Node* tempBranch = obj.getBranchName();
					if (tempBranch == nullptr) {
						char tempArr[] = "Al-Bakrah Bank";
						tempBranch = new Node(tempArr);
						obj.setBranchName(tempBranch);
					}
					else {
						char tempArr[] = "Al-Bakrah Bank";
						Node* temp2 = new Node(tempArr);
						temp2->setNext(tempBranch);
						tempBranch = temp2;
						obj.setBranchName(tempBranch);
					}

					int opt3 = 0;

					cout << "Press 1 For Personal Account " << endl;
					cout << "Press 2 For Business Account " << endl;
					cout << "Enter Your Choice " << endl;
					cin >> opt3;
					if (opt3 == 1) {
						Node* temp = obj.getAccountType();
						if (temp == nullptr) {
							char arr[] = "Personal Account";
							temp = new Node(arr);
							obj.setAccount(temp);
							//obj.createAccount();
						}
						else {
							char arr[] = "Personal Account";
							Node* temp2 = new Node(arr);
							temp2->setNext(temp);
							temp = temp2;
							obj.setAccount(temp);
						}
						cin.ignore();
						obj.createAccount();
						ofstream fout;
						fout.open("accounts.txt");
						fout << obj;
						fout.close();
						break;
					}
					if (opt3 == 2) {
						Node* temp = obj.getAccountType();
						if (temp == nullptr) {
							char arr[] = "Buisness Account";
							temp = new Node(arr);
							obj.setAccount(temp);
							//obj.createAccount();
						}
						else {
							char arr[] = "Buisness Account";
							Node* temp2 = new Node(arr);
							temp2->setNext(temp);
							temp = temp2;
							obj.setAccount(temp);
						}
						cin.ignore();

						obj.createAccount();
						ofstream fout;
						fout.open("accounts.txt");
						fout << obj;
						fout.close();
						break;
					}
				}
				else if (opt2 == 3) {
					Node* tempBranch = obj.getBranchName();
					if (tempBranch == nullptr) {
						char tempArr[] = "HBL Bank";
						tempBranch = new Node(tempArr);
						obj.setBranchName(tempBranch);
					}
					else {
						char tempArr[] = "HBL Bank";
						Node* temp2 = new Node(tempArr);
						temp2->setNext(tempBranch);
						tempBranch = temp2;
						obj.setBranchName(tempBranch);
					}

					int opt3 = 0;

					cout << "Press 1 For Personal Account " << endl;
					cout << "Press 2 For Business Account " << endl;
					cout << "Enter Your Choice " << endl;
					cin >> opt3;
					if (opt3 == 1) {
						Node* temp = obj.getAccountType();
						if (temp == nullptr) {
							char arr[] = "Personal Account";
							temp = new Node(arr);
							obj.setAccount(temp);
							//obj.createAccount();
						}
						else {
							char arr[] = "Personal Account";
							Node* temp2 = new Node(arr);
							temp2->setNext(temp);
							temp = temp2;
							obj.setAccount(temp);
						}
						cin.ignore();

						obj.createAccount();
						ofstream fout;
						fout.open("accounts.txt");
						fout << obj;
						fout.close();
						break;
					}
					if (opt3 == 2) {
						Node* temp = obj.getAccountType();
						if (temp == nullptr) {
							char arr[] = "Buisness Account";
							temp = new Node(arr);
							obj.setAccount(temp);
							//obj.createAccount();
						}
						else {
							char arr[] = "Buisness Account";
							Node* temp2 = new Node(arr);
							temp2->setNext(temp);
							temp = temp2;
							obj.setAccount(temp);
						}
						cin.ignore();

						obj.createAccount();
						ofstream fout;
						fout.open("accounts.txt");
						fout << obj;
						fout.close();
						break;
					}
				}
				else if (opt2 == 4) {
					Node* tempBranch = obj.getBranchName();
					if (tempBranch == nullptr) {
						char tempArr[] = "UBL Bank ";
						tempBranch = new Node(tempArr);
						obj.setBranchName(tempBranch);
					}
					else {
						char tempArr[] = "UBL Bank ";
						Node* temp2 = new Node(tempArr);
						temp2->setNext(tempBranch);
						tempBranch = temp2;
						obj.setBranchName(tempBranch);
					}
				}
				else if (opt2 == 5) {
				break;
				}

				int opt3 = 0;

				cout << "Press 1 For Personal Account " << endl;
				cout << "Press 2 For Business Account " << endl;
				cout << "Enter Your Choice " << endl;
				cin >> opt3;
				if (opt3 == 1) {
					Node* temp = obj.getAccountType();
					if (temp == nullptr) {
						char arr[] = "Personal Account";
						temp = new Node(arr);
						obj.setAccount(temp);
						//obj.createAccount();
					}
					else {
						char arr[] = "Personal Account";
						Node* temp2 = new Node(arr);
						temp2->setNext(temp);
						temp = temp2;
						obj.setAccount(temp);
					}
					cin.ignore();

					obj.createAccount();
					ofstream fout;
					fout.open("accounts.txt");
					fout << obj;
					fout.close();
					break;
				}
				if (opt3 == 2) {
					Node* temp = obj.getAccountType();
					if (temp == nullptr) {
						char arr[] = "Buisness Account";
						temp = new Node(arr);
						obj.setAccount(temp);
						//obj.createAccount();
					}
					else {
						char arr[] = "Buisness Account";
						Node* temp2 = new Node(arr);
						temp2->setNext(temp);
						temp = temp2;
						obj.setAccount(temp);
					}
					cin.ignore();

					obj.createAccount();
					ofstream fout;
					fout.open("accounts.txt");
					fout << obj;
					fout.close();
					break;
				}
			}
		}
		else if (opt == 2) {
			cin.ignore();
			obj.loginAccount();
			ofstream fout;
			fout.open("accounts.txt");
			fout << obj;
			fout.close();
		}
	} while (opt != 3);
}


