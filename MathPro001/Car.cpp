#include "stdafx.h"
#include "Car.h"
const float GRAV{ 1.0 };
const float FRICTIONTERM{ 0.985 };
const float MAX_SPEED{ 100 };//m/s 1pixel=1m


Car::Car()
{
	pos_ = { Scene::Width()-50, GROUND_HIGHT - 50 / 2 + 9 };
	speed_ = { 0.0,0.0 }; // 初速0 m/s
	accel_ = { -100.0, 0.0 };
	dir_ = { -1.0, 0 };
	tex_ = TextureAsset(U"CAR");
	isMaxSpeed_ = false;
	isJump = false;
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
		if(speed_.x <= 100)
			speed_.x = speed_.x + accel_.x * Scene::DeltaTime();
	}else
		speed_.x = speed_.x - speed_.x * FRICTIONTERM * Scene::DeltaTime();

	//pos_ = pos_ + speed_.x * dir_ * Scene::DeltaTime();
	if (KeyV.down())
	{
		if (isJump == false)
		{
			isJump = true;
			accel_.y = 360.0;
			speed_.y = -180;
		}
	}
	else
	{

		if(isJump && pos_.y > GROUND_HIGHT-50/2+10)
		{
			pos_.y = GROUND_HIGHT - 50 / 2 + 10;
			speed_.y = 0;
			accel_.y = 0;
			isJump = false;
		}
		
		speed_.y = speed_.y + accel_.y * Scene::DeltaTime();
	}
	pos_ = pos_ + speed_ * Scene::DeltaTime();
}

void Car::Draw()
{
	tex_.resized(50).drawAt(pos_);
	String strSPD = ToString(-(int)speed_.x);
	FontAsset(U"FONT")(strSPD + U" m/s").drawAt(pos_.x, pos_.y + 48);
}
