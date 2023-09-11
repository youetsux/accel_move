# include <Siv3D.hpp> // OpenSiv3D v0.6.10
# include "Car.h"



void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(Palette::Burlywood);
	// 太文字のフォントを作成する | Create a bold font with MSDF method
	//const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	FontAsset::Register(U"FONT", FontMethod::MSDF, 48, Typeface::Bold);
	TextureAsset::Register(U"CAR", U"🚜"_emoji);

	Car mycar;

	while (System::Update())
	{
		Rect{ {0, 470},Scene::Width(), Scene::Height() - 470 }.draw(Palette::Firebrick);
		mycar.Update();
		mycar.Draw();
	
	}
}


