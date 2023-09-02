#include "../inc/FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap("Jane Frag Doe")
{
	set_energy_pts(100);
	set_hit_pts(100);
	set_damage_pts(30);
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	set_energy_pts(100);
	set_hit_pts(100);
	set_damage_pts(30);
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << get_name() << " destructor's called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::string answer;
	std::cout << std::endl;
	std::cout << "Hey, high five !(Y/n):\n\\0\n |\\\n/ \\" << std::endl;
	std::cin >> answer;
	if (answer.empty() || tolower(answer[0]) != 'y')
		std::cout << "let's assume he didn't see me." << std::endl;
	else
		std::cout << get_name() << " clap this hand." << std::endl;
	std::cout << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap: ";
	ClapTrap::attack(target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap: ";
	ClapTrap::takeDamage(amount);
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap: ";
	ClapTrap::beRepaired(amount);
}
