#pragma once
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
	void Update();
	void Draw();
};

