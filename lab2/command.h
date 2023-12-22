#pragma once
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "GroupMonitor.h"
#include "Department.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <list>
#include <functional>

using namespace std;

int commandss() {
	string command;
	vector<string> commands = { "Створити","Показати","Записатись","Видалити","СтворитиКурс","Оцінки",
		"СкількиМісць" , "СереднійБал" ,"Рейтинг", "Відчислитись"};
	cin >> command;
	int num = -1;
	for (int i = 0; i < commands.size(); ++i) {
		if (commands[i] == command) {
			num = i;
			break;
		}
		num = stoi(command) - 1;
	}
	return num;
}

void createStudent(vector<Student*>& students) {
	int count, age, id;
	string name, command, email, phone_number;
	Student* stud = new Student;
	cout << "Скiльки студентiв ви хочете створити" << endl;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Iнформацiя Повна/Скорочена/Рандом" << endl;
		cin >> command;
		if (command == "Повна" || command == "1")
		{
			cout << "Введiть iм'я" << endl;
			cin >> name;
			cout << "Введiть вiк" << endl;
			cin >> age;
			cout << "Введiть Id" << endl;
			cin >> id;
			cout << "Введiть емейл" << endl;
			cin >> email;
			cout << "Введiть номер телефону" << endl;
			cin >> phone_number;

			Student* stud = new Student(name, age);
			stud->add_info(id, email, phone_number);
			students.push_back(stud);
			/*delete stud;*/
		}

		else if (command == "Скорочена" || command == "2")
		{
			cout << "Введiть iм'я" << endl;
			cin >> name;
			cout << "Введiть вiк" << endl;
			cin >> age;

			Student* stud = new Student(name, age);
			students.push_back(stud);
			/*delete stud;*/
		}
		else if (command == "Рандом" || command == "3")
		{
			Student* stud = new Student();
			students.push_back(stud);
			/*delete stud;*/
		}

	}
}

void createTeacher(vector<Teacher*> &teachers) {
	int age;
	string name, command, email, phone_number, teaching_experience;
	
		cout << "Iнформацiя Повна/Скорочена" << endl;
		cin >> command;
		if (command == "Повна" || command == "1")
		{
			cout << "Введiть iм'я" << endl;
			cin >> name;
			cout << "Введiть вiк" << endl;
			cin >> age;
			cout << "Введiть емейл" << endl;
			cin >> email;
			cout << "Введiть номер телефону" << endl;
			cin >> phone_number;
			cout << "Введiть досвiд вчителя" << endl;
			cin >> teaching_experience;

			
			Teacher* teach = new Teacher(name, age);
			teach->add_info(email, phone_number, teaching_experience);
			teachers.push_back(teach);
			/*delete teach;*/
		}
		if (command == "Скорочена" || command == "2")
		{
			cout << "Введiть iм'я" << endl;
			cin >> name;
			cout << "Введiть вiк" << endl;
			cin >> age;

			Teacher* teach = new Teacher(name, age);
			teachers.push_back(teach);
			/*delete teach;*/
		}	
}

void crateCourse(vector<Teacher*> &teachers) {
	try
	{	
		if (teachers.empty())
		{
			throw runtime_error("Немає викладачв для створення курсу");
		}
		string command;
		cout << "Створити/Зберегти" << endl;
		cin >> command;

		if (command == "Створити" || command == "1")
		{
			cout << "Виберiть викладача для створення курсу" << endl;
			int num, max, id;
			string nameCourse;
			for (int i = 0; i < teachers.size(); i++)
			{
				cout << i + 1 << " " << teachers[i]->get_name() << endl;
			}
			cin >> num;
			cout << "Введiть iм'я курсу, максимальну кiлькiсть студенiв i код курсу" << endl;
			cin >> nameCourse >> max >> id;
			teachers[num - 1]->create_course(nameCourse, max, id);
		}
		else if (command == "Зберегти" || command == "2") {
			cout << "Виберiть викладача для збереженню у файл" << endl;
			int num;
		
			for (int i = 0; i < teachers.size(); i++)
			{
				cout << i + 1 << " " << teachers[i]->get_name() << endl;
			}
			cin >> num;
			teachers[num - 1]->get_course()->save_course_info();
		}
		
	}
	catch (const exception& e) {
		cout << "Помилка: " << e.what() << endl;
	}
}

void crateDepartment(vector<Teacher*> &teachers, Department<string,Course> &department) {
	if (!teachers.empty())
	{
		cout << "Виберiть викладача який володiє курсом" << endl;
		int num;
		string nameDep;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num;
		cout << "Введiть iм'я факультету" << endl;
		cin >> nameDep;
		department.set_name(nameDep);
		department.add_course(*teachers[num - 1]->get_course());
	}
	else
	{
		cout << "Немає курсiв для створення факультету" << endl;
	}
}



void show_student_array(vector<Student*>& students) {
	try {
		if (students.empty())
		{
			throw std::runtime_error("Студентiв немає");
		}
		cout << "Iнформацiю про якого студента ви хочете побачити?" << endl;
		int num;
		string command;
		/*for (int i = 0; i < students.size(); i++)
		{
				cout << i + 1 << " " << students[i]->get_name() << endl;
		}
		cin >> num;*/

		int i = 0;

		for_each(students.begin(), students.end(), [&](Student* student) {
			cout << i + 1 << " " << student->get_name() << endl;
			i++;
			});

		cin >> num;

		cout << "Повна/Оцiнки" << endl;
		cin >> command;
		if (command == "Повна" || command == "1")
		{
			Human* newHuman;
			newHuman = students[num - 1];
			newHuman->show();
		}
		else if (command == "Оцінки" || command == "2")
		{
			students[num - 1]->show_grades();
		}
	}
	catch (const exception& e) {
		cout << "Помилка: " << e.what() << endl;
	}
}

void show_teacher_array(vector<Teacher*> &teachers) {
	if (!teachers.empty())
	{
		cout << "Виберiть викладача для виводу iнформацiї" << endl;
		int num;
		string command;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num;
		cout << "Повна/ПроКрус" << endl;
		cin >> command;
		if (command == "Повна" || command == "1")
		{
			teachers[num - 1]->show();
		}
		else if(command == "ПроКрус" || command == "2")
		{
			teachers[num - 1]->get_course()->show();
		}
	}
	else
	{
		cout << "Немає викладачiв" << endl;
	}
}

void show_course(vector<Teacher*> &teachers) {
	if (!teachers.empty())
	{
		cout << "Виберiть викладача для виводу iнформацiї" << endl;
		int num;
		string command;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num;
		cout << "Повна" << endl;
		cin >> command;
		if (command == "Повна" || command == "1")
		{
			teachers[num - 1]->get_course()->show();
		}
	}
	else
	{
		cout << "Немає курсiв" << endl;
	}
}

void show_Department(Department<string, Course> &department) {
	cout << "iнформацiя про факультет: " << department.get_name() << endl;
	cout << "iм'я: " << department.get_name() << endl;
	cout << "Курси: " << endl;
	for (int i = 0; i < department.get_courseArray().size(); i++){
	
		cout << department.get_courseArray()[i]->get_name() << endl;

	}
}




void set_grades(vector<Teacher*>& teachers, vector<Student*>& students) {
		try
		{
			if (students.empty())
			{
				throw runtime_error("Студентiв немає");
			}
			if (teachers.empty())
			{
				throw runtime_error("Викладачiв немає");
			}
			cout << "Виберiть викладача" << endl;
			int num1, num2, num3;
			string command;
			for (int i = 0; i < teachers.size(); i++)
			{
				cout << i + 1 << " " << teachers[i]->get_name() << endl;
			}
			cin >> num1;
			cout << "Виберiть студента" << endl;
			for (int i = 0; i < students.size(); i++)
			{
				cout << i + 1 << " " << students[i]->get_name() << endl;
			}
			cin >> num2;
			cout << "Виставлення Вручну/Рандом" << endl;
			cin >> command;
			if (command == "Вручну" || command == "1")
			{
				cout << "Скiльки предметiв бажаєте ввести (до 5)" << endl;
				cin >> num3;
				teachers[num1 - 1]->assigns_grade(students[num2 - 1], num3);
			}
			else if (command == "Рандом" || command == "2")
			{
				teachers[num1 - 1]->assigns_grade(students[num2 - 1]);
			}

		}
		catch (const exception& e) {
			cout << "Помилка: " << e.what() << endl;
		}

}

void subscription_on_course(vector<Student*>& students, vector<Teacher*>& teachers) {
	
		cout << "Виберiть студента який хоче записатись на курс:" << endl;
		int num1, num2;
		string command;
		for (int i = 0; i < students.size(); i++)
		{
			cout << i + 1 << ". " << students[i]->get_name() << endl;
		}
		cin >> num1;
		cout << "Виберiть викладача для запису на курс" << endl;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num2;

		students[num1 - 1]->subscription_on_course(teachers[num2 - 1]->get_course());

}

void unsubscribe_on_course(vector<Student*>& students, vector<Teacher*>& teachers) {

	cout << "Виберiть студента який хоче вiдчислитись з курсу:" << endl;
	int num1, num2;
	string command;
	for (int i = 0; i < students.size(); i++)
	{
		cout << i + 1 << ". " << students[i]->get_name() << endl;
	}
	cin >> num1;
	cout << "Виберiть викладача курсу:" << endl;
	for (int i = 0; i < teachers.size(); i++)
	{
		cout << i + 1 << " " << teachers[i]->get_name() << endl;
	}
	cin >> num2;

	students[num1 - 1]->unbscription_on_course(teachers[num2 - 1]->get_course());

}


void writeStudentsToFile(vector<Student*>& students, string filename) {		
	try {
		ofstream file(filename, ios::trunc);

		if (!file.is_open()) {
			throw runtime_error("Не вдалося відкрити файл.");
		}

		for (int i = 0; i < students.size(); i++) {
			file << "Студент" << endl;
			file << "Iм'я: " << students[i]->get_name() << endl;
			file << "Вік: " << students[i]->get_age() << endl;
			file << "Id: " << students[i]->get_id() << endl;
			file << "Емейл: " << students[i]->get_email() << endl;
			file << "Номер телефону: " << students[i]->get_phone_number() << endl;
			file << "Рейтинг: " << students[i]->get_rating() << endl;
			file << "Оцінки:" << endl;
			for (const auto& grade : students[i]->grade_stud) {
				file << " " << grade.first << ": " << grade.second << endl;
			}
			file << endl;
		}

		file.close();
	}
	catch (const exception& e) {
		std::cerr << "Помилка: " << e.what() << endl;
	}
}

void readStudentsFromFile(vector<Student*>& students, string filename) {
	try {
		ifstream file("students.txt");
		
		if (!file.is_open()) {
			throw runtime_error("Не вдалося відкрити файл.");
		}
		
		string line;
		while (getline(file, line)) {
			if (line == "Студент") {

				getline(file, line); 
				string name = line.substr(6); // Зберігаємо ім'я

				getline(file, line); 
				int age = stoi(line.substr(5)); // Зберігаємо вік
				
				Student* student = new Student(name, age);

				getline(file, line); 
				int id = stoi(line.substr(4)); // Зберігаємо id

				getline(file, line); 
				string email = line.substr(7); // Зберігаємо email

				getline(file, line); 
				string phone_number = line.substr(16); // Зберігаємо номер телефону

				getline(file, line);
				string rating = line.substr(9); // Зберігаємо рейтинг

				student->add_info(id, email, phone_number);
				*student += stoi(rating);

				getline(file, line); 

				while(1) 
				{
					getline(file, line);  // Читаємо рядок з оцінкою

					if (line.empty() || line == "Студент" || file.eof()) {
						break;
					}

					size_t pos = line.find(":");
					if (pos != string::npos) {
						string subject = line.substr(0, pos);
						int mark = stoi(line.substr(pos + 1));

						student->grade_stud.insert({ subject, mark });
					}
				}
				
				//for (int i = 0; i < 5; i++)
				//{
				//	getline(file, line); // Читаємо рядок з оцінкою
				//	size_t pos = line.find(":");
				//	if (pos != string::npos) {
				//		string subject = line.substr(0, pos);
				//		int mark = stoi(line.substr(pos + 1));

				//		student->grade_stud.insert({ subject, mark });
				//	}
				//}
				

				students.push_back(student); // Додаємо студента до вектора
				/*delete student;*/
				
			}
		}

		file.close();
	}
	catch (const exception& e) {
		std::cerr << "Помилка: " << e.what() << endl;
	}
}

void writeTeacherToFile(vector<Teacher*>& teachers, string filename) {
	ofstream file(filename, ios::trunc);
	if (!file.is_open()) {
		cerr << "Помилка відкриття файлу для запису вчителів." << endl;
		return;
	}
	for (int i = 0; i < teachers.size(); i++)
	{
		file << "Викладач" << endl;
		file << "Iм'я: " << teachers[i]->get_name() << endl;
		file << "Вiк: " << teachers[i]->get_age() << endl;
		if (teachers[i]->get_id() != NULL || teachers[i]->get_email() != "" || teachers[i]->get_phone_number() != "" || teachers[i]->get_teaching_experience() != "") {
			file << "Id: " << teachers[i]->get_id() << endl;
			file << "Емейл: " << teachers[i]->get_email() << endl;
			file << "Номер телефону: " << teachers[i]->get_phone_number() << endl;
			file << "Досвід: " << teachers[i]->get_teaching_experience() << endl;
		}
		
		if (teachers[i]->get_course()) {
			file << "Назва курсу: " << teachers[i]->get_course()->get_name() << endl;
			file << "Id: " << teachers[i]->get_course()->get_course_code() << endl;
		}

		file << endl;
	}
	file.close();
}

void readTeachersFromFile(vector<Teacher*>& teachers, vector<Student*>& students, string filename1, string filename2) {
	try {
		ifstream file(filename1);

		if (!file.is_open()) {
			throw runtime_error("Не вдалося відкрити файл.");
		}
	
		string line, line2;
		while (getline(file, line)) {
			if (line == "Викладач") {

				getline(file, line);
				string name = line.substr(6); // Зберігаємо ім'я

				getline(file, line);
				int age = stoi(line.substr(5)); // Зберігаємо вік

				Teacher* teacher = new Teacher(name, age);

				getline(file, line);
				int id = stoi(line.substr(4)); // Зберігаємо id

				getline(file, line);
				string email = line.substr(7); // Зберігаємо email

				getline(file, line);
				string phone_number = line.substr(16); // Зберігаємо номер телефону

				getline(file, line);
				string teaching_experience = line.substr(8); // Зберігаємо досвід

				
				teacher->add_info(email, phone_number, teaching_experience);
				teacher->set_id(id);
				
				getline(file, line);
				if (line.find("Назва курсу: ") != string::npos) {
					string courseNameTeach = line.substr(13); // Зберігаємо ім'я курсу

					getline(file, line);
					int courseIdTeach = stoi(line.substr(4)); // Зберігаємо id курсу
					
					ifstream file2(filename2);
					while (getline(file2, line2)) {
						if (line2 == "Курс") {
							getline(file2, line2);
							string courseName = line2.substr(13); // Зберігаємо ім'я

							getline(file2, line2);
							int courseId = stoi(line2.substr(4)); // Зберігаємо id курсу
							
							if (courseNameTeach == courseName && courseIdTeach == courseId)
							{
								getline(file2, line2);
								int maxStudent = stoi(line2.substr(33)); // Зберігаємо максимальну кiлькiсть студентiв

								teacher->create_course(courseName, maxStudent , courseId);

								bool stop = false;
								while (getline(file2, line2)) {

									if (stop){break;}
									
									if (line2.find("Студенти: ") != string::npos) {
										while (getline(file2, line2)) {
											if (line2.find("Курс") != string::npos) {
												stop = true;
												break;  // Завершуємо цикл, якщо знайшли наступне входження "Курс"
												
											}
											if (!line2.empty()) {
												size_t pos = line2.find("Id: ");
												if (pos != string::npos) {
													int id = stoi(line2.substr(pos + 4));

													// Знаходимо студента за Id у векторі
													for (Student* student : students) {
														if (student->get_id() == id) {

															*teacher->get_course() + student;
															break;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
					file2.close();
				}

				getline(file, line);

				teachers.push_back(teacher); // Додаємо вчителя до вектора
			}
		}
		
		file.close();
	}
	catch (const exception& e) {
		cerr << "Помилка: " << e.what() << endl;
	}
}

void saveCoursesToFile(vector<Teacher*>& teachers, string filename) {
	ofstream file(filename, ios::trunc);
	if (!file.is_open()) {
		cerr << "Помилка відкриття файлу для запису." << endl;
		return;
	}
	
	for (int i = 0; i < teachers.size(); i++)
	{

		Course *course = teachers[i]->get_course();

		file << "Курс" << endl;
		file << "Назва курсу: " << course->get_name() << endl;
		file << "Id: " << course->get_course_code() << endl;
		file << "Максимальна кiлькiсть студентiв: " << course->get_maxStudent() << endl;
		file << "Кiлькiсть студентiв на курсi: " << course->get_studentMap().size() << endl;

		file << "Студенти: " << endl;
		int count = 1;
		for (const auto& pair : course->get_studentMap()) {
			file << count << ". " << "Ім'я: " << pair.first->get_name() << ", Id: " << pair.second << endl;
			count++;
		}
		file << endl;
	}
	file.close();
}


void sortStudentsByRating(vector<Student*>& students) {
	sort(students.begin(), students.end(), [](Student* a, Student* b) {
		return a->get_rating() < b->get_rating();
		});
}


//void functor() {
//	static int grades[5] = { 1, 2, 3, 4, 5 };
//
//	list<int> pricesList(grades, grades + sizeof(grades) / sizeof(grades[0]));
//
//	plus<int> addition;
//	addition(grades[3], grades[5]);
//
//	multiplies<int> multiplication;
//	multiplication(grades[1], 2);
//
//	divides<int> division;
//	division(grades[1], 2);
//
//	greater<int> greater_than;
//	greater_than(grades[2], grades[5]);
//
//	less<int> less_than;
//	less_than(grades[5], grades[6]);
//
//}


template <typename T>
void delete_item(vector<T*>& items) {
	try {
		if (items.empty()) {
			throw runtime_error("Об'єктiв немає");
		}

		cout << "Кого ви хочете видалити?" << endl;
		int num;

		for (int i = 0; i < items.size(); i++) {
			cout << i + 1 << " " << items[i]->get_name() << endl;
		}

		cin >> num;

		if (num >= 1 && num <= items.size()) {
			auto it = items.begin() + (num - 1);
			delete* it;												// Видалення об'єкта
			items.erase(it);										// Видалення вказівника з вектора
			cout << "Об'єкт видалений з вектора." << endl;
		}
		else {
			cout << "Введено некоректний номер елемента." << endl;
		}
	}
	catch (const exception& e) {
		cout << "Помилка: " << e.what() << endl;
	}
}

void delete_course(vector<Teacher*>& teachers) {

	cout << "Виберiть викладача для видалення курсу" << endl;
	int num;
	string command;
	for (int i = 0; i < teachers.size(); i++)
	{
		cout << i + 1 << " " << teachers[i]->get_name() << endl;
	}
	cin >> num;

	if (!teachers[num - 1]->get_course())
	{
		delete teachers[num - 1]->get_course();
	}
	else
	{
		cout << "У цього викладача немає курсу" << endl;
	}
	
}

void rating(vector<Student*>& students, vector<Teacher*>& teachers) {
	try{
		if (teachers.empty())
		{
			throw std::runtime_error("Викладачів немає");
		}
		if (students.empty())
		{
			throw std::runtime_error("Студентiв немає");
		}

		int teach, stud;
		string num3, num4, num5;
		cout << "Виберiть викладача для виставлення рейтингу" << endl;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> teach;
		cout << "Виберiть студента студента" << endl;
		
		for (int i = 0; i < students.size(); i++)
		{
			cout << i + 1 << " " << students[i]->get_name() << endl;
		}
		cin >> stud;

		cout << "Збiльшити чи зменшити рейтинг?" << endl
			<< "1. Збiльшити" << endl
			<< "2. Зменшити" << endl;

		cin >> num3;
		if (num3 == "1")
		{
			cout << "Збiльшити на скiльки?" << endl
				 << "1. Збiльшити" << endl
				 << "2. На скiльки" << endl;
			cin >> num4;
			if (num4 == "1")
			{
				++(*students[stud - 1]);
			}
			else if (num4 == "2")
			{
				int num6;
				cout << "Кiлькiсть рейтингу" << endl;
				cin >> num6;
				(*students[stud - 1]) += num6;
			}
			
		}
		if (num3 == "2")
		{
			cout << "Зменшити на скiльки?" << endl
				<< "1. Зменшити" << endl
				<< "2. На скiльки" << endl;
			cin >> num4;
			if (num4 == "1")
			{
				--(*students[stud - 1]);
			}
			else if (num4 == "2")
			{
				int num6;
				cout << "Кiлькiсть рейтингу" << endl;
				cin >> num6;
				(*students[stud - 1]) -= num6;
			}
		}
	}
	catch (const exception& e) {
		cout << "Помилка: " << e.what() << endl;
	}
}

inline void available_places_on_course(vector<Teacher*>& teachers) {
	cout << "Виберiть викладача для виводу iнформацiї" << endl;
	int num;
	string command;
	for (int i = 0; i < teachers.size(); i++)
	{
		cout << i + 1 << " " << teachers[i]->get_name() << endl;
	}
	cin >> num;

	cout << "Кiлькiсть мiсць у курсi: " << teachers[num - 1]->get_course()->get_maxStudent() - teachers[num - 1]->get_course()->get_studentCount() << endl;
};

inline void show_average_grade(vector<Teacher*>& teachers)
{
	cout << "Виберiть викладача для виводу iнформацiї" << endl;
	int num;
	for (int i = 0; i < teachers.size(); i++)
	{
		cout << i + 1 << " " << teachers[i]->get_name() << endl;
	}
	cin >> num;

	double sum = 0;
	int count = 0;
	for (auto& pair : teachers[num - 1]->get_course()->get_studentMap()) {

		for (auto& pair2 : pair.first->grade_stud)
		{
				if (pair2.second > 0) {
					sum += pair2.second;
					count++;
				}
		}
			
	}
	if (count > 0) {
		double average = sum / count;
		cout << "Середнiй бал студентiв на курсi " << teachers[num - 1]->get_course()->get_name() << " - " << average << endl;
	}
	else {
		cout << "Оцiнки вiдсутнi на курсi: " << teachers[num - 1]->get_course()->get_name() << endl;
	}
}
