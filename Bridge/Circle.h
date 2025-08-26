#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
	Point m_Position{};
	float m_Radius{};

public:
	Circle(const Point& m_position, float m_radius)
		: m_Position(m_position),
		m_Radius(m_radius) {
	}
	void Draw() override;
};
