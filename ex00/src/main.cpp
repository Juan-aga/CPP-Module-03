#include "ClapTrap.hpp"
#include <iostream>


int	main( void )
{
	ClapTrap a;
	ClapTrap b("clap");
	ClapTrap c(b);

	std::cout << a;
	std::cout << b;
	std::cout << c;

	c = a;
	std::cout << c;

	for(int i = 11; i > 0; i--)
		a.attack("Trap");
	for(int i = 11; i > 0; i--)
		b.takeDamage(1);
	b.beRepaired(100);
	std::cout << b;
	a.beRepaired(100);

	return 0;
};
