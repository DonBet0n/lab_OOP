#pragma once

#include "Human.h"
//#include "Course.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Course;

class Student : virtual public Human
{
public:
	Student();
	Student(string name, int age);														//�����������
	Student(string name, int age, int id, string email, string phone_number) :			//����������� �����������
		Human(name, age, id, email, phone_number) {}

	Student(const Student& other) :														//����������� ���������
		Human(other) {}
	
	void subscription_on_course(Course *courseName);									//����� ������� �� ����
	void unbscription_on_course(Course* courseName);
	void add_info(int id, string email, string phone_number);							//��������� �������� ����������
		
	
	/*void test() override {
		cout << "��������� ����� ��������� ������� � ��������� ����." << endl;
	};*/

	

	string get_name();																	//�������� ��'� ��������
	int get_age();
	int get_id();
	string get_email();
	string get_phone_number();
	int get_rating();

	
	Student& operator++() {									// �������������� ����������� ��������� "++"
		rating++;
		return *this;
	}

	Student& operator--() {									// �������������� ����������� ��������� "--"
		rating--;
		return *this;
	}
	
	Student& operator+=(int num) {
		rating += num;
		return *this;
	}
	Student& operator-=(int num) {
		rating -= num;
		return *this;
	}

	int operator[](const string& subject) {
		auto it = grade_stud.find(subject);
		if (it != grade_stud.end()) {
			return it->second;
		}
		else {
			return 0; 
		}
	}

	


	void show() override;																//�������� ���������� ��� ��������
	void show_grades();

	multimap<string, int> grade_stud;
	

	~Student() override;
private:
	int rating;
};
