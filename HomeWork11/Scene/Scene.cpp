#include "Scene.h"
#include <fstream>
#include <filesystem>
#include "Shape.h"

Scene::~Scene()
{
	for (auto& pShape : m_aShapes)
	{
		delete pShape;
		pShape = nullptr;
	}
	m_aShapes.clear();
}

bool Scene::AddShape(Shape* pShape)
{
	if (!pShape)
		return false;
	m_aShapes.push_back(pShape);
	return true;
}

Shape* Scene::GetShape(int nPos) const
{
	if (nPos >= (int)m_aShapes.size())
		return nullptr;
	return m_aShapes[nPos];
}


bool Scene::SaveToFile(const std::string& sPath)
{
	std::ofstream out(sPath);
	if (!out.is_open())
		return false;

	std::string sData;
	for (const auto& pShape : m_aShapes)
	{
		pShape->Save(sData);
	}

	out << sData.c_str();
	out.close();
	return true;
}

bool Scene::LoadFromFile(const std::string& sPath)
{
	std::ifstream in(sPath);
	if (!in.is_open())
		return false;

	std::string sLine;
	sLine.resize(_MAX_PATH);
	while (in.getline(sLine.data(), _MAX_PATH))
	{
		size_t nTypePos = sLine.find('|');
		std::string sType(sLine.c_str(), nTypePos);
		int nType = std::atoi(sType.c_str());

		Shape* pNewShape = nullptr;
		if (!Shape::Create(nType, &pNewShape))
			continue;

		
		if (!pNewShape->Load(sLine.c_str() + nTypePos + 1))
		{
			delete pNewShape;
			continue;
		}

		AddShape(pNewShape);
	}

	in.close();
	return false;
}


void Scene::Show() const
{
	for (const auto& pShape : m_aShapes)
	{
		pShape->Show();
	}
}