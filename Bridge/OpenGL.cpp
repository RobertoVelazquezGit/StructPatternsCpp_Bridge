#include "OpenGL.h"

#include <tuple>

OpenGL::OpenGL() {
	m_pWindow = S2D_CreateWindow("MainWindow", 800, 600, nullptr, OpenGL::Render, S2D_RESIZABLE) ;
}

void OpenGL::RenderCircle(Point position, float radius) {
	m_Circles.push_back(std::make_tuple(position, radius)) ;
}

void OpenGL::RenderLine(Point start, Point end) {
	m_Lines.push_back(std::make_tuple(start, end)) ;
}

void OpenGL::Render() {
	for(auto line : m_Lines) {
		auto [start, end] = line ;
		S2D_DrawLine(start.x, start.y, end.x, end.y,1,
			1, 1, 1, 1,
			1, 1, 1, 1,
			1, 1, 1, 1,
			1, 1, 1, 1
		) ;
	}

	for(auto circle : m_Circles) {
		auto [position, radius] = circle ;
		S2D_DrawCircle(position.x, position.y, radius, 100, 1, 1 , 0, 1) ;
	}
}

void OpenGL::Show() {
	S2D_Show(m_pWindow) ;
}
