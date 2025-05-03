#pragma once
#include "structs.h"
#include <vector>
#include <string>



struct PartDatabase {
    std::vector<Part> parts;

    void addPart(const Part& part);
    std::vector<Part> getPartsByType(PartType type) const;

    bool saveToBinary(const std::string& filename) const;
    bool loadFromBinary(const std::string& filename);

    void addPartFromUser();
    void loadDefaultParts();
};
