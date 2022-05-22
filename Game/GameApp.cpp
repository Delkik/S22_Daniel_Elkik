#include "GameApp.h"

GameApp::GameApp()
{


	SetKeyPressedCallback([this](const Peng::KeyPressedEvent& e) {
		switch (e.GetKeyCode()) {

		case PENG_KEY_LEFT:
			speedX_ = -5;
			characterDirectionX_ = CharacterDirectionX::Left;
			character_.SetActiveImage(2);
			break;
		case PENG_KEY_RIGHT:
			speedX_ = 5;
			characterDirectionX_ = CharacterDirectionX::Right;
			character_.SetActiveImage(0);
			break;
		case PENG_KEY_UP:
			speedY_ = 5;
			characterDirectionY_ = CharacterDirectionY::UP;
			break;
		case PENG_KEY_DOWN:
			speedY_ = -5;
			characterDirectionY_ = CharacterDirectionY::DOWN;
			break;
		case PENG_KEY_SPACE:
			break;
		}

		});

	SetKeyReleasedCallback([this](const Peng::KeyReleasedEvent& e) {

		// Smoothed out controls
		if (e.GetKeyCode() == PENG_KEY_LEFT && characterDirectionX_ == CharacterDirectionX::Left) {
			speedX_ = 0;
		}
		if (e.GetKeyCode() == PENG_KEY_RIGHT && characterDirectionX_ == CharacterDirectionX::Right) {
			speedX_ = 0;
		}
		
		if (e.GetKeyCode() == PENG_KEY_UP && characterDirectionY_ == CharacterDirectionY::UP) {
			speedY_ = 0;
		}
		if (e.GetKeyCode() == PENG_KEY_DOWN && characterDirectionY_ == CharacterDirectionY::DOWN) {
			speedY_ = 0;
		}

		});


	SetMousePressedCallback([this](const Peng::MousePressedEvent& e) {
		switch (e.GetButton()) {

		case PENG_MOUSE_BUTTON_LEFT:
			std::cout << Peng::GameWindow::GetWindow()->GetMousePosition()[0] << std::endl;;
			break;
		}

		});

}

void GameApp::OnUpdate()
{
	time_++;
	character_.SetX((character_.GetX() + speedX_)%1000);
	character_.SetY(character_.GetY() + speedY_);


	// CHOOSE RANDOM STARTING POSITION AROUND BORDER //

	auto win = Peng::GameWindow::GetWindow();

	if (!(time_ % SPAWN_SPEED)) {
		dangers_.push_back({ {"Assets/Images/Danger.png"} });

		int w[2]{ 0 - dangers_[spawnCounter_].GetWidth(), win->GetWidth() };
		int h[2]{ 0 - dangers_[spawnCounter_].GetHeight(), win->GetHeight() };
		int c1[2]{ w[rand() % 2], rand() % win->GetWidth() };
		int c2[2]{ rand() % win->GetHeight(), h[rand() % 2] };

		int choice = rand() % 2;
		dangers_[spawnCounter_].SetX(choice ? c1[0] : c2[0]);
		dangers_[spawnCounter_].SetY(choice ? c1[1] : c2[1]);
		spawnCounter_++;
	}
	// CHOOSE RANDOM STARTING POSITION AROUND BORDER //
	//std::cout << spawnCounter_ << std::endl;

	for (int i = 0; i < dangers_.size(); i++) {
		if (dangers_[i].GetCenter()[0] > character_.GetCenter()[0]) {
			enemySpeedX_ = -1;
		}
		else if (dangers_[i].GetCenter()[0] < character_.GetCenter()[0]) {
			enemySpeedX_ = 1;
		}
		else  {
			enemySpeedX_ = 0;
		}

		if (dangers_[i].GetCenter()[1] > character_.GetCenter()[1]) {
			enemySpeedY_ = -1;
		}
		else if (dangers_[i].GetCenter()[1] < character_.GetCenter()[1]) {
			enemySpeedY_ = 1;
		}
		else {
			enemySpeedY_ = 0;
		}
		if (Collide(character_, dangers_[i])) {
			//exit(0);
			//std::cout << "HIT!" << std::endl;
		}

		dangers_[i].SetY(dangers_[i].GetY() + enemySpeedY_);
		dangers_[i].SetX(dangers_[i].GetX() + enemySpeedX_);
		dangers_[i].Draw();
	}

	character_.Draw();
}

bool GameApp::Collide(const Entity& one, const Entity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

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
