#pragma once
#include <string>
#include <vector>
#include <cstdint>

enum class PartType {
    RECEIVER,
    BARREL,
    SIGHT
};

enum class FrameType {
    BALLISTIC,
    PLASMA,
    LASER
};

struct Part {
    std::string name;
    PartType type;

    int hitDieModifier;
    int damageDieModifier;
    int rangeModifier;

    std::string ammoType;

    uint32_t compatibilityMask;
    uint32_t exclusionMask;

    FrameType frameType;
};

struct Weapon {
    std::string name;

    int hitDie;
    int damageDie;
    int rangeMin;
    int rangeMax;

    std::string ammoType;
    std::vector<Part> parts;
};
