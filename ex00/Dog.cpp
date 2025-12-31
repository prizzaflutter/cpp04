#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog Constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other): Animal(other){
    type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog make sound" << std::endl;
}
