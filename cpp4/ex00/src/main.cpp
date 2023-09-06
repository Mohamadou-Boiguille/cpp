#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>

int main (void)
{
    { 
        const Animal* meta = new Animal();
        const Animal any;
        const Dog doggy;
        const Cat caty;

        std::cout << "================ Animal ==================" << std::endl;
        std::cout << "The " << any.getType() << std::endl;
        any.makeSound();
        std::cout << "================   Dog  ==================" << std::endl;
        std::cout << "The " << doggy.getType() << std::endl;
        doggy.makeSound();
        std::cout << "================   Cat  ==================" << std::endl;
        std::cout << "The " << caty.getType() << std::endl;
        caty.makeSound();
        std::cout << "==========   allocated Animal  ===========" << std::endl;
        std::cout << "The " << meta->getType() << std::endl;
        meta->makeSound();
        std::cout << "==========================================" << std::endl;
        delete meta;
    }
    {
        std::cout << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "================ Wrongs ==================" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal wrongAny;
        const WrongCat wrongCaty;

        std::cout << std::endl;
        std::cout << "================ WrongAnimal ==================" << std::endl;
        std::cout << "The " << wrongAny.getType() << std::endl;
        wrongAny.makeSound();
        std::cout << "================   WrongCat  ==================" << std::endl;
        std::cout << "The " << wrongCaty.getType() << std::endl;
        wrongCaty.makeSound();
        std::cout << "==========   allocated WrongAnimal  ===========" << std::endl;
        std::cout << "The " << wrongMeta->getType() << std::endl;
        wrongMeta->makeSound();
        std::cout << "================================================" << std::endl;
        delete wrongMeta;
    }



    return 0;
}