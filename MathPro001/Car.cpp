#include "stdafx.h"
#include "Car.h"

Car::Car()
{
	pos_ = { Scene::Width()-50, GROUND_HIGHT-25};
	speed_ = 0.0; // 初速0 m/s
	accel_ = 30.0;
	dir_ = { -1.0, 0 };
	tex_ = TextureAsset(U"CAR");
	isMaxSpeed = false;
}

Car::~Car()
{
	//なんもしない
}
//スペースキーで１００m/sまで加速
//離したら、減速
//bでバック
void Car::Update()
{
	if (KeySpace.pressed())
	{
		if(speed_ <= 100)
			speed_ = speed_ + accel_ * Scene::DeltaTime();
	}else
		speed_ = speed_ * 0.985;

	pos_ = pos_ + speed_ * dir_ * Scene::DeltaTime();
	if (KeyV.pressed())
	{
		pos_.y = pos_.y - 1;
	}
	else
	{
		if(pos_.y < GROUND_HIGHT-50/2+10)
			pos_.y = pos_.y + 1;
	}

}

void Car::Draw()
{
	tex_.resized(50).drawAt(pos_);
	String strSPD = ToString((int)speed_);
	FontAsset(U"FONT")(strSPD + U" m/s").drawAt(pos_.x, pos_.y + 48);
}
