#include <iostream>
#include"Header.h"
#include"Course.h"
#include"Staff.h"
#pragma warning(disable : 4996)

using namespace std;

int main() {
	//Testing
	Year* pHead = nullptr;
	int n = 0;
	char Tmp[101];
	cin >> Tmp;
	int len = strlen(Tmp);
	char* year = new char[len + 1];
	strcpy(year, Tmp); 
	
	Create_New_Year(pHead, n, year);
}
