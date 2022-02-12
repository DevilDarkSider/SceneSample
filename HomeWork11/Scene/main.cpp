#include "Scene.h"
#include "Circle.h"
#include "Square.h"
#include "Ellipse.h"
#include "Rect.h"

int main()
{
	Scene scene;
	Circle* pCircle = new Circle({ 0,0 }, 10);
	scene.AddShape(pCircle);

	Square* pSquare = new Square({ -15, 5 }, 10);
	scene.AddShape(pSquare);

	Ellipse* pElipse = new Ellipse({ 5, 5 }, 5, 10);
	scene.AddShape(pElipse);

	Rect* pRect = new Rect({ 5,0 }, 5, 10);
	scene.AddShape(pRect);
	scene.Show();
	scene.SaveToFile("C:\\Users\\senki\\Desktop\\Data.txt");

	Scene newScene;
	newScene.LoadFromFile("C:\\Users\\senki\\Desktop\\Data.txt");

	newScene.Show();
}