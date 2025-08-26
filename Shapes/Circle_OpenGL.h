#pragma once
//#include <simple2d.h>
#include "my_simple2d.h"

#include "Point.h"
#include "Shape.h"
class Circle_OpenGL :
	public Shape
{
	inline static Point m_Position{};
	inline static float m_Radius;
	S2D_Window* m_pWindow{};

public:
	Circle_OpenGL(const Point& m_position, float m_radius, S2D_Window* m_p_window)
		:
		m_pWindow(m_p_window) {
		m_Position = m_position;
		m_Radius = m_radius;
	}
	static void Render();

	void Draw() override;
};

