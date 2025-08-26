#pragma once
#include "Shape.h"
class Line :
	public Shape
{
	Point m_Start{};
	Point m_End{};

public:
	Line(const Point& m_start, const Point& m_end)
		: m_Start(m_start),
		m_End(m_end) {
	}

	void Draw() override;
	Point GetStart()const {
		return m_Start;
	}
	Point GetEnd()const {
		return m_End;
	}
};

