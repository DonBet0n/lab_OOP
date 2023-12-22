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
	cout << "I�������i� ��� ����:" << endl;
	cout << "����� �����: " << courseName << endl;
	cout << "����������� �i���i��� �������i�: " << maxStudent << endl;
	cout << "�i���i��� �������i� �� ����i: " << studentCount << endl;

	int count = 1;
	if (!studentMap.empty())
	{
		cout << "��������: " << endl;
		for (const auto& pair : studentMap) {
			cout << count << ". " << "I�'�: " << pair.first->get_name() << ", Id: " << pair.second << endl;
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
//	cout << "��� ���i��� ������������ �� ����" << endl;
//	return true;
//}


void Course::save_course_info() {
	ofstream file("course/Course_" + this->get_name() + ".txt", ios::trunc);
	if (!file.is_open()) {
		cerr << "������� �������� ����� ��� ������." << endl;
		return;
	}

	file << "����" << endl;
	file << "����� �����: " << courseName << endl;
	file << "Id: " << courseCode << endl;
	file << "����������� �i���i��� �������i�: " << maxStudent << endl;
	file << "�i���i��� �������i� �� ����i: " << studentMap.size() << endl;

	file << "��������: " << endl;
	int count = 1;
	for (const auto& pair : studentMap) {
		file << count << ". " << "��'�: " << pair.first->get_name() << ", Id: " << pair.second << endl;
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
	studentMap.clear();											// ��������� ���������� ������ ��������
}