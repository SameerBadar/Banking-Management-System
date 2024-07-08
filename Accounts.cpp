#include<iostream>
#include<fstream>
#include"util.h"
#include"Node.h"
#include "Accounts.h"
using namespace std;
void Accounts::createAccount() {
	cout << "Enter Your Name : ";
	if (name == nullptr) {
		name = new Node();
		cin >> (*name);
	}
	else {
		Node * temp = new Node();
		cin >> (*temp);
		temp->setNext(name);
		name = temp;
	}
	cout << "\t\t				@yahoo or @gmail" << endl;
	cout << "Enter Your Email : ";
	if (email == nullptr) {
		email = new Node();
		cin >> (*email);
	}
	else {
		Node* temp = new Node();
		cin >> (*temp);
		if (checkIfStringExist(temp, email)) {
			cout << "This Email Already Exist " << endl;
			cout << "Please Try Again " << endl;
			cout << "Enter Your Email : ";
			delete temp;
			temp = new Node();
			cin >> (*temp);
			int count = 2;
			while (checkIfStringExist(temp, email)==true) {
				if (count == 0) {
					cout << "\t\tTry Again Later " << endl;
					Node* temp1 = name;
					name = name->getNext();
					temp1->setNext(nullptr);
					delete temp1;
					return;
				}
				cout << "Please Try Again " << endl;
				cout << "Enter Your Email : ";
				delete temp;
				temp = new Node();
				cin >> (*temp);
				count--;
			}
			cout << endl;
			cout << "Email Verified " << endl;
			temp->setNext(email);
			email = temp;
			cout << endl;
		} else{
			cout << endl;
			cout << "Email Verified " << endl;
			temp->setNext(email);
			email = temp;
		}
	}
	if (password == nullptr) {
		password = new Node();
		cout << endl;
		cout << "Make Sure To Include Symbols For A Secure Password " << endl;
		cout << "Enter Your Password " << endl;
		cin >> (*password);
	char * ptr=password->getValue();
	int lenght = findLength(ptr);
	if (lenght < 8) {
		cout << "Password Is To Small " << endl;
		int count = 3;
		while (lenght < 8) {
			if (count == 0) {
				cout << endl;
				cout << "Try Again Later " << endl;
				Node* temp1 = email;
				email = email->getNext();
				temp1->setNext(nullptr);
				delete temp1;
				temp1 = name;
				name = name->getNext();
				temp1->setNext(nullptr);
				delete temp1;
				cout << endl;
				return;
			}
			delete password;
			password = new Node();
			cout << "Enter PassWord Again " << endl;
			cin >> (*password);
			ptr = password->getValue();
			lenght = findLength(ptr);
			count--;
		}
	}
	}
	else {
		Node* temp = new Node();
		cout << endl;
		cout << "Make Sure To Include Symbols For A Secure Password " << endl;
		cout << "Enter Your Password " << endl;
		cin >> (*temp);
		char* ptr = temp->getValue();
		int lenght = findLength(ptr);
		int count = 3;
		if (lenght < 8) {
			while (lenght < 8) {
			if (count == 0) {
				cout << endl;
				cout << "Try Again Later " << endl;
				cout << endl;
				return;
			}
			delete temp;
			temp = new Node();
			cout << "Enter PassWord Again " << endl;
			cin >> (*temp);
			ptr = temp->getValue();
			lenght = findLength(ptr);
			count--;
			}
		}
		temp->setNext(password);
		password = temp;
	}
	if (idCard == nullptr) {
		cout << "Enter Your Id Card Number " << endl;
		idCard = new Node();
		cin >> (*idCard);
		int length = findLength(idCard->getValue());
		if (length > 15 || length<14) {
			cout << "Id Card Size Can only Be Of Size 15 " << endl;
			int count = 3;
			while (length > 15 ||length <14) {
				if (count == 0) {
					cout << "Try Again Later " << endl;
					return;
				}
			cout << "Please Try Again " << endl;
				delete idCard;
				idCard = new Node();
				cin >> (*idCard);
			length=findLength(idCard->getValue());
				count--;
			}	
		}
	}
	else {
		cout << "Enter Your Id Card Number " << endl;
		Node* temp = new Node();
		cin >> (*temp);
		int length = findLength(temp->getValue());
		int count = 3;
		if (length > 15 ||length<14) {
			while (length > 15 || length<14) {
				if (count == 0) {
					cout << "Try Again Later " << endl;
					Node* temp1 = name;
					name = name->getNext();
					temp1->setNext(nullptr);
					delete temp1;
					temp1 = email;
					email = email->getNext();
					temp1->setNext(nullptr);
					delete temp1;
					temp1 = password;
					password = password->getNext();
					temp1->setNext(nullptr);
					delete temp1;
					return;
				}
				cout << "Please Try Again " << endl;
				delete temp;
				temp = new Node();
				cin >> (*temp);
				length = findLength(temp->getValue());
				count--;
			}
		}
			if (checkIfStringExist(temp, idCard)) {
				cout << "This IdCard Already Exist " << endl;
				//cin >> (*temp);
				int count = 3;
				while (checkIfStringExist(temp, idCard) == true) {
					if (count == 0) {
						cout << "\t\tTry Again Later " << endl;
						Node* temp1 = name;
						name = name->getNext();
						temp1->setNext(nullptr);
						delete temp1;
						temp1 = email;
						email = email->getNext();
						temp1->setNext(nullptr);
						delete temp1;
						temp1 = password;
						password = password->getNext();
						temp1->setNext(nullptr);
						delete temp1;
						return;
					}
					cout << "Please Try Again " << endl;
					cout << "Enter Your IdCard : ";
					delete temp;
					temp = new Node();
					cin >> (*temp);
					count--;
				}
				cout << endl;
				cout << "IdCard Verified " << endl;
				temp->setNext(idCard);
				idCard = temp;
				cout << endl;

			}
			else {
				cout << "IdCard Verified " << endl;
				temp->setNext(idCard);
				idCard = temp;
			}
		
		
	}
	if (amount == nullptr) {
		amount = new int [1];
	}
	else {
		amount = singlePointerCopy(amount, name);
	}
	cout << "Your Account Has Been SuccessFully Created " << endl;
	accountNumber = readAccountNumbers(accountNumber);
	cout << "Here Is Your Account Number : "<<accountNumber->getValue() << endl;
}

void Accounts::loginAccount() {
	Node* emailNode = new Node();
	Node* passwordNode = new Node();

	cout << "Enter Your Email : ";
	cin >> (*emailNode);
	
	if (checkIfStringExist(emailNode, email) == true) {
		cout << "Enter Password : ";
		cin >> (*passwordNode);
		int n = findAccountIndex(emailNode, email);
		Node* tempPassword = getSpecificNode(password, n);
		if (checkIfStringExist(passwordNode, tempPassword)) {
			cout << "Your Account Has Been Successfully Logged In" << endl;
			//int n = findAccountIndex(passwordNode, password);
			cout << "N is : " << n << endl;
			displayGrid(n);
		}
		else {
			int attempts = 3;
			while (attempts > 0 && !checkIfStringExist(passwordNode, tempPassword)) {
				cout << "Password Incorrect" << endl;
				cout << "Try Again (" << attempts << " attempts left)" << endl;

				cin >> (*passwordNode);
				attempts--;
			}

			if (attempts == -1) {
				cout << "Maximum attempts reached. Exiting." << endl;
			}
			else {
				cout << "Account Login Successful" << endl;
				//int n = findAccountIndex(passwordNode, password);
				cout << "N is : " << n << endl;
				displayGrid(n);
			}
		}
	}
	else {
		cout << "Email Not Found" << endl;
	}

	delete emailNode;
	delete passwordNode;
}


	/*
void Accounts::loginAccount() {
	
	
	Node* temp1 = new Node();
	int n = 0;
	cout << "Enter Your Email : ";
	cin >> (*temp1);
	if (checkIfStringExist(temp1, email) == true) {
		cout << "Enter Password : ";
		delete temp1;
		temp1 = new Node();
		cin >> (*temp1);
		if (checkIfStringExist(temp1, password) == true) {
			cout << "Your Account Has Been SuccessFully Login " << endl;
			 n = findAccountIndex(temp1, password);
			 cout << "N iS : " << n << endl;
			 displayGrid(n);
		}
		else {
			int count = 3;
			while (checkIfStringExist(temp1, password) != true) {
				if (count == 0) {
					return;
				}
				cout << "Password InCorrect " << endl;
				cout << "Try Again \t\t" << count << "Attempts" << endl;
				delete temp1;
				temp1 = new Node();
				cin >> (*temp1);
				count--;
			}
			cout << "Account Login " << endl;
		int n=findAccountIndex(temp1, password);
		cout << "N iS : " << n << endl;
		displayGrid(n);
		}
		//displayGrid(n);
	}
	else {
		cout << "Email Not Found " << endl;
	}
}
	*/

void Accounts::withDraw(int index) {
	int x = 0;
	cout << endl;
	cout << "Enter Valid Amount " << endl;
	cin >> x;
	if (x <= 0) {
		int count = 3;
		while (x <= 0) {
			if (count == 0) {
				cout << "Try Again Later " << endl;
				return;
			}
			cout << "Attempts Left\t\t" << count << endl;
			cout << "Enter Valid Amount " << endl;
			cin >> x;
			count--;
		}
	}
	int result = amount[index] - x;
	if (result < 0) {
		int count = 3;
		while (result < 0) {
			if (count == 0) {
				cout << "Try Again Later " << endl;
				return;
			}
			cout << "You Dont Have This Much Amount " << endl;
			cout << "Attempts Left\t\t" << count << endl;
			cout << "Please Try Again " << endl;
			cin >> x;
			result = amount[index] - x;
		}
	}
	amount[index] = result;
	
}
/*
void Accounts::transfer(int index) {
	int x = 0;
	cout << "Enter Amount : ";
	cin >> x;
	if (x <= 0) {
		int count = 3;
		while (x <= 0) {
			if (count == 0) {
				cout << "Try Again Later " << endl;
				return;
			}
			cout << "Attempts Left " << count << endl;
			cout << "Enter Valid Amount : ";
			cin >> x;
		}
	}
	int transferResult = amount[index] - x;
	if (transferResult < 0) {
		int count = 3;
		while (transferResult < 0) {
			if (count == 0) {
				cout << "Try Again Later" << endl;
				return;
			}
			cout << "Attempts Left : " << count << endl;
			cout << "Enter Valid Amount : ";
			cin >> x;
			transferResult = amount[index] - x;
		}
	}
	amount[index] = transferResult;
	cout << "Enter Account Number " << endl;
	Node* temp = new Node();
	cin.ignore();
	cin >> (*temp);
	if (checkIfStringExist(temp, accountNumber) == true) {
		transferInfo.setToAccount(temp);
		Node* temp2 = getSpecificNode(accountNumber, index);
		transferInfo.setFromAccount(temp2);
		int n = findAccountIndex(temp, accountNumber);
		transferInfo.setAmount(x);
		
		//here latest changes are made
		if (amount[n] < 0) {
			amount[n] = 0;
		}
		
		amount[n] += transferResult;
		cout << endl;
		cout << "Amount Has Been SuccessFully Transfer " << endl;
		cout << endl;
	}
	else {
		cout << "Account Does Not Exist " << endl;
		cout << "Try Again Later " << endl;
	}
}

*/

void Accounts::transfer(int index) {
	int x = 0;
	cout << "Enter Amount : ";
	cin >> x;
	if (x <= 0) {
		int count = 3;
		while (x <= 0) {
			if (count == 0) {
				cout << "Try Again Later " << endl;
				return;
			}
			cout << "Attempts Left: " << count << endl;
			cout << "Enter Valid Amount : ";
			cin >> x;
			count--;
		}
	}
	int transferResult = amount[index] - x;
	if (transferResult < 0) {
		int count = 3;
		while (transferResult < 0) {
			if (count == 0) {
				cout << "Try Again Later" << endl;
				return;
			}
			cout << "Attempts Left : " << count << endl;
			cout << "Enter Valid Amount : ";
			cin >> x;
			transferResult = amount[index] - x;
			count--;
		}
	}
	amount[index] -= x; // Update the source account's balance
	cout << "Enter Account Number: ";
	Node* temp = new Node();
	cin.ignore();
	cin >> (*temp);
	if (checkIfStringExist(temp, accountNumber) == true) {
		transferInfo.setToAccount(temp);
		Node* temp2 = getSpecificNode(accountNumber, index);
		transferInfo.setFromAccount(temp2);
		int n = findAccountIndex(temp, accountNumber);
		transferInfo.setAmount(x);

		// here latest changes are made
		if (amount[n] < 0) {
			amount[n] = 0;
		}

		amount[n] += x; // Add the transferred amount to the destination account
		cout << endl;
		cout << "Amount Has Been Successfully Transferred" << endl;
		cout << endl;
		ofstream fout;
		fout.open("transactions.txt",ios::app);
		fout << transferInfo;
		fout.close();
	
	}
	else {
		cout << "Account Does Not Exist" << endl;
		cout << "Try Again Later" << endl;
		return;
	}
}


void Accounts::deposit(int index) {
	int x = 0;

	Node* temp = getSpecificNode(accountType, index);
	char* data1 = accountType->getValue();
	char data2[] = "Buisness Account";
	if (compareString(data1, data2) == true) {
		cout << "Enter Valid Amount : ";

		cin >> x;
		if (x <= 0) {
			int count = 3;
			while (x <= 0) {
				if (count == 0) {
					cout << "Try Later " << endl;
					return;
				}
				cout << "Amount Should Above 0 ";
				cin >> x;
				count--;
			}
		}
		amount[index] += x;

	}

	char tempData[] = "Personal Account";
	if (compareString(data1, tempData) == true) {
		cout << "Your Maximum Deposit Can Be RS 10 Lakh " << endl;
		cout << "Enter Amount : ";
		cin >> x;
		if (x <= 0 || x > 1000000) {
			int count = 3;
			while (x <= 0 || x > 1000000) {
				if (count == 0) {
					cout << "Try Later " << endl;
					return;
				}
				cout << "Enter Valid Amount : ";
				cin >> x;
				count--;
			}
		}

		amount[index] += x;

	}

}
void Accounts::setPassword(char* arr) {
	if (password == nullptr) {
		password = new Node(arr);
	}
	else {
		Node* temp = new Node(arr);
		temp->setNext(password);
		password = temp;
	}
}
void Accounts::setIdCard(char* arr) {
	if (idCard == nullptr) {
		idCard = new Node(arr);
	}
	else {
		Node* temp = new Node(arr);
		temp->setNext(idCard);
		idCard = temp;
	}
}
void Accounts::setAccountNumber(char* arr) {
	if (accountNumber == nullptr) {
		accountNumber = new Node(arr);
	}
	else {
		Node* temp = new Node(arr);
		temp->setNext(accountNumber);
		accountNumber = temp;
	}
}
void Accounts::setEmail(char* arr) {
	if (email == nullptr) {
		email = new Node(arr);
	}
	else {
		Node* temp = new Node(arr);
		temp->setNext(email);
		email = temp;
	}
}

void Accounts::setAccountType(char* arr) {
	if (accountType == nullptr) {
		accountType = new Node(arr);
	}
	else {
		Node* temp = new Node(arr);
		temp->setNext(accountType);
		accountType = temp;
	}
}
void Accounts::setAmount(int _amount) {
	if (amount == nullptr) {
		amount = new int[1];
		amount[0] = _amount;
	}
	else {
		amount = singlePointerCopy(amount, email);
		amount[0] = _amount;
	}
}
	/*
		char tempData[] = "Personal Account";
	if (compareString(data1, tempData) == true) {
		cout << "Your Maximum Deposit Can Be RS 10 Lakh " << endl;
		cout << "Enter Amount : ";
		cin >> x;
		if (x <= 0 || x > 1000000) {
			int count = 3;
			while (x <= 0 || x > 1000000) {
				if (count == 0) {
					cout << "Try Later " << endl;
					return;
				}
				cout << "Enter Valid Amount : ";
				cin >> x;
				count--;
			}
		}
		
			amount[index] += x;
		
	}
}
	*/

void Accounts::setName(char* arr) {
	if (name == nullptr) {
		name = new Node(arr);
	}
	else {
		Node* temp = new Node(arr);
		temp->setNext(name);
		name = temp;
	}
}
void Accounts::displayGrid(int index) {
	if (amount[index] < 0) {
		amount[index] = 0;
	}
	cout << endl;
	cout << endl;
	Node * temp = getSpecificNode(accountType, index);
	Node* branchTemp = getBranchName();
      branchTemp = getSpecificNode(branchTemp, index);
	int opt = 0;
	while (opt!=6) {
		cout << endl;
		cout <<"BranchName\t\t\t"<<"Account Type" << "\t\t\t""Amount" << endl;
		cout <<branchTemp->getValue()<<"\t\t\t" << temp->getValue() << "\t\t\t" << amount[index] << endl;
		cout << endl;
		cout << endl;
		cout << "Press 1 To Deposit Amount " << endl;
		cout << "Press 2 To WithDraw Amount " << endl;
		cout << "Press 3 To Transfer Amount " << endl;
		cout << "Press 4 To View Account Info " << endl;
		cout << "Press 5 To View Transfer Record " << endl;
		cout << "Press 6 To Return  " << endl;
		cout << "Enter Option : ";
		cin >> opt;
		if (opt == 1) {
			cout << endl;
			deposit(index);
		}
		if (opt == 2) {
			cout << endl;
			withDraw(index);
		}
		if (opt == 3) {
			cout << endl;
			transfer(index);
		}
		if (opt == 4) {
			cout << endl;
			cout << endl;
			accountInfo(index);
			//cout << transferInfo << endl;
		}
		if (opt == 5) {
			cout << endl;
			cout << endl;
			transferRecords(index);
		}
	}
	
	/*
	Node* temp1 = name;
	Node* temp2 = email;
	Node* temp3 = password;
	Node* temp4 = idCard;
	Node* temp5 = accountNumber;
		cout << "Name\t\tEmail\t\tPassword" << endl;
	while (temp1 != nullptr) {
		if (temp1 != nullptr) {
			cout << temp1->getValue() << "\t\t";
	}
		else {
			cout << "Null" << endl;
		}
		if (temp2 != nullptr) {
			cout << temp2->getValue() << "\t\t";
		}
		else {
			cout << "Null" << endl;
		}

		if (temp3 != nullptr) {
			cout << temp3->getValue() << "\t\t";
		}
		else {
			cout << "Null" << endl;
		}

		if (temp4 !=nullptr) {
		cout<<temp4->getValue()<<"\t\t";
		}
		else {
			cout << "Null" << endl;
		}
		if (temp5 != nullptr) {
			cout << temp5->getValue() << endl;

		}
		else {
			cout << "Null" << endl;
		}

		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
		temp3 = temp3->getNext();
		temp4 = temp4->getNext();
		temp5 = temp5->getNext();
	}
	*/
}
ostream& operator<<(ostream& fout,  Accounts& obj) {
	obj.display(fout);
	return fout;
}
void Accounts::display(ostream & fout ) {
	Node* temp1 = nullptr;
	Node* temp2 = nullptr;
	Node* temp3 = nullptr;
	Node* temp4 = nullptr;
	Node* temp5 = nullptr;
	Node* temp6 = nullptr;
	int i = 0;
	temp1 = email;
	temp2 = password;
	temp3 = idCard;
	temp4 = accountNumber;
	temp5 = getBranchName();
	temp6 = accountType;
	Node* temp7 = name;
		
	if (temp1 == nullptr) {
		cout << "Data Is Not Set " << endl;
		return;
	}
	fout << "Email\t " << "Password\t " << "IDCard\t " << "AccountNumber\t " << "Amount\t " << "BranchName\t " << "Type\t " << "Name" << endl;
	while (temp1 != nullptr) {
		if (amount[i] < 0) { amount[i] = 0; }
		fout << temp1->getValue() << "," << temp2->getValue() << "," << temp3->getValue() << "," << temp4->getValue()<<"," << amount[i] << "," << temp5->getValue() << "," << temp6->getValue()<<","<<temp7->getValue() << endl;
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
		temp3 = temp3->getNext();
		temp4 = temp4->getNext();
		temp5 = temp5->getNext();
		temp6 = temp6->getNext();
		temp7 = temp7->getNext();
		i++;
	}
		
}


void Accounts::accountInfo(int index) {
	Node* tempName = getSpecificNode(name,index);
	Node* tempEmail = getSpecificNode(email, index);
	Node * tempId = getSpecificNode(idCard, index);
	Node* tempPassword = getSpecificNode(password, index);
	Node* tempAccountNumber = getSpecificNode(accountNumber, index);
	Node* tempAccountType = getSpecificNode(accountType, index);
	Node* tempBranch = Branch::getBranchName();
	cout << endl;
	cout << endl;
	
	cout << "Branch       : " << tempBranch->getValue() << endl;
	cout << "AccountType  : " << tempAccountType->getValue() << endl;
	cout << "Name         : " << tempName->getValue() << endl;
	cout << "Email        : " << tempEmail->getValue() << endl;
	cout << "Password     : " << tempPassword->getValue() << endl;
	cout << "AccountNumber: " << tempAccountNumber->getValue() << endl;
	cout << "TotalAmount  : " << amount[index] << endl;
	cout << "ID_Card      : " << tempId->getValue() << endl;
	cout << endl;
	cout << endl;	
}




void Accounts::transferRecords(int index) {
	ifstream fin;
	int l = 0;
	fin.open("transactions.txt");
	if (!fin.is_open()) {
		cout << "File Not Found " << endl;
	}
	else {
		char ch;
		while (fin.get(ch)) {
			if (ch == '\n') {
				l++;
			}
		}
	}
	fin.close();
	//ifstream fin;
	fin.open("transactions.txt");
	if (!fin.is_open()) {
		cout << "File Not Found " << endl;
	}
	else {
		int count = 0;
		Node* currentAccount = getSpecificNode(accountNumber, index);
		char* tempArr = currentAccount->getValue();
		Node* tempTo = nullptr;
		for (int i = 0; i <=l; i++) {
			if (i == 0) {
		int size = 100;
				char* temp = new char[size + 1];
				temp[size] = '\0';

				fin.getline(temp, size);
			}
			else {
				int size = 100;
				char* temp = new char[size + 1];
				temp[size] = '\0';
				fin.getline(temp, size,',');
				char* arr = nullptr;
				 arr = copyData(temp, arr);
				if (compareString(arr, tempArr) == true) {
					fin.getline(temp,size,',');
					//cout << temp << endl;
					
					arr = copyData(temp, arr);
					fin.getline(temp, size);
					//cout << temp << endl;
					char* temp2 = nullptr;
					 temp2 = copyData(temp, temp2);
					fin.ignore();
					//cout << arr << endl;
					//cout << amount << endl;
					//cout << temp2 << endl;
					//cout << "FromAccount\t\t " << "ToAccount\t\t " << "Amount " << endl;
					cout <<"ToAccount "<< "\t\t Amount   "<< endl;
					cout << arr << "\t\t" << temp2 << endl;
					count++;
				}
				else {
					//fin.ignore();
					//cout << "Im Here " << endl;
					fin.getline(temp, size, ',');
					arr = copyData(temp, arr);
					fin.getline(temp, size);
					char* temp2 = nullptr;
					temp2 = copyData(temp, temp2);

	//				int _x = 0;
		//			fin >> _x;
			//		fin.ignore();

				}
				
			}
		}if (count == 0) {
			cout << endl;
			cout << endl;
			cout << "No Records Found " << endl;
			cout << endl;
			cout << endl;
		}
	}
	fin.close();
}