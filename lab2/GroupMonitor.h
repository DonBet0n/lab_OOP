#pragma once

#include "Human.h"
#include "Student.h"

using namespace std;

class GroupMonitor : public Student, public Human {
public:
	GroupMonitor() : Student() {};
	GroupMonitor(string name, int age) : Student(name, age) {};

	virtual ~GroupMonitor() override {}
};