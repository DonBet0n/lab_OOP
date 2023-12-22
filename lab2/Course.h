#pragma once

#include "Student.h"


#include <string>
#include <map>

using namespace std;

class Course
{
public:
	void show();														//Показати інформацію про курс
	void set_course(string name, int max, int courseCode);				//Створити курс
	//bool add_student(Student* newStudent);								//Додати студентів до курсу

	string get_name();													//Отримати ім'я курсу
	map<Student*, int> get_studentMap();
	int get_maxStudent();
	int get_studentCount();
	int get_course_code();

	void save_course_info();												//Записати студентів до курсу

	bool operator+(Student* newStudent) {
		if (studentMap.size() >= maxStudent) {
			cout << "Досягнуто максимальну кількість студентів для курсу." << endl;
			return false;
		}
		studentMap[newStudent] = newStudent->get_id();		// Додаємо ім'я та ідентифікатор студента до мапи
		
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
			cout << "Студент не знайдений на курсі" << endl;
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
