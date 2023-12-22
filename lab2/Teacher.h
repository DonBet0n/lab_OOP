#pragma once

#include "Human.h"
#include "Student.h"
#include "Course.h"

using namespace std;

class Teacher : public Human
{
public:
	Teacher(string name, int age);													//����������� ��� ��������
	void create_course(string courseName, int maxStudent, int courseCode);			//��������� �����
	void assigns_grade(Student* new_student);										//��������� ���������� ������
	void assigns_grade(Student* new_student, int count);								//������ ������ ��� ��������
	void add_info(string email, string phone_number, string teaching_experience);	//������ ����� ���������� ��� �������

	void set_id(int id);

	void show() override;

	Course* get_course();															//�������� ���� �����
	string get_name();
	int get_age();
	int get_id();
	string get_email();
	string get_phone_number();
	string get_teaching_experience();


	~Teacher() override {}
private:
	Course teacherCourse;
	string teaching_experience;
};