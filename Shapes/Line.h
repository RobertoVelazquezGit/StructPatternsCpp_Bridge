#pragma once
#include "Point.h"
#include "Shape.h"
#include "Window.h"

class Line : public Shape
{
	Point m_Start{} ;
	Point m_End{} ;
	Window * m_pWindow{} ;
public:
	Line(const Point& m_start, const Point& m_end, Window *pWin)
		: m_Start(m_start),
		m_End(m_end), m_pWindow{pWin} {
	}
	void Draw() override;    
};

