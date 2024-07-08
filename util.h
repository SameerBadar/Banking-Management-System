#include"Node.h"
static int count = 0;
char* copyData(char*, char*);
int findLength(char*);
bool compareString(char*, char*);
int findTotalNodes(Node*);
int* singlePointerCopy(int*,Node * );
bool checkIfStringExist(Node*, Node*);
bool checkSpecialSymbols(Node*);
Node* readAccountNumbers(Node*);
int findAccountIndex(Node*, Node*);
Node * getSpecificNode(Node * ,int);
int findIndexForSpace(char*, int);
int findIndexForCharacters(char*, int);
char* copyData(char*, int, int);
int findLength(char*, int, int);