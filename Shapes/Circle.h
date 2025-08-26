#pragma once
#include "Point.h"
#include "Shape.h"
#include "Window.h"

class Circle :
    public Shape
{
	Point m_Position{} ;
	float m_Radius{} ;
	Window *m_pWindow{} ;

public:
	Circle(const Point& m_position, float m_radius, Window* m_p_window)
		: m_Position(m_position),
		  m_Radius(m_radius),
		  m_pWindow(m_p_window) {
	}

	void Draw() override;
};

