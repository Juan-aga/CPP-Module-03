#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

#define CLAP_TRAP_HEALTH 10

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & c );
	~ClapTrap( void );

	ClapTrap &	operator=( ClapTrap const & c );

	void		attack( const std::string& target );
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

	std::string	getName( void ) const;
	void		getStatus( unsigned int stats[3] ) const;

};

std::ostream &	operator<<( std::ostream & o, ClapTrap const & c );

#endif
