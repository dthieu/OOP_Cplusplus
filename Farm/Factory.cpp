#include "Factory.h"

std::unique_ptr<Animal> AnimalFactory::createAnimal(AnimalFactory::eAnimal animal){
        switch (animal){
        case AnimalFactory::COW:
            return std::make_unique<Cow>();
            break;
        case AnimalFactory::SHEEP:
            return std::make_unique<Sheep>();
            break;
        case AnimalFactory::PIG:
            return std::make_unique<Pig>();
            break;
        case AnimalFactory::CHICKEN:
            return std::make_unique<Chicken>();
            break;
        default:
            std::cout << "No support!\n";
            break;
        }
}
