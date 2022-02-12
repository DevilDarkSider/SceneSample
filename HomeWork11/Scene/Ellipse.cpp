#include "Ellipse.h"

Ellipse::Ellipse()
{
}

Ellipse::Ellipse(const Point& pLT, int nH, int nW) : Rect(pLT, nH, nW)
{
}

int Ellipse::GetType() const noexcept
{
	return ShapeType_Ellipse;
}