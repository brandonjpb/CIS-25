#include "pch.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	double num1, num2;
	char operation;

	cout << "Enter operation (+, -, /, * only): " << endl;
	cin >> operation;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	switch (operation) {
	case '+':
		cout << "Result: " << (num1 + num2) << endl;
		break;
	case '-':		
		cout << "Result: " << (num1 - num2) << endl;
		break;
	case '/':
		if (num2 == 0)
			cout << "Invalid number! Cannot divide by zero.";
			break;
		else
		cout << "Result: " << (num1 / num2) << endl;
		break;
	case '*':
		cout << "Result: " << (num1 * num2) << endl;
		break;
	default:
		cout << "Please enter valid input." << endl;
		break;
	}
	return 0;
}