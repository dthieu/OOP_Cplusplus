#pragma once
#include "Chicken.h"
#include "Cow.h"
#include "Pig.h"
#include "Sheep.h"

class AnimalFactory {
public:
    enum eAnimal {
        COW,    // 0
        SHEEP,  // 1
        PIG,    // 2
        CHICKEN // 3
    };

    std::unique_ptr<Animal> createAnimal(AnimalFactory::eAnimal animal);
};
