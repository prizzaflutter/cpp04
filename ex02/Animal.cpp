#include "Animal.hpp"

Animal::Animal(): type("Animal"){
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &other){
    type = other.type;
}

Animal &Animal::operator=(const Animal &other){
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}


std::string Animal::getType() const {
    return this->type;
}
