#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;


int main() {

	// Conversion rate table, accurate as of 2/2/2025
	float rates[4][4] = {
		{1.00, 0.98, 0.81, 154.85},     // USD -> USD, EUR, GBP, JPY
		{1.02, 1.00, 0.83, 157.96},     // EUR -> USD, EUR, GBP, JPY
		{1.23, 1.20, 1.00, 189.42},     // GBP -> USD, EUR, GBP, JPY
		{0.0065, 0.0063, 0.0053, 1.00}, // JPY -> USD, EUR, GBP, JPY
	};

	// Initialize variables; index for in and out begins at -1 for proper input checking
	string currencies[4] = { "USD", "EUR", "GBP", "JPY" };
	int indexIn = -1, indexOut = -1;
	float amountIn, amountOut;
	string currencyIn, currencyOut;
	char Promotion;

	// Get input
	cout << "Enter currency to be converted (USD, EUR, GBP, JPY): " << endl;
	cin >> currencyIn;
	cout << "Enter desired currency (USD, EUR, GBP, JPY): " << endl;
	cin >> currencyOut;
	cout << "Enter amount in numbers only: " << endl;
	cin >> amountIn;
	cout << "Promotional conversion rate? " << endl;
	cin >> Promotion;
	if (Promotion == 'y' || Promotion == 'Y')
		amountIn = amountIn * 1.05;


	// Loop to find proper index using i as the index counter - increases by 1 and ensures i does not exceed 3 (4x4 2d array)
	// When the input string matches the string in the table, it assigns i to that index number (for both in and out)
	for (int i = 0; i < 4; i++) {
		if (currencies[i] == currencyIn) indexIn = i;
		if (currencies[i] == currencyOut) indexOut = i;
	}

	// Check for invalid input; if the above loop does not change values of indexIn or indexOut, error message will be displayed
	if (indexIn == -1 || indexOut == -1) {
		cout << "Invalid currency type entered!" << endl;
	}

	// Calculation of currency conversion by indexing the 2d array for conversion rate
	amountOut = amountIn * rates[indexIn][indexOut];
	cout << "Converted amount: " << fixed << setprecision(2) << amountOut << " " << currencyOut << endl;
		return 0;
}