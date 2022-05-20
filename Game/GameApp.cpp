#include "GameApp.h"

GameApp::GameApp()
{
	SetKeyPressedCallback([this](const Peng::KeyPressedEvent& e) {
		switch (e.GetKeyCode()) {
		
		case PENG_KEY_LEFT:
			speedX_ = -5;
			character_.SetActiveImage((int)CharacterDirectionX::Left);
			break;
		case PENG_KEY_RIGHT:
			speedX_ = 5;
			character_.SetActiveImage((int)CharacterDirectionX::Right);
			break;
		case PENG_KEY_UP:
			speedY_ = 5;
			break;
		case PENG_KEY_DOWN:
			speedY_ = -5;
			break;
		
		}
		
		});

	SetKeyReleasedCallback([this](const Peng::KeyReleasedEvent& e) {
		if (e.GetKeyCode() == PENG_KEY_LEFT || e.GetKeyCode() == PENG_KEY_RIGHT) {
			speedX_ = 0;
		}
		if (e.GetKeyCode() == PENG_KEY_DOWN || e.GetKeyCode() == PENG_KEY_UP) {
			speedY_ = 0;
		}

		});

	dangers_[0].SetX(600);
	dangers_[0].SetY(600);
}

void GameApp::OnUpdate()
{
	character_.SetX((character_.GetX() + speedX_)%800);
	character_.SetY(character_.GetY() + speedY_);

	if (dangers_[0].GetY() < 0) {
		enemySpeedY_ *= -1;
	}
	else if (dangers_[0].GetY() > Peng::GameWindow::GetWindow()->GetHeight() - dangers_[0].GetHeight()) {
		enemySpeedY_ *= -1;
	}

	if (Collide(character_, dangers_[0])) {
		//exit(0);
		PENG_LOG("HIT!");
	}

	dangers_[0].SetY(dangers_[0].GetY() + enemySpeedY_);
	dangers_[0].Draw();
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
	if ((oneLeft <= anotherLeft and anotherLeft <= oneRight) or
		(anotherLeft <= oneLeft and oneLeft <= anotherRight))
	{
		collideX = true;
	}

	bool collideY{ false };
	if ((oneBottom <= anotherBottom and anotherBottom <= oneTop) or
		(anotherBottom <= oneBottom and oneBottom <= anotherTop))
	{
		collideY = true;
	}

	return collideX && collideY;

}
