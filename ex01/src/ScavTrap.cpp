#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap basic constructor called." << std::endl;
	*this = ScavTrap("");
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_hitPoints = SCAV_TRAP_HEALTH;
	this->_energyPoints = 50;
	this->_attackDamage= 20;

	std::cout << "ScavTrap string constructor called." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & s ) : ClapTrap(s)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void		ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
void			ScavTrap::attack( const std::string & target )
{
	unsigned int	stats[3];

	this->getStatus(stats);
	if (stats[0] == 0 || stats[1] == 0)
		std::cout << this->_name << " can't attack!" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << stats[2] << " points of damage!";
		std::cout << std::endl;
	}
	if (DEBUG)
		std::cout << *this;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & s )
{
	if (this != &s)
	{
		ClapTrap::operator=(s);
	}
	return *this;
}
