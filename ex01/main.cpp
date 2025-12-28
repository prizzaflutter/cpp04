#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void separator(const std::string& title) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << title << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

void testCorrectImplementation() {
    separator("TEST 1: Correct Implementation (with virtual)");
    
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    std::cout << "\nSounds (should be specific to each animal):" << std::endl;
    std::cout << "Cat sound: ";
    cat->makeSound();  // Should output cat sound
    
    std::cout << "Dog sound: ";
    dog->makeSound();  // Should output dog sound
    
    std::cout << "Animal sound: ";
    meta->makeSound();  // Should output generic animal sound
    
    std::cout << "\nDeleting animals:" << std::endl;
    delete meta;
    delete dog;
    delete cat;
}

void testWrongImplementation() {
    separator("TEST 2: Wrong Implementation (without virtual)");
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "\nSounds (THIS IS THE PROBLEM!):" << std::endl;
    std::cout << "WrongCat sound through base pointer: ";
    wrongCat->makeSound();  // Will output WrongAnimal sound, NOT WrongCat!
    
    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();
    
    std::cout << "\nDeleting wrong animals:" << std::endl;
    delete wrongMeta;
    delete wrongCat;
}

void testDirectObjects() {
    separator("TEST 3: Direct Objects (no pointers)");
    
    std::cout << "\nCorrect implementation:" << std::endl;
    Cat directCat;
    std::cout << "Direct Cat sound: ";
    directCat.makeSound();  // Works correctly
    
    std::cout << "\nWrong implementation:" << std::endl;
    WrongCat directWrongCat;
    std::cout << "Direct WrongCat sound: ";
    directWrongCat.makeSound();  // Also works when called directly!
}

void demonstrateTheProblem() {
    separator("TEST 4: The Real Difference - Polymorphism");
    
    std::cout << "\n--- With virtual (correct) ---" << std::endl;
    Animal* animals[2];
    animals[0] = new Cat();
    animals[1] = new Dog();
    
    for (int i = 0; i < 2; i++) {
        std::cout << "Animal[" << i << "] type: " << animals[i]->getType();
        std::cout << " - Sound: ";
        animals[i]->makeSound();  // Calls correct derived class method
    }
    
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }
    
    std::cout << "\n--- Without virtual (wrong) ---" << std::endl;
    WrongAnimal* wrongAnimals[2];
    wrongAnimals[0] = new WrongCat();
    wrongAnimals[1] = new WrongAnimal();
    
    for (int i = 0; i < 2; i++) {
        std::cout << "WrongAnimal[" << i << "] type: " << wrongAnimals[i]->getType();
        std::cout << " - Sound: ";
        wrongAnimals[i]->makeSound();  // Always calls base class method!
    }
    
    for (int i = 0; i < 2; i++) {
        delete wrongAnimals[i];
    }
}

void testCopyConstructors() {
    separator("TEST 5: Copy Constructors");
    
    std::cout << "\n--- Dog copy ---" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    std::cout << "Dog2 sound: ";
    dog2.makeSound();
    
    std::cout << "\n--- Cat assignment ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    std::cout << "Cat2 sound: ";
    cat2.makeSound();
}

int main() {
    testCorrectImplementation();
    testWrongImplementation();
    testDirectObjects();
    demonstrateTheProblem();
    testCopyConstructors();
    
    separator("ALL TESTS COMPLETED");
    return 0;
}