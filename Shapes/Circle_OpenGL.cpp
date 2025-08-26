#include "Circle_OpenGL.h"

void Circle_OpenGL::Render() {
	S2D_DrawCircle(m_Position.x, m_Position.y, m_Radius, 100, 1, 1 , 0, 1) ;
}

void Circle_OpenGL::Draw() {
}
