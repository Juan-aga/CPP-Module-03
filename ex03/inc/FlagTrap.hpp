#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

# define FLAG_TRAP_HEALTH 100

class FlagTrap : virtual public ClapTrap
{
public:
	FlagTrap( void );
	FlagTrap( std::string name );
	FlagTrap( FlagTrap const & s );
	~FlagTrap( void );

	FlagTrap &	operator=( FlagTrap const & s );

	void	highFivesGuys( void );
	void	attack( std::string const & name );
};

#endif
