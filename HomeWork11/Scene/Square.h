#pragma once
#include "Rect.h"

class Square : public Rect
{
public:
	Square();
	Square(const Point& pLT, int nSide);
	~Square() = default;

public:
	virtual bool Load(const std::string& sData) override;
	virtual bool Save(std::string& sData) const override;

public:
	virtual int GetType() const noexcept override;
};

