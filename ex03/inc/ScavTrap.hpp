#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAV_TRAP_HEALTH 100

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & s );
	~ScavTrap( void );

	ScavTrap &	operator=( ScavTrap const & s );

	void	guardGate( void );
	void	attack( std::string const & name );

protected:
	static const int	_energy = 50;

};

#endif
