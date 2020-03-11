#pragma once
#include<string>
using namespace std;

struct Contact {

	string FullName;
	string PhoneNumber;

};

void init();
void addNewContact();
void ShowAllContacts();
