#include "Circle.h"
void Circle::Draw() {
	m_pRenderer->RenderCircle(m_Position, m_Radius);
}
