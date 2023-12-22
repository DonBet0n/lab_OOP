#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "GroupMonitor.h"
#include "Department.h"

#include "command.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <map>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ukr");
	SetConsoleCP(1251);
	srand(time(0));

	vector<Student*> students;
	vector<Teacher*> teachers;
	string start, command;

	Department<string, Course> department;

	readStudentsFromFile(students,"students.txt");
	readTeachersFromFile(teachers, students, "teachers.txt", "courses.txt");

	sortStudentsByRating(students);


	Student student;
	student.grade_stud.insert({ "���� ����������", 5 });

	int mathGrade = student["���� ����������"];

	cout << mathGrade << endl;








	//Test2 t2;

	//t2.test();



	////C���� �����
	//Human* p;
	//
	//p = new Human;
	//p->show();
	//cout << endl;
	//delete p;
	//
	//p = new Student;
	//p = students[0];
	//p->show();
	//delete p;
	//cout << endl;

	//p = new Teacher("�������", 25);
	//p = teachers[0];
	//p->show();
	//delete p;
	//cout << endl;

	////C���� ������
	//Student stud2;
	//Teacher teach2("�������", 25);

	//p = &stud2;
	//p->show();
	//cout << endl;

	//p = &teach2;
	//p->show();
	//cout << endl;

	////C���� �����
	//Teacher teach3("�������", 45);
	//Student stud3;
	//Human hum3;

	//// ������� ��'��� �������
	//Human* p3 = &hum3;
	//p3->show();
	//cout << endl;

	//// ������� ����� ��'���� �� �������� 
	//p3 = (Human*)&stud3;
	//p3->show();
	//cout << endl;

	//// ������� ����� ��'���� �� ������� 
	//p3 = (Human*)&teach3;
	//p3->show();	//cout << endl;



	while (command != "�����")
	{
		cout << "�������/��������/����/���������" << endl;
		cin >> command;

		if (command == "�������" || command == "1")
		{
			cout << "��������(1)/��������(2)/����������(3)/³����������(10)/��������(4)" << endl;
			
			switch (commandss())
			{
			case 0: createStudent(students);
				break;
			case 1: show_student_array(students);
				break;
			case 2: subscription_on_course(students, teachers);
				break;
			case 3: delete_item(students);
				break;
			case 9: unsubscribe_on_course(students, teachers);
				break;

			default: cout << "���i��� �������" << endl;
				break;
			}
		}
		if (command == "��������" || command == "2")
		{
			cout << "��������(1)/��������(2)/��������(4)/ /������������(5)/��i���(6)/�������(9)" << endl;

			switch (commandss())
			{
			case 0: createTeacher(teachers);
				break;
			case 1: show_teacher_array(teachers);
				break;
			case 4: crateCourse(teachers);
				break;
			case 5: set_grades(teachers, students);
				break;
			case 3:	delete_item(teachers);
				break;
			case 8: rating(students, teachers);
				break;

			default: cout << "���i��� �������" << endl;
				break;
			}
		}
		if (command == "����" || command == "3")
		{
			cout << "��������(2)/��i�����i���(7)/������i����(8)/��������(4)" << endl;

			switch (commandss())
			{
			case 1: show_course(teachers);
				break;
			case 6:	available_places_on_course(teachers);
				break;
			case 7:	show_average_grade(teachers);
				break;
			case 3:	delete_course(teachers);
				break;

			default: cout << "���i��� �������" << endl;
				break;
			}

		}
		if (command == "���������" || command == "4")
		{
			cout << "��������(2)/��������(4)" << endl;

			switch (commandss())
			{
			case 0:	show_Department(department);
				break;

			default: cout << "���i��� �������" << endl;
				break;
			}

		}
		else if (command == "5") { break; }
	}
	writeStudentsToFile(students, "students.txt");
	writeTeacherToFile(teachers, "teachers.txt");
	saveCoursesToFile(teachers, "courses.txt");

}



	//Student Vasil;
	//Vasil.add_info(013120, "vasa@gmail.com", "+310-933-3373");
	//
	//Human* p = &Vasil;
	//p->show();

	//Vasil.show();


