#pragma once

const int GROUND_HIGHT{ 470 };


class Car
{
	//コーディング規約
public:
	Car();//<- コンストラクタ：メンバ変数の初期化
	~Car();
	Vec2 pos_;
	double accel_;
	double speed_;
	Vec2 dir_;
	Texture tex_;
	bool isMaxSpeed;//100m/s到達
	void Update();
	void Draw();
};

