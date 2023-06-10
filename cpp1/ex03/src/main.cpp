#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int	main(void)
{
    {
		Weapon club = Weapon("");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("crude spiked club");
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		club.setType("");
		bob.attack();
    }
    {
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		club.setType("");
		jim.attack();
	}
    return (0);
}
