#include <iostream>
#include <fstream>
#include <string.h>
#include "Staff.h"
#include "Header.h"

using namespace std;

void inputScoreboardCSV(Scoreboard *& newScr , char *s) {
	int t = 0, n = strlen(s);
	char *cur = new char[505]; 
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == ',') {
			if (i == n - 1)
				cur[pos++] = s[i];
			cur[pos] = '\0';
			if (t == 0) {
				newScr -> stu = new Student;
			}
			else if (t == 1) {
				newScr -> stu -> studentID = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newScr -> stu -> studentID[j] = cur[j];
				newScr -> stu -> studentID[pos] = '\0';					
			} 
			else if (t == 2) {
				newScr -> stu -> Name = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newScr -> stu -> Name[j] = cur[j];
				newScr -> stu -> Name[pos] = '\0';
			}
			else if (t == 3) {
				newScr -> midterm = atof(cur);
			}
			else if (t == 4) {
				newScr -> final = atof(cur); 
			}
			else if (t == 5) {
				newScr -> bonus = atof(cur); 
			}else if(t == 6) {
				newScr -> total = atof(cur);
			}
			t++;
			pos = 0;
		}
		else 
			cur[pos++] = s[i];
	} 
	delete[] cur;
}


void addScoreBoardCSV(Scoreboard *& pScore, char* yearName, char* semesterName, char* courseName) {
	char dirOut[] = { "C:\\Github\\CS162FinalProject\\Data\\" };

	/* The course has already been chosen in courseName so we don't need this part
	char d[505] = "";
	strcat(d, dirOut);
	strcat(d, yearName);
	strcat(d, "\\Semester\\");
	strcat(d, semesterName);
	strcat(d, "\\");
	strcat(d, "Course.txt");

	ifstream fin;
	
	fin.open(d);
	if(!fin.is_open()){
		cout << "Error at open Course.txt" << endl;
		return;
	}else{
		system("cls");
		cout << ">>Course: " << endl;
		int n;
		fin >> n;
		for(int i = 0; i < n; i++){
			char tcourse[20];
			fin.ignore(100, '\n');
			fin.get(tcourse, 20, '\n');
			cout << "[" << i+1 << "] " << tcourse << endl;
		}
		cout << "Please input a course: ";
		char mycourse[20];
		cin.ignore(100, '\n');
		cin.get(mycourse, 20, '\n'); 
	}
	fin.close();
	*/
	
	char dc[201] = "";
	strcat(dc, courseName);
	strcat(dc, ".txt");
	
	char ddd[505] = "";
	strcat(ddd, dirOut);
	strcat(ddd, yearName);
	strcat(ddd, "\\Semester\\");
	strcat(ddd, semesterName);
	strcat(ddd, "\\");
	strcat(ddd, courseName);
	strcat(ddd, "\\");
	strcat(ddd, "Scoreboard.txt");

	ofstream fOut(ddd);

	char dirIn[] = { "C:\\Github\\CS162FinalProject\\Data\\Scoreboard_csv\\" };
	char dd[505] = "";
	strcat(dd, dirIn);
	strcat(dd, courseName);
	strcat(dd, ".csv");


	ifstream fIn(dd);

	if (!fIn.is_open()) {
		cout << "Cannot locate the file\n";
		system("pause");
		system("cls");
		return;
	}

	char* s = new char[505];
	while (fIn.getline(s, 505)) {
		Scoreboard *newScr = new Scoreboard;
	    inputScoreboardCSV(newScr, s);
	
		if (pScore == nullptr)
			pScore = newScr;
		else {
			Scoreboard* pCur = pScore;
			while (pCur -> scoreboardNext != nullptr)
				pCur = pCur -> scoreboardNext;
			pCur -> scoreboardNext = newScr;
		}
	}

	Scoreboard *pCur = pScore;
	int cnt = 0;
	while (pCur != nullptr) {
		fOut << ++cnt << ',' << pCur -> stu -> studentID << ',' << pCur -> stu -> Name << ',' << pCur -> midterm << ',' << pCur -> final << ',' << pCur -> bonus << ',' << pCur -> total << '\n';
		pCur = pCur -> scoreboardNext;
	}
	fOut.close();
	delete[] s;
}