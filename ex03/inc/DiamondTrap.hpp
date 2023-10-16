#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FlagTrap.hpp"


class DiamondTrap : public ScavTrap, public FlagTrap
{
public:

	DiamondTrap( void );
	DiamondTrap( std::string const & name );
	DiamondTrap( DiamondTrap const & d );
	~DiamondTrap( void );

	DiamondTrap &	operator=( DiamondTrap const & d );

	void			whoAmI( void );
	using ScavTrap::attack;

private:
	std::string		_name;

};

#endif
