#include "weapongen.h"
#include <random>

bool isCompatible(const Part& a, const Part& b) {
    if ((a.compatibilityMask & b.exclusionMask) != 0) return false;
    if ((b.compatibilityMask & a.exclusionMask) != 0) return false;
    return true;
}

Weapon generateWeapon(const PartDatabase& db) {
    Weapon weapon = { "Generated Weapon", 0, 0, 0, 0, "Unknown", {} };

    std::random_device rd;
    std::mt19937 rng(rd());

    auto receivers = db.getPartsByType(PartType::RECEIVER);
    auto barrels = db.getPartsByType(PartType::BARREL);
    auto sights = db.getPartsByType(PartType::SIGHT);

    if (receivers.empty() || barrels.empty() || sights.empty()) return weapon;

    std::uniform_int_distribution<> recDist(0, receivers.size() - 1);
    std::uniform_int_distribution<> barDist(0, barrels.size() - 1);
    std::uniform_int_distribution<> sigDist(0, sights.size() - 1);

    Part receiver = receivers[recDist(rng)];
    Part barrel = barrels[barDist(rng)];
    Part sight = sights[sigDist(rng)];

    if (!isCompatible(receiver, barrel) || !isCompatible(receiver, sight) || !isCompatible(barrel, sight)) {
        return generateWeapon(db); // Try again
    }

    weapon.parts = { receiver, barrel, sight };

    weapon.hitDie = receiver.hitDieModifier + barrel.hitDieModifier + sight.hitDieModifier;
    weapon.damageDie = receiver.damageDieModifier + barrel.damageDieModifier + sight.damageDieModifier;

    int rangeSum = receiver.rangeModifier + barrel.rangeModifier + sight.rangeModifier;
    weapon.rangeMin = rangeSum / 2;
    weapon.rangeMax = rangeSum;

    if (!receiver.ammoType.empty()) weapon.ammoType = receiver.ammoType;
    else if (!barrel.ammoType.empty()) weapon.ammoType = barrel.ammoType;
    else if (!sight.ammoType.empty()) weapon.ammoType = sight.ammoType;

    return weapon;
}
