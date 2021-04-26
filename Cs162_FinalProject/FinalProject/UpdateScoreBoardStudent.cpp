#include<iostream>
#include<fstream>
#include<string>
#include"Staff.h"
#include"Header.h"

using namespace std;

void UpdateScoreBoardStudent(Scoreboard * & pScr, char* studentID){
	while(pScr != nullptr && strcmp(pScr->stu->studentID, studentID) != 0){
		pScr = pScr-> scoreboardNext;
	}	
	
	if(pScr != nullptr){
		cout << "Update Score:" << endl;
		cout << "Midterm: "; cin >> pScr->midterm << endl;
		cout << "Final: "; cin >> pScr->final << endl;
		cout << "Bonus: "; cin >> pScr->bonus << endl;
		cout << "Total: "; cin >> pScr->total << endl;
	}else{
		cout << "Student ID not found." << endl;
	}
}


