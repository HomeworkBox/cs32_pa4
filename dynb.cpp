// This implementation of dynamic dispatch is not how it is implemented
// in contemporary C++ compilers. We are using only one pointer to a virtual
// table, and the price we pay for it is that, from time to time, we have
// to change this pointer to point to different virtual tables, which is
// necessary to support calling base implementations

#include <iostream>
#include <string>
#include <ctime>
#include "dynb.h"

#define CALL_MEMBER_BY_PTR(obj, member_ptr) ((obj).*(member_ptr))
#define SET_VTBL(current_vtbl) this->_pvtbl = &current_vtbl; vtbl_t *__temp_pvtbl = this->_pvtbl
#define RESTORE_VTBL this->_pvtbl = __temp_pvtbl

using namespace std;

// Defining vtbls

static vtbl_t student_vtbl(
	NULL,
	&Student::print_classname,
	&Student::print_state
);

static vtbl_t college_student_vtbl(
	&student_vtbl,
	(printer_t)&CollegeStudent::print_classname,
	(printer_t)&CollegeStudent::print_state
);

// Defining classes Student, CollegeStudent (and, in future, CollegeGraduate)

Student::Student()
	: _name(""), _dob(0) {
	_pvtbl = &student_vtbl;
}

Student::Student(string name, time_t dob)
	: _name(name), _dob(dob) {
	_pvtbl = &student_vtbl;
}

void Student::print() {
	//
	// Parts of behavior of Student and its derived classes will
	// be defined through a table of "virtual" functions. This table
	// will contain pointers to different functions, depending on
	// which class we are dealing with.
	//
	SET_VTBL(*this->_pvtbl);
	CALL_MEMBER_BY_PTR(*this, _pvtbl->_print_classname)();
	RESTORE_VTBL;
	cout << " { ";
	CALL_MEMBER_BY_PTR(*this, _pvtbl->_print_state)();
	RESTORE_VTBL;
	cout << " }\n";
}

void Student::print_classname() {
	cout << "Student";
}

void Student::print_state() {
	cout << "name = " << _name << ", dob = " << _dob;
}

CollegeStudent::CollegeStudent()
	: Student(), _perm("") {
	_pvtbl = &college_student_vtbl;
}

CollegeStudent::CollegeStudent(string name, time_t dob, string perm)
	: Student(name, dob), _perm(perm) {
	_pvtbl = &college_student_vtbl;
}

void CollegeStudent::print_classname() {
	cout << "CollegeStudent";
}

void CollegeStudent::print_state() {
	SET_VTBL(college_student_vtbl);
	CALL_MEMBER_BY_PTR(*this, _pvtbl->_pbase->_print_state)();
	RESTORE_VTBL;
	cout << ", perm = " << _perm;
}
