#include <iostream>
#include"Header.h"
#include"Student.h"

using namespace std;

void ViewEnrollList(Course* pEnrollCourse){
	while(pEnrollCourse != nullptr){
		cout << pEnrollCourse->id << endl;
		cout << pEnrollCourse->name << endl;
		cout << pEnrollCourse->lecturerName << endl;
		cout << pEnrollCourse->numberOfCredits << endl;
		cout << endl;
		pEnrollCourse = pEnrollCourse->courseNext;
	}
}
