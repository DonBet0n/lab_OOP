#include "Student.h"
#include "Teacher.h"
#include "Course.h"

#include <iostream>

using namespace std;

Teacher::Teacher(string name, int age) {
	this->name = name;
	this->age = age;
	this->id = rand() % 90000 + 10000;
}

void Teacher::add_info(string email, string phone_number, string teaching_experience) {
	this->email = email;
	this->phone_number = phone_number;
	this->teaching_experience = teaching_experience;
}

void Teacher::set_id(int id) {
	this->id = id;
}

void Teacher::show() {
	cout << "Iнформацiя про викладача " << this->get_name() << endl;
	cout << "Iм'я: " << name << endl;
	cout << "Вiк: " << age << endl;
	if (id != NULL || email != "" || phone_number != "" || teaching_experience != "")
	{
		cout << "Id: " << id << endl;
		cout << "Емейл: " << email << endl;
		cout << "Номер телефону: " << phone_number << endl;
		cout << "Досвiд: " << teaching_experience << endl;
	}
}

void Teacher::create_course(string courseName, int maxStudent, int courseCode) {
	Course* tmp = new Course;
	tmp->set_course(courseName, maxStudent, courseCode);
	teacherCourse = *tmp;
}

Course* Teacher::get_course() {
	return &teacherCourse;
}

string Teacher::get_name() {
	return this->name;
}
int Teacher::get_age() {
	return age;
}
int Teacher::get_id() {
	return id;
}
string Teacher::get_email() {
	return email;
}
string Teacher::get_phone_number() {
	return phone_number;
}
string Teacher::get_teaching_experience() {
	return teaching_experience;
}

void Teacher::assigns_grade(Student* new_student, int count) {
		cout << "Виставлення оцiнок для студента: " << new_student->get_name() << endl;

		for (int i = 0; i < count; i++)
		{
			string subject;
			int mark;

			cout << "Введiть назву " << i + 1 << " предмету: ";
			cin >> subject;
			cout << "Введiть оцiнку: ";
			cin >> mark;

			new_student->grade_stud.insert({ subject, mark });

		}
}
void Teacher::assigns_grade(Student* new_student) {

	string subjects[5] = { "Вища математика", "Фiзика", "ООП", "ТЕМК", "Англ.мова" };

	for (int i = 0; i < 5; ++i) {
		new_student->grade_stud.insert({ subjects[i], rand() % 5 + 1 });
	}

	

	/*int* grades = new int[5];
	string* subject = new string[5]{ "Вища математика", "Фiзика", "ООП", "ТЕМК", "Англ.мова" };
	for (int i = 0; i < 5; i++) {
		new_student->grade_stud[i].subject = subject[i];
		new_student->grade_stud[i].mark = rand() % 5 + 1;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (new_student->grade_stud[j].mark > new_student->grade_stud[j + 1].mark) {
				int temp = new_student->grade_stud[j].mark;
				new_student->grade_stud[j].mark = new_student->grade_stud[j + 1].mark;
				new_student->grade_stud[j + 1].mark = temp;
			}
		}
	}
	delete[] grades;*/

}


