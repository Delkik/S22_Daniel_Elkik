#include "Character.h"

Character::Character(const std::vector<std::string>& filenames) : Entity(filenames)
{
}

double Character::GetStamina() const
{
	return stamina_;
}

int Character::GetHealth() const
{
	return health_;
}

void Character::SetHealth(int health)
{
	health_ = health;
}

void Character::SetStamina(double stamina)
{
	stamina_ = stamina;
}

Projectile Character::GetProjectile() const
{
	return projectile_;
}
