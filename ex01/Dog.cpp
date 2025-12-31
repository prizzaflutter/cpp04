#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dob Constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other){
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other){
         type = other.type;
         delete brain; 
         brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Dog make sound" << std::endl;
}

Brain* Dog::getBrain() const{
    return brain; 
}
