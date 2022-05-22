#pragma once

#include "Peng.h"
#include "Entity.h"
#include "Character.h"
#include <stdlib.h>


class GameApp : public Peng::PengApp {

public:

	GameApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);

private:
	const int MAX_SPEED{ 5 };
	const int SPAWN_SPEED{ 150 };

	Character character_{ {"Assets/Images/Right1.png","Assets/Images/Right2.png","Assets/Images/Left1.png","Assets/Images/Left2.png"} };

	std::vector<Entity> dangers_{ { {"Assets/Images/Danger.png"} } };


	enum class CharacterDirectionX { Right = 1, Left = -1 } characterDirectionX_{ CharacterDirectionX::Right };
	enum class CharacterDirectionY { UP = 1, DOWN = -1 } characterDirectionY_{ CharacterDirectionY::UP };

	// probably need to add "running" state and also better implement right and left

	int enemySpeedY_{ 1 };
	int enemySpeedX_{ 1 };

	int speedX_{ 0 }; // speed measured in px / frame
	int speedY_{ 0 }; // speed measured in px / frame
	//int staminaRegen_{ 8 }; // unused for now
	int spawnCounter_{ 1 };
	int time_{ 0 };



};
