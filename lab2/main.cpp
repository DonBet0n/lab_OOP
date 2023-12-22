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
	student.grade_stud.insert({ "Вища математика", 5 });

	int mathGrade = student["Вища математика"];

	cout << mathGrade << endl;








	//Test2 t2;

	//t2.test();



	////Cпосіб пеший
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

	//p = new Teacher("вчитель", 25);
	//p = teachers[0];
	//p->show();
	//delete p;
	//cout << endl;

	////Cпосіб другий
	//Student stud2;
	//Teacher teach2("вчитель", 25);

	//p = &stud2;
	//p->show();
	//cout << endl;

	//p = &teach2;
	//p->show();
	//cout << endl;

	////Cпосіб третій
	//Teacher teach3("Вчитель", 45);
	//Student stud3;
	//Human hum3;

	//// Зробити об'єкт Людиною
	//Human* p3 = &hum3;
	//p3->show();
	//cout << endl;

	//// Замінити форму об'єкта на Студента 
	//p3 = (Human*)&stud3;
	//p3->show();
	//cout << endl;

	//// Замінити форму об'єкта на Вчитель 
	//p3 = (Human*)&teach3;
	//p3->show();	//cout << endl;



	while (command != "Вийти")
	{
		cout << "Студент/Викладач/Курс/Факультет" << endl;
		cin >> command;

		if (command == "Студент" || command == "1")
		{
			cout << "Створити(1)/Показати(2)/Записатись(3)/Відчислитись(10)/Видалити(4)" << endl;
			
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

			default: cout << "Невiрна команда" << endl;
				break;
			}
		}
		if (command == "Викладач" || command == "2")
		{
			cout << "Створити(1)/Показати(2)/Видалити(4)/ /СтворитиКурс(5)/Оцiнки(6)/Рейтинг(9)" << endl;

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

			default: cout << "Невiрна команда" << endl;
				break;
			}
		}
		if (command == "Курс" || command == "3")
		{
			cout << "Показати(2)/СкiлькиМiсць(7)/СереднiйБал(8)/Видалити(4)" << endl;

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

			default: cout << "Невiрна команда" << endl;
				break;
			}

		}
		if (command == "Факультет" || command == "4")
		{
			cout << "Показати(2)/Видалити(4)" << endl;

			switch (commandss())
			{
			case 0:	show_Department(department);
				break;

			default: cout << "Невiрна команда" << endl;
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


