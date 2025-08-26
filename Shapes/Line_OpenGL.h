#pragma once
#include "Point.h"
#include "Shape.h"

//#include <simple2d.h>
#include "my_simple2d.h"

class Line_OpenGL :
	public Shape
{
	inline static Point m_Start{};  // Used inside static void Render function
	inline static Point m_End{};
	S2D_Window* m_pWindow{};
public:
	Line_OpenGL(const Point& m_start, const Point& m_end, S2D_Window* m_p_window)
		:
		m_pWindow(m_p_window) {  
		m_Start = m_start;  // there can not be static members in the constructor initialization list
		m_End = m_end;
	}
// Render must be according to the function pointer expected by S2D_CreateWindow at typedef void (*S2D_Render)();,
// notice there is no instance of Line_OpenGL when S2D_CreateWindow is called.
	static void Render(); 
	void Draw() override;
};

