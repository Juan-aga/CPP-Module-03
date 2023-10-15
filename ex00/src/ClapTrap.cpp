#include "ClapTrap.hpp"


ClapTrap::ClapTrap( void )
{
	std::cout << "Basic Constructor called." << std::endl;
	*this = ClapTrap( "" );

}

ClapTrap::ClapTrap( std::string name ) : _hitPoints(CLAP_TRAP_HEALTH), _energyPoints(10), _attackDamage(0)
{
	if (name.empty())
		name = "Anonymous";
	this->_name = name;
	std::cout << "String constructor called." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & c )
{
	std::cout << "Copy constructor called." << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Basic destructor called." << std::endl;
}

void			ClapTrap::attack( const std::string & target )
{
	unsigned int	stats[3];

	this->getStatus(stats);
	if (stats[0] == 0 || stats[1] == 0)
		std::cout << this->_name << " can't attack!" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << stats[2] << " points of damage!";
		std::cout << std::endl;
	}
	if (DEBUG)
		std::cout << *this;
}

void			ClapTrap::takeDamage( unsigned int amount )
{
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount;
	std::cout << " points of damage!" << std::endl;
	if (DEBUG)
		std::cout << *this;
}

void			ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints == 0)
		std::cout << this->_name << " can't be reapaired!" << std::endl;
	else
	{
		if (amount + this->_hitPoints > CLAP_TRAP_HEALTH)
			this->_hitPoints = CLAP_TRAP_HEALTH;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " has been repaired with ";
		std::cout << amount << " hit points!" << std::endl;
	}
	if (DEBUG)
		std::cout << *this;
}

std::string		ClapTrap::getName( void ) const
{
	return this->_name;
}

void			ClapTrap::getStatus( unsigned int stats[3] ) const
{
	stats[0] = this->_hitPoints;
	stats[1] = this->_energyPoints;
	stats[2] = this->_attackDamage;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const & c )
{
	if (this != &c)
	{
		this->_name = c._name;
		this->_hitPoints = c._hitPoints;
		this->_energyPoints = c._energyPoints;
		this->_attackDamage = c._attackDamage;
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, ClapTrap const & c )
{
	unsigned int	stats[3];

	c.getStatus(stats);
	o << c.getName() << "\t>> Hit Points: " << stats[0];
	o << "\tEnergy Points: " << stats[1] << "\tAttack Damage: " << stats[2];
	o << std::endl;

	return o;
}
