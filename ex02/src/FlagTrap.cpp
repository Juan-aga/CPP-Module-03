#include "FlagTrap.hpp"

#include <iostream>

FlagTrap::FlagTrap( void )
{
	std::cout << "FlagTrap basic constructor called." << std::endl;
	*this = FlagTrap("");
}

FlagTrap::FlagTrap( std::string name ) : ClapTrap(name)
{
	this->_hitPoints = FLAG_TRAP_HEALTH;
	this->_energyPoints = 100;
	this->_attackDamage= 30;

	std::cout << "FlagTrap string constructor called." << std::endl;
}

FlagTrap::FlagTrap( FlagTrap const & s ) : ClapTrap(s)
{
	std::cout << "FlagTrap copy constructor called." << std::endl;
}

FlagTrap::~FlagTrap( void )
{
	std::cout << "FlagTrap destructor called." << std::endl;
}

void		FlagTrap::highFivesGuys( void )
{
	std::cout << "FlagTrap " << this->_name << " is doing a high fives." << std::endl;
}
void			FlagTrap::attack( const std::string & target )
{
	unsigned int	stats[3];

	this->getStatus(stats);
	if (stats[0] == 0 || stats[1] == 0)
		std::cout << this->_name << " can't attack!" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "FlagTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << stats[2] << " points of damage!";
		std::cout << std::endl;
	}
	if (DEBUG)
		std::cout << *this;
}

FlagTrap &	FlagTrap::operator=( FlagTrap const & s )
{
	if (this != &s)
	{
		ClapTrap::operator=(s);
	}
	return *this;
}
