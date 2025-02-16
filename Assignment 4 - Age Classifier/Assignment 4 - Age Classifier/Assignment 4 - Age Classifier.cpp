#include "pch.h"
#include <iostream>
using namespace std;

int main() {
    int age;

    // Input age from the user
    cout << "Enter the age: ";
    cin >> age;

    // Logic to categorize by age
    if (age < 12) {
        cout << "Child" << endl;
    }
    else if (age >= 12 && age <= 19) {
        cout << "Teen" << endl;
    }
    else if (age >= 20 && age <= 64) {
        cout << "Adult" << endl;
    }
    else {
        cout << "Senior" << endl;
    }

    return 0;
}
