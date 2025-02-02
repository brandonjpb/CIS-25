#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

int main() {
    // Random number using time as a seed
    long elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);

    // Arrays for Rank and Suit
    string arrRank[13]{ "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    string arrSuit[4]{ "Spades", "Hearts", "Clubs", "Diamonds" };

    // Selection of random card
    int card = rand() % 52;
    int suit = card / 13;
    int rank = card % 13;

    // Determines length of the string for Rank and Suit to fill with the proper amount of '-'
    // fillLength: 40 total width, 14 for label, 4 for " of "
    string rankStr = arrRank[rank];
    string suitStr = arrSuit[suit];
    int rankSuitLength = rankStr.length() + suitStr.length();
    int fillLength = 40 - 14 - 4 - rankSuitLength;

    // Print output
    cout << string(40, '*') << endl << endl;
    cout << left << "Casino Card: " << setfill('-') << setw(fillLength) << "" << right << arrRank[rank] << " of " << arrSuit[suit] << endl << endl;
    cout << string(40, '*') << endl;
    return 0;
}
