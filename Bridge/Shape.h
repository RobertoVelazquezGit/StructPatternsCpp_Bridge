#pragma once
#include "Renderer.h"

class Shape
{
protected:
	Renderer* m_pRenderer;
public:
	void SetRenderer(Renderer* r) {
		m_pRenderer = r;
	}
	virtual void Draw() = 0;
	virtual ~Shape() = default;
};
