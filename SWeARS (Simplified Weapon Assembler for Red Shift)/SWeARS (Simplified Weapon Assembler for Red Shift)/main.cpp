int main() {
    PartDatabase db;

    // Load existing parts from binary file, or load default parts if not available
    if (std::ifstream("parts.bin").good()) {
        db.loadFromBinary("parts.bin");
    }
    else {
        db.loadDefaultParts(); // Load the default parts if no binary file exists
    }

    // Allow user to add custom parts
    db.addPartFromUser();

    // Generate and save the weapon as usual
    Weapon weapon = generateWeapon(db);
    saveWeaponToTextFile(weapon, "weapon_output.txt");

    return 0;
}
