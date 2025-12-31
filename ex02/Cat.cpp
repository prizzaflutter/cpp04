#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat Constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other): Animal(other){
    type = other.type;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;

}
Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const{
    std::cout << "Cat make sound" << std::endl;
}

Brain* Cat::getBrain() const{
    return brain; 
}
