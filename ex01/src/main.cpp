//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int	main( void )
{
	ScavTrap a;
	ScavTrap b("clap");
	ScavTrap c(b);

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
	a.guardGate();
	return 0;
};
