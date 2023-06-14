#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include <iostream>

int main (void)
{
    const Animal* meta = new Animal();
    const Animal any;
    const Dog doggy;
    const Cat caty;

    std::cout << "================ Animal ==================" << std::endl;
    std::cout << "The " << any.getType() << ": " << any.getSound() << std::endl;
    std::cout << "================   Dog  ==================" << std::endl;
    std::cout << "The " << doggy.getType() << ": " << doggy.getSound() << std::endl;
    std::cout << "================   Cat  ==================" << std::endl;
    std::cout << "The " << caty.getType() << ": " << caty.getSound() << std::endl;
    std::cout << "==========   allocated Animal  ===========" << std::endl;
    std::cout << "The " << meta->getType() << ": " << meta->getSound() << std::endl;
    std::cout << "========== test makeSound() ==============" << std::endl;
    std::cout << "Animal -> ";
    any.makeSound();
    std::cout << "new Animal -> ";
    meta->makeSound();
    std::cout << "Dog -> ";
    doggy.makeSound();
    std::cout << "Cat -> ";
    caty.makeSound();
    return 0;
}
