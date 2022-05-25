#pragma once

#include "Entity.h"


class Projectile : public Entity {

public:
	Projectile(const std::vector<std::string>& filenames);

	float GetTrajectoryX() const;
	float GetTrajectoryY() const;
	int GetProjectileLife() const;

	void SetTrajectory(float trajectoryX, float trajectoryY);
	void SetProjectileLife(int projectileLife);

private:
	float trajectoryX_{ 0 };
	float trajectoryY_{ 0 };

	int projectileLife_{ 1 };

};

