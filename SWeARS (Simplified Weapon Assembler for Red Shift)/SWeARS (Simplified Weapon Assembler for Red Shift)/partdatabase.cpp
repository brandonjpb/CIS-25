#include "partdatabase.h"
#include <fstream>
#include <iostream>

void PartDatabase::addPart(const Part& part) {
    parts.push_back(part);
}

std::vector<Part> PartDatabase::getPartsByType(PartType type) const {
    std::vector<Part> result;
    for (const auto& part : parts) {
        if (part.type == type) result.push_back(part);
    }
    return result;
}

// Database saving function
bool PartDatabase::saveToBinary(const std::string& filename) const {
    std::ofstream out(filename, std::ios::binary);
    if (!out) return false;

    // Saves string length and chars
    uint32_t count = parts.size();
    out.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (const Part& p : parts) {
        size_t nameLen = p.name.size();
        size_t ammoLen = p.ammoType.size();

        // Reinterpret as char to ensure uniformity of .bin storage
        out.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        out.write(p.name.data(), nameLen);

        out.write(reinterpret_cast<const char*>(&p.type), sizeof(p.type));
        out.write(reinterpret_cast<const char*>(&p.hitDieModifier), sizeof(p.hitDieModifier));
        out.write(reinterpret_cast<const char*>(&p.damageDieModifier), sizeof(p.damageDieModifier));
        out.write(reinterpret_cast<const char*>(&p.rangeModifier), sizeof(p.rangeModifier));

        out.write(reinterpret_cast<const char*>(&ammoLen), sizeof(ammoLen));
        out.write(p.ammoType.data(), ammoLen);

        out.write(reinterpret_cast<const char*>(&p.compatibilityMask), sizeof(p.compatibilityMask));
        out.write(reinterpret_cast<const char*>(&p.exclusionMask), sizeof(p.exclusionMask));
    }
    return true;
}

// Same as saving to .bin but in reverse - parse binary to char 
bool PartDatabase::loadFromBinary(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) return false;

    uint32_t count;
    in.read(reinterpret_cast<char*>(&count), sizeof(count));

    parts.clear();

    for (uint32_t i = 0; i < count; ++i) {
        Part p;
        size_t nameLen, ammoLen;

        in.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        p.name.resize(nameLen);
        in.read(&p.name[0], nameLen);

        in.read(reinterpret_cast<char*>(&p.type), sizeof(p.type));
        in.read(reinterpret_cast<char*>(&p.hitDieModifier), sizeof(p.hitDieModifier));
        in.read(reinterpret_cast<char*>(&p.damageDieModifier), sizeof(p.damageDieModifier));
        in.read(reinterpret_cast<char*>(&p.rangeModifier), sizeof(p.rangeModifier));

        in.read(reinterpret_cast<char*>(&ammoLen), sizeof(ammoLen));
        p.ammoType.resize(ammoLen);
        in.read(&p.ammoType[0], ammoLen);

        in.read(reinterpret_cast<char*>(&p.compatibilityMask), sizeof(p.compatibilityMask));
        in.read(reinterpret_cast<char*>(&p.exclusionMask), sizeof(p.exclusionMask));

        parts.push_back(p);
    }

    return true;
}

// Some default parts
void PartDatabase::loadDefaultParts() {
    addPart({ "Basic Receiver", PartType::RECEIVER, 1, 1, 5, "Standard", 0b0001, 0b0000 });
    addPart({ "Sniper Receiver", PartType::RECEIVER, 2, 3, 10, "Heavy", 0b0010, 0b0100 });

    addPart({ "Short Barrel", PartType::BARREL, 0, 1, -2, "", 0b0001, 0b0000 });
    addPart({ "Long Barrel", PartType::BARREL, 1, 2, 5, "", 0b0010, 0b1000 });

    addPart({ "Red Dot Sight", PartType::SIGHT, 0, 1, 1, "", 0b0001, 0b0000 });
    addPart({ "Scope", PartType::SIGHT, 0, 2, 4, "", 0b0010, 0b0000 });
}

void PartDatabase::addPartFromUser() {

    std::string name;
    int type, hitDie, damageDie, range;
    std::string ammoType;
    uint32_t compatibilityMask, exclusionMask;

    std::cout << "Enter part name: ";
    std::getline(std::cin, name);

    std::cout << "Enter part type (1: Receiver, 2: Barrel, 3: Sight): ";
    std::cin >> type;

    std::cout << "Enter hit die modifier: ";
    std::cin >> hitDie;

    std::cout << "Enter damage die modifier: ";
    std::cin >> damageDie;

    std::cout << "Enter range modifier: ";
    std::cin >> range;

    std::cout << "Enter ammo type: ";
    std::cin.ignore();
    std::getline(std::cin, ammoType);

    std::cout << "Enter compatibility mask (binary format): ";
    std::cin >> compatibilityMask;

    std::cout << "Enter exclusion mask (binary format): ";
    std::cin >> exclusionMask;

    addPart({ name, static_cast<PartType>(type), hitDie, damageDie, range, ammoType, compatibilityMask, exclusionMask });

    saveToBinary("parts.bin");
}
