#include "Circle.h"
#include <iostream>
#include <format>

Circle::Circle()
{
}

Circle::Circle(const Point& pCenter, int nRadius) : m_pCenter(pCenter), m_nRadius(nRadius)
{
}

bool Circle::Load(const std::string& sData)
{
	size_t nXPos = sData.find('|');
	std::string sX(sData.c_str(), nXPos);
	m_pCenter.m_nX = std::atoi(sX.c_str());

	size_t nYPos = sData.find('|', nXPos + 1);
	std::string sY(sData.c_str() + nXPos + 1, nYPos);
	m_pCenter.m_nY = std::atoi(sY.c_str());

	std::string sR(sData.c_str() + nYPos + 1, sData.size());
	m_nRadius = std::atoi(sR.c_str());

	return true;
}

bool Circle::Save(std::string& sData) const
{
	std::string sFormat;
	sFormat.resize(_MAX_PATH);
	int nSeted = std::snprintf(sFormat.data(), _MAX_PATH, "%d|%d|%d|%d\n", GetType(), m_pCenter.m_nX, m_pCenter.m_nY, m_nRadius);
	sData.append(sFormat.c_str(), nSeted);
	return true;
}

void Circle::Show() const
{
	std::cout << GetNameByType() << " Center: (" << m_pCenter.m_nX << "," << m_pCenter.m_nY << ") Radius: " << m_nRadius << std::endl;
}

int Circle::GetType() const noexcept
{
	return ShapeType_Circle;
}