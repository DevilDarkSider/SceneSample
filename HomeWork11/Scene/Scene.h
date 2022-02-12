#pragma once
#include <vector>
#include <string>

class Shape;
class Scene
{
public:
	Scene() = default;
	~Scene();

public:
	bool AddShape(Shape* pShape);
	Shape* GetShape(int nPos) const;

public:
	bool SaveToFile(const std::string& sPath);
	bool LoadFromFile(const std::string& sPath);

public:
	void Show() const;

private:
	std::vector<Shape*> m_aShapes;
};

