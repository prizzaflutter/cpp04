#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat Constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other): Animal(other){
    type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        type = other.type;
    return *this;

}
Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat make sound" << std::endl;
}
