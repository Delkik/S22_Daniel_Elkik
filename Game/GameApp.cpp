#include "GameApp.h"

GameApp::GameApp()
{


	SetKeyPressedCallback([this](const Peng::KeyPressedEvent& e) {
		switch (e.GetKeyCode()) {

		case PENG_KEY_A:
			speedX_ = -MAX_SPEED;
			characterDirectionX_ = CharacterDirectionX::Left;
			character_.SetActiveImage(1);
			break;
		case PENG_KEY_D:
			speedX_ = MAX_SPEED;
			characterDirectionX_ = CharacterDirectionX::Right;
			character_.SetActiveImage(0);
			break;
		case PENG_KEY_W:
			speedY_ = MAX_SPEED;
			characterDirectionY_ = CharacterDirectionY::UP;
			break;
		case PENG_KEY_S:
			speedY_ = -MAX_SPEED;
			characterDirectionY_ = CharacterDirectionY::DOWN;
			break;
		case PENG_KEY_SPACE: // unused
			break;
		}

		});

	SetKeyReleasedCallback([this](const Peng::KeyReleasedEvent& e) {

		// Smoothed out controls
		if (e.GetKeyCode() == PENG_KEY_A && characterDirectionX_ == CharacterDirectionX::Left) {
			speedX_ = 0;
		}
		if (e.GetKeyCode() == PENG_KEY_D && characterDirectionX_ == CharacterDirectionX::Right) {
			speedX_ = 0;
		}
		
		if (e.GetKeyCode() == PENG_KEY_W && characterDirectionY_ == CharacterDirectionY::UP) {
			speedY_ = 0;
		}
		if (e.GetKeyCode() == PENG_KEY_S && characterDirectionY_ == CharacterDirectionY::DOWN) {
			speedY_ = 0;
		}

		});


	SetMousePressedCallback([this](const Peng::MousePressedEvent& e) {
		switch (e.GetButton()) {

		case PENG_MOUSE_BUTTON_LEFT:
			if (currentAmmo_ <= 0) { break; }

			float tempX = Peng::GameWindow::GetWindow()->GetMousePosition()[0];
			float tempY = Peng::GameWindow::GetWindow()->GetMousePosition()[1];

			//auto shoot{ Shoot(tempX, character_.GetCenter()[0], tempY, character_.GetCenter()[1], 10) };

			float diffX = Peng::GameWindow::GetWindow()->GetMousePosition()[0] - character_.GetCenter()[0];
			float diffY = Peng::GameWindow::GetWindow()->GetMousePosition()[1] - character_.GetCenter()[1];

			float angle = atanf(abs(diffY / diffX));
			float x = 10 * cos(angle);
			float y = 10 * sin(angle);

			if (diffY < 0) { y *= -1; }
			if (diffX < 0) { x *= -1; }


			Projectile temp{ character_.GetProjectile() };
			temp.SetX(character_.GetCenter()[0] - temp.GetWidth() / 2);
			temp.SetY(character_.GetCenter()[1] - temp.GetHeight() / 2);
			temp.SetTrajectory(x, y);
			projectiles_.push_back( temp );
			currentAmmo_--;
			std::cout << "Ammo: " << currentAmmo_ << std::endl;
			break;
		}
		
		});

	srand(time(0));
}

void GameApp::OnUpdate()
{

	auto win = Peng::GameWindow::GetWindow();

	time_ %= SPAWN_SPEED;
	ammoTime_ %= MAX_AMMO_SPAWN;
	time_++;
	ammoTime_++;
	character_.SetX(character_.GetX() + speedX_);
	character_.SetY(character_.GetY() + speedY_);

	/* Lock character to screen */
	if (character_.GetX() > win->GetWidth()) { character_.SetX(0 - character_.GetWidth()); }
	if (character_.GetX() < 0 - character_.GetWidth()) { character_.SetX(win->GetWidth()); }
	if (character_.GetY() > win->GetHeight()) { character_.SetY(0 - character_.GetHeight()); }
	if (character_.GetY() < 0 - character_.GetHeight()) { character_.SetY(win->GetHeight()); }
	/* Lock character to screen */

	// 30% chance that ammo can spawn every "MAX_AMMO_SPAWN" frames
	if ((rand() % 100) + 1 < 30 && !(ammoTime_ % MAX_AMMO_SPAWN) && ammoSpawned < 5) {
		Entity ammo{ { {"Assets/Images/ammo.png"} } };

		/* Place ammo in random place */
		ammo.SetX(rand() % win->GetWidth());
		ammo.SetY(rand() % win->GetHeight());
		ammoSpawned++;
		/* Place ammo in random place */

		ammo_.push_back(ammo);
	}

	for (int i = 0; i < ammo_.size(); i++) {

		if (Collide(ammo_[i], character_)) {
			/* Add random amounts of ammo to magazine */
			ammo_.erase(ammo_.begin() + i);
			i--;
			ammoSpawned--;
			currentAmmo_ += (rand() % 10 + 5);
			if (currentAmmo_ > MAX_AMMO) { currentAmmo_ = MAX_AMMO; }
			/* Add random amounts of ammo to magazine */

			std::cout << "Ammo: " << currentAmmo_ << std::endl; // Display current ammo count
		}
		else {
			ammo_[i].Draw();
		}
	}

	/* CHOOSE RANDOM STARTING POSITION AROUND BORDER */
	if (!(time_ % SPAWN_SPEED)) {

		auto s = "Assets/Images/enemy" + std::to_string((rand() % 8) + 1) + ".png";
		dangers_.push_back({ { s } });

		float w[2]{ 0 - dangers_[spawnCounter_].GetWidth(), win->GetWidth() };
		float h[2]{ 0 - dangers_[spawnCounter_].GetHeight(), win->GetHeight() };
		float c1[2]{ w[rand() % 2], rand() % win->GetWidth() };
		float c2[2]{ rand() % win->GetHeight(), h[rand() % 2] };

		int choice = rand() % 2;
		dangers_[spawnCounter_].SetX(choice ? c1[0] : c2[0]);
		dangers_[spawnCounter_].SetY(choice ? c1[1] : c2[1]);
		spawnCounter_++;
	}
	/* CHOOSE RANDOM STARTING POSITION AROUND BORDER */


	for (int i = 0; i < projectiles_.size(); i++) {
		for (int j = 0; j < dangers_.size(); j++) {
			if (Collide(dangers_[j], projectiles_[i])) {
				dangers_.erase(dangers_.begin() + j);
				projectiles_.erase(projectiles_.begin() + i);
				spawnCounter_--;
				j--;
				i--;
			}
			if (j >= dangers_.size() || projectiles_.size() == 0) { break; }
		}
		if (i >= projectiles_.size() || projectiles_.size() == 0) { break; }
		
		/* This doesn't work */

		//if (!(projectiles_[i].GetProjectileLife() % MAX_PROJECTILE_LIFE)) {
		//	//std::cout << "i = " << i << projectiles_.size() << std::endl;
		//	projectiles_.erase(projectiles_.begin() + i);
		//	//std::cout << "i = " << i << projectiles_.size() << std::endl;
		//	i--;
		//	if (i >= projectiles_.size() || projectiles_.size() == 0) { break; }
		//}

		/* This doesn't work */

		projectiles_[i].SetX(projectiles_[i].GetX() + projectiles_[i].GetTrajectoryX());
		projectiles_[i].SetY(projectiles_[i].GetY() + projectiles_[i].GetTrajectoryY());
		projectiles_[i].SetProjectileLife(projectiles_[i].GetProjectileLife() + 1);
		projectiles_[i].Draw();

	}


	for (int i = 0; i < dangers_.size(); i++) {

		if (Collide(character_, dangers_[i])) {

			if (character_.GetHealth() <= 0) {
				exit(0);
			}
			
			/* Reset every value */
			character_.SetHealth(character_.GetHealth() - 1);
			character_.SetX(win->GetWidth() / 2);
			character_.SetY(win->GetHeight() / 2);
			dangers_.clear();
			ammo_.clear();
			projectiles_.clear();
			spawnCounter_ = 0;
			time_ = 0;
			ammoTime_ = 0;
			ammoSpawned = 0;
			currentAmmo_ = MAX_AMMO;
			/* Reset every value */

			
			DisplayStatus();
			break;
		}



		float x = character_.GetX() - dangers_[i].GetX();
		float y = character_.GetY() - dangers_[i].GetY();

		auto angle = atanf(abs(y / x));
		enemySpeedX_ = 1.0f * cos(angle);
		enemySpeedY_ = 1.0f * sin(angle);

		if (y < 0) {
			enemySpeedY_ *= -1;
		}
		if (x < 0) {
			enemySpeedX_ *= -1;
		}
		dangers_[i].SetX(dangers_[i].GetX() + enemySpeedX_);
		dangers_[i].SetY(dangers_[i].GetY() + enemySpeedY_);
		dangers_[i].Draw();


	}

	character_.Draw();
}

bool GameApp::Collide(const Entity& one, const Entity& another)
{
	float oneLeft{ one.GetX() };
	float oneRight{ one.GetX() + one.GetWidth() };
	float anotherLeft{ another.GetX() };
	float anotherRight{ another.GetX() + another.GetWidth() };

	float oneBottom{ one.GetY() };
	float oneTop{ one.GetY() + one.GetHeight() };
	float anotherBottom{ another.GetY() };
	float anotherTop{ another.GetY() + another.GetHeight() };

	bool collideX{ false };
	if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
		(anotherLeft <= oneLeft && oneLeft <= anotherRight))
	{
		collideX = true;
	}

	bool collideY{ false };
	if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
		(anotherBottom <= oneBottom && oneBottom <= anotherTop))
	{
		collideY = true;
	}

	return collideX && collideY;

}

void GameApp::DisplayStatus() const
{
	std::cout << "=================" << std::endl;
	std::cout << "Health = " << character_.GetHealth() + 1 << std::endl;
	std::cout << "Ammo = " << currentAmmo_ << std::endl;
	std::cout << "=================" << std::endl;
}

float* GameApp::Shoot(float x1, float x2, float y1, float y2, float speed)
{
	
	float speedX{ 0 };
	float speedY{ 0 };
	float x = x1 - x2;
	float y = y1 - y2;


	float angle = atanf(abs(y / x));
	speedX = speed * cos(angle); // normalize speed
	speedY = speed * sin(angle); // normalize speed

	if (x < 0) { speedX *= -1; }
	if (y < 0) { speedY *= -1; }

	float xy[2]{ speedX,speedY };
	return xy;
}
