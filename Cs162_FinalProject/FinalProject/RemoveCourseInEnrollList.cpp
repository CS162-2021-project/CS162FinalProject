#include<iostream>
#include"Header.h"
#include"Student.h"

using namespace std;

void RemoveCourseInEnrollList(Course* pEnrollCourse, Course* CourseID){
	while(pEnrollCourse!= nullptr && pEnrollCourse->courseNext->id != CourseID->id){
		pEnrollCourse = pEnrollCourse -> courseNext;
	}
	if(pEnrollCourse!= nullptr){
		Course* Tmp = pEnrollCourse->courseNext;
		pEnrollCourse->courseNext = pEnrollCourse->courseNext->courseNext;
		delete Tmp;
	}
}

