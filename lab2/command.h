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
	vector<string> commands = { "��������","��������","����������","��������","������������","������",
		"������̳���" , "����������" ,"�������", "³����������"};
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
	cout << "��i���� �������i� �� ������ ��������" << endl;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "I�������i� �����/���������/������" << endl;
		cin >> command;
		if (command == "�����" || command == "1")
		{
			cout << "����i�� i�'�" << endl;
			cin >> name;
			cout << "����i�� �i�" << endl;
			cin >> age;
			cout << "����i�� Id" << endl;
			cin >> id;
			cout << "����i�� �����" << endl;
			cin >> email;
			cout << "����i�� ����� ��������" << endl;
			cin >> phone_number;

			Student* stud = new Student(name, age);
			stud->add_info(id, email, phone_number);
			students.push_back(stud);
			/*delete stud;*/
		}

		else if (command == "���������" || command == "2")
		{
			cout << "����i�� i�'�" << endl;
			cin >> name;
			cout << "����i�� �i�" << endl;
			cin >> age;

			Student* stud = new Student(name, age);
			students.push_back(stud);
			/*delete stud;*/
		}
		else if (command == "������" || command == "3")
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
	
		cout << "I�������i� �����/���������" << endl;
		cin >> command;
		if (command == "�����" || command == "1")
		{
			cout << "����i�� i�'�" << endl;
			cin >> name;
			cout << "����i�� �i�" << endl;
			cin >> age;
			cout << "����i�� �����" << endl;
			cin >> email;
			cout << "����i�� ����� ��������" << endl;
			cin >> phone_number;
			cout << "����i�� ����i� �������" << endl;
			cin >> teaching_experience;

			
			Teacher* teach = new Teacher(name, age);
			teach->add_info(email, phone_number, teaching_experience);
			teachers.push_back(teach);
			/*delete teach;*/
		}
		if (command == "���������" || command == "2")
		{
			cout << "����i�� i�'�" << endl;
			cin >> name;
			cout << "����i�� �i�" << endl;
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
			throw runtime_error("���� ��������� ��� ��������� �����");
		}
		string command;
		cout << "��������/��������" << endl;
		cin >> command;

		if (command == "��������" || command == "1")
		{
			cout << "�����i�� ��������� ��� ��������� �����" << endl;
			int num, max, id;
			string nameCourse;
			for (int i = 0; i < teachers.size(); i++)
			{
				cout << i + 1 << " " << teachers[i]->get_name() << endl;
			}
			cin >> num;
			cout << "����i�� i�'� �����, ����������� �i���i��� ������i� i ��� �����" << endl;
			cin >> nameCourse >> max >> id;
			teachers[num - 1]->create_course(nameCourse, max, id);
		}
		else if (command == "��������" || command == "2") {
			cout << "�����i�� ��������� ��� ���������� � ����" << endl;
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
		cout << "�������: " << e.what() << endl;
	}
}

void crateDepartment(vector<Teacher*> &teachers, Department<string,Course> &department) {
	if (!teachers.empty())
	{
		cout << "�����i�� ��������� ���� �����i� ������" << endl;
		int num;
		string nameDep;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num;
		cout << "����i�� i�'� ����������" << endl;
		cin >> nameDep;
		department.set_name(nameDep);
		department.add_course(*teachers[num - 1]->get_course());
	}
	else
	{
		cout << "���� ����i� ��� ��������� ����������" << endl;
	}
}



void show_student_array(vector<Student*>& students) {
	try {
		if (students.empty())
		{
			throw std::runtime_error("�������i� ����");
		}
		cout << "I�������i� ��� ����� �������� �� ������ ��������?" << endl;
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

		cout << "�����/��i���" << endl;
		cin >> command;
		if (command == "�����" || command == "1")
		{
			Human* newHuman;
			newHuman = students[num - 1];
			newHuman->show();
		}
		else if (command == "������" || command == "2")
		{
			students[num - 1]->show_grades();
		}
	}
	catch (const exception& e) {
		cout << "�������: " << e.what() << endl;
	}
}

void show_teacher_array(vector<Teacher*> &teachers) {
	if (!teachers.empty())
	{
		cout << "�����i�� ��������� ��� ������ i�������i�" << endl;
		int num;
		string command;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num;
		cout << "�����/�������" << endl;
		cin >> command;
		if (command == "�����" || command == "1")
		{
			teachers[num - 1]->show();
		}
		else if(command == "�������" || command == "2")
		{
			teachers[num - 1]->get_course()->show();
		}
	}
	else
	{
		cout << "���� ��������i�" << endl;
	}
}

void show_course(vector<Teacher*> &teachers) {
	if (!teachers.empty())
	{
		cout << "�����i�� ��������� ��� ������ i�������i�" << endl;
		int num;
		string command;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num;
		cout << "�����" << endl;
		cin >> command;
		if (command == "�����" || command == "1")
		{
			teachers[num - 1]->get_course()->show();
		}
	}
	else
	{
		cout << "���� ����i�" << endl;
	}
}

void show_Department(Department<string, Course> &department) {
	cout << "i�������i� ��� ���������: " << department.get_name() << endl;
	cout << "i�'�: " << department.get_name() << endl;
	cout << "�����: " << endl;
	for (int i = 0; i < department.get_courseArray().size(); i++){
	
		cout << department.get_courseArray()[i]->get_name() << endl;

	}
}




void set_grades(vector<Teacher*>& teachers, vector<Student*>& students) {
		try
		{
			if (students.empty())
			{
				throw runtime_error("�������i� ����");
			}
			if (teachers.empty())
			{
				throw runtime_error("��������i� ����");
			}
			cout << "�����i�� ���������" << endl;
			int num1, num2, num3;
			string command;
			for (int i = 0; i < teachers.size(); i++)
			{
				cout << i + 1 << " " << teachers[i]->get_name() << endl;
			}
			cin >> num1;
			cout << "�����i�� ��������" << endl;
			for (int i = 0; i < students.size(); i++)
			{
				cout << i + 1 << " " << students[i]->get_name() << endl;
			}
			cin >> num2;
			cout << "����������� ������/������" << endl;
			cin >> command;
			if (command == "������" || command == "1")
			{
				cout << "��i���� �������i� ������ ������ (�� 5)" << endl;
				cin >> num3;
				teachers[num1 - 1]->assigns_grade(students[num2 - 1], num3);
			}
			else if (command == "������" || command == "2")
			{
				teachers[num1 - 1]->assigns_grade(students[num2 - 1]);
			}

		}
		catch (const exception& e) {
			cout << "�������: " << e.what() << endl;
		}

}

void subscription_on_course(vector<Student*>& students, vector<Teacher*>& teachers) {
	
		cout << "�����i�� �������� ���� ���� ���������� �� ����:" << endl;
		int num1, num2;
		string command;
		for (int i = 0; i < students.size(); i++)
		{
			cout << i + 1 << ". " << students[i]->get_name() << endl;
		}
		cin >> num1;
		cout << "�����i�� ��������� ��� ������ �� ����" << endl;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> num2;

		students[num1 - 1]->subscription_on_course(teachers[num2 - 1]->get_course());

}

void unsubscribe_on_course(vector<Student*>& students, vector<Teacher*>& teachers) {

	cout << "�����i�� �������� ���� ���� �i���������� � �����:" << endl;
	int num1, num2;
	string command;
	for (int i = 0; i < students.size(); i++)
	{
		cout << i + 1 << ". " << students[i]->get_name() << endl;
	}
	cin >> num1;
	cout << "�����i�� ��������� �����:" << endl;
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
			throw runtime_error("�� ������� ������� ����.");
		}

		for (int i = 0; i < students.size(); i++) {
			file << "�������" << endl;
			file << "I�'�: " << students[i]->get_name() << endl;
			file << "³�: " << students[i]->get_age() << endl;
			file << "Id: " << students[i]->get_id() << endl;
			file << "�����: " << students[i]->get_email() << endl;
			file << "����� ��������: " << students[i]->get_phone_number() << endl;
			file << "�������: " << students[i]->get_rating() << endl;
			file << "������:" << endl;
			for (const auto& grade : students[i]->grade_stud) {
				file << " " << grade.first << ": " << grade.second << endl;
			}
			file << endl;
		}

		file.close();
	}
	catch (const exception& e) {
		std::cerr << "�������: " << e.what() << endl;
	}
}

void readStudentsFromFile(vector<Student*>& students, string filename) {
	try {
		ifstream file("students.txt");
		
		if (!file.is_open()) {
			throw runtime_error("�� ������� ������� ����.");
		}
		
		string line;
		while (getline(file, line)) {
			if (line == "�������") {

				getline(file, line); 
				string name = line.substr(6); // �������� ��'�

				getline(file, line); 
				int age = stoi(line.substr(5)); // �������� ��
				
				Student* student = new Student(name, age);

				getline(file, line); 
				int id = stoi(line.substr(4)); // �������� id

				getline(file, line); 
				string email = line.substr(7); // �������� email

				getline(file, line); 
				string phone_number = line.substr(16); // �������� ����� ��������

				getline(file, line);
				string rating = line.substr(9); // �������� �������

				student->add_info(id, email, phone_number);
				*student += stoi(rating);

				getline(file, line); 

				while(1) 
				{
					getline(file, line);  // ������ ����� � �������

					if (line.empty() || line == "�������" || file.eof()) {
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
				//	getline(file, line); // ������ ����� � �������
				//	size_t pos = line.find(":");
				//	if (pos != string::npos) {
				//		string subject = line.substr(0, pos);
				//		int mark = stoi(line.substr(pos + 1));

				//		student->grade_stud.insert({ subject, mark });
				//	}
				//}
				

				students.push_back(student); // ������ �������� �� �������
				/*delete student;*/
				
			}
		}

		file.close();
	}
	catch (const exception& e) {
		std::cerr << "�������: " << e.what() << endl;
	}
}

void writeTeacherToFile(vector<Teacher*>& teachers, string filename) {
	ofstream file(filename, ios::trunc);
	if (!file.is_open()) {
		cerr << "������� �������� ����� ��� ������ �������." << endl;
		return;
	}
	for (int i = 0; i < teachers.size(); i++)
	{
		file << "��������" << endl;
		file << "I�'�: " << teachers[i]->get_name() << endl;
		file << "�i�: " << teachers[i]->get_age() << endl;
		if (teachers[i]->get_id() != NULL || teachers[i]->get_email() != "" || teachers[i]->get_phone_number() != "" || teachers[i]->get_teaching_experience() != "") {
			file << "Id: " << teachers[i]->get_id() << endl;
			file << "�����: " << teachers[i]->get_email() << endl;
			file << "����� ��������: " << teachers[i]->get_phone_number() << endl;
			file << "�����: " << teachers[i]->get_teaching_experience() << endl;
		}
		
		if (teachers[i]->get_course()) {
			file << "����� �����: " << teachers[i]->get_course()->get_name() << endl;
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
			throw runtime_error("�� ������� ������� ����.");
		}
	
		string line, line2;
		while (getline(file, line)) {
			if (line == "��������") {

				getline(file, line);
				string name = line.substr(6); // �������� ��'�

				getline(file, line);
				int age = stoi(line.substr(5)); // �������� ��

				Teacher* teacher = new Teacher(name, age);

				getline(file, line);
				int id = stoi(line.substr(4)); // �������� id

				getline(file, line);
				string email = line.substr(7); // �������� email

				getline(file, line);
				string phone_number = line.substr(16); // �������� ����� ��������

				getline(file, line);
				string teaching_experience = line.substr(8); // �������� �����

				
				teacher->add_info(email, phone_number, teaching_experience);
				teacher->set_id(id);
				
				getline(file, line);
				if (line.find("����� �����: ") != string::npos) {
					string courseNameTeach = line.substr(13); // �������� ��'� �����

					getline(file, line);
					int courseIdTeach = stoi(line.substr(4)); // �������� id �����
					
					ifstream file2(filename2);
					while (getline(file2, line2)) {
						if (line2 == "����") {
							getline(file2, line2);
							string courseName = line2.substr(13); // �������� ��'�

							getline(file2, line2);
							int courseId = stoi(line2.substr(4)); // �������� id �����
							
							if (courseNameTeach == courseName && courseIdTeach == courseId)
							{
								getline(file2, line2);
								int maxStudent = stoi(line2.substr(33)); // �������� ����������� �i���i��� �������i�

								teacher->create_course(courseName, maxStudent , courseId);

								bool stop = false;
								while (getline(file2, line2)) {

									if (stop){break;}
									
									if (line2.find("��������: ") != string::npos) {
										while (getline(file2, line2)) {
											if (line2.find("����") != string::npos) {
												stop = true;
												break;  // ��������� ����, ���� ������� �������� ��������� "����"
												
											}
											if (!line2.empty()) {
												size_t pos = line2.find("Id: ");
												if (pos != string::npos) {
													int id = stoi(line2.substr(pos + 4));

													// ��������� �������� �� Id � ������
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

				teachers.push_back(teacher); // ������ ������� �� �������
			}
		}
		
		file.close();
	}
	catch (const exception& e) {
		cerr << "�������: " << e.what() << endl;
	}
}

void saveCoursesToFile(vector<Teacher*>& teachers, string filename) {
	ofstream file(filename, ios::trunc);
	if (!file.is_open()) {
		cerr << "������� �������� ����� ��� ������." << endl;
		return;
	}
	
	for (int i = 0; i < teachers.size(); i++)
	{

		Course *course = teachers[i]->get_course();

		file << "����" << endl;
		file << "����� �����: " << course->get_name() << endl;
		file << "Id: " << course->get_course_code() << endl;
		file << "����������� �i���i��� �������i�: " << course->get_maxStudent() << endl;
		file << "�i���i��� �������i� �� ����i: " << course->get_studentMap().size() << endl;

		file << "��������: " << endl;
		int count = 1;
		for (const auto& pair : course->get_studentMap()) {
			file << count << ". " << "��'�: " << pair.first->get_name() << ", Id: " << pair.second << endl;
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
			throw runtime_error("��'���i� ����");
		}

		cout << "���� �� ������ ��������?" << endl;
		int num;

		for (int i = 0; i < items.size(); i++) {
			cout << i + 1 << " " << items[i]->get_name() << endl;
		}

		cin >> num;

		if (num >= 1 && num <= items.size()) {
			auto it = items.begin() + (num - 1);
			delete* it;												// ��������� ��'����
			items.erase(it);										// ��������� ��������� � �������
			cout << "��'��� ��������� � �������." << endl;
		}
		else {
			cout << "������� ����������� ����� ��������." << endl;
		}
	}
	catch (const exception& e) {
		cout << "�������: " << e.what() << endl;
	}
}

void delete_course(vector<Teacher*>& teachers) {

	cout << "�����i�� ��������� ��� ��������� �����" << endl;
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
		cout << "� ����� ��������� ���� �����" << endl;
	}
	
}

void rating(vector<Student*>& students, vector<Teacher*>& teachers) {
	try{
		if (teachers.empty())
		{
			throw std::runtime_error("���������� ����");
		}
		if (students.empty())
		{
			throw std::runtime_error("�������i� ����");
		}

		int teach, stud;
		string num3, num4, num5;
		cout << "�����i�� ��������� ��� ����������� ��������" << endl;
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << i + 1 << " " << teachers[i]->get_name() << endl;
		}
		cin >> teach;
		cout << "�����i�� �������� ��������" << endl;
		
		for (int i = 0; i < students.size(); i++)
		{
			cout << i + 1 << " " << students[i]->get_name() << endl;
		}
		cin >> stud;

		cout << "��i������ �� �������� �������?" << endl
			<< "1. ��i������" << endl
			<< "2. ��������" << endl;

		cin >> num3;
		if (num3 == "1")
		{
			cout << "��i������ �� ��i����?" << endl
				 << "1. ��i������" << endl
				 << "2. �� ��i����" << endl;
			cin >> num4;
			if (num4 == "1")
			{
				++(*students[stud - 1]);
			}
			else if (num4 == "2")
			{
				int num6;
				cout << "�i���i��� ��������" << endl;
				cin >> num6;
				(*students[stud - 1]) += num6;
			}
			
		}
		if (num3 == "2")
		{
			cout << "�������� �� ��i����?" << endl
				<< "1. ��������" << endl
				<< "2. �� ��i����" << endl;
			cin >> num4;
			if (num4 == "1")
			{
				--(*students[stud - 1]);
			}
			else if (num4 == "2")
			{
				int num6;
				cout << "�i���i��� ��������" << endl;
				cin >> num6;
				(*students[stud - 1]) -= num6;
			}
		}
	}
	catch (const exception& e) {
		cout << "�������: " << e.what() << endl;
	}
}

inline void available_places_on_course(vector<Teacher*>& teachers) {
	cout << "�����i�� ��������� ��� ������ i�������i�" << endl;
	int num;
	string command;
	for (int i = 0; i < teachers.size(); i++)
	{
		cout << i + 1 << " " << teachers[i]->get_name() << endl;
	}
	cin >> num;

	cout << "�i���i��� �i��� � ����i: " << teachers[num - 1]->get_course()->get_maxStudent() - teachers[num - 1]->get_course()->get_studentCount() << endl;
};

inline void show_average_grade(vector<Teacher*>& teachers)
{
	cout << "�����i�� ��������� ��� ������ i�������i�" << endl;
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
		cout << "������i� ��� �������i� �� ����i " << teachers[num - 1]->get_course()->get_name() << " - " << average << endl;
	}
	else {
		cout << "��i��� �i�����i �� ����i: " << teachers[num - 1]->get_course()->get_name() << endl;
	}
}
