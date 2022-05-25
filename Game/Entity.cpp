#include "Entity.h"
#include "Peng.h"

Entity::Entity(const std::vector<std::string>& filenames) : 
	images_(filenames.begin(), filenames.end())
{

}

float Entity::GetX() const
{
	return x_;
}

float Entity::GetY() const
{
	return y_;
}

float Entity::GetZ() const
{
	return z_;
}

bool Entity::GetSolid() const
{
	return solid_;
}

int Entity::GetActiveImage() const
{
	return activeImage_;
}

int Entity::GetWidth() const
{
	return images_[activeImage_].GetWidth();
}

int Entity::GetHeight() const
{
	return images_[activeImage_].GetHeight();
}

std::vector<float> Entity::GetCenter() const
{
	return std::vector<float>({ GetX() + (GetWidth() / 2), GetY() + (GetHeight() / 2) });
}

void Entity::SetX(float x)
{
	x_ = x;
}

void Entity::SetY(float y)
{
	y_ = y;
}

void Entity::SetZ(float z)
{
	z_ = z;
}

void Entity::SetSolid(bool solid)
{
	solid_ = solid;
}

void Entity::SetActiveImage(int activeImage)
{
	activeImage_ = activeImage;
}

void Entity::Draw()
{
	Peng::Renderer::Draw(images_[activeImage_],x_,y_,z_);
}
