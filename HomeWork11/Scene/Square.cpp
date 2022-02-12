#include "Square.h"


Square::Square()
{
}

Square::Square(const Point& pLT, int nSide) : Rect(pLT, nSide, nSide)
{
}

bool Square::Load(const std::string& sData)
{
	size_t nXPos = sData.find('|');
	std::string sX(sData.c_str(), nXPos);
	m_pLT.m_nX = std::atoi(sX.c_str());

	size_t nYPos = sData.find('|', nXPos + 1);
	std::string sY(sData.c_str() + nXPos + 1, nYPos);
	m_pLT.m_nY = std::atoi(sY.c_str());

	std::string sSide(sData.c_str() + nYPos + 1, sData.size());
	m_nWidth = m_nHeight = std::atoi(sSide.c_str());
	return true;
}

bool Square::Save(std::string& sData) const
{
	std::string sFormat;
	sFormat.resize(_MAX_PATH);
	int nSeted = std::snprintf(sFormat.data(), _MAX_PATH, "%d|%d|%d|%d\n", GetType(), m_pLT.m_nX, m_pLT.m_nY, m_nHeight);
	sData.append(sFormat.c_str(), nSeted);
	return true;
}


int Square::GetType() const noexcept
{
	return ShapeType_Square;
}