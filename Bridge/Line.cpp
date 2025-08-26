#include "Line.h"
void Line::Draw() {
	m_pRenderer->RenderLine(m_Start, m_End);
}