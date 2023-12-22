#include <iostream>
#include "Human.h"

using namespace std;

void Human::show() {
	cout << "Iм'я: " << name << endl;
	cout << "Вiк: " << age << endl;
	if (id != NULL || email != "" || phone_number != "")
	{
		cout << "Id: " << id << endl;
		cout << "Емейл: " << email << endl;
		cout << "Номер телефону: " << phone_number << endl;
	}
}


