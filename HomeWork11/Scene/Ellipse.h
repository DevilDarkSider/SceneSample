#pragma once
#include "Rect.h"

class Ellipse : public Rect
{
public:
	Ellipse();
	Ellipse(const Point& pLT, int nH, int nW);

public:
	virtual int GetType() const noexcept;
};

