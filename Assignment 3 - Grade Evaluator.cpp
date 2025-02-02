#include "pch.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    // Declare variable, get score
    int score;
    cout << "Enter your score in whole numbers: " << endl;
    cin >> score;
    // Logic to output proper feedback
    if (score < 60) {
        std::cout << "Fail" << std::endl;
    }
    else if (score >= 60 && score <= 69) {
        std::cout << "Pass" << std::endl;
    }
    else if (score >= 70 && score <= 89) {
        std::cout << "Good" << std::endl;
    }
    else if (score >= 90) {
        std::cout << "Excellent" << std::endl;
    }
    // Error handling; ensures user inputs only whole numbers
    else {
        std::cout << "Invalid score" << std::endl;
    }
    return 0;
}