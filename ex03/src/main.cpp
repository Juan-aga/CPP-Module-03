//#include "ClapTrap.hpp"
//#include "ScavTrap.hpp"
//#include "FlagTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>


int	main( void )
{
	{
	DiamondTrap a;
	DiamondTrap b("clap");
	DiamondTrap c(b);

	std::cout << a;
	std::cout << b;
	std::cout << c;

//	c = a;
	std::cout << c;

	for(int i = 11; i > 0; i--)
	{
		b.attack("Trap");
		std::cout << b;
	}
	for(int i = 11; i > 0; i--)
		b.takeDamage(10);
	b.beRepaired(100);
	std::cout << b;
	a.beRepaired(100);
//	a.guardGate();
	a.whoAmI();
	}
	{
		DiamondTrap	a("hola");
		DiamondTrap b(a);
		std::cout << "A: " << a << std::endl;
		a.whoAmI();
		std::cout << "B: " << b << std::endl;
		b.whoAmI();
	}
	{
		DiamondTrap	a("hola");
		DiamondTrap b;
		b = a;
		std::cout << "A: " << a << std::endl;
		a.whoAmI();
		std::cout << "B: " << b << std::endl;
		b.whoAmI();
	}
	return 0;
};
