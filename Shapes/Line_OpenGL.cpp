#include "Line_OpenGL.h"


void Line_OpenGL::Render() {
	S2D_DrawLine(m_Start.x, m_Start.y, m_End.x, m_End.y, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
		) ;
}

void Line_OpenGL::Draw() {
}
