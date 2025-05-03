#pragma once
#include "structs.h"
#include "partdatabase.h"

Weapon generateWeapon(const PartDatabase& db);
bool isCompatible(const Part& a, const Part& b);
