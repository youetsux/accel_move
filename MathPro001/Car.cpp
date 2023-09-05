#include "stdafx.h"
#include "Car.h"

Car::Car()
{
	pos_ = { Scene::Width()-50, 450};
	speed_ = 10.0; // 10 m/s
	accel_ = 10.0;
	dir_ = { -1.0, 0 };
	tex_ = TextureAsset(U"CAR");
}

Car::~Car()
{
	//なんもしない
}

void Car::Update()
{
	speed_ = speed_ + accel_ * Scene::DeltaTime();
	pos_ = pos_ + speed_ * dir_ * Scene::DeltaTime();
}

void Car::Draw()
{
	tex_.resized(50).drawAt(pos_);
}
