#pragma once

#include "Peng.h"
#include "Entity.h"
#include "Character.h"
#include "Projectile.h"
#include <string>
#include <cmath>
#include <stdlib.h>


class GameApp : public Peng::PengApp {

public:

	GameApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);
	void DisplayStatus() const;

	float* Shoot(float x1, float x2, float y1, float y2, float speed);

private:
	const int MAX_PROJECTILE_LIFE{ 42 };
	const float MAX_SPEED{ 3 };
	const int SPAWN_SPEED{ 100 };
	const int MAX_AMMO_SPAWN{ 200 };
	const int MAX_AMMO{ 30 };

	Character character_{ {"Assets/Images/Right1.png","Assets/Images/Left1.png"} };

	std::vector<Entity> dangers_{ { {"Assets/Images/enemy1.png"} } };
	std::vector<Projectile> projectiles_;
	std::vector<Entity> ammo_;

	enum class CharacterDirectionX { Right = 1, Left = -1 } characterDirectionX_{ CharacterDirectionX::Right };
	enum class CharacterDirectionY { UP = 1, DOWN = -1 } characterDirectionY_{ CharacterDirectionY::UP };

	// probably need to add "running" state and also better implement right and left

	float enemySpeedY_{ 1 };
	float enemySpeedX_{ 1 };

	float speedX_{ 0.0 }; // speed measured in px / frame
	float speedY_{ 0.0 }; // speed measured in px / frame
	int currentAmmo_{ MAX_AMMO };

	//float projectileSpeedX_{ 0 };
	//float projectileSpeedY_{ 0 };


	//int staminaRegen_{ 8 }; // unused for now
	int spawnCounter_{ 1 };
	int time_{ 0 };
	int ammoTime_{ 0 };
	int ammoSpawned{ 0 };



};
