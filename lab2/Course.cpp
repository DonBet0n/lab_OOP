#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

void Course::set_course(string name, int max, int courseCode) {
	courseName = name;
	maxStudent = max;
	this->courseCode = courseCode;
	/*studentArray = new Student * [maxStudent];*/
}

void Course::show() {
	cout << "Iнформацiя про курс:" << endl;
	cout << "Назва курсу: " << courseName << endl;
	cout << "Максимальна кiлькiсть студентiв: " << maxStudent << endl;
	cout << "Кiлькiсть студентiв на курсi: " << studentCount << endl;

	int count = 1;
	if (!studentMap.empty())
	{
		cout << "Студенти: " << endl;
		for (const auto& pair : studentMap) {
			cout << count << ". " << "Iм'я: " << pair.first->get_name() << ", Id: " << pair.second << endl;
			count++;
		}
	}
	/*for (int i = 0; i < studentCount; i++)
	{
		cout << i + 1 << ". " << studentArray[i]->get_name() << endl;
	}*/
}

//bool Course::add_student(Student* newStudent) {
//	if (studentCount >= maxStudent) {
//		return false;
//	}
//	studentArray[studentCount] = newStudent;
//	++studentCount;
//	cout << "Вас успiшно зареєстровано на курс" << endl;
//	return true;
//}


void Course::save_course_info() {
	ofstream file("course/Course_" + this->get_name() + ".txt", ios::trunc);
	if (!file.is_open()) {
		cerr << "Помилка відкриття файлу для запису." << endl;
		return;
	}

	file << "Курс" << endl;
	file << "Назва курсу: " << courseName << endl;
	file << "Id: " << courseCode << endl;
	file << "Максимальна кiлькiсть студентiв: " << maxStudent << endl;
	file << "Кiлькiсть студентiв на курсi: " << studentMap.size() << endl;

	file << "Студенти: " << endl;
	int count = 1;
	for (const auto& pair : studentMap) {
		file << count << ". " << "Ім'я: " << pair.first->get_name() << ", Id: " << pair.second << endl;
		count++;
	}
	file << endl;
	file.close();
}
int Course::get_maxStudent() {
	return maxStudent;
}

int Course::get_studentCount() {
	return studentCount;
}

int Course::get_course_code() {
	return courseCode;
}

map<Student*, int> Course::get_studentMap()
{
	return studentMap;
}

string Course::get_name() {
	return courseName;
}

Course::~Course() {
	studentMap.clear();											// Звільнення динамічного масиву студентів
}