#include "iofile.h"
#include <fstream>
#include <iostream>

void saveWeaponToTextFile(const Weapon& weapon, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Failed to write weapon to " << filename << "\n";
        return;
    }

    file << "--------------------------\n";
    file << "         Weapon Info       \n";
    file << "--------------------------\n";
    file << " Name        : " << weapon.name << "\n";
    file << " Hit Die     : " << weapon.hitDie << "\n";
    file << " Damage Die  : " << weapon.damageDie << "\n";
    file << " Range       : " << weapon.rangeMin << " - " << weapon.rangeMax << "\n";
    file << " Ammo Type   : " << weapon.ammoType << "\n";
    file << "--------------------------\n";
    file << "      Weapon Parts         \n";
    file << "--------------------------\n";
    for (const auto& part : weapon.parts) {
        file << " - " << part.name << "\n";
    }
    file << "--------------------------\n";
