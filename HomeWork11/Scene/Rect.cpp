#include "Rect.h"
#include <iostream>

Rect::Rect()
{
}

Rect::Rect(const Point& pLT, int nH, int nW) : m_pLT(pLT), m_nHeight(nH), m_nWidth(nW)
{
}

bool Rect::Load(const std::string& sData)
{
	size_t nXPos = sData.find('|');
	std::string sX(sData.c_str(), nXPos);
	m_pLT.m_nX = std::atoi(sX.c_str());

	size_t nYPos = sData.find('|', nXPos + 1);
	std::string sY(sData.c_str() + nXPos + 1, nYPos);
	m_pLT.m_nY = std::atoi(sY.c_str());

	size_t nHPos = sData.find('|', nYPos + 1);
	std::string sH(sData.c_str() + nYPos + 1, nHPos);
	m_nHeight = std::atoi(sH.c_str());

	std::string sW(sData.c_str() + nHPos + 1, sData.size());
	m_nWidth = std::atoi(sW.c_str());

	return true;
}

bool Rect::Save(std::string& sData) const
{
	std::string sFormat;
	sFormat.resize(_MAX_PATH);
	int nSeted = std::snprintf(sFormat.data(), _MAX_PATH, "%d|%d|%d|%d|%d\n", GetType(), m_pLT.m_nX, m_pLT.m_nY, m_nHeight, m_nWidth);
	sData.append(sFormat.c_str(), nSeted);
	return true;
}

void Rect::Show() const
{
	std::cout << GetNameByType() << " Left-Top: (" << m_pLT.m_nX << "," << m_pLT.m_nY << ") Height: " << m_nHeight << " Width: " << m_nWidth << std::endl;
}

int Rect::GetType() const noexcept
{
	return ShapeType_Rect;
}