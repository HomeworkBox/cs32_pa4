//
//  dynb.h
//  pa4x
//
//  Created by TF: Tyler Weimin Ouyang & Felicia Truong on 8/27/14.
//  Copyright (c) 2014 TF: Tyler Weimin Ouyang & Felicia Truong. All rights reserved.
//

#ifndef __DYNB_H__
#define __DYNB_H__

#include <string>

/*
	We do not use virtual functions in this assignment and we do
	not implement a "virtual" destructor ourselves as well. Thus,
	there will be a memory leaks caused by strings in derived
	classes. You do not need to fix these leaks in this part of the
	assignment.
*/

using std::string;

class Student;

typedef void (Student::*printer_t)();

struct vtbl_t {
	vtbl_t *_pbase;
	printer_t _print_classname;
	printer_t _print_state;

	vtbl_t(vtbl_t *pbase, printer_t print_classname, printer_t print_state)
		: _pbase(pbase),
		  _print_classname(print_classname),
		  _print_state(print_state) {
	}
};

class Student {
protected:
	vtbl_t *_pvtbl;
private:
	string _name;
	time_t _dob;
public:
	Student();
	Student(string name, time_t dob);
	void print();
	void print_classname();
	void print_state();
};

class CollegeStudent : public Student {
private:
	string _perm;
public:
	CollegeStudent();
	CollegeStudent(string name, time_t dob, string perm);
	void print_classname();
	void print_state();
};

#endif // __DYNB_H__
