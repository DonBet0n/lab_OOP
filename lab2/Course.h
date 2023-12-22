#pragma once

#include "Student.h"


#include <string>
#include <map>

using namespace std;

class Course
{
public:
	void show();														//�������� ���������� ��� ����
	void set_course(string name, int max, int courseCode);				//�������� ����
	//bool add_student(Student* newStudent);								//������ �������� �� �����

	string get_name();													//�������� ��'� �����
	map<Student*, int> get_studentMap();
	int get_maxStudent();
	int get_studentCount();
	int get_course_code();

	void save_course_info();												//�������� �������� �� �����

	bool operator+(Student* newStudent) {
		if (studentMap.size() >= maxStudent) {
			cout << "��������� ����������� ������� �������� ��� �����." << endl;
			return false;
		}
		studentMap[newStudent] = newStudent->get_id();		// ������ ��'� �� ������������� �������� �� ����
		
		++studentCount;
		return true;
	}

	bool operator-(Student* newStudent) {
		auto it = studentMap.find(newStudent);
		if (it != studentMap.end()) {
			studentMap.erase(it);

			--studentCount;
			return true;
		}
		else {
			cout << "������� �� ��������� �� ����" << endl;
			return false;
		}
	}

	~Course();
private:
	string courseName;
	int maxStudent;
	int studentCount;
	int courseCode;

	map<Student*, int> studentMap;

	/*Student** studentArray;*/
};
