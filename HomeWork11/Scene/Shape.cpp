#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Ellipse.h"
#include "Square.h"

bool Shape::Create(int nType, Shape** ppShape)
{
	switch (nType)
	{
	case ShapeType_Circle:
		*ppShape = new Circle();
		break;
	case ShapeType_Rect:
		*ppShape = new Rect();
		break;
	case ShapeType_Square:
		*ppShape = new Square();
		break;
	case ShapeType_Ellipse:
		*ppShape = new Ellipse();
		break;
	}

	return *ppShape != nullptr;
}

int Shape::GetType() const noexcept
{
	return ShapeType_Undefined;
}

const char* Shape::GetNameByType() const noexcept
{
	switch (GetType())
	{
	case ShapeType_Undefined:
		return "Undefined";
	case ShapeType_Square:
		return "Square";
	case ShapeType_Rect:
		return "Rect";
	case ShapeType_Circle:
		return "Circle";
	case ShapeType_Ellipse:
		return "Ellipse";
	}

	return "Invalid";
}