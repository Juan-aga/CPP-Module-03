//#include "ClapTrap.hpp"
//#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include <iostream>


int	main( void )
{
	FlagTrap a;
	FlagTrap b("clap");
	FlagTrap c(b);

	std::cout << a;
	std::cout << b;
	std::cout << c;

	c = a;
	std::cout << c;

	for(int i = 11; i > 0; i--)
		a.attack("Trap");
	for(int i = 11; i > 0; i--)
		b.takeDamage(10);
	b.beRepaired(100);
	std::cout << b;
	a.beRepaired(100);
//	a.guardGate();
	a.highFivesGuys();
	return 0;
};
