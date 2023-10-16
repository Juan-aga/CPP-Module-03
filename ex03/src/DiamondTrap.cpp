#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap basic constructor called." << std::endl;
	*this = DiamondTrap("");
}

DiamondTrap::DiamondTrap( std::string const & name ) : ScavTrap(name), FlagTrap(name)
{
	std::cout << "DiamondTrap string constructor called." << std::endl;
	this->_name = ClapTrap::_name;
	ClapTrap::_name = this->_name + "_clap_name";
//	this->_hitPoints = FlagTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energy;
//	this->_attackDamage = FlagTrap::_attackDamage;
	if(DEBUG)
	{
		std::cout << *this;
		std::cout << "My energy: " << this->_energyPoints << std::endl;
		std::cout << "Scav Energy: " << ScavTrap::_energyPoints << std::endl;
	}
}

DiamondTrap::DiamondTrap( DiamondTrap const & d ) : ClapTrap(d), ScavTrap(d), FlagTrap(d)
{
	std::cout << "DiamonTrap copy constructor called." << std::endl;
	*this = d;
}

DiamondTrap::~DiamondTrap( void )
{
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & d )
{
	if(this != &d)
	{
		ClapTrap::operator=(d);
		this->_name = d._name;
	}
	return *this;
}

void			DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " << this->_name << " and my clap name is " << ClapTrap::_name << std::endl;
}
