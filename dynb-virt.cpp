#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Student {
private:
	string _name;
	time_t _dob;
public:
	Student()
		: _name(""), _dob(0) {
	}
	Student(string name, time_t dob)
		: _name(name), _dob(dob) {
	}
	virtual ~Student() { } // <-- Figure out why we need an empty virtual dtor
	void print() const {
		print_classname();
		cout << " { ";
		print_state();
		cout << " }\n";
	}
protected:
	void print_classname() const {
		cout << "Student";
	}
	void print_state() const {
		cout << "name = " << _name << ", dob = " << _dob;
	}
};

class CollegeStudent : public Student {
private:
	string _perm;
public:
	CollegeStudent()
		: Student(), _perm("") {
	}
	CollegeStudent(string name, time_t dob, string perm)
		: Student(name, dob), _perm(perm) {
	}
protected:
	void print_classname() const /*override*/ {
		cout << "CollegeStudent";
	}
	void print_state() const /*override*/ {
		Student::print_state();
		cout << ", perm = " << _perm;
	}
};

int main() {
	Student john("John Doe", 12311990);
	john.print();
	cout << "-------------------------\n\n";

	Student &jane = *(new CollegeStudent("Jane Doe", 11211989, "UC-12345"));
	jane.print();
	cout << "-------------------------\n\n";

	Student *pstudent = &jane;
	pstudent->print();
	cout << "-------------------------\n\n";

	// Student &bilbo = *(new CollegeGraduate("Bilbo Baggins", 2128506,
    //	"MiddleEarthUniversity-#24123", true));
    // bilbo.print();
	// cout << "-------------------------\n\n";

	// delete &bilbo;
	delete &jane;

	return 0;
}
