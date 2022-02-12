#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(const Point& pCenter, int nRadius);
	~Circle() = default;

public:
	virtual bool Load(const std::string& sData) override;
	virtual bool Save(std::string& sData) const override;
	virtual void Show() const override;

public:
	virtual int GetType() const noexcept override;

private:
	Point			m_pCenter = { 0, 0 };
	int				m_nRadius = 0;
};

