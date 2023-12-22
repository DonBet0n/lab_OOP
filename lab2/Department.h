#pragma once

#include "Course.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template<typename T, typename C>
class Department {
public:
    Department();
    Department(T name);
    void add_course(C& courseName);
    int get_curse_count();
    void set_name(T name);
    T get_name();
    void show();

    vector<C*> get_courseArray();
    ~Department();

private:
    T name;
    vector <C*> courseArray;
};



template<typename T, typename C>
Department<T, C>::Department() {
    this->name = T("Факультет");
}

template<typename T, typename C>
Department<T, C>::Department(T name) {
    this->name = name;
}

template<typename T, typename C>
void Department<T, C>::set_name(T name) {
    this->name = name;
}

template<typename T, typename C>
void Department<T, C>::show() {
    cout << "Курси на факультетi: " << get_name() << endl;
    for (int i = 0; i < courseArray.size(); i++) {
        cout << i + 1 << ". " << courseArray[i]->get_name() << endl;
    }
}

template<typename T, typename C>
void Department<T, C>::add_course(C& courseName) {
    courseArray.push_back(&courseName);
}

template<typename T, typename C>
T Department<T, C>::get_name() {
    return this->name;
}

template<typename T, typename C>
int Department<T, C>::get_curse_count() {
    return courseArray.size();
}

template<typename T, typename C>
vector<C*> Department<T, C>::get_courseArray() {
    return courseArray;
}

template<typename T, typename C>
Department<T, C>::~Department() {
    for (auto& course : courseArray) {
        delete course;
    }
}

//class Department {
//public:
//	Department();
//	Department(string name);
//	void add_course(Course& courseName);
//	int get_curse_count();
//	void set_name(string name);
//	string get_name();
//	void show();
//	vector<Course*> get_courseArray();
//	~Department();
//private:
//	string name;
//	vector<Course*> courseArray;
//
//};