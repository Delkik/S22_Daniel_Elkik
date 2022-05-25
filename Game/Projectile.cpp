#include "Projectile.h"

Projectile::Projectile(const std::vector<std::string>& filenames) : Entity(filenames) {}

float Projectile::GetTrajectoryX() const
{
    return trajectoryX_;
}

float Projectile::GetTrajectoryY() const
{
    return trajectoryY_;
}

int Projectile::GetProjectileLife() const
{
    return projectileLife_;
}

void Projectile::SetTrajectory(float trajectoryX, float trajectoryY)
{
    if (!trajectoryX_) { trajectoryX_ = trajectoryX; }
    if (!trajectoryY_) { trajectoryY_ = trajectoryY; }
}

void Projectile::SetProjectileLife(int projectileLife)
{
    projectileLife_ = projectileLife;
}
