#pragma once
#include "Shape.h"

class Rect : public Shape
{
public:
	Rect();
	Rect(const Point& pLT, int nH, int nW);
	~Rect() = default;

public:
	virtual bool Load(const std::string & sData) override;
	virtual bool Save(std::string & sData) const override;
	virtual void Show() const override;

public:
	virtual int GetType() const noexcept override;

protected:
	Point			m_pLT = { 0, 0 };
	int				m_nWidth = 0;
	int				m_nHeight = 0;
};

