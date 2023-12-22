
#include "Student.h"
#include "Course.h"

#include <iostream>
#include <vector>

using namespace std;

Student::Student() {
	static vector<string> names = { "Petro", "Ivan", "Olena", "Kateryna", "Andriy", "Anna", "Oleksandr", "Mariya", "Mykola", "Nataliya" };
	int index = rand() % names.size();
	this->name = names[index];
	this->age = rand() % 8 + 18;
	this->id = rand() % 90000 + 10000;
	this->rating = 0;
	/*for (int i = 0; i < 5; i++) {
		this->grade_stud[i].subject = "�������" + to_string(i + 1);
		this->grade_stud[i].mark = 0;
	}*/
}
Student::Student(string name, int age) {
	this->name = name;
	if (age < 18 || age > 50) {
		throw exception();
	}
	this->rating = 0;
	this->age = age;
	this->id = rand() % 90000 + 10000;
	/*for (int i = 0; i < 5; i++) {
		this->grade_stud[i].subject = "�������" + to_string(i + 1);
		this->grade_stud[i].mark = 0;
	}*/
}

Student::~Student() {
	cout << "������� " << this->name << " ���������" << endl;
}

void Student::add_info(int id, string email, string phone_number) {
	this->id = id;
	this->email = email;
	this->phone_number = phone_number;
}

void Student::show() {
	cout << "I�������i� ��� ��������: " << this->get_name() << endl;
	cout << "I�'�: " << name << endl;
	cout << "�i�: " << age << endl;
	if (id != NULL || email != "" || phone_number != "")
	{
		cout << "Id: " << id << endl;
		cout << "�����: " << email << endl;
		cout << "����� ��������: " << phone_number << endl;
	}
	cout << "�������: " << rating << endl;

}
void Student::show_grades() {
	cout << "��i��� ��������: " << this->get_name() << endl;

	for (const auto& pair : grade_stud) {
		cout << pair.first << ": " << pair.second << std::endl;
	}

	/*for (int i = 0; i < 5; i++)
	{
		cout << grade_stud[i].subject << ": " << grade_stud[i].mark << endl;
	}*/
}
string Student::get_name() {
	return this->name;
}
int Student::get_age() {
	return this->age;
}
int Student::get_id() {
	return this->id;
}
string Student::get_email() {
	return this->email;
}
string Student::get_phone_number() {
	return this->phone_number;
}
int Student::get_rating() {
	return this->rating;
}

void Student::subscription_on_course(Course* courseName) {
	if (*courseName + this) {
		cout << "��� ���i��� ������������ �� ����" << endl;
	}
	else
	{
		cout << "������� ��� ������ �������� �� ����: " << courseName->get_name() << endl;
	}
}

void Student::unbscription_on_course(Course* courseName) {
	if (*courseName - this) {
		cout << "��� ���i��� �i�������� � �����" << endl;
	}
}