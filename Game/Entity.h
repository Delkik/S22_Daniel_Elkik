#pragma once

#include "Peng.h"
#include <vector>

class Entity
{
public:

	Entity(const std::vector<std::string>& filenames);

	float GetX() const;
	float GetY() const;
	float GetZ() const;
	bool GetSolid() const;
	int GetActiveImage() const;
	int GetWidth() const;
	int GetHeight() const;
	std::vector<float> GetCenter() const;

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetSolid(bool solid);
	void SetActiveImage(int activeImage);

	void Draw();

private:
	float x_{ 0 };
	float y_{ 0 };
	float z_{ 0 };

	bool solid_{ true };

	int activeImage_{ 0 };

	std::vector<Peng::Sprite> images_;

};

