#include "PhoneBook.h"
#include<list>
#include<iostream>
#include<fstream>
using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");


list<Contact> contacts;
const string fileName = "Contakts.txt";

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();

	if (isOpen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		Contact oldContact;
		while (!fin.eof()) {
			currentString++;

			getline(fin,data);
			if (currentString == 1) {
				oldContact.FullName = data;
			}
			else {
				oldContact.PhoneNumber = data;
				currentString = 0;
				contacts.push_back(oldContact);
				oldContact = Contact();
			}
		}
	}
}

void addNewContact()
{
	Contact newcontact;
	cout << "Enter full name for new contact:";
	cin.ignore();
	getline(cin, newcontact.FullName);
	cout << "Enter phone number for new contact:";
	cin >> newcontact.PhoneNumber;

	contacts.push_back(newcontact);
	ofstream fout;
	fout.open(fileName,fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file" << endl;
	}else {
		fout << newcontact.FullName<<endl;
		fout << newcontact.PhoneNumber << endl;

	}
	fout.close();
	cout << "New contact succssful added..." << endl;
	PAUSE
	CLEAR
}

void ShowAllContacts()
{
	for (Contact item:contacts)
	{
		cout << item.FullName << " - " << item.PhoneNumber << endl;
	}
}
