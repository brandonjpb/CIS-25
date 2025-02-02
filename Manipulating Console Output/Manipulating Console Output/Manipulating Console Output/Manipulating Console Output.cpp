#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    // Declare variables and set max size to 100
    int i = 0;
    int employeeID[100];
    string employeeName[100];
    double dailyBalance[100];

    // Loop to input data
    // 00000 is exit command
    do {
        cout << "Input employee ID (or 0 to exit): ";
        cin >> employeeID[i];

    // Break command
        if (employeeID[i] == 0) {
            break;
        }
        cout << "Input employee name: ";

    // cin.ignore took me a while to figure out, it's there to clear the previous line's data to ensure we're getting ONLY the name
        cin.ignore();
        getline(cin, employeeName[i]);

        cout << "Input daily balance (enter numbers only, no '$' or ',' allowed): ";
        cin >> dailyBalance[i];

    // Incrementing index
        i++;
    } while (i < 100);

    // Draws the table header, left aligned with padding
    cout << endl << setw(20) << left << "Employee ID"
        << " | " << setw(20) << left << "Employee Name"
        << " | " << setw(20) << "Daily Balance" << endl;
    cout << string(60, '=') << endl;

    // Fill table using c as a comparitor to i to draw the correct amount of lines
    for (int c = 0; c < i; c++) {
        cout << setw(20) << left << employeeID[c]
            << " | " << setw(20) << left << employeeName[c]
            << " | " << setw(20) << fixed << setprecision(2) << dailyBalance[c] << endl;
    }
    return 0;
}