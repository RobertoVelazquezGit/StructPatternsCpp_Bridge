#pragma once
#include "Renderer.h"
#include "Window.h"

class GDI :
    public Renderer
{
	Window m_hWnd{} ;
public:
	GDI() ;
	void RenderCircle(Point position, float radius) override;
	void RenderLine(Point start, Point end) override;
	void Show() override;
};

