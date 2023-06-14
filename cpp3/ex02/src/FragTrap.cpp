#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor" << std::endl;
    set_energy_pts(100);
    set_hit_pts(100);
    set_damage_pts(30);
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
    std::string answer;
    std::cout << "Hey, high five !(Y/n):\n\\0\n |\\\n/ \\" << std::endl;
    std::cin >> answer;
    if (answer.empty() || tolower(answer[0]) != 'y')
        std::cout << "let's assume he didn't see me." << std::endl;
    else
        std::cout << get_name() << " takes 10 pts of nothing but it was cool." << std::endl;
}

