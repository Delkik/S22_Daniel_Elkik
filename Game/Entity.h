#pragma once

#include "Peng.h"
#include <vector>

class Entity
{
public:

	Entity(const std::vector<std::string>& filenames);

	int GetX() const;
	int GetY() const;
	int GetZ() const;
	bool GetSolid() const;
	int GetActiveImage() const;
	int GetWidth() const;
	int GetHeight() const;

	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);
	void SetSolid(bool solid);
	void SetActiveImage(int activeImage);

	void Draw();

private:
	int x_{ 0 };
	int y_{ 0 };
	int z_{ 0 };

	bool solid_{ true };

	int activeImage_{ 0 };

	std::vector<Peng::Sprite> images_;

};

