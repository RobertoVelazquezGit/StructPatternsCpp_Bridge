#pragma once
#include "Point.h"
class Renderer
{
public:
	virtual void RenderCircle(Point position, float radius) = 0 ;
	virtual void RenderLine(Point start, Point end) = 0 ;
	virtual void Show() = 0 ;
	virtual ~Renderer() = default ;
};

