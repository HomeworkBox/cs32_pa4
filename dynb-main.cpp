//
//  dynb-main.cpp
//  pa4x
//
//  Created by TF: Tyler Weimin Ouyang & Felicia Truong on 8/27/14.
//  Copyright (c) 2014 TF: Tyler Weimin Ouyang & Felicia Truong. All rights reserved.
//
#include <iostream>
#include "dynb.h"

int main() {
	using std::cout;

	Student john("John Doe", 12311990);
	john.print();
	cout << "-------------------------\n\n";

	Student &jane = *(new CollegeStudent("Jane Doe", 11211989, "UC-12345"));
	jane.print();
	cout << "-------------------------\n\n";

	Student *pstudent = &jane;
	pstudent->print();
	cout << "-------------------------\n\n";

	//Student &bilbo = *(new CollegeGraduate("Bilbo Baggins", 2128506,
	//	"MiddleEarthUniversity-#24123", true));
	//bilbo.print();
	//cout << "-------------------------\n\n";

	//delete &bilbo;
	delete &jane;

	return 0;
}
