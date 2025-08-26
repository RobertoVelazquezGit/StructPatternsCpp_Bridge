#include "GDI.h"
#include "Point.h"

GDI::GDI() {
	m_hWnd.Show() ;
}

void GDI::RenderCircle(Point position, float radius)
{
	m_hWnd.DrawCircle(position, radius) ;
}

void GDI::RenderLine(Point start, Point end)
{
	m_hWnd.DrawLine(start, end) ;
}
void Run();

void GDI::Show() {
	Run() ;
}
