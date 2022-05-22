#include "Character.h"

Character::Character(const std::vector<std::string>& filenames) : Entity(filenames)
{
}

double Character::GetStamina() const
{
	return stamina_;
}

void Character::SetStamina(double stamina)
{
	stamina_ = stamina;
}

Entity Character::GetProjectile() const
{
	return projectile_;
}
