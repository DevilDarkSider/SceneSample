#pragma once
#include <string>

enum ShapeType
{
	ShapeType_Undefined = 0,
	//
	ShapeType_Rect,
	ShapeType_Square,
	ShapeType_Circle,
	ShapeType_Ellipse,
	//
	_ShapeType_All_
};

class Shape
{
public:
	static bool Create(int nType, Shape** ppShape);
	
public:
	virtual bool Load(const std::string& sData) = 0;
	virtual bool Save(std::string& sData) const = 0;
	virtual void Show() const = 0;

public:
	virtual int GetType() const noexcept;

protected:
	const char* GetNameByType() const noexcept;
};

struct Point
{
	int m_nX = 0;
	int m_nY = 0;
};