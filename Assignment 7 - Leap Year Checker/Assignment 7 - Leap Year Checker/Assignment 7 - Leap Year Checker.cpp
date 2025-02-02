#include "pch.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	// Get user input
	int year;
	cout << "Enter year: " << endl;
	cin >> year;

	// Logic to determine if it's a leap year or not
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		cout << year << " is a leap year!";
	}
	else{
		cout << year << " is not a leap year." << endl;
	}
	return 0;
}