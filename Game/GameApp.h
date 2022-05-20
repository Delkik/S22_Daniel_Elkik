#pragma once

#include "Peng.h"
#include "Entity.h"

class GameApp : public Peng::PengApp {

public:

	GameApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);

private:
	Entity character_{ {"Assets/Images/Right1.png","Assets/Images/Left1.png"} };

	std::vector<Entity> dangers_{ { {"Assets/Images/Danger.png"} } };
	int enemySpeedY_{ 5 };

	enum class CharacterDirectionX { Right, Left } characterDirectionX_{ CharacterDirectionX::Right };
	enum class CharacterDirectionY { Right, Left } characterDirectionY_{ CharacterDirectionY::Right };

	int speedX_{ 0 }; // speed measured in px / frame
	int speedY_{ 0 }; // speed measured in px / frame


};
