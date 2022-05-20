#include "Entity.h"
#include "Peng.h"

Entity::Entity(const std::vector<std::string>& filenames) : 
	images_(filenames.begin(), filenames.end())
{

}

int Entity::GetX() const
{
	return x_;
}

int Entity::GetY() const
{
	return y_;
}

int Entity::GetZ() const
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

void Entity::SetX(int x)
{
	x_ = x;
}

void Entity::SetY(int y)
{
	y_ = y;
}

void Entity::SetZ(int z)
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
