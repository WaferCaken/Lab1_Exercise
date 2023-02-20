// Lab 1.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;


int get_integer_with_prompt(string prompt)
{
	int value = 0;

	do {
		if (cin.fail()) {
			// cin fails to convert to integer, clear the flag.
			cin.clear();
			cout << "That's not a number!\n";
			// flush stdin, so we can get a new value.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cout << prompt << std::flush;
	} while (!(cin >> value));
	// flush stdin, for line returns or other data.
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return value;
}

string get_string_with_prompt(string prompt)
{
	string value;

	if (cin.fail()) {
		// cin fails to convert to string, clear the flag.
		cin.clear();
		// flush stdin, so we can get a new value.
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << prompt << std::flush;
	cin >> value;
	// flush stdin, for line returns or other data.
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return value;
}

int main()
{
	int choice = 0;

	string name = "";
	// use int for age so we can increment value.
	int age = 0;
	string occup = "";
	string prompt = "-1: Exit\n"
		"1: Enter Name\n"
		"2: Enter Age\n"
		"3: Enter Occupation\n";

	while (choice != -1)
	{
		choice = get_integer_with_prompt(prompt);
		
		if (choice == -1) {
			break;
		}
		switch (choice)
		{
		case 1:
			name = get_string_with_prompt("What is your Name: ");
			break;
		case 2:
			age = get_integer_with_prompt("What is your Age? ");
			break;
		case 3:
			occup = get_string_with_prompt("What is your Occupation? ");
			break;
		default:
			// Assume Invalid Menu Choice
			cout << "Sorry that choice is not valid!\n";
			break;
		}
	}

	age += 1;

	cout << "Thank you for using our application, " << name << " and hope your career in " << occup << " is successful.";
	cout << "Hope your " << age << " birthday will enjoyable and exciting";

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
