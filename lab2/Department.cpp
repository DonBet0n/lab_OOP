
#include "Course.h"
#include "Department.h"

#include <iostream>

using namespace std;

//template<typename T, typename C>
//Department<T,C>::Department() {
//    this->name = T("Факультет");
//}
//
//template<typename T, typename C>
//Department<T, C>::Department(T name) {
//    this->name = name;
//}
//
//template<typename T, typename C>
//void Department<T, C>::set_name(T name) {
//    this->name = name;
//}
//
//template<typename T, typename C>
//void Department<T, C>::show() {
//    cout << "Курси на факультетi: " << get_name() << endl;
//    for (int i = 0; i < courseArray.size(); i++) {
//        cout << i + 1 << ". " << courseArray[i]->get_name() << endl;
//    }
//}
//
//template<typename T, typename C>
//void Department<T, C>::add_course(C& courseName) {
//    courseArray.push_back(&courseName);
//}
//
//template<typename T, typename C>
//T Department<T, C>::get_name() {
//    return this->name;
//}
//
//template<typename T, typename C>
//int Department<T, C>::get_curse_count() {
//    return courseArray.size();
//}
//
//template<typename T, typename C>
//vector<C*> Department<T, C>::get_courseArray() {
//    return courseArray;
//}
//
//template<typename T, typename C>
//Department<T,C>::~Department() {
//    for (auto& course : courseArray) {
//        delete course;
//    }
//}


//Department::Department() {
//	this->name = "Факультет";
//}
//Department::Department(string name) {
//	this->name = name;
//}
//void Department::set_name(string name) {
//	this->name = name;
//}
//
//void Department::show() {
//	cout << "Курси на факультетi: " << get_name() << endl;
//	for (int i = 0; i < courseArray.size(); i++)
//	{
//		cout << i + 1 << ". " << courseArray[i]->get_name() << endl;
//	}
//}
//
//void Department::add_course(Course& courseName) {
//	courseArray.push_back(&courseName);
//}
//string Department::get_name() {
//	return this->name;
//}
//int Department::get_curse_count() {
//	return courseArray.size();
//}
//
//
//vector<Course*> Department::get_courseArray() {
//	return courseArray;
//}
//Department::~Department() {
//	for (auto& course : courseArray) {
//		delete course; // Звільнення курсів, на які посилаються вектори
//	}
//}
