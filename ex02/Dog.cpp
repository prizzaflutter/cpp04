#include "Dog.hpp"

Dog::Dog() : Animal(){
    type = "Dog";
}

Dog::Dog(const Dog &other): Animal(other){
    type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        type = other.type;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog make sound" << std::endl;
}

Brain* Dog::getBrain() const{
    return brain; 
}
