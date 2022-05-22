#pragma once

#include "Entity.h"

class Character : public Entity
{
public:
	Character(const std::vector<std::string>& filenames);

	double GetStamina() const;
	void SetStamina(double stamina);

	Entity GetProjectile() const;

private:
	double stamina_{ 100 };
	Entity projectile_{ {"Assets/Images/projectile.png"} };

};

