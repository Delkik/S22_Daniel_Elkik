#pragma once

#include "Entity.h"
#include "Projectile.h"

class Character : public Entity
{
public:
	Character(const std::vector<std::string>& filenames);

	double GetStamina() const;
	int GetHealth() const;

	void SetHealth(int health);
	void SetStamina(double stamina);

	Projectile GetProjectile() const;

private:
	double stamina_{ 100 };
	Projectile projectile_{ {"Assets/Images/projectile.png"} };
	int health_{ 3 };
};

