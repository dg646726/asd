#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include "PhoneBook.h"

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define CLEAR system("cls");
#define PAUSE system("pause");


int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));

	init();
	int action = 0;

	do
	{

		cout << "\tMenu" << endl;
		cout << "1.Add new contact" << endl;
		cout << "2.Show all contacts" << endl;
		cout << "3.Exit" << endl;
		cout << endl;
		cout << "Select action:";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			cout << "ADD NEW CONTACT:" << endl;
			addNewContact();
			break;
		case 2:
			cout << "LIST ALL CONTACTS:" << endl;
			ShowAllContacts();
			PAUSE
			CLEAR
			break;
		case 3:
			cout << "Bye" << endl;
			break;
		default:
			cout << "Please select action (1 - 3)" << endl;
			break;
		}
	} while (action != 3);




	system("pause");
	return 0;
}